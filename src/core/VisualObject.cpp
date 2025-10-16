#include <core/VisualObject.hpp>
#include <iostream>

namespace Core {

VisualObject::VisualObject() {
    // Create OpenGL objects
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
}

VisualObject::~VisualObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void VisualObject::upload() {
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindVertexArray(1);
}

// 🔹 New function to attach a shader
void VisualObject::setShader(Shader* shader) {
    this->shader = shader;
}

void VisualObject::drawVisualObject() {
    if (!shader) {
        std::cerr << "Warning: VisualObject has no shader set!\n";
        return;
    }

    shader->use(); // use Shader class instead of raw program ID
    glBindVertexArray(VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (!indices.empty())
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size() / 3));

}

} // namespace Core
