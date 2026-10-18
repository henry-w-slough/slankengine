#pragma once

#include <string>

#include "utility/color.h"



//SHADER DATA MUST MATCH THESE OR ELSE YOU DIE


static const char* vertexShaderTemplate = R"(#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

out vec4 vColor;

void main() {
    vColor = aColor;
    gl_Position = vec4(aPos, 1.0);
}

)";


static const char* fragmentShaderTemplate = R"(#version 330 core

out vec4 FragColor;

uniform vec4 color;
uniform float roughness;
uniform float metallic;

void main() {
    FragColor = vec4(color);
}
)";



namespace slankengine::rendering {


    enum class ShaderType {
        VERTEX,
        FRAGMENT
    };

    
    struct ShaderData {
        ShaderType type;

        Color color;
        float roughness;
        float metallic;
    };


    unsigned int toGL(const ShaderType type);
}





