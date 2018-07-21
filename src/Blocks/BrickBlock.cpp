//
//  BrickBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "BrickBlock.hpp"

BrickBlock::BrickBlock() :
    Block()
{
    
}

BrickBlock::~BrickBlock()
{
    
}

int BrickBlock::blockId()
{
    return 4;
}

std::string BrickBlock::blockName()
{
    return std::string("craft:brick_block");
}

int BrickBlock::stackSize()
{
    return 64;
}

float BrickBlock::hardness()
{
    return 2.0f;
}
