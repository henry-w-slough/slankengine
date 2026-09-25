#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include <unordered_map>

#include "utility/color.h"


class Screen {


public:

    const int width;
    const int height;
    std::string title;
    bool isRunning = true;

    Color backgroundColor{1.0f, 1.0f, 1.0f, 1.0f};

    void update();
    void destroy();

    void setTitle(std::string title);

    Screen(const int width, const int height, Uint32 windowFlags = SDL_WINDOW_OPENGL);
    ~Screen();


private:

    SDL_Window* window = nullptr;
    SDL_GLContext context = nullptr;

    void clearWindow();
};