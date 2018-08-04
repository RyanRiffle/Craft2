//
//  Inventory.hpp
//  Craft2
//
//  Created by Ryan Riffle on 8/4/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include "../Render/Renderable.hpp"

struct InventoryItem
{
    int block;
    int count;
};

class Inventory : public Renderable
{
public:
    Inventory();
    ~Inventory();
    
    bool isOpen();
    void open();
    void close();
    void setTexture(unsigned texture);

    virtual int render(ShaderAttributes *attrib);
    
protected:
    void renderSingleItem(InventoryItem *item, int x, int y);
    int renderItems();
    
private:
    bool mIsOpen;
    unsigned mTexture;
    float mScale;
    int mSlotsTaken;
    float mInventoryPosLeft;
    float mInventoryPosTop;
    int mScreenHeight;
    InventoryItem mItems[4][9];
};

#endif /* Inventory_hpp */
