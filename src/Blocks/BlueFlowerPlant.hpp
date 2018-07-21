
//
//  BlueFlowerPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef BlueFlowerPlant_hpp
#define BlueFlowerPlant_hpp

#include "Plant.hpp"

class BlueFlowerPlant : public Plant {
public:
    BlueFlowerPlant();
    ~BlueFlowerPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* BlueFlowerPlant_hpp */
