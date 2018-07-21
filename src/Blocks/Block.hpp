//
//  Block.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp

#include <string>
#include <vector>
#include <map>
#include <functional>

typedef enum {
    BLOCKFACE_TOP = 0,
    BLOCKFACE_BOTTOM = 1,
    BLOCKFACE_LEFT = 2,
    BLOCKFACE_RIGHT = 3,
    BLOCKFACE_FRONT = 4,
    BLOCKFACE_BACK = 5,
    BLOCKFACE_ALL = 6
} BlockFace;

class Block {
public:
    typedef enum {
        BLOCKTYPE_BLOCK,
        BLOCKTYPE_SLAB,
        BLOCKTYPE_STAIR,
        BLOCKTYPE_PLANE,
        BLOCKTYPE_PLANT,
        BLOCKTYPE_LIQUID
    } BlockType;
    
    Block();
    Block(int x, int y, int z);
    virtual ~Block();
    
    virtual float hardness();
    virtual bool isObstacle();
    virtual bool isPlant();
    virtual bool isFlammable();
    virtual bool isTransparent();
    virtual float blastResistance();
    virtual float luminance();
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
    virtual std::vector<int> textures();
    virtual BlockType type();
    
    virtual bool onDestroy();
    virtual bool onPlace();
    virtual void onInteract();
    
    bool isStackable();
    void setBlockPosition(int x, int y, int z);
    
    void setTexture(BlockFace face, int atlasIndex);
    
    Block &operator=(const Block &rhs);
    
protected:
    int x, y, z;
    std::vector<int> m_textures;
};

typedef std::map<int, Block*> BlockMap;

extern BlockMap *GlobalBlockMap;

#endif /* Block_hpp */
