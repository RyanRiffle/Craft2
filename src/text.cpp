//
//  text.cpp
//  Craft2
//
//  Created by Ryan Riffle on 8/12/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "text.hpp"
#include "global.h"
#include "matrix.h"
#include "util.h"
#include "cube.h"

void render_text(
                 ShaderAttributes *attrib, int justify, float x, float y, float n, char *text, int isSign, int darkenBackground)
{
    float matrix[16];
    float b[16];
    set_matrix_2d(b, g->width, g->height);
    float a[16];
    mat_translate(a, 0, 0, -0.7);
    mat_multiply(matrix, a, b);
    glUseProgram(attrib->program);
    glUniformMatrix4fv(attrib->matrix, 1, GL_FALSE, matrix);
    glUniform1i(attrib->sampler, 1);
    glUniform1i(attrib->extra1, isSign);
    glUniform1i(attrib->extra2, darkenBackground);
    size_t length = strlen(text);
    x -= n * justify * (length - 1) / 2;
    GLuint buffer = gen_text_buffer(x, y, n, text);
    draw_text(attrib, buffer, length);
    del_buffer(buffer);
}

GLuint gen_text_buffer(float x, float y, float character_height, char *text)
{
    int length = static_cast<int>(strlen(text));
    GLfloat *data = malloc_faces(5, length);
    for (int i = 0; i < length; i++) {
        make_character(data + i * 24, x, y,
                       character_height / 2, character_height, text[i]);
        x += character_height;
    }
    return gen_faces(4, length, data);
}

void draw_text(ShaderAttributes *attrib, GLuint buffer, size_t length)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    draw_triangles_2d(attrib, buffer, static_cast<int>(length) * 6);
    glDisable(GL_BLEND);
}
