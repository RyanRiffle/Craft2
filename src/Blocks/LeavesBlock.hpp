//
//  LeavesBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef LeavesBlock_hpp
#define LeavesBlock_hpp

#include "Block.hpp"

class LeavesBlock : public Block {
public:
    LeavesBlock();
    ~LeavesBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual bool isTransparent();
};

#endif /* LeavesBlock_hpp */
