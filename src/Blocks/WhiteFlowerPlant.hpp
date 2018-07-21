
//
//  WhiteFlowerPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef WhiteFlowerPlant_hpp
#define WhiteFlowerPlant_hpp

#include "Plant.hpp"

class WhiteFlowerPlant : public Plant {
public:
    WhiteFlowerPlant();
    ~WhiteFlowerPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* WhiteFlowerPlant_hpp */
