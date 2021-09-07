#include "base_layer.h"

// TODO(Barni): We could have a enum that has all the keys in it
internal b32 IsKeyPressed(i32 key)
{
    i32 state = glfwGetKey(GetGLWindow(), key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

// TODO(Barni): We could have a enum that has all the buttons in it
internal b32 IsMouseButtonDown(i32 button)
{
    i32 state = glfwGetMouseButton(GetGLWindow(), button);
    return state == GLFW_PRESS;
}

internal iv2 GetWindowSize()
{
    iv2 wh;
    glfwGetWindowSize(GetGLWindow(), &wh.width, &wh.height);
    return wh;
}

internal void SetWindowSize(iv2 size)
{
    glfwSetWindowSize(GetGLWindow(), size.x, size.y);
}

/* GLFW doesn't support this */
internal char* GetWindowTitle()
{
    ThrowNotImplementedFunction();
    return "";
}

internal void SetWindowTitle(const char* title)
{
    glfwSetWindowTitle(GetGLWindow(), title);
}

internal iv2 GetMousePos()
{
    f64 x, y;
    glfwGetCursorPos(GetGLWindow(), &x, &y);
    return iv2((i32)x, (i32)y);
}