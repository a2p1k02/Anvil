#ifndef ANVIL_ANVILUTILS_H
#define ANVIL_ANVILUTILS_H

#include <array>
#include <vector>
#include <optional>
#include <glm/glm.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class anvilutils {
public:
    struct Vertex {
        glm::vec3 pos;
        glm::vec3 color;

        static VkVertexInputBindingDescription getBindingDescription();
        static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions();
    };

    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        [[nodiscard]] bool isComplete() const;
    };

    struct UniformBufferObject {
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 proj;
    };
};

#endif //ANVIL_ANVILUTILS_H
