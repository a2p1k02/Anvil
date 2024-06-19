cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME Anvil)

set(PROJECT_FILES
        src/main.cpp
        src/engine/anvilwin.h
        src/engine/anvilwin.cpp
        src/engine/anvilengine.h
        src/engine/anvilengine.cpp
        src/engine/anvilshader.h
        src/engine/anvilshader.cpp
        src/engine/anvilutils.cpp
        src/engine/anvilutils.h
)

if (WIN32)
    add_subdirectory(libs/glfw)
    add_subdirectory(libs/glm)

    find_package(Vulkan REQUIRED)
    set(VULKAN_SDK_PATH "D:/VulkanSDK/1.3.283.0") # Change that to your path
endif ()

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

if (WIN32)
    if (DEFINED VULKAN_SDK_PATH)
        set(Vulkan_INCLUDE_DIRS "${VULKAN_SDK_PATH}/Include") # 1.1 Make sure this include path is correct
        set(Vulkan_LIBRARIES "${VULKAN_SDK_PATH}/Lib") # 1.2 Make sure lib path is correct
        set(Vulkan_FOUND "True")
    else()
        find_package(Vulkan REQUIRED) # throws error if could not find Vulkan
    endif()

    if (USE_MINGW)
        target_include_directories(${PROJECT_NAME} PUBLIC
                ${MINGW_PATH}/include
        )
        target_link_directories(${PROJECT_NAME} PUBLIC
                ${MINGW_PATH}/lib
        )
    endif()

    target_include_directories(${PROJECT_NAME} PUBLIC
            ${PROJECT_SOURCE_DIR}/src
            ${Vulkan_INCLUDE_DIRS}
            ${GLFW_INCLUDE_DIRS}
            ${GLM_PATH}
    )

    target_link_directories(${PROJECT_NAME} PUBLIC
            ${Vulkan_LIBRARIES}
            ${GLFW_LIB}
    )

    target_link_libraries(${PROJECT_NAME} glfw vulkan-1)
elseif (UNIX)
    target_include_directories(${PROJECT_NAME} PUBLIC
            ${PROJECT_SOURCE_DIR}/src
    )
    target_link_libraries(${PROJECT_NAME} glfw vulkan)
endif()
