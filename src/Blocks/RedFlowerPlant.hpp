
//
//  RedFlowerPlant.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/13/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef RedFlowerPlant_hpp
#define RedFlowerPlant_hpp

#include "Plant.hpp"

class RedFlowerPlant : public Plant {
public:
    RedFlowerPlant();
    ~RedFlowerPlant();
    
    virtual int stackSize();
    virtual int blockId();
    virtual std::string blockName();
};

#endif /* RedFlowerPlant_hpp */
