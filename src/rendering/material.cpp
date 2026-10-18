#include "rendering/material.h"    

#include <glad/glad.h>

#include "utility/logging.h"


namespace slankengine::rendering {


    GLuint Material::getShaderProgram() {
        return shaderProgram;
    }


    void Material::use() {
        //unitialized shaderProgram
        if (shaderProgram == 0) {
            return;
        }
        glUseProgram(shaderProgram);
    }


    Material::Material(const MaterialData data) :
        vertexShader(ShaderData{ShaderType::VERTEX, data.color, data.roughness, data.metallic}),
        fragmentShader(ShaderData{ShaderType::FRAGMENT, data.color, data.roughness, data.metallic})
    {
        //setting up program
        shaderProgram = glCreateProgram();

        vertexShader.compile();
        fragmentShader.compile();

        glAttachShader(shaderProgram, vertexShader.getShader());
        glAttachShader(shaderProgram, fragmentShader.getShader());
        glLinkProgram(shaderProgram);

        GLint success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            GLchar log[512] = {};
            glGetProgramInfoLog(shaderProgram, sizeof(log), nullptr, log);
            logging::log(std::string("SLANKENGINE FAILURE: Unsuccessful shader program setup: ")+log, logging::Severity::ERROR);
            return;
        }

        use();

        GLint colorLocation = glGetUniformLocation(shaderProgram, "color");
        GLint roughnessLocation = glGetUniformLocation(shaderProgram, "roughness");
        GLint metallicLocation  = glGetUniformLocation(shaderProgram, "metallic");

        glUniform4f(colorLocation, data.color.red, data.color.green, data.color.blue, data.color.alpha);
        glUniform1f(roughnessLocation, data.roughness);
        glUniform1f(metallicLocation, data.metallic);
    }

}