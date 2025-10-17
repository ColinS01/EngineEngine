#ifndef UI_H
#define UI_H

#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <rend/Shader.h>
#include <core/VisualObject.hpp>

namespace ui
{
    class Ui
    {
    public:
        Ui() = default;
        ~Ui() = default;

        // Add object to the UI scene
        void addObject(Core::VisualObject &obj, Shader &ourShader)
        {
            obj.upload();
            obj.setShader(&ourShader);
            scene_objects.push_back(&obj); // store pointer
        }

        // Draw all objects (outline or filled)
        void drawAll(bool outLineOnly)
        {
            for (auto *obj : scene_objects)
                obj->drawVisualObject(outLineOnly);
        }

    protected:
        std::vector<Core::VisualObject*> scene_objects;
    };
}

#endif // UI_H
