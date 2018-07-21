
//
//  PurpleFlowerPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "PurpleFlowerPlant.hpp"

PurpleFlowerPlant::PurpleFlowerPlant() :
    Plant()
{
    
}

PurpleFlowerPlant::~PurpleFlowerPlant()
{
    
}

int PurpleFlowerPlant::blockId()
{
    return 20;
}

std::string PurpleFlowerPlant::blockName()
{
    return std::string("craft:PurpleFlower_plant");
}

int PurpleFlowerPlant::stackSize()
{
    return 64;
}


