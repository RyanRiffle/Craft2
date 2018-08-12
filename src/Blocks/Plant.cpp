//
//  Block.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "Plant.hpp"

Plant::Plant() :
    Block()
{
    
}


Plant::~Plant()
{
    
}


Block::BlockType Plant::type()
{
    return BLOCKTYPE_PLANT;
}


bool Plant::isFlammable()
{
    return true;
}


bool Plant::isObstacle()
{
    return false;
}

bool Plant::isTransparent()
{
    return true;
}

bool Plant::isPlant()
{
    return true;
}
