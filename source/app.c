#include "window.h"

internal GLFWwindow* GetGLWindow()
{
    return ApplicationInstance->main_window.gl_window;
}

internal void RunApplication(int argc, char* argv[])
{
    Application dummy;
    
    /* Creating window */
    dummy.main_window = CreateWindow();
    
    /* Assinging application instance */
    ApplicationInstance = &dummy;
    
    App_Init(argc, argv);
    
    /* Main loop */
    while(!IsWindowOpen(&dummy.main_window))
    {
        /* Rendering */
        App_Update();
        
        /* Swapping window buffers and updating window events */
        UpdateWindow(&dummy.main_window);
    }
    
    App_Terminate();
}