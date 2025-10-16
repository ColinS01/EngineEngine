#pragma once
#include <vector>
#include <string>
#include <glad/glad.h>

namespace Core {

class VisualObject {
public:
    VisualObject();
    virtual ~VisualObject();

    virtual void upload();       // Upload vertices/indices to GPU
    virtual void drawVisualObject();

protected:
    unsigned int VBO = 0;
    unsigned int VAO = 0;
    unsigned int EBO = 0;
    unsigned int shaderProgram = 0;

    unsigned int vertexShader = 0;
    unsigned int fragmentShader = 0;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0, 0.5, 0.2, 1.0);
        }
    )";

private:
    unsigned int compileShader(GLenum type, const char* source);
    void linkProgram(unsigned int vs, unsigned int fs);
};

}
