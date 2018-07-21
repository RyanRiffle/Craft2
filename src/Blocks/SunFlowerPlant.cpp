
//
//  SunFlowerPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "SunFlowerPlant.hpp"

SunFlowerPlant::SunFlowerPlant() :
    Plant()
{
    
}

SunFlowerPlant::~SunFlowerPlant()
{
    
}

int SunFlowerPlant::blockId()
{
    return 21;
}

std::string SunFlowerPlant::blockName()
{
    return std::string("craft:sunflower_plant");
}

int SunFlowerPlant::stackSize()
{
    return 64;
}


