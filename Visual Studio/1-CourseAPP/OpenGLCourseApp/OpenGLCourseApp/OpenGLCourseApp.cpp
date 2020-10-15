// OpenGLCourseApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

//Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;


int main()
{

    //Initialize GLFW
    if (!glfwInit()) {
        std::cout << "GLFW Initialization failed!";
        glfwTerminate();
    }

    //Setup GLFW window properties
    //OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Core Profile = No Backwards Compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);

    if (!mainWindow) {
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

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW Initialization failed!";
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
    }

    //Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // LLop until window close
    while (!glfwWindowShouldClose(mainWindow)) {
        // Get + Handle user input events
        glfwPollEvents();

        // Clear window
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
