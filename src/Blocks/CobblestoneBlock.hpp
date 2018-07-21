
//
//  CobblestoneBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef CobblestoneBlock_hpp
#define CobblestoneBlock_hpp

#include "Block.hpp"

class CobblestoneBlock : public Block {
public:
    CobblestoneBlock();
    ~CobblestoneBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* CobblestoneBlock_hpp */
