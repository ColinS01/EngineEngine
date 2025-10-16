#include <core/Triangle.hpp>

namespace Core
{
    Triangle::Triangle()
    {
        vertices = {
            // positions        // colors
            0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f
        };
    }
}
