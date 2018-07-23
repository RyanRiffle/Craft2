//
//  GrassBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef GrassBlock_hpp
#define GrassBlock_hpp

#include "Block.hpp"

class GrassBlock : public Block {
public:
    GrassBlock();
    GrassBlock(int x, int y, int z);
    ~GrassBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual bool onPlace();
};

#endif /* GrassBlock_hpp */
