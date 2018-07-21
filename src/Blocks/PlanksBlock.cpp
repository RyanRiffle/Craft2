//
//  PlanksBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "PlanksBlock.hpp"

PlanksBlock::PlanksBlock() :
    Block()
{
    
}

PlanksBlock::~PlanksBlock()
{
    
}

int PlanksBlock::blockId()
{
    return 8;
}

std::string PlanksBlock::blockName()
{
    return std::string("craft:planks_block");
}

int PlanksBlock::stackSize()
{
    return 64;
}

float PlanksBlock::hardness()
{
    return 2.0f;
}
