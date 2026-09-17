#include <SDL3/SDL.h>
#include "rendering/screen.h"
#include "utility/color.h"
#include "rendering/layer.h"


Screen::Screen(int width, int height, std::string title, Uint32 window_flags, Uint32 renderer_flags): 
    width(width), 
    height(height), 
    title(title), 
    window(SDL_CreateWindow(title.c_str(), width, height, window_flags)), 
    renderer(SDL_CreateRenderer(window, nullptr)) {}


Screen::~Screen() {
    Destroy();
}


void Screen::Update() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        
        if (event.type == SDL_EVENT_QUIT) {
            isRunning = false;
        }
        
        //drawing backgroundColor for screen refresh
        SDL_SetRenderDrawColor(renderer, backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.alpha);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
}


void Screen::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void Screen::setBackgroundColor(RGBA color) {
    backgroundColor = color;
}


void Screen::addLayer(std::string name) {
    layers.emplace(name, Layer());
}


void Screen::removeLayer(std::string name) {
     
    auto it = layers.find(name);
    if (it != layers.end()) {
        layers.erase(it);
    }

    throw std::runtime_error("Layer not found of the given name: " + name);
}


Layer Screen::getLayer(std::string name) {

    auto it = layers.find(name);
    if (it != layers.end()) {
        return it->second;
    }

    throw std::runtime_error("Layer not found of the given name:" + name);
}
