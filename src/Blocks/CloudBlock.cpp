//
//  CloudBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "CloudBlock.hpp"

CloudBlock::CloudBlock() :
    Block()
{
    
}

CloudBlock::~CloudBlock()
{
    
}

int CloudBlock::blockId()
{
    return 16;
}

std::string CloudBlock::blockName()
{
    return std::string("craft:cloud_block");
}

int CloudBlock::stackSize()
{
    return 64;
}

float CloudBlock::hardness()
{
    return 2.0f;
}

bool CloudBlock::isObstacle()
{
    return false;
}
