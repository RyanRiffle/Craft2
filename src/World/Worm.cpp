//
//  Worm.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/21/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "Worm.hpp"
extern "C" {
    #include "noise.h"
}
#include <iostream>
#include "config.h"

#define SEGMENT_COUNT 64

Worm::Worm()
{
    
}

Worm::~Worm()
{
    
}

void Worm::generate(int chunkX, int chunkZ, world_func func, void *arg)
{
    float hasWorm = simplex2(chunkX * 0.01f, chunkZ * 0.01f, 4, 0.5, 2);
    if (hasWorm < 0.5)
        return;
    
    //std::cout << "Chunk (" << chunkX << ", " << chunkZ << ") has a cave" << std::endl;
    
    int x = chunkX * CHUNK_SIZE;
    int z = chunkZ * CHUNK_SIZE;
    int y = z * 32 + 16;
    
    int currentX = x + (simplex3(x * 0.1f, y * 0.1f, z * 0.1f, 4, 0.5, 2) * 16);
    int currentY = (simplex3(x * 0.1f, y * 0.1f, z * 0.1f, 4, 0.5, 2) * 16);
    int currentZ = z + (simplex3(x * 0.1f, y * 0.1f, z * 0.1f, 4, 0.5, 2) * 16);
    for (int i = 0; i < SEGMENT_COUNT; i++) {
        //WormSegment segment;
        
        float val = simplex2(currentX * 0.01f, currentZ * 0.01f, 2, 0.5, 2);
        std::cout << val << std::endl;
       
        float xval = simplex3(x * 0.1f, y * 0.01f, z * 0.1f, 4, 0.5, 2);
        float yval = simplex3(x * 0.1f, y * 0.1f, z * 0.01f, 2, 0.5, 2);
        float zval = simplex3(x * 0.01f, y * 0.1f, z * 0.1f, 4, 0.5, 2);
        
        if (xval > 0.4f)
            currentX++;
        if (yval > 0.2f)
            currentY++;
        if (zval > 0.6f)
            currentZ++;
        
        for (int r = -1; r <= 1; r++) {
            func(currentX+r, currentY, currentZ, 0, arg);
            func(currentX+r, currentY+r, currentZ, 0, arg);
            func(currentX, currentY, currentZ, 0, arg);
            func(currentX, currentY+r, currentZ, 0, arg);
            func(currentX, currentY, currentZ+r, 0, arg);
        }
    }
}
