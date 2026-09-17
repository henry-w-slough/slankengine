#include "rendering/texture.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>


Texture::Texture(SDL_Renderer* renderer) :
    renderer(renderer) {}


SDL_Texture* Texture::get() {
    return texture;
}


void Texture::setSource(std::string source) {
    texture = IMG_LoadTexture(renderer, source.c_str());
}


Texture::~Texture() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}