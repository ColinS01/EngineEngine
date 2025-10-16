#include <core/Triangle.hpp>

namespace Core
{
    Triangle::Triangle()
    {
        // Access the inherited vertices vector and assign to it
        vertices = {
            0.0f,  0.5f, 0.0f,   // top vertex
           -0.5f, -0.5f, 0.0f,   // bottom left
            0.5f, -0.5f, 0.0f    // bottom right
        };
    }
}
