#include "rendering/renderer.h"

#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>

#include "utility/logging.h"


namespace slankengine::rendering {


    Renderer::Renderer(SDL_Window* window, SDL_GLContext context) :
        context(context) {
            
            SDL_GL_MakeCurrent(window, context);

            if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
                logging::log("SLANKENGINE FAILURE: Failed to load GLAD in Renderer initialization", logging::Severity::ERROR);
            }
        }


    void Renderer::clear() {
        glClearColor(clearColor.red, clearColor.green, clearColor.blue, clearColor.alpha);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    

}





