
//
//  SunFlowerPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef SunFlowerPlant_hpp
#define SunFlowerPlant_hpp

#include "Plant.hpp"

class SunFlowerPlant : public Plant {
public:
    SunFlowerPlant();
    ~SunFlowerPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* SunFlowerPlant_hpp */
