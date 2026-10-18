#include "rendering/shader.h"
#include "rendering/shader_data.h"

#include <glad/glad.h>


namespace slankengine::rendering {


    Shader::Shader(ShaderData data) {
        shader = glCreateShader(toGL(data.type));

        //sets the template from which the shader will be built on
        const char* source;
        if (data.type == ShaderType::VERTEX) {
            source = vertexShaderTemplate;
        }
        if (data.type == ShaderType::FRAGMENT) {
            source = fragmentShaderTemplate;
        }

        glShaderSource(shader, 1, &source, nullptr);
    }


    Shader::~Shader() {
        glDeleteShader(shader);
    }


    void Shader::compile() {
        glCompileShader(shader);
    }


    unsigned int Shader::getShader() {
        return shader;
    }

}