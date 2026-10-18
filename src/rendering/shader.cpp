#include "rendering/shader.h"
#include "rendering/shader_data.h"

#include <glad/glad.h>


namespace slankengine::rendering {

    Shader::Shader(const ShaderData data, ShaderType type) {
        shader = glCreateShader(toGl(type));

        glShaderSource(shader, 1, &data.source, nullptr);
    }


    Shader::~Shader() {

    }


    void Shader::compile() {
        glCompileShader(shader);
    }
}