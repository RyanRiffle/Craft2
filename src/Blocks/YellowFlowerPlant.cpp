
//
//  YellowFlowerPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "YellowFlowerPlant.hpp"

YellowFlowerPlant::YellowFlowerPlant() :
    Plant()
{
    
}

YellowFlowerPlant::~YellowFlowerPlant()
{
    
}

int YellowFlowerPlant::blockId()
{
    return 18;
}

std::string YellowFlowerPlant::blockName()
{
    return std::string("craft:yellowflower_plant");
}

int YellowFlowerPlant::stackSize()
{
    return 64;
}


