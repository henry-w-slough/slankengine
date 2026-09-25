#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>

#include "core.h"


namespace slankengine {


    bool init(Uint32 sdl2_flags) {
        // Video also starts event subsystem (Fixed for SDL3 bool return value)
        if (!SDL_Init(SDL_INIT_VIDEO | sdl2_flags)) {
            std::cout << "Slankengine initialization failed during SDL setup: " << std::endl;
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
            return false;
        }

        // Setting OpenGL attributes globally
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        
        return true;
    }

    
    void shutdown() {
        SDL_Quit();
    }

}