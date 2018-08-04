//
//  main.cpp
//  UITest
//
//  Created by Ryan Riffle on 8/4/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../src/util.h"

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, const char * argv[]) {
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
    exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    
    glEnable(GL_TEXTURE_2D);
    GLuint inventory;
    glGenTextures(1, &inventory);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, inventory);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    load_png_texture("textures/texture_pack/assets/minecraft/textures/gui/container/inventory.png", 1);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glEnable2D();
        glBindTexture(GL_TEXTURE_2D, inventory);
        glBegin(GL_TRIANGLES);
            glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 0);
            glTexCoord2f(1.0f, 0.0f); glVertex2f(800.0f,0);
            glTexCoord2f(0.0f, 1.0f); glVertex2f(0, 800.0f);
        
            glTexCoord2f(1.0f, 0.0f); glVertex2f(800.0f, 0);
            glTexCoord2f(1.0f, 1.0f); glVertex2f(800.0f, 800.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 800.0f);
        glEnd();
        glDisable2D();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    return 0;
}
