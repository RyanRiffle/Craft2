//
//  GrassBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "GrassBlock.hpp"

GrassBlock::GrassBlock()
{
    
}

GrassBlock::GrassBlock(int x, int y, int z) :
    Block(x, y, z)
{
    
}

GrassBlock::~GrassBlock()
{
    
}

int GrassBlock::blockId()
{
    return 1;
}

std::string GrassBlock::blockName()
{
    return std::string("craft:grass_block");
}

int GrassBlock::stackSize()
{
    return 64;
}

bool GrassBlock::onPlace()
{
    return false;
}
