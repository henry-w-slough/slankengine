#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "rendering/screen.h"
#include "utility/color.h"


Screen::Screen(const int width, const int height, Uint32 windowFlags) : 
    width(width), 
    height(height), 
    window(SDL_CreateWindow("slankengine game", width, height, windowFlags)), 
    context(SDL_GL_CreateContext(window)) {
}