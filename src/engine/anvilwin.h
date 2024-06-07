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
private:
    GLFWwindow* m_window;

    static void processInput(GLFWwindow* window);
};

#endif //ANVIL_ANVILWIN_H
