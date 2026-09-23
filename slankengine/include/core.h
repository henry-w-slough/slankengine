#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

/**
 * Handles all globally accessed properties, such as libraries,
 * and their initialization and destruction.
 * 
 * Always call from here for proper slankengine initialization and use.
 */
namespace slankengine {
    /**
     * Loads and executes all intialization logic for slankengine, this includes SDL2 and GLAD as well.
     * Always check that this function returns true, otherwise libraries were not loaded correctly and the engine will not function.
     * @param engineFlags Optional flags to add to SDL2 initialization.
     * @return Returns a boolean determining whether the engine successfully initialized or not. 
     */
    bool init(Uint32 engineFlags = SDL_INIT_VIDEO);

    /**
     * Deinitializes slankengine along with all libraries used by it.
     */
    void shutdown();
}