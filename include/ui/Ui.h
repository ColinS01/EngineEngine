#ifndef UI_H
#define UI_H

#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <rend/Shader.h>
#include <ui/Scene.h>
#include <core/VisualObject.hpp>

namespace ui
{
    class Ui
    {
    public:
        Ui() = default;
        ~Ui() = default;
        
        ui::Scene scene;
    };
}

#endif // UI_H
