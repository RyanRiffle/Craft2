
//
//  TallGrassPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef TallGrassPlant_hpp
#define TallGrassPlant_hpp

#include "Plant.hpp"

class TallGrassPlant : public Plant {
public:
    TallGrassPlant();
    ~TallGrassPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* TallGrassPlant_hpp */
