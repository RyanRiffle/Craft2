//
//  GlassBlock.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "GlassBlock.hpp"

GlassBlock::GlassBlock() :
    Block()
{
    
}

GlassBlock::~GlassBlock()
{
    
}

int GlassBlock::blockId()
{
    return 10;
}

std::string GlassBlock::blockName()
{
    return std::string("craft:glass_block");
}

int GlassBlock::stackSize()
{
    return 64;
}

float GlassBlock::hardness()
{
    return 2.0f;
}

bool GlassBlock::isTransparent()
{
    return true;
}
