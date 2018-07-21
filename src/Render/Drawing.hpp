//
//  Drawing.hpp
//  craft
//
//  Created by Ryan Riffle on 7/13/18.
//

#ifndef Drawing_hpp
#define Drawing_hpp

#include <GL/glew.h>
#include "ShaderAttributes.hpp"

void draw_triangles_3d_ao(ShaderAttributes *attrib, GLuint buffer, int count);
void draw_triangles_3d_text(ShaderAttributes *attrib, GLuint buffer, int count);
void draw_triangles_3d(ShaderAttributes *attrib, GLuint buffer, int count);
void draw_triangles_2d(ShaderAttributes *attrib, GLuint buffer, int count);
void draw_lines(ShaderAttributes *attrib, GLuint buffer, int components, int count);

#endif /* Drawing_hpp */
