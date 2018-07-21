
//
//  CobblestoneBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "CobblestoneBlock.hpp"

CobblestoneBlock::CobblestoneBlock() :
Block()
{
    
}

CobblestoneBlock::~CobblestoneBlock()
{
    
}

int CobblestoneBlock::blockId()
{
    return  11;
}

std::string CobblestoneBlock::blockName()
{
    return std::string("craft:cobblestone_block");
}

int CobblestoneBlock::stackSize()
{
    return 64;
}

float CobblestoneBlock::hardness()
{
    return 2.0f;
}
