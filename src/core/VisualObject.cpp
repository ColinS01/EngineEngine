#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <core/VisualObject.hpp>

namespace Core
{

    VisualObject::VisualObject() 
    {
        // init a buffer
        glGenBuffers(1, &VBO);
        
        // init a vertex array
        glGenVertexArrays(1, &VAO);  


        // creating an empty shader and assign it the vertex type
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        // creating an empty shader and assign it the fragment type
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        // create a shader program and attatch the vertex and fragment shaders from above
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);

        // link the shader program and delete the shaders
        glLinkProgram(shaderProgram);glUseProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void VisualObject::drawVisualObject()
    {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);  
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        /*
        glVertexAttribPointer:
            params:
                - "0": the location of the position vertex attribute in the vertex shader with layout
                - "3": the size of the vertex attribute
                - "GL_FLOAT": the type of the data
                - "GL_FALSE": if we want the data to be normalized
                - "3 * sizeof(float)": known as the stride and tells us the space between consecutive vertex attributes
                - "(void*)0": the offset of where the position data begins in the buffer
        */
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(0);  

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }
}