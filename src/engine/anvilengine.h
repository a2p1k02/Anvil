#ifndef ANVIL_ANVILENGINE_H
#define ANVIL_ANVILENGINE_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <chrono>
#include "anvilwin.h"
#include "anvilshader.h"
#include "anvilutils.h"

const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

const std::vector<anvilutils::Vertex> vertices = {
        // back face
        {{-0.5f, -0.5f, -0.5f},  {0.0f,  0.0f, 0.5}},
        {{0.5f,  0.5f, -0.5f},  {0.0f,  0.0f, 0.5}},
        {{0.5, -0.5, -0.5f},  {0.0f,  0.0f, 0.5}},
        {{0.5,  0.5, -0.5f},  {0.0f,  0.0f, 0.5}},
        {{-0.5, -0.5, -0.5},  {0.0f,  0.0f, 0.5}},
        {{-0.5,  0.5, -0.5},  {0.0f,  0.0f, 0.5}},
        // front face								   
        {{-0.5, -0.5,  0.5},  {0.0f,  0.0f,  0.5}},
        {{0.5, -0.5,  0.5},  {0.0f,  0.0f,  0.5}},
        {{0.5,  0.5,  0.5},  {0.0f,  0.0f,  0.5}},
        {{0.5,  0.5,  0.5},  {0.0f,  0.0f,  0.5}},
        {{-0.5,  0.5,  0.5},  {0.0f,  0.0f,  0.5}},
        {{-0.5, -0.5,  0.5},  {0.0f,  0.0f,  0.5}},
        // left face								   
        {{-0.5,  0.5,  0.5}, {0.5,  0.0f,  0.0f}},
        {{-0.5,  0.5, -0.5}, {0.5,  0.0f,  0.0f}},
        {{-0.5, -0.5, -0.5}, {0.5,  0.0f,  0.0f}},
        {{-0.5, -0.5, -0.5}, {0.5,  0.0f,  0.0f}},
        {{-0.5, -0.5,  0.5}, {0.5,  0.0f,  0.0f}},
        {{-0.5,  0.5,  0.5}, {0.5,  0.0f,  0.0f}},
        // right face								   
        {{0.5,  0.5,  0.5},  {0.5,  0.0f,  0.0f}},
        {{0.5, -0.5, -0.5},  {0.5,  0.0f,  0.0f}},
        {{0.5,  0.5, -0.5},  {0.5,  0.0f,  0.0f}},
        {{0.5, -0.5, -0.5},  {0.5,  0.0f,  0.0f}},
        {{0.5,  0.5,  0.5},  {0.5,  0.0f,  0.0f}},
        {{0.5, -0.5,  0.5},  {0.5,  0.0f,  0.0f}},
        // bottom face								   
        {{-0.5, -0.5, -0.5},  {0.0f, 0.5,  0.0f}},
        {{0.5, -0.5, -0.5},  {0.0f, 0.5,  0.0f}},
        {{0.5, -0.5,  0.5},  {0.0f, 0.5,  0.0f}},
        {{0.5, -0.5,  0.5},  {0.0f, 0.5,  0.0f}},
        {{-0.5, -0.5,  0.5},  {0.0f, 0.5,  0.0f}},
        {{-0.5, -0.5, -0.5},  {0.0f, 0.5,  0.0f}},
        // top face									   
        {{-0.5,  0.5, -0.5},  {0.0f,  0.5,  0.0f}},
        {{0.5,  0.5 , 0.5},  {0.0f,  0.5,  0.0f}},
        {{0.5,  0.5, -0.5},  {0.0f,  0.5,  0.0f}},
        {{0.5,  0.5,  0.5},  {0.0f,  0.5,  0.0f}},
        {{-0.5,  0.5, -0.5},  {0.0f,  0.5,  0.0f}},
        {{-0.5,  0.5,  0.5},  {0.0f,  0.5,  0.0f}}
};

const std::vector<uint16_t> indices = {
        0, 1, 2, 3, 4, 5,
        6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23,
        24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35
};

const int MAX_FRAMES_IN_FLIGHT = 2;

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class anvilengine {
public:
    anvilengine(int width, int height);
    ~anvilengine();
    void start();
private:
    //Objects
    VkInstance instance{};
    VkPhysicalDevice physicalDevice{};
    VkSwapchainKHR swapChain{};
    VkDevice vkDevice{};
    VkQueue graphicsQueue{};
    VkQueue presentQueue{};
    VkSurfaceKHR surface{};
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkRenderPass renderPass;
    VkPipeline graphicsPipeline;
    VkDebugUtilsMessengerEXT debugMessenger{};
    VkCommandPool commandPool;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
    std::vector<VkCommandBuffer> commandBuffers;
    anvilwin window;
    anvilshader shader;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;

    //Classes methods
    void initVulkan();
    void createInstance();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSurface();
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createDescriptorSetLayout();
    void createGraphicsPipeline();
    void createFramebuffers();
    void createCommandPool();
    void createVertexBuffer();
    void createIndexBuffer();
    void createUniformBuffers();
    void createDescriptorPool();
    void createDescriptorSets();
    void createCommandBuffers();
    void createSyncObjects();
    void recreateSwapChain();
    void cleanupSwapChain();
    void cleanup();

    //Window methods
    void drawFrame();

    //Vulkan methods
    static bool checkValidationLayerSupport();
    bool isDeviceSuitable(VkPhysicalDevice device);
    static bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    static std::vector<const char *> getRequiredExtensions();
    anvilutils::QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    anvilutils::SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    static VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    static VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    void updateUniformBuffer(uint32_t currentImage);

    //Debug
    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);
    void setupDebugMessenger();
    static VkResult CreateDebugUtilsMessengerEXT(
            VkInstance vkInstance,
            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
            const VkAllocationCallbacks* pAllocator,
            VkDebugUtilsMessengerEXT* pDebugMessenger);
    static void DestroyDebugUtilsMessengerEXT(
            VkInstance instance,
            VkDebugUtilsMessengerEXT debugMessenger,
            const VkAllocationCallbacks* pAllocator);

};

#endif //ANVIL_ANVILENGINE_H
