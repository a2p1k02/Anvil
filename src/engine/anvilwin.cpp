#include "anvilwin.h"

anvilwin::anvilwin(int width, int height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(width, height, "Anvil", nullptr, nullptr);
}

anvilwin::~anvilwin()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

GLFWwindow* anvilwin::getWindowInstance()
{
    return m_window;
}

void anvilwin::render()
{
    processInput(m_window);
    glfwPollEvents();
}

void anvilwin::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
