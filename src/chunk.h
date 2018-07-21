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

typedef struct {
    int x;
    int z;
} ChunkPosition;

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
    static void destroy(std::list<Chunk*> *chunks);
    static void destroyAll();
    
    static Chunk *getAllChunks();
    static int bufferSize();
    
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
};

#endif /* chunk_h */
