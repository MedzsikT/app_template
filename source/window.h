/* date = September 5th 2021 7:59 pm */

#ifndef WINDOW_H
#define WINDOW_H

#include "base_layer.h"
#include "options.h"

#include <GLFW/glfw3.h>

typedef struct Window Window;
struct Window
{
    GLFWwindow* gl_window;
};

internal Window CreateWindow();
internal void UpdateWindow(Window* window);
internal b32 IsWindowOpen(Window* window);

#endif //WINDOW_H
