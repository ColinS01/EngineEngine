#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <core/VisualObject.hpp>

namespace Core {

class Triangle : public VisualObject {
public:
    // Constructor: optional spawn position & rotation
    Triangle(glm::vec3 spawn_pos = glm::vec3(0.0f), 
             glm::vec3 spawn_rot = glm::vec3(0.0f)) 
        : VisualObject(spawn_pos, spawn_rot) 
    {
        // Define vertices (positions + colors)
        vertices = {
            // positions        // colors
             0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // top vertex, red
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom-left vertex, green
             0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // bottom-right vertex, blue
        };

        // Send the vertex data to the GPU
        upload();
    }

    // Destructor (default is fine)
    ~Triangle() = default;
};

} // namespace Core

#endif // TRIANGLE_HPP
