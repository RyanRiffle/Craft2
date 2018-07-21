//
//  AirBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef AirBlock_hpp
#define AirBlock_hpp

#include "Block.hpp"

class AirBlock : public Block {
public:
    AirBlock();
    ~AirBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual bool isTransparent();
    virtual bool isObstacle();
};

#endif /* AirBlock_hpp */
