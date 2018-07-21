
//
//  PurpleFlowerPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef PurpleFlowerPlant_hpp
#define PurpleFlowerPlant_hpp

#include "Plant.hpp"

class PurpleFlowerPlant : public Plant {
public:
    PurpleFlowerPlant();
    ~PurpleFlowerPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* PurpleFlowerPlant_hpp */
