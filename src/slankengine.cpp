#include <slankengine/slankengine.h>
#include <SDL3/SDL.h>


namespace slankengine { 

    
    bool isInitialized = false;


    bool init() {

        //SDL3 initialization
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Slankengine initialization failed: couldn't initialize SDL: %s", SDL_GetError());      
            return false;
        }

        //Global attributes for OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        
        isInitialized = true;
        return true;
    }

    
    void deinit() {

        if (isInitialized) {
            return;
        }
        
        SDL_Quit();
    }
    
}

