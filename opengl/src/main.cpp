#include "config.h"

int main() {
    GLFWwindow* window;

    if (!glfwInit()) {
        std::cout << "GLFW cannot start." << std::endl;
        return -1;
    }

    // setting GLFWmonitor param as NULL -> this sets the app as a floating window rather than a full screen on a specific monitor
    window = glfwCreateWindow(1400, 800, "Untitled Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    // telling/checking the system to load OpenGL definitions here
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -1;
    }

    glClearColor(0.25f, 0.5f, 0.75f, 1.0f); // setting the screen's clear colour (?)

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT); // using the clear colour setting here
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}