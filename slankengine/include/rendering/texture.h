#include <SDL3/SDL.h>
#pragma once


#include <SDL3_image/SDL_image.h>
#include <iostream>


class Texture {
    
public:
    void setSource(std::string source);
    SDL_Texture* get();
    Texture(SDL_Renderer* renderer, float width, float height);
    ~Texture();

private:
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;

    float width;
    float height;

};