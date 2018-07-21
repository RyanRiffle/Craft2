//
//  ShaderAttributes.hpp
//  craft
//
//  Created by Ryan Riffle on 7/13/18.
//

#ifndef ShaderAttributes_h
#define ShaderAttributes_h

#include <GL/glew.h>

typedef struct {
    GLuint program;
    GLuint position;
    GLuint normal;
    GLuint uv;
    GLuint matrix;
    GLuint sampler;
    GLuint camera;
    GLfloat timer;
    GLuint extra1;
    GLuint extra2;
    GLuint extra3;
    GLuint extra4;
} ShaderAttributes;

#endif /* ShaderAttributes_h */
