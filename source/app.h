/* date = September 6th 2021 5:45 am */

#ifndef APP_H
#define APP_H

/* Functions that has to be defined by the user */
internal void App_Init(int argc, char* argv[]);
internal void App_Update();
internal void App_Terminate();

typedef struct Application Application;
struct Application
{
    Window main_window;
};
global Application* ApplicationInstance;

internal GLFWwindow* GetGLWindow();
internal void RunApplication(int argc, char* argv[]);

#endif //APP_H
