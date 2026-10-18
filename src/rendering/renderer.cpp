#include "rendering/renderer.h"

#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>

#include "utility/logging.h"
#include "rendering/mesh.h"
#include "rendering/material.h"
#include "rendering/mesh_data.h"


struct DrawCommand {
    GLuint vao;
    GLuint shaderProgram;
    GLsizei vertexCount;
    GLsizei indexCount;

    slankengine::rendering::DrawMode drawMode;
};


namespace slankengine::rendering {


    Renderer::Renderer(SDL_Window* window, SDL_GLContext context) :
        context(context) {
            if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
                logging::log("SLANKENGINE FAILURE: Failed to load GLAD in Renderer initialization", logging::Severity::ERROR);
            }

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);      
        }


    Renderer::~Renderer() = default;


    void Renderer::draw() {
        glClearColor(clearColor.red, clearColor.green, clearColor.blue, clearColor.alpha);
        glClear(GL_COLOR_BUFFER_BIT);

        for (const auto& command : renderQueue) {
            glUseProgram(command.shaderProgram);
            // set per-draw uniforms here

            glBindVertexArray(command.vao);
            if (command.indexCount > 0) {
                glDrawElements(toGL(command.drawMode), command.indexCount, GL_UNSIGNED_INT, nullptr);
            } else {
                glDrawArrays(toGL(command.drawMode), 0, command.vertexCount);
            }
        }

        renderQueue.clear();
    }


    void Renderer::queue(Mesh& mesh, Material& material) {

        renderQueue.push_back(DrawCommand{
            .vao = mesh.vao,
            .shaderProgram = material.getShaderProgram(),
            .vertexCount = mesh.getVertexCount(),
            .indexCount = mesh.getIndexCount(),
            .drawMode = mesh.drawMode
        });

    }


}





