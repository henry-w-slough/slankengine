#include <SDL3/SDL.h>
#include <iostream>


namespace slankengine { 

    
    bool isInitialized = false;


    void init() {

        //SDL3 initialization
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            throw std::runtime_error("Slankengine initialization failed: Failed to initialize SDL library.");
        }

        //Global attributes for OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        
        isInitialized = true;
    }

    
    void deinit() {

        if (!isInitialized) {
            return;
        }
        
        SDL_Quit();
    }
    
}