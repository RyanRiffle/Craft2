//
//  TextureImporter.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef TextureImporter_hpp
#define TextureImporter_hpp

#include "../Blocks/Block.hpp"
#include <string>
#include "atlasgenerator.h"

/*!
 * @discussion TextureImporter loads textures required for the blocks that have
 * been initialized for the game and stores them using an in memory texture
 * atlas. It ensures there are no duplicates, and modifies each block in the
 * GlobalBlockMap to set the proper atlas index for the generated texture atlas.
 */
class TextureImporter {
public:
    TextureImporter();
    ~TextureImporter();
    
    bool import(BlockMap *blockMap);
    
protected:
    bool fileExists(std::string path);
    bool hasLoadedImage(std::string path);
    
private:
    std::vector<std::string> m_loadedImages;
    int m_atlasImageCount;
    Atlas *m_atlas;
};

#endif /* TextureImporter_hpp */
