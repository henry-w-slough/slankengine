#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "rendering/screen.h"
#include "utility/color.h"


Screen::Screen(const int width, const int height, Uint32 windowFlags) : 
    width(width), height(height), 
    window(SDL_CreateWindow("slankengine game", width, height, windowFlags)), context(SDL_GL_CreateContext(window)) {

    // Loading GLAD for OpenGL
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Slankengine initialization failed when loading GLAD for OpenGL.");
    }
}


Screen::~Screen() {
    destroy();
}


void Screen::update() {

    SDL_Event e;
    while (SDL_PollEvent(&e)) {

        if (e.type == SDL_EVENT_QUIT) {
            isRunning = false;
        }
        
    }
}


void Screen::destroy() {
    SDL_DestroyWindow(window);
    SDL_GL_DestroyContext(context);
}




