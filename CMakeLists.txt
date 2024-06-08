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

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} glfw vulkan)