//
//  SandBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef SandBlock_hpp
#define SandBlock_hpp

#include "Block.hpp"

class SandBlock : public Block {
public:
    SandBlock();
    ~SandBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* SandBlock_hpp */
