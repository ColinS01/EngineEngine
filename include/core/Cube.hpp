#ifndef CUBE_HPP
#define CUBE_HPP

#include <core/VisualObject.hpp>

namespace Core {

class Cube : public VisualObject {
public:
    // Constructor: optional spawn position & rotation
    Cube(glm::vec3 spawn_pos = glm::vec3(0.0f), 
         glm::vec3 spawn_rot = glm::vec3(0.0f))
        : VisualObject(spawn_pos, spawn_rot)
    {
        // Define cube vertices (positions + colors)
        // 8 corners, repeated for each face with color per vertex
        vertices = {
            // positions           // colors
            // Front face
            -0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,
             0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.0f,

            // Back face
            -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 1.0f,
             0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,   0.5f, 0.5f, 0.5f
        };

        // Define cube indices for triangles
        indices = {
            // Front face
            0, 1, 2,  2, 3, 0,
            // Right face
            1, 5, 6,  6, 2, 1,
            // Back face
            5, 4, 7,  7, 6, 5,
            // Left face
            4, 0, 3,  3, 7, 4,
            // Top face
            3, 2, 6,  6, 7, 3,
            // Bottom face
            4, 5, 1,  1, 0, 4
        };

        // Upload vertex & index data to GPU
        upload();
    }

    ~Cube() = default;
};

} // namespace Core

#endif // CUBE_HPP
