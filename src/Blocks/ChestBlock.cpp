//
//  ChestBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "ChestBlock.hpp"

ChestBlock::ChestBlock() :
    Block()
{
    
}

ChestBlock::~ChestBlock()
{
    
}

int ChestBlock::blockId()
{
    return 14;
}

std::string ChestBlock::blockName()
{
    return std::string("craft:chest_block");
}

int ChestBlock::stackSize()
{
    return 64;
}

float ChestBlock::hardness()
{
    return 2.0f;
}
