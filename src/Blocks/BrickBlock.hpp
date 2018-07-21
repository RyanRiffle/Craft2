
//
//  BrickBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef BrickBlock_hpp
#define BrickBlock_hpp

#include "Block.hpp"

class BrickBlock : public Block {
public:
    BrickBlock();
    ~BrickBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* BrickBlock_hpp */
