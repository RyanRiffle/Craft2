//
//  WoodBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "WoodBlock.hpp"

WoodBlock::WoodBlock() :
    Block()
{
    
}

WoodBlock::~WoodBlock()
{
    
}

int WoodBlock::blockId()
{
    return 5;
}

std::string WoodBlock::blockName()
{
    return std::string("craft:wood_block");
}

int WoodBlock::stackSize()
{
    return 64;
}

float WoodBlock::hardness()
{
    return 2.0f;
}
