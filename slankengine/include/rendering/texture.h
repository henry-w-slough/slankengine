#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


class Texture {
    
public:
    Texture(float width, float height);
    ~Texture();

private:
    SDL_Texture* texture = nullptr;
    float width;
    float height;

};