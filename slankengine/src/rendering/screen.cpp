#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "rendering/screen.h"
#include "utility/color.h"


Screen::Screen(const int width, const int height, Uint32 windowFlags) : 
    width(width), height(height), 
    window(SDL_CreateWindow("slankengine game", width, height, SDL_WINDOW_OPENGL | windowFlags)), context(SDL_GL_CreateContext(window)) {

    if (!window) {
        throw std::runtime_error(std::string("Failed to create SDL window: ") + SDL_GetError());
    }

    if (!context) {
        throw std::runtime_error(std::string("Failed to create OpenGL context: ") + SDL_GetError());
    }

    SDL_GL_MakeCurrent(window, context);

    // Loading GLAD for OpenGL
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Slankengine initialization failed when loading GLAD for OpenGL.");
    }

    int fb_w, fb_h;
    SDL_GetWindowSizeInPixels(window, &fb_w, &fb_h);
    glViewport(0, 0, fb_w, fb_h);
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
    
    clearWindow();
}


void Screen::clearWindow() {
    SDL_GL_MakeCurrent(window, context); 

    //clearing screen
    glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
}


void Screen::destroy() {
    SDL_DestroyWindow(window);
    SDL_GL_DestroyContext(context);
}




