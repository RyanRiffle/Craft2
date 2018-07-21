
//
//  RedFlowerPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "RedFlowerPlant.hpp"

RedFlowerPlant::RedFlowerPlant() :
    Plant()
{
    
}

RedFlowerPlant::~RedFlowerPlant()
{
    
}

int RedFlowerPlant::blockId()
{
    return 19;
}

std::string RedFlowerPlant::blockName()
{
    return std::string("craft:redflower_plant");
}

int RedFlowerPlant::stackSize()
{
    return 64;
}


