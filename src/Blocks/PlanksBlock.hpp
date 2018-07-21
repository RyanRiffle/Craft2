
//
//  PlanksBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef PlanksBlock_hpp
#define PlanksBlock_hpp

#include "Block.hpp"

class PlanksBlock : public Block {
public:
    PlanksBlock();
    ~PlanksBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* PlanksBlock_hpp */
