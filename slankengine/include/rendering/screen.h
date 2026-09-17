#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include <unordered_map>

#include "utility/color.h"
#include "rendering/layer.h"


class Screen {

public:

    const int width;
    const int height;
    std::string title;
    bool isRunning = true;

    RGBA backgroundColor{255, 255, 255, 255};

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    void Update();
    void Destroy();
    void setBackgroundColor(RGBA color);

    void addLayer(std::string name);
    void removeLayer(std::string name);
    Layer getLayer(std::string name);

    Screen(int width, int height, std::string title = "slankengine game", Uint32 window_flags = 0, Uint32 renderer_flags = 0);
    ~Screen();

private:
    std::unordered_map<std::string, Layer> layers;

};