
//
//  GlassBlock.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef GlassBlock_hpp
#define GlassBlock_hpp

#include "Block.hpp"

class GlassBlock : public Block {
public:
    GlassBlock();
    ~GlassBlock();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual float hardness();
    virtual bool isTransparent();
};

#endif /* GlassBlock_hpp */
