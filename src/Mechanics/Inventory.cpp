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
#include "text.hpp"
#include "db.h"

#define ITEM_SPACING 18.0f
#define HOTBAR_ITEM_SPACING 20.0f

Inventory::Inventory() :
    Renderable(),
    mIsOpen(false),
    mScale(4.0f),
    mSlotsTaken(0),
    mHotbarSelection(8),
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
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glUseProgram(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture);
    glTranslatef(width / 2, height / 2, -0.5f);
    glScalef(450.0f, 450.0f, 0.0f);
    
    //Since the inventory is rendered on -1 to 1 it starts off with a size of 2
    //Scaling it by the number above makes its size on screen 2 * scale
    //the scale numbers are used to figure out the proper position for
    //rendered items in the inventory
    mScale = (450.0f * 2) / 177.0f; // 177.0f is the origional width of the texture
                                    // stored in the texture .png file
    mVerticalScale = (450.0f * 2) / 166.0f; // 166.0f is the height of the texture

    GLdouble mvmatrix[16];
    GLdouble projmatrix[16];
    glGetDoublev(GL_PROJECTION, projmatrix);
    glGetDoublev(GL_MODELVIEW, mvmatrix);
    
    glBegin(GL_TRIANGLES);
    {
        glTexCoord2f(0.0f, 0.3515625f);    glVertex2f(-1.0f, -1.0f);
        glTexCoord2f(0.6875f, 0.3515625f); glVertex2f(1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f);          glVertex2f(-1.0f, 1.0f);
        
        glTexCoord2f(0.6875f, 0.3515625f); glVertex2f(1.0f, -1.0f);
        glTexCoord2f(0.6875f, 1.0f);       glVertex2f(1.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);          glVertex2f(-1.0f, 1.0f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 1);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    InventoryItem item;
    item.block = 1;
    item.count = 1;

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 4; y++) {
            InventoryItem *item = &this->mItems[x][y];
            if (item->block != 0 && item->count != 0) {
                int xpos = 4 - x;
                int ypos = 3 - y;
                
                int translateX = xpos * ITEM_SPACING * mScale;
                int translateY = ((ITEM_SPACING / 2) + (ypos * ITEM_SPACING)) * mVerticalScale;
                
                if (y == 0) {
                    translateY += (4.0f * mVerticalScale);
                }
                
                renderSingleItem(item, (g->width / 2) + translateX, (g->height / 2) - translateY);
            }
        }
    }
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    char text_buffer[1024];
    float text_size = 11 * g->scale;
    float tx = (g->width / 2);
    float ty = text_size * 2;
    
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 4; y++) {
            InventoryItem *item = &this->mItems[x][y];
            if (item->block == 0 || item->count == 0) {
                continue;
            }
            
            int xpos = 4 - x;
            int ypos = 3 - y;
            
            int translateX = (g->width / 2) + xpos * ITEM_SPACING * mScale;
            int translateY = ((ITEM_SPACING / 2) + (ypos * ITEM_SPACING)) * mVerticalScale;
            
            if (y == 0) {
                translateY += (4.0f * mVerticalScale);
            }
            
            snprintf(text_buffer, 1024,"%d", item->count);
            render_text(mTextShader, ALIGN_LEFT, translateX, (g->height / 2) - translateY - 12, text_size, text_buffer, 0, 0);
        }
    }
    glEnable(GL_BLEND);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    //TODO: Fix. When used it messes up the hotbar / inventory.
    //Render the transparent darkened background
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glUseProgram(0);
    glTranslatef(width / 2, height / 2, -0.6f);
    
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLES);
    {
        glColor4d(0.0, 0.0, 0.0, 0.70);    glVertex2f(-g->width, -g->height);
        glColor4d(0.0, 0.0, 0.0, 0.70); glVertex2f(g->width, -g->height);
        glColor4d(0.0, 0.0, 0.0, 0.70);          glVertex2f(-g->width, g->height);
        
        glColor4d(0.0, 0.0, 0.0, 0.70); glVertex2f(g->width, -g->height);
        glColor4d(0.0, 0.0, 0.0, 0.70);       glVertex2f(g->width, g->height);
        glColor4d(0.0, 0.0, 0.0, 0.7);         glVertex2f(-g->width, g->height);
        glColor4d(1, 1, 1, 1);
    }
    glEnd();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    return 2;
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

void Inventory::setBlockTexture(unsigned texture)
{
    mBlockTexture = texture;
}

int Inventory::renderItems()
{
    
    return mSlotsTaken * 2;
}

void Inventory::renderSingleItem(InventoryItem *item, int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    float uvscale = 0.0625; //item width / atlas width (16 / 256)
    int w = item->block;
    int tiles[6];
    bool isPlant = false;
    try {
        tiles[0] = GlobalBlockMap->at(w)->textures()[BLOCKFACE_LEFT];
        tiles[1] = GlobalBlockMap->at(w)->textures()[BLOCKFACE_RIGHT];
        tiles[2] = GlobalBlockMap->at(w)->textures()[BLOCKFACE_TOP];
        tiles[3] = GlobalBlockMap->at(w)->textures()[BLOCKFACE_BOTTOM];
        tiles[4] = GlobalBlockMap->at(w)->textures()[BLOCKFACE_FRONT];
        tiles[5] = GlobalBlockMap->at(w)->textures()[BLOCKFACE_BACK];
        
        isPlant = GlobalBlockMap->at(w)->isPlant();
    } catch (std::out_of_range &) {
        return;
    }
    
    glUseProgram(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mBlockTexture);
    
    
    glTranslatef(x, y, 0.5f);
    
    if (!isPlant)
        glScalef(23.0f, 23.0f, 0.0f);
    else
        glScalef(35.0f, 35.0f, 0.0f);
    
    if (!isPlant) {
        glRotatef(-23, 1.0, 0.0, 0.0);
        glRotatef(45, 0.0, 1.0, 0.0);
    }
    
    float du;
    float dv;
    
    glBegin(GL_TRIANGLES);
    {
        if (!isPlant) {
            du = (tiles[1] % 16) * uvscale;
            dv = (tiles[1] / 16) * uvscale;
            //Right
            glTexCoord2f(du, dv); glVertex3f(+1, -1, -1);
            glTexCoord2f(du + uvscale, dv); glVertex3f(+1, -1, +1);
            glTexCoord2f(du, dv + uvscale); glVertex3f(+1, +1, -1);
            
            glTexCoord2f(du + uvscale, dv); glVertex3f(+1, -1, +1);
            glTexCoord2f(du + uvscale, dv + uvscale); glVertex3f(+1, +1, +1);
            glTexCoord2f(du, dv + uvscale); glVertex3f(+1, +1, -1);
            
            du = (tiles[2] % 16) * uvscale;
            dv = (tiles[2] / 16) * uvscale;
            //Top
            glTexCoord2f(du, dv); glVertex3f(-1, +1, -1);
            glTexCoord2f(du + uvscale, dv); glVertex3f(+1, +1, -1);
            glTexCoord2f(du, dv + uvscale); glVertex3f(-1, +1, +1);
            
            glTexCoord2f(du, dv + uvscale); glVertex3f(-1, +1, +1);
            glTexCoord2f(du + uvscale, dv); glVertex3f(+1, +1, -1);
            glTexCoord2f(du + uvscale, dv + uvscale); glVertex3f(+1, +1, +1);
            
        }
        //Front
        du = (tiles[4] % 16) * uvscale;
        dv = (tiles[4] / 16) * uvscale;
        
        glTexCoord2f(du, dv); glVertex3f(-1, -1, -1);
        glTexCoord2f(du + uvscale, dv); glVertex3f(+1, -1, -1);
        glTexCoord2f(du, dv + uvscale); glVertex3f(-1, +1, -1);
        
        glTexCoord2f(du, dv + uvscale); glVertex3f(-1, +1, -1);
        glTexCoord2f(du + uvscale, dv); glVertex3f(+1, -1, -1);
        glTexCoord2f(du + uvscale, dv + uvscale); glVertex3f(+1, +1, -1);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 1);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

bool Inventory::addItem(int block, int count)
{
    for (int y = 0; y < 5; y++) {
        for (int x = 8; x >= 0; x--) {
            InventoryItem *item = &mItems[x][y];
            if (item->block == 0 || item->count == 0) {
                item->block = block;
                item->count = count;
                db_insert_inventory_item(0, x, y, block, count);
                return true;
            } else if (item->block == block) {
                Block *blockInfo = GlobalBlockMap->at(block);
                if (item->count < blockInfo->stackSize() && item->count + count < blockInfo->stackSize()) {
                    item->count += count;
                    db_insert_inventory_item(0, x, y, block, item->count);
                    return true;
                } else if (item->count + count > blockInfo->stackSize()) {
                    int remainder = blockInfo->stackSize() - (item->count + count);
                    item->count = blockInfo->stackSize();
                    db_insert_inventory_item(0, x, y, block, item->count);
                    count = remainder;
                }
            }
        }
    }
    
    return false;
}

void Inventory::setHotbarTexture(unsigned int texture)
{
    mHotbarTexture = texture;
}

void Inventory::renderHotbar()
{
    int vPort[4];
    glGetIntegerv(GL_VIEWPORT, vPort);
    
    int width = vPort[2];
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glUseProgram(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mHotbarTexture);
    glTranslatef(width / 2, 75.0f, -0.5f);
    glScalef(450.0f, 56.96f, 0.0f);
    
    GLdouble mvmatrix[16];
    GLdouble projmatrix[16];
    glGetDoublev(GL_PROJECTION, projmatrix);
    glGetDoublev(GL_MODELVIEW, mvmatrix);
    
    glBegin(GL_TRIANGLES);
    {
        glTexCoord2f(0.0f, 0.91015625f);    glVertex2f(-1.0f, -1.0f);
        glTexCoord2f(0.7109375f, 0.91015625f); glVertex2f(1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f);          glVertex2f(-1.0f, 1.0f);
        
        glTexCoord2f(0.7109375f, 0.91015625f); glVertex2f(1.0f, -1.0f);
        glTexCoord2f(0.7109375f, 1.0f);       glVertex2f(1.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);                     glVertex2f(-1.0f, 1.0f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 1);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    char text_buffer[1024];
    float text_size = 11 * g->scale;
    float tx = (g->width / 2);
    float ty = text_size * 2;
    
    for (int x = 8; x >= 0; x--) {
        if (mItems[x][0].block == 0 || mItems[x][0].count == 0)
            continue;
        
        int offsetX = 4 - x;
        float scale = (450.0f * 2) / 182.0f;
        int translateX = (g->width / 2) + (offsetX * HOTBAR_ITEM_SPACING * scale);
        renderSingleItem(&mItems[x][0], translateX, 75.0f);
    }
    
    for (int x = 8; x >= 0; x--) {
        if (mItems[x][0].count <= 1) {
            continue;
        }
        
        int offsetX = 4 - x;
        float scale = (450.0f * 2) / 182.0f;
        int translateX = (g->width / 2) + (offsetX * HOTBAR_ITEM_SPACING * scale);

        snprintf(text_buffer, 1024,"%d", mItems[x][0].count);
        render_text(mTextShader, ALIGN_LEFT, translateX + 6, ty + text_size / 2, text_size, text_buffer, 0, 0);
    }
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glUseProgram(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mHotbarTexture);
    
    int offsetX = 4 - mHotbarSelection;
    float scale = (450.0f * 2) / 182.0f;
    int translateX = (g->width / 2) + (offsetX * HOTBAR_ITEM_SPACING * scale);
    
    glTranslatef(translateX, 75.0f, -0.4f);
    glScalef(56.96f, 56.96f, 0.0f);
    
    glBegin(GL_TRIANGLES);
    {
        glTexCoord2f(0.0f, 0.82421875f);    glVertex2f(-1.0f, -1.0f);
        glTexCoord2f(0.09375f, 0.82421875f); glVertex2f(1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.91015625f);          glVertex2f(-1.0f, 1.0f);
        
        glTexCoord2f(0.09375f, 0.82421875f); glVertex2f(1.0f, -1.0f);
        glTexCoord2f(0.09375f, 0.91015625f);       glVertex2f(1.0f, 1.0f);
        glTexCoord2f(0.0f, 0.91015625f);                     glVertex2f(-1.0f, 1.0f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 1);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void Inventory::setHotbarSelection(int index)
{
    mHotbarSelection = index;
}

InventoryItem *Inventory::getSelectedHotbarItem()
{
    return &mItems[mHotbarSelection][0];
}

void Inventory::setTextShader(ShaderAttributes *shader)
{
    mTextShader = shader;
}

bool Inventory::loadFromDatabase(int userId)
{
    int x, y, block, count;
    for (int ix = 0; ix < 9; ix++) {
        for (int iy = 0; iy < 4; iy++) {
            x = 0;
            y = 0;
            block = 0;
            count = 0;
            
            if (!db_load_inventory_item(userId, ix, iy, &x, &y, &block, &count)) {
                continue;
            }
            
            mItems[x][y].block = block;
            mItems[x][y].count = count;
        }
    }
    
    return true;
}








