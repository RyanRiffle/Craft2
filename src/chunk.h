//
//  chunk.h
//  craft
//
//  Created by Ryan Riffle on 7/11/18.
//

#ifndef chunk_h
#define chunk_h

#include "map.h"
#include "sign.h"
#include "Render/Renderable.hpp"
#include <GL/glew.h>
#include <vector>
#include <list>

#define XZ_SIZE (CHUNK_SIZE * 3 + 2)
#define XZ_LO (CHUNK_SIZE)
#define XZ_HI (CHUNK_SIZE * 2 + 1)
#define Y_SIZE 258
#define XYZ(x, y, z) ((y) * XZ_SIZE * XZ_SIZE + (x) * XZ_SIZE + (z))
#define XZ(x, z) ((x) * XZ_SIZE + (z))

typedef struct {
    int x;
    int z;
} ChunkPosition;

/**
 * Class representing a chunk in the game.
 *
 * Currently this class is never instantiated on the heap. It is on the stack
 * and the Chunk::initialize() and Chunk::destory() functions should be used
 * to setup the chunk or remove all values respectively. Each instance of a
 * chunk are stored in the extern g or global struct at (g->chunks). It is an
 * array allowing up to MAX_CHUNKS which is specified in global.h.
 */
class Chunk : public Renderable {
public:
    Chunk();
    Chunk(int chunkX, int chunkZ);
    ~Chunk();
    
    void initialize(int chunkX, int chunkZ);
    static Chunk* findChunk(int chunkX, int chunkZ);
    
    void dirty(bool isDirty);
    bool isDirty() const;
    bool isVisible(float planes[6][4]) const;
    bool isValid() const;
    ChunkPosition getChunkPosition() const;
    static void destroy(Chunk *chunk);
    static void destroyAll();
    
    static Chunk *getAllChunks();
    static int bufferSize();
    static int chunked(int x);
    static int highest(int x, int z);
    void setHighest(unsigned char *highest);
    
    virtual int render(ShaderAttributes *attrib) override;
    
    void setMinY(float miny);
    void setMaxY(float maxy);
    float getMinY();
    float getMaxY();
    
    Map* getBlockMap();
    Map* getLightMap();
    
    bool hasLights() const;
    bool hasSigns() const;
    int distanceTo(int chunkX, int chunkZ) const;
    
    Chunk &operator=(const Chunk &rs);
    
    void onTick(unsigned tickCount);
    bool isWaitingForChunk(ChunkPosition p);
    void addWaitingForChunk(ChunkPosition p);
    void clearWaitingChunks();
    
    
    SignList signs;
    int faces;
    int sign_faces;
    GLuint buffer;
    GLuint sign_buffer;
private:
    Map map;
    Map lights;
    float m_miny;
    float m_maxy;
    bool m_isSetup;
    bool m_isDirty;
    ChunkPosition m_chunkPosition;
    std::vector<ChunkPosition> mWaitingForChunks;
    unsigned char *mHighest;
};

#endif /* chunk_h */
