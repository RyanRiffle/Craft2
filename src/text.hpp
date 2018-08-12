//
//  text.hpp
//  Craft2
//
//  Created by Ryan Riffle on 8/12/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef text_hpp
#define text_hpp

#include "Render/ShaderAttributes.hpp"

void render_text(ShaderAttributes *attrib,
                 int justify, float x, float y, float n, char *text, int isSign = 0, int darkenBackground = 1);

GLuint gen_text_buffer(float x, float y, float character_height, char *text);

void draw_text(ShaderAttributes *attrib, GLuint buffer, size_t length);
#endif /* text_hpp */
