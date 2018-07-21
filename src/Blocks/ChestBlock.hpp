
//
//  ChestBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//TODO: Make this work

#ifndef ChestBlock_hpp
#define ChestBlock_hpp

#include "Block.hpp"

class ChestBlock : public Block {
public:
    ChestBlock();
    ~ChestBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* ChestBlock_hpp */
