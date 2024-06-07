#include "anvilwin.h"

bool anvilwin::framebufferResized = false;

anvilwin::anvilwin(int width, int height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    m_window = glfwCreateWindow(width, height, "Anvil", nullptr, nullptr);
    glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
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

void anvilwin::framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
    auto app = reinterpret_cast<anvilwin*>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}
