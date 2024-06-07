#ifndef ANVIL_ANVILWIN_H
#define ANVIL_ANVILWIN_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class anvilwin {
public:
    anvilwin(int width, int height);
    ~anvilwin();
    void render();
    GLFWwindow* getWindowInstance();

    static bool framebufferResized;
private:
    GLFWwindow* m_window;

    static void processInput(GLFWwindow* window);
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};

#endif //ANVIL_ANVILWIN_H
