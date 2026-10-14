#include <rendering/renderer.h>

#include <SDL3/SDL.h>
#include <glad/glad.h>


namespace slankengine {

    Renderer::Renderer(SDL_GLContext context) :
        context(context) {
            SDL_GL_MakeCurrent(SDL_GL_GetCurrentWindow(), context);
        }

}





