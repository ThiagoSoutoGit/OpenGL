#include <iostream>

using namespace std;

#include <stdio.h>
#include <C:/LIBS/glew-2.2.0/include/GL/glew.h>
#include <C:/LIBS/glfw-3.3.2.bin.WIN32/include/GLFW/glfw3.h>

//#include


//#pragma comment(lib, "glew32.lib")

int main()
{
    const GLint WIDTH = 800, HEIGHT = 600;

    if (!glfwInit()){
        std::cout << "GLFW Initialization failed!";
        glfwTerminate();
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH,HEIGHT, "Test Window", NULL, NULL);

    if (!mainWindow){
        std::cout << " GLFW window creation failed!";
        glfwTerminate();
    }

    // Get Buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


    //Set the context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    //Allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK){
        std::cout << "GLEW Initialization failed!";
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
    }

    //Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // LLop until window close
    while(!glfwWindowShouldClose(mainWindow)){
        // Get + Handle user input events
        glfwPollEvents();

        // Clear window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }
}
