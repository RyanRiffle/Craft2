
//
//  DirtBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef DirtBlock_hpp
#define DirtBlock_hpp

#include "Block.hpp"

class DirtBlock : public Block {
public:
    DirtBlock();
    ~DirtBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* DirtBlock_hpp */
