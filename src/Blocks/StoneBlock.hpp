
//
//  StoneBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef StoneBlock_hpp
#define StoneBlock_hpp

#include "Block.hpp"

class StoneBlock : public Block {
public:
    StoneBlock();
    ~StoneBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
    virtual Block::BlockType type();
    virtual bool isTransparent();
    virtual int drops();
};

#endif /* StoneBlock_hpp */
