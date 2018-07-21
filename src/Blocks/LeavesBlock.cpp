//
//  LeavesBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "LeavesBlock.hpp"

LeavesBlock::LeavesBlock() :
Block()
{
    
}

LeavesBlock::~LeavesBlock()
{
    
}

int LeavesBlock::blockId()
{
    return 15;
}

std::string LeavesBlock::blockName()
{
    return std::string("craft:leaves_block");
}

int LeavesBlock::stackSize()
{
    return 64;
}

bool LeavesBlock::isTransparent()
{
    return true;
}
