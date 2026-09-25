#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "rendering/screen.h"
#include "utility/color.h"


Screen::Screen(const int width, const int height, Uint32 windowFlags) : 
    width(width), height(height), 
    window(SDL_CreateWindow("slankengine game", width, height, SDL_WINDOW_OPENGL | windowFlags)), context(SDL_GL_CreateContext(window)) {

    // Loading GLAD for OpenGL
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Slankengine initialization failed when loading GLAD for OpenGL.");
    }
}


Screen::~Screen() {
    destroy();
}


void Screen::update() {

    //running event loop
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        //checking for exit
        if (e.type == SDL_EVENT_QUIT) {
            isRunning = false;
        }
    }

    //clearing screen
    glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
}


void Screen::destroy() {
    SDL_DestroyWindow(window);
    SDL_GL_DestroyContext(context);
}




