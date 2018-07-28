//
//  chunk.cpp
//  craft
//
//  Created by Ryan Riffle on 7/11/18.
//

#include "global.h"
#include "db.h"
#include "util.h"
#include <map>
#include <iostream>
#include <cmath>
#include "item.h"
#include "client.h"
#include "db.h"

/*
 * ChunkMap is used to store chunks in a easier to lookup
 * structure.
 *
 * Firstly it is a map with the Chunk X position as the key.
 * The value for the key is a vector of chunks. That way
 * at any given moment instead of looking through ViewDistance * ViewDistance
 * the lookup only has to look through ViewDistance number of chunks at the
 * most.
 */
typedef std::map<int, std::vector<Chunk*> > ChunkMap;

static ChunkMap gChunkMap;
static std::list<Chunk*> gAllChunks;

Chunk::Chunk() :
    Renderable(),
    m_isSetup(false),
    m_isDirty(false),
    mHighest(NULL)
{
    
}

Chunk::Chunk(int, int) :
    m_isSetup(false)
{
    //initialize(chunkX, chunkZ);
}

Chunk::~Chunk()
{

}

void Chunk::initialize(int chunkX, int chunkZ)
{
    m_chunkPosition.x = chunkX;
    m_chunkPosition.z = chunkZ;
    
    faces = 0;
    sign_faces = 0;
    buffer = 0;
    sign_buffer = 0;
    SignList *signs = &this->signs;
    sign_list_alloc(signs, 16);
    db_load_signs(signs, m_chunkPosition.x, m_chunkPosition.z);
    Map *block_map = &map;
    Map *light_map = &lights;
    int dx = chunkX * CHUNK_SIZE - 1;
    int dy = 0;
    int dz = chunkZ * CHUNK_SIZE - 1;
    map_alloc(block_map, dx, dy, dz, 0xfff);
    map_alloc(light_map, dx, dy, dz, 0xf);
    
    m_isSetup = true;
    m_isDirty = true;
}

Chunk* Chunk::findChunk(int chunkX, int chunkZ)
{
    for (int i = 0; i < g->chunk_count; i++) {
        Chunk *chunk = g->chunks + i;
        if (chunk->getChunkPosition().x == chunkX && chunk->getChunkPosition().z == chunkZ) {
            return chunk;
        }
    }
    
    return nullptr;
}

void Chunk::dirty(bool isDirty) { 
    m_isDirty = isDirty;
    
    if (isDirty) {
        if (hasLights()) {
            for (int dp = -1; dp <= 1; dp++) {
                for (int dq = -1; dq <= 1; dq++) {
                    Chunk *other = findChunk(getChunkPosition().x + dp, getChunkPosition().z + dq);
                    if (other) {
                        other->m_isDirty = true;
                    }
                }
            }
        }
    }
}

bool Chunk::isDirty() const { 
    return m_isDirty;
}

ChunkPosition Chunk::getChunkPosition() const
{
    return m_chunkPosition;
}

void Chunk::setMinY(float miny)
{
    m_miny = miny;
}

void Chunk::setMaxY(float maxy)
{
    m_maxy = maxy;
}

float Chunk::getMinY()
{
    return m_miny;
}

float Chunk::getMaxY()
{
    return m_maxy;
}

Map* Chunk::getBlockMap()
{
    return &map;
}

Map* Chunk::getLightMap()
{
    return &lights;
}

bool Chunk::hasLights() const
{
    if (!SHOW_LIGHTS) {
        return false;
    }
    
    for (int dp = -1; dp <= 1; dp++) {
        for (int dq = -1; dq <= 1; dq++) {
            Chunk *other = nullptr;
            if (dp || dq) {
                other = findChunk(getChunkPosition().x + dp, getChunkPosition().z + dq);
            }
            if (!other) {
                continue;
            }
            Map *map = &other->lights;
            if (map->size) {
                return true;
            }
        }
    }
    
    return false;
}

int Chunk::distanceTo(int chunkX, int chunkZ) const
{
    int dp = ABS(getChunkPosition().x - chunkX);
    int dq = ABS(getChunkPosition().z - chunkZ);
    return MAX(dp, dq);
}

bool Chunk::isVisible(float planes[6][4]) const
{
    float x = m_chunkPosition.x * CHUNK_SIZE - 1;
    float z = m_chunkPosition.z * CHUNK_SIZE - 1;
    int d = CHUNK_SIZE + 1;
    float points[8][3] = {
        {x + 0, m_miny, z + 0},
        {x + d, m_miny, z + 0},
        {x + 0, m_miny, z + d},
        {x + d, m_miny, z + d},
        {x + 0, m_maxy, z + 0},
        {x + d, m_maxy, z + 0},
        {x + 0, m_maxy, z + d},
        {x + d, m_maxy, z + d}
    };
    int n = g->ortho ? 4 : 6;
    for (int i = 0; i < n; i++) {
        int in = 0;
        int out = 0;
        for (int j = 0; j < 8; j++) {
            float d =
            planes[i][0] * points[j][0] +
            planes[i][1] * points[j][1] +
            planes[i][2] * points[j][2] +
            planes[i][3];
            if (d < 0) {
                out++;
            }
            else {
                in++;
            }
            if (in && out) {
                break;
            }
        }
        if (in == 0) {
            return 0;
        }
    }
    return 1;
}

bool Chunk::isValid() const
{
    return m_isSetup;
}

bool Chunk::hasSigns() const
{
    return signs.size > 0;
}

int Chunk::render(ShaderAttributes *attrib)
{
    draw_triangles_3d_ao(attrib, this->buffer, this->faces * 6);
    return this->faces;
}

Chunk *Chunk::getAllChunks()
{
    return g->chunks;
}

int Chunk::bufferSize()
{
    return static_cast<int>(gAllChunks.max_size());
}

void Chunk::destroy(Chunk *chunk)
{
    map_free(chunk->getBlockMap());
    map_free(chunk->getLightMap());
    sign_list_free(&chunk->signs);
    del_buffer(chunk->buffer);
    del_buffer(chunk->sign_buffer);
    
    Chunk *other = g->chunks + (--g->chunk_count);
    chunk->map = other->map;
    chunk->signs = other->signs;
    chunk->lights = other->lights;
    chunk->m_isDirty = other->m_isDirty;
    chunk->m_maxy = other->m_maxy;
    chunk->m_miny = other->m_miny;
    chunk->m_chunkPosition = other->m_chunkPosition;
    chunk->m_isSetup = other->m_isSetup;
    chunk->faces = other->faces;
    chunk->buffer = other->buffer;
    chunk->sign_faces = other->sign_faces;
    chunk->sign_buffer = other->sign_buffer;
}

void Chunk::destroyAll()
{
    std::list<Chunk*> chunks;
    for (int i = 0; i < g->chunk_count; i++) {
        Chunk *chunk = g->chunks + i;
        Chunk::destroy(chunk);
    }
    
}

Chunk &Chunk::operator=(const Chunk &rs)
{
    this->map = rs.map;
    this->signs = rs.signs;
    this->lights = rs.lights;
    this->m_isDirty = rs.m_isDirty;
    this->m_maxy = rs.m_maxy;
    this->m_miny = rs.m_miny;
    this->m_chunkPosition = rs.m_chunkPosition;
    this->m_isSetup = rs.m_isSetup;
    this->faces = rs.faces;
    this->buffer = rs.buffer;
    this->sign_faces = rs.sign_faces;
    this->sign_buffer = rs.sign_buffer;
    
    return *this;
}

void Chunk::onTick(unsigned int tickCount)
{
    
}

int Chunk::chunked(int x)
{
    return floorf(roundf(x) / CHUNK_SIZE);
}

int Chunk::highest(int x, int z)
{
    int result = -1;
    int nx = roundf(x);
    int nz = roundf(z);
    int p = Chunk::chunked(x);
    int q = Chunk::chunked(z);
    Chunk *chunk = Chunk::findChunk(p, q);
    if (chunk) {
        Map *map = chunk->getBlockMap();
        MAP_FOR_EACH(map, ex, ey, ez, ew) {
            if (is_obstacle(ew) && ex == nx && ez == nz) {
                result = MAX(result, ey);
            }
        } END_MAP_FOR_EACH;
    }
    return result;
}

void Chunk::setHighest(unsigned char *highest)
{
    if (mHighest != NULL && highest != mHighest)
        free(mHighest);
    mHighest = highest;
}

void Chunk::addWaitingForChunk(ChunkPosition p)
{
    mWaitingForChunks.push_back(p);
}


bool Chunk::isWaitingForChunk(ChunkPosition p)
{
    for (auto it = mWaitingForChunks.begin(); it != mWaitingForChunks.end(); ++it) {
        ChunkPosition a = *it;
        
        if (a.x == p.x && a.z == p.z) {
            return true;
        }
    }
    
    return false;
}

void Chunk::clearWaitingChunks()
{
    mWaitingForChunks.clear();
}









