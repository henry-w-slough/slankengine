#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <print>

#include "core.h"


namespace slankengine {

    bool init(Uint32 engineFlags) {
        // Required: video (also starts the events subsystem).
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("SDL_Init failed: %s", SDL_GetError());
            return false;
        }

        // Optional: failures are logged but don't fail init.
        if (engineFlags != 0 && !SDL_InitSubSystem(engineFlags)) {
            return false;
        }

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
            return false;
        }

        return true;
    }

    void shutdown() {
        // Destroy Screen (window + GL context) before calling this.
        SDL_Quit();
    }

}