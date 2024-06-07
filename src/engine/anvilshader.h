#ifndef ANVIL_ANVILSHADER_H
#define ANVIL_ANVILSHADER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <fstream>
#include <vector>

class anvilshader {
public:
    std::vector<char> vertexShader;
    std::vector<char> fragmentShader;

    void setShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    static VkShaderModule createShaderModule(VkDevice device, const std::vector<char>& code);
private:

    static std::vector<char> readFile(const std::string& filename);
};


#endif //ANVIL_ANVILSHADER_H
