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

    RGBA backgroundColor{255, 255, 255, 255};

    void update();
    void destroy();

    void setBackgroundColor(const RGBA color);
    void setTitle(std::string title);

    Screen(const int width, const int height, Uint32 windowFlags = 0);
    ~Screen();


private:

    SDL_Window* window = nullptr;
    SDL_GLContext context = nullptr;

    void clearWindow();

};