#include "rendering/renderer.h"

#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>

#include "utility/logging.h"
#include "rendering/mesh.h"


struct DrawCommand {
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    
    GLuint drawMode;
};


namespace slankengine::rendering {


    Renderer::Renderer(SDL_Window* window, SDL_GLContext context) :
        context(context) {
            if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
                logging::log("SLANKENGINE FAILURE: Failed to load GLAD in Renderer initialization", logging::Severity::ERROR);
            }
        }

        
    //placeholder for proper destruction with DrawCommand defined in .cpp
    Renderer::~Renderer() = default;


    void Renderer::draw() {
        glClearColor(clearColor.red, clearColor.green, clearColor.blue, clearColor.alpha);
        glClear(GL_COLOR_BUFFER_BIT);

        for (auto& command : renderQueue) {

        }   

    }


    void Renderer::queue(const Mesh mesh) {
        renderQueue.push_back(
            DrawCommand{
                .vao = mesh.vao,
                .vbo = mesh.vbo,
                .ebo = mesh.ebo
            }
        );
    }


}





