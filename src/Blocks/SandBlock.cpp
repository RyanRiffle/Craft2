//
//  SandBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "SandBlock.hpp"

SandBlock::SandBlock() :
    Block()
{
    
}

SandBlock::~SandBlock()
{
    
}

int SandBlock::blockId()
{
    return 2;
}

std::string SandBlock::blockName()
{
    return std::string("craft:sand_block");
}

int SandBlock::stackSize()
{
    return 64;
}

float SandBlock::hardness()
{
    return 0.5f;
}


