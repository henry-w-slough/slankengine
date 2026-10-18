#pragma once

#include "shader.h"
#include "material_data.h"


namespace slankengine::rendering {

    class Material {

    public:
        Material(const MaterialData data);

        void use();

        unsigned int getShaderProgram();

    private:
        Shader vertexShader;
        Shader fragmentShader;

        unsigned int shaderProgram = 0;
    };

}