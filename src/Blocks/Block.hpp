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
#include "Renderable.hpp"

typedef enum {
    BLOCKFACE_TOP = 0,
    BLOCKFACE_BOTTOM = 1,
    BLOCKFACE_LEFT = 2,
    BLOCKFACE_RIGHT = 3,
    BLOCKFACE_FRONT = 4,
    BLOCKFACE_BACK = 5,
    BLOCKFACE_ALL = 6
} BlockFace;

/**
 * Base class for all blocks in the game.
 * This class servers as the base class for all blocks in the game,
 * including plants which is a subclass. Most of the functions are
 * virtual functions so that they can be changed and code inserted
 * if neccessary. Every attempt will be made to make values in
 * accordance with the Minecraft Official Wiki.
 *
 * When this class is subclassed it should be added into the InitBlocks.hpp
 * file. This updates the extern GlobalBlockMap. Once the block is added
 * to the file and the game is run, it attempts to parse the Craft2/assets/blocks
 * yaml file for the block to fetch textures for building a texture atlas. If
 * a yaml file for the block doesn't exist the game will create an empty one
 * and the block will not render properly until the .yaml file is updated.
 */
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
    
    /**
     * Block hardness as a float (Default: 2.5f)
     * The value should be between 0.0f (Breaks Instantly)
     * and 50.0f (Obsidian in vanilla Minecraft).
     */
    virtual float hardness();
    
    /**
     * Whether block stops player as a collision (Default: true)
     */
    virtual bool isObstacle();
    virtual bool isPlant();
    
    /**
     * Can the block be caught on fire? (Default: false)
     */
    virtual bool isFlammable();
    
    /**
     * Tells whether the block should stop light. It also helps decide on
     * what faces to render for the blocks around it. (Default: false)
     */
    virtual bool isTransparent();
    
    /**
     * Block blast resistance as a float (Default: 3.0f)
     * The value should be betwen 0.0f (Breaks Instantly)
     * and 6000.0f (Same as vanilla obsidian) up to 18000.0f
     * (Bedrock)
     */
    virtual float blastResistance();
    
    /**
     * Whether the block emits light (0.0f to 16.0f)
     */
    virtual float luminance();
    
    /**
     * Maximum number of items in a stack in the user's inventory.
     */
    virtual int stackSize();
    
    /**
     * ID of the block (Use minecraft block ID's when available)
     */
    virtual int blockId();
    
    virtual int drops();
    
    /**
     * The name of the block. e.g craft:grass_block
     */
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
