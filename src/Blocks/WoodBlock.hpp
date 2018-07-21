
//
//  WoodBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef WoodBlock_hpp
#define WoodBlock_hpp

#include "Block.hpp"

class WoodBlock : public Block {
public:
    WoodBlock();
    ~WoodBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
};

#endif /* WoodBlock_hpp */
