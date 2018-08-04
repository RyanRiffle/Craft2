//
//  Inventory.cpp
//  Craft2
//
//  Created by Ryan Riffle on 8/4/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "Inventory.hpp"
#include "global.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../Blocks/Block.hpp"

Inventory::Inventory() :
    Renderable(),
    mIsOpen(false),
    mScale(4.0f),
    mSlotsTaken(0),
    mItems()
{
    
}

Inventory::~Inventory() noexcept
{
    
}

int Inventory::render(ShaderAttributes *)
{
    int vPort[4];
    glGetIntegerv(GL_VIEWPORT, vPort);
    
    int width = vPort[2];
    int height = vPort[3];
    mScreenHeight = height;
    
    float invWidth = 176.0f;
    float invHeight = 166.0f;
    
    invWidth += (invWidth * mScale);
    invHeight += (invHeight * mScale);
    
    float startX = (width / 2) - (invWidth / 2);
    float startY = (height / 2) - (invHeight / 2);
    
//    startX *= mScale;
//    startY *= mScale;
//    invWidth *= mScale;
//    invHeight *= mScale;
    
    glUseProgram(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.3515625f);               glVertex2f(startX, startY);
    glTexCoord2f(0.6875f, 0.3515625f); glVertex2f(startX + invWidth, startY);
    glTexCoord2f(0.0f, 1.0f);                     glVertex2f(startX, startY + invHeight);
    
    glTexCoord2f(0.6875f, 0.3515625f); glVertex2f(startX + invWidth, startY);
    glTexCoord2f(0.6875f, 1.0f);       glVertex2f(startX + invWidth, startY + invHeight);
    glTexCoord2f(0.0f, 1.0f);                     glVertex2f(startX, startY + invHeight);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 1);
    
    mInventoryPosLeft = startX;
    mInventoryPosTop = startY + invHeight;
    
    int faces = renderItems();
    
    InventoryItem item;
    item.block = 4;
    item.count = 0;
    //renderSingleItem(&item, 0, 0);
    
    return faces + 2;
}


bool Inventory::isOpen()
{
    return mIsOpen;
}

void Inventory::close()
{
    mIsOpen = false;
    glfwSetInputMode(g->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Inventory::open()
{ 
    mIsOpen = true;
    glfwSetInputMode(g->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Inventory::setTexture(unsigned int texture)
{
    mTexture = texture;
}

int Inventory::renderItems()
{
    
    return mSlotsTaken * 2;
}

void Inventory::renderSingleItem(InventoryItem *item, int x, int y)
{
    int lclStartX = 16; //16 Pixels until the middle of the first square in the inventory img
    
    int lclStartY = 92; //92 Pixels from the top to the middle of the top squares
    
    lclStartX = (lclStartX + (16 * x) + (x * 2));
    lclStartY = (lclStartY + (16 * y) + (y * 2));
    
    int topFace = 0;
    try {
        Block *block = GlobalBlockMap->at(item->block);
        topFace = block->textures()[static_cast<int>(BLOCKFACE_TOP)];
    } catch (std::out_of_range &) {}
    
    float startU = (topFace % 16) * 0.0625;
    float startV = (topFace / 16) * 0.0625;
    float endU = startU + 0.0625;
    float endV = startV + 0.0625;
    
    float size = 32.0f;
    
    float startX = mInventoryPosLeft + lclStartX;
    float startY = mInventoryPosTop - lclStartY;
    
    startX *= mScale;
    startY *= mScale;
    size *= mScale;
    
    std::cout << startX << ", " << startY << ", " << size << std::endl;
    
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);               glVertex2f(startX, startY);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(startX + size, startY);
    glTexCoord2f(0.0f, 1.0f);                     glVertex2f(startX, startY + size);
    
    glTexCoord2f(1.0f, 0.0f); glVertex2f(startX + size, startY);
    glTexCoord2f(1.0f, 1.0f);       glVertex2f(startX + size, startY + size);
    glTexCoord2f(0.0f, 1.0f);                     glVertex2f(startX, startY + size);
    glEnd();
    
}




