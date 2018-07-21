//
//  Plant.hpp
//  Craft2vec4 transparency = vec4(texture2D(sampler, fragment_uv));
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef Plant_hpp
#define Plant_hpp

#include "Block.hpp"

class Plant : public Block {
public:
    Plant();
    ~Plant();
    
    virtual Block::BlockType type();
    virtual bool isObstacle();
    virtual bool isFlammable();
    virtual bool isTransparent();
};

#endif /* PlantBlock_hpp */
