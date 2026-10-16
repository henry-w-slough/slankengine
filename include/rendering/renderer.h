#pragma once

#include "utility/color.h"


struct SDL_GLContextState;
struct SDL_Window;


namespace slankengine::rendering {


    class Renderer {

        
    public:
        Renderer(SDL_Window* window, SDL_GLContextState* context);

        void clear();

        Color clearColor = Color{0.0f, 0.0f, 0.0f, 1.0f};


    private:
        SDL_GLContextState* context;
    };

}