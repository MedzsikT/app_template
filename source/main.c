#include "include.h"

/* Gets called once at app initialization */
internal void App_Init(int argc, char* argv[])
{
    printf("Initialized for %s!\n", Stringify(OS));
    
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

/* Gets called every frame */
internal void App_Update()
{
    /* Clearing buffers */
    glClear(GL_COLOR_BUFFER_BIT);
}

/* Gets called once at app termination */
internal void App_Terminate()
{
    printf("Terminating...\n");
}
