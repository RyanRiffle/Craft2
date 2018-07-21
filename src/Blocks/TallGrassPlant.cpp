
//
//  TallGrassPlant.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "TallGrassPlant.hpp"

TallGrassPlant::TallGrassPlant() :
    Plant()
{
    
}

TallGrassPlant::~TallGrassPlant()
{
    
}

int TallGrassPlant::blockId()
{
    return 17;
}

std::string TallGrassPlant::blockName()
{
    return std::string("craft:tallgrass_plant");
}

int TallGrassPlant::stackSize()
{
    return 64;
}


