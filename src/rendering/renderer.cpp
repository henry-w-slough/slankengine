#include <rendering/renderer.h>

#include <SDL3/SDL.h>
#include <glad/glad.h>

#include <iostream>


namespace slankengine::rendering {

    Renderer::Renderer(SDL_GLContext context) :
        context(context) {
            SDL_GL_MakeCurrent(SDL_GL_GetCurrentWindow(), context);

            if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SLANKENGINE FAILURE: Failed to load OpenGL functions through glad.");
            }
        }

}





