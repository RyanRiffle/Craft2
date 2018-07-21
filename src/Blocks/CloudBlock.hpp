
//
//  CloudBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef CloudBlock_hpp
#define CloudBlock_hpp

#include "Block.hpp"

class CloudBlock : public Block {
public:
    CloudBlock();
    ~CloudBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
    virtual bool isObstacle();
};

#endif /* CloudBlock_hpp */
