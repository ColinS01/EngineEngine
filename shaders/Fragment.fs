#version 330 core
out vec4 FragColor;

uniform vec3 objectColor = vec3(0.25);
uniform vec3 outlineColor = vec3(0.0, 1.0, 0.0); 
uniform bool isOutline = true;
uniform float alpha = 0.5;                     

void main()
{
    if (isOutline)
        FragColor = vec4(outlineColor, 1.0);
    else
        FragColor = vec4(objectColor, alpha);
}
