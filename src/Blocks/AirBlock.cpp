//
//  AirBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "AirBlock.hpp"

AirBlock::AirBlock() :
Block()
{
    
}

AirBlock::~AirBlock()
{
    
}

int AirBlock::blockId()
{
    return 0;
}

std::string AirBlock::blockName()
{
    return std::string("craft:air_block");
}

int AirBlock::stackSize()
{
    return 0;
}

bool AirBlock::isTransparent()
{
    return true;
}

bool AirBlock::isObstacle()
{
    return false;
}
