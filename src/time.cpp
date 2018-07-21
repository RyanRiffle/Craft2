//
//  time.cpp
//  craft
//
//  Created by Ryan Riffle on 7/13/18.
//

#include "time.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "global.h"

extern GameModel *g;

float time_of_day() {
    if (g->day_length <= 0) {
        return 0.5;
    }
    float t;
    t = glfwGetTime();
    t = t / g->day_length;
    t = t - (int)t;
    return t;
}

float get_daylight() {
    float timer = time_of_day();
    if (timer < 0.5) {
        float t = (timer - 0.25) * 100;
        return 1 / (1 + powf(2, -t));
    }
    else {
        float t = (timer - 0.85) * 100;
        return 1 - 1 / (1 + powf(2, -t));
    }
}
