//
//  Block.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "Block.hpp"
#include "global.h"
#include <iostream>

static BlockMap InternalBlockMap;
BlockMap *GlobalBlockMap = &InternalBlockMap;


Block::Block()
{
    m_textures.reserve(6);
    for(int x = 0; x < 6; x++) {
        m_textures.push_back(240);
    }
}

Block::Block(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Block::~Block()
{
    
}

std::vector<int> Block::textures()
{
    return m_textures;
}
std::string Block::blockName()
{
    return std::string("craft:undefined");
}

int Block::blockId()
{
    return INT_MAX;
}

int Block::drops()
{
    return this->blockId();
}

int Block::stackSize()
{
    return 64;
}

float Block::luminance()
{
    return 0.0f;
}

float Block::blastResistance()
{
    return 3.0f;
}

bool Block::isFlammable()
{
    return false;
}

bool Block::isTransparent()
{
    return false;
}

bool Block::isPlant()
{
    return false;
}

bool Block::isObstacle()
{
    return true;
}

float Block::hardness()
{
    return 2.5f;
}

bool Block::isStackable()
{
    return this->stackSize() > 1;
}

void Block::onInteract()
{
    
}

bool Block::onPlace()
{
    return true;
}

bool Block::onDestroy()
{
    std::cout << "Destroyed " << blockName() << " at (" << x << "," << y << "," << z << ")" << std::endl;
    if (this->drops()) {
        g->playerInventory.addItem(this->drops());
    }
    return true;
}

void Block::setBlockPosition(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Block::setTexture(BlockFace face, int atlasIndex)
{
    int iface = static_cast<int>(face);
    
    if (face == BLOCKFACE_ALL) {
        for(int x = 0; x < 6; x++) {
            m_textures[x] = atlasIndex;
        }
    } else {
        m_textures[iface] = atlasIndex;
    }
}

Block &Block::operator=(const Block &rhs)
{
    m_textures = rhs.m_textures;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Block::BlockType Block::type()
{
    return BLOCKTYPE_BLOCK;
}






