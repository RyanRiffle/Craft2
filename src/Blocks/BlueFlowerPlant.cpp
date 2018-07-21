
//
//  BlueFlowerPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "BlueFlowerPlant.hpp"

BlueFlowerPlant::BlueFlowerPlant() :
    Plant()
{
    
}

BlueFlowerPlant::~BlueFlowerPlant()
{
    
}

int BlueFlowerPlant::blockId()
{
    return 23;
}

std::string BlueFlowerPlant::blockName()
{
    return std::string("craft:blueflower_plant");
}

int BlueFlowerPlant::stackSize()
{
    return 64;
}


