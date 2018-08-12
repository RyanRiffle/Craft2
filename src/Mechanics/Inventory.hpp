//
//  Inventory.hpp
//  Craft2
//
//  Created by Ryan Riffle on 8/4/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#ifdef __cplusplus
#include "../Render/Renderable.hpp"
#endif

struct InventoryItem
{
    int block;
    int count;
};

#ifdef __cplusplus
class Inventory : public Renderable
{
public:
    Inventory();
    ~Inventory();
    
    bool isOpen();
    void open();
    void close();
    bool loadFromDatabase(int userId);
    void setTexture(unsigned texture);
    void setBlockTexture(unsigned texture);
    void setHotbarTexture(unsigned texture);
    void setTextShader(ShaderAttributes *shader);
    
    void setHotbarSelection(int index);
    
    bool addItem(int block, int count = 1);
    InventoryItem *getSelectedHotbarItem();

    void renderHotbar();
    virtual int render(ShaderAttributes *attrib);
    
protected:
    void renderSingleItem(InventoryItem *item, int x, int y);
    int renderItems();
    
private:
    bool mIsOpen;
    int mHotbarSelection;
    unsigned mTexture;
    unsigned mBlockTexture;
    unsigned mHotbarTexture;
    float mScale;
    float mVerticalScale;
    int mSlotsTaken;
    InventoryItem mItems[9][4];
    InventoryItem *mCrafting[3][3];
    ShaderAttributes *mTextShader;
};
#endif

#endif /* Inventory_hpp */
