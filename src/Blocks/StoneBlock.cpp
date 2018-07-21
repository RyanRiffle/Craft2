//
//  StoneBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "StoneBlock.hpp"

StoneBlock::StoneBlock() :
    Block()
{
    
}

StoneBlock::~StoneBlock()
{
    
}

int StoneBlock::blockId()
{
    return 3;
}

std::string StoneBlock::blockName()
{
    return std::string("craft:stone_block");
}

int StoneBlock::stackSize()
{
    return 64;
}

float StoneBlock::hardness()
{
    return 2.0f;
}

Block::BlockType StoneBlock::type()
{
    return Block::BLOCKTYPE_SLAB;
}

bool StoneBlock::isTransparent()
{
    return true;
}
