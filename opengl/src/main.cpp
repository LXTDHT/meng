#include "config.h"

int main() {
    GLFWwindow* window;

    if (!glfwInit()) {
        std::cout << "GLFW cannot start." << std::endl;
        return -1;
    }

    // setting GLFWmonitor param as NULL -> this sets the app as a floating window rather than a full screen on a specific monitor
    window = glfwCreateWindow(1400, 800, "Untitled Window", NULL, NULL);

    // glClearColor(0.5f, 0.75f, 0.1f, 0.5f);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        // glfwSwapBuffers(window);
    }

    glfwTerminate();
}