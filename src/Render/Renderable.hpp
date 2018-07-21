//
//  Renderable.hpp
//  craft
//
//  Created by Ryan Riffle on 7/13/18.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include "Drawing.hpp"

class Renderable
{
public:
    Renderable();
    virtual ~Renderable();
    
    /**
     * 
     * @param attrib shader attributes to be passed for render
     * @return Number of faces rendered
     */
    virtual int render(ShaderAttributes *attrib);
};

#endif /* Renderable_hpp */
