#include <core/VisualObject.hpp>
#include <iostream>

namespace Core {

VisualObject::VisualObject(glm::vec3 spawn_pos, glm::vec3 spawn_rot) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    current_pos = spawn_pos;
    current_rot = spawn_rot;
}

VisualObject::~VisualObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void VisualObject::upload() {
    glBindVertexArray(VAO);

    // Upload vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Upload index data (if any)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Vertex layout: position (3 floats) + color (3 floats)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

// Attach shader to this object
void VisualObject::setShader(Shader* shader) {
    this->shader = shader;
}

// Draw the object
void VisualObject::drawVisualObject(bool outlineOnly) {
    if (!shader) {
        std::cerr << "[VisualObject] Warning: no shader set!\n";
        return;
    }

    shader->use();
    glBindVertexArray(VAO);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, current_pos);
    model = glm::rotate(model, glm::radians(current_rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(current_rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(current_rot.z), glm::vec3(0.0f, 0.0f, 1.0f));

    // Send model matrix to shader
    shader->setMat4("model", model);

    if (outlineOnly) {
        // --- Outline mode ---
        shader->setBool("isOutline", true);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2.0f); // adjust outline thickness
    } else {
        shader->setBool("isOutline", false);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    if (!indices.empty()) {
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size() / 6));
    }

    // Reset polygon mode (avoid affecting other draws)
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(0);
}

void VisualObject::rotateVisualObject(glm::vec3 rot)
{
    current_rot += rot; // accumulate rotation
}

} // namespace Core
