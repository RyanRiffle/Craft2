//
//  TextureImporter.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "TextureImporter.hpp"
#include "lodepng.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <yaml-cpp/yaml.h>

#define CHARS_PER_PX 4
#define IMAGE_SIZE_PX 16*16
#define IMAGES_PER_ATLAS 16*16

typedef struct {
    std::string sTop;
    std::string sBottom;
    std::string sLeft;
    std::string sRight;
    std::string sFront;
    std::string sBack;
} BlockTextures;

TextureImporter::TextureImporter()
{
    m_atlas = atlas_create();
    m_atlasImageCount = 0;
}

TextureImporter::~TextureImporter()
{
    
}

bool TextureImporter::import(BlockMap *blockMap)
{
    std::map<std::string, BlockFace> mapping;
    mapping["all"] = BLOCKFACE_ALL;
    mapping["top"] = BLOCKFACE_TOP;
    mapping["bottom"] = BLOCKFACE_BOTTOM;
    mapping["front"] = BLOCKFACE_FRONT;
    mapping["back"] = BLOCKFACE_BACK;
    mapping["left"] = BLOCKFACE_LEFT;
    mapping["right"] = BLOCKFACE_RIGHT;
    
    for(auto it = blockMap->begin(); it != blockMap->end(); ++it) {
        std::pair<int, Block*> item = *it;
        std::string path = item.second->blockName();
        path = std::regex_replace(path, std::regex(":"), "_");
        path = "./assets/blocks/" + path + ".yaml";
        
        if (!fileExists(path)) {
            std::ofstream of(path);
            of.close();
            std::cout << "WARNING: Could not find " << path << std::endl;
            std::cout << "INFO: Creating asset file " << path << std::endl;
            continue;
        }
        
        YAML::Node yamlBlock = YAML::LoadFile(path);
        YAML::Node textures = yamlBlock["textures"].as<YAML::Node>();
        YAML::Node colorize = yamlBlock["colorize"].as<YAML::Node>();
        YAML::Node tex;
        
        for(auto mit = mapping.begin(); mit != mapping.end(); ++mit) {
            std::string position = (*mit).first;
            BlockFace face = (*mit).second;
            
            if ((tex = textures[position])) {
                //Exists
                std::string ipath = tex.as<std::string>() + ".png";
                ipath = "./textures/texture_pack/assets/minecraft/textures/blocks/" + ipath;
                
                int imgIndex;
                if (colorize[position]) {
                    YAML::Node c = colorize[position].as<YAML::Node>();
                    int r, g, b, a;
                    r = c[0].as<int>();
                    g = c[1].as<int>();
                    b = c[2].as<int>();
                    a = c[3].as<int>();
                    
                    imgIndex = atlas_addImageColorize(m_atlas, ipath.c_str(), r, g, b, a);
                } else {
                    imgIndex = atlas_addImage(m_atlas, ipath.c_str());
                }
                
                item.second->setTexture(face, imgIndex);
            } else {
                //Does not exist
            }
        }
    }
    
    atlas_generate(m_atlas, "./textures/atlas.png");
    
    return true;
}

bool TextureImporter::fileExists(std::string path)
{
    std::ifstream in(path);
    return static_cast<bool>(in);
}

bool TextureImporter::hasLoadedImage(std::string path)
{
    for(auto it = m_loadedImages.begin(); it != m_loadedImages.end(); ++it) {
        if (*it == path) {
            return true;
        }
    }
    
    return false;
}





