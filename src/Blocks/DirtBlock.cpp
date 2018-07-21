//
//  DirtBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "DirtBlock.hpp"

DirtBlock::DirtBlock() :
    Block()
{
    
}

DirtBlock::~DirtBlock()
{
    
}

int DirtBlock::blockId()
{
    return 7;
}

std::string DirtBlock::blockName()
{
    return std::string("craft:dirt_block");
}

int DirtBlock::stackSize()
{
    return 64;
}

float DirtBlock::hardness()
{
    return 2.0f;
}
