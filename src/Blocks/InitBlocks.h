//
//  InitBlocks.h
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef InitBlocks_h
#define InitBlocks_h

#define REGISTER_BLOCK(CLASSNAME) {CLASSNAME tmp;(*GlobalBlockMap)[tmp.blockId()] = new CLASSNAME();}

#include "GrassBlock.hpp"
#include "SandBlock.hpp"
#include "WoodBlock.hpp"
#include "CobblestoneBlock.hpp"
#include "LeavesBlock.hpp"
#include "TallGrassPlant.hpp"
#include "YellowFlowerPlant.hpp"
#include "RedFlowerPlant.hpp"
#include "PurpleFlowerPlant.hpp"
#include "PlanksBlock.hpp"
#include "StoneBlock.hpp"
#include "BrickBlock.hpp"
#include "DirtBlock.hpp"
#include "GlassBlock.hpp"
#include "ChestBlock.hpp"
#include "AirBlock.hpp"
#include "SunFlowerPlant.hpp"
#include "WhiteFlowerPlant.hpp"
#include "BlueFlowerPlant.hpp"
#include "CloudBlock.hpp"

void InitBlocks()
{
    REGISTER_BLOCK(GrassBlock);
    REGISTER_BLOCK(SandBlock);
    REGISTER_BLOCK(WoodBlock);
    REGISTER_BLOCK(CobblestoneBlock);
    REGISTER_BLOCK(LeavesBlock);
    REGISTER_BLOCK(TallGrassPlant);
    REGISTER_BLOCK(YellowFlowerPlant);
    REGISTER_BLOCK(RedFlowerPlant);
    REGISTER_BLOCK(PurpleFlowerPlant);
    REGISTER_BLOCK(PlanksBlock);
    REGISTER_BLOCK(StoneBlock);
    REGISTER_BLOCK(BrickBlock);
    REGISTER_BLOCK(DirtBlock);
    REGISTER_BLOCK(GlassBlock);
    REGISTER_BLOCK(ChestBlock);
    REGISTER_BLOCK(AirBlock);
    REGISTER_BLOCK(SunFlowerPlant);
    REGISTER_BLOCK(WhiteFlowerPlant);
    REGISTER_BLOCK(BlueFlowerPlant);
    REGISTER_BLOCK(CloudBlock);
    //(*GlobalBlockMap)[grassBlock.blockId()] = &CreateBlockInstance<GrassBlock>;
}

#endif /* InitBlocks_h */
