#include "window.h"

internal Window CreateWindow()
{
    Window result;
    
    /* Initializing GLFW */
    Assert(glfwInit(), "Failed to initialize GLFW!");
    
    /* Creating GLFWwindow */
    if(WINDOW_FULLSCREEN)
        result.gl_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, glfwGetPrimaryMonitor(), NULL); 
    else
        result.gl_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL); 
    
    Assert(result.gl_window, "Failed to create GLFWwindow!");
    
    glfwSwapInterval(WINDOW_VSYNC);
    glfwMakeContextCurrent(result.gl_window);
    
    /* Initializing GLAD */
    Assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD!");
    
    return result;
}

internal void UpdateWindow(Window* window)
{
    glfwSwapBuffers(window->gl_window);
    glfwPollEvents();
}

internal b32 IsWindowOpen(Window* window)
{
    return glfwWindowShouldClose(window->gl_window);
}
