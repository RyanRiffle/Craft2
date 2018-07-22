
//
//  WaterBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef WaterBlock_hpp
#define WaterBlock_hpp

#include "Block.hpp"

class WaterBlock : public Block {
public:
    WaterBlock();
    ~WaterBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
    virtual bool isObstacle();
    virtual bool isTransparent();
};

#endif /* WaterBlock_hpp */
