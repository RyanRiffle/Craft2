//
//  WaterBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "WaterBlock.hpp"

WaterBlock::WaterBlock() :
    Block()
{
    
}

WaterBlock::~WaterBlock()
{
    
}

int WaterBlock::blockId()
{
    return 64;
}

std::string WaterBlock::blockName()
{
    return std::string("craft:water_block");
}

int WaterBlock::stackSize()
{
    return 64;
}

float WaterBlock::hardness()
{
    return 2.0f;
}

bool WaterBlock::isObstacle()
{
    return false;
}

bool WaterBlock::isTransparent()
{
    return true;
}
