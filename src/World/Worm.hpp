//
//  Worm.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/21/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef Worm_hpp
#define Worm_hpp

#include "../world.h"
#include <vector>
class Chunk;

struct WormSegment {
    int x;
    int y;
    int z;
};

class Worm {
public:
    Worm();
    ~Worm();
    
    void generate(int chunkX, int chunkZ, world_func func, void *arg);
    
private:
    std::vector<WormSegment> mSegments;
};

#endif /* Worm_hpp */
