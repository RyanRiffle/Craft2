
//
//  YellowFlowerPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef YellowFlowerPlant_hpp
#define YellowFlowerPlant_hpp

#include "Plant.hpp"

class YellowFlowerPlant : public Plant {
public:
    YellowFlowerPlant();
    ~YellowFlowerPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* YellowFlowerPlant_hpp */
