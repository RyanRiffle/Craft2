
//
//  WhiteFlowerPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "WhiteFlowerPlant.hpp"

WhiteFlowerPlant::WhiteFlowerPlant() :
    Plant()
{
    
}

WhiteFlowerPlant::~WhiteFlowerPlant()
{
    
}

int WhiteFlowerPlant::blockId()
{
    return 22;
}

std::string WhiteFlowerPlant::blockName()
{
    return std::string("craft:whiteflower_plant");
}

int WhiteFlowerPlant::stackSize()
{
    return 64;
}


