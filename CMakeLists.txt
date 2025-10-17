cmake_minimum_required(VERSION 3.10)
project(EngineEngine)

cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}
    include 
    include/core 
    include/phys 
    include/chem 
    include/ui 
    include/glad 
    include/KHR 
    include/rend 
    include/glm)

file(GLOB SHADERS shaders/*)
file(GLOB CORE_SRC src/core/*.cpp)
file(GLOB CHEM_SRC src/chem/*.cpp)
file(GLOB PHYS_SRC src/phys/*.cpp)
file(GLOB UI_SRC src/ui/*.cpp)

add_executable(EngineEngine src/main.cpp src/glad.c ${CORE_SRC} ${CHEM_SRC} ${PHYS_SRC} ${UI_SRC})

file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})


target_include_directories(EngineEngine PRIVATE 
    include 
    include/core 
    include/phys 
    include/chem 
    include/ui 
    include/glad 
    include/KHR 
    include/rend 
    include/glm
)

target_link_libraries(EngineEngine
    OpenGL::GL
    glfw
)
