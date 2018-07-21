//
//  main.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/15/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../src/Assets/Model.hpp"

GLFWwindow* create_window() {
    int window_width = 640;
    int window_height = 480;
    GLFWmonitor *monitor = NULL;
    return glfwCreateWindow(
                                 window_width, window_height, "Craft", monitor, NULL);
}

int main(int argc, char *argv[])
{
    // INITIALIZATION //
    srand(time(NULL));
    rand();
    
    // WINDOW INITIALIZATION //
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow *window = create_window();
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLogicOp(GL_INVERT);
    glClearColor(0, 0, 0, 1);

    return 0;
}
