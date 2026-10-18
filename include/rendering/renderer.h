#pragma once

#include "utility/color.h"
#include "rendering/mesh.h"


struct SDL_GLContextState;
struct SDL_Window;

struct DrawCommand;


namespace slankengine::rendering {


    class Renderer {


    public:
        Renderer(SDL_Window* window, SDL_GLContextState* context);
        ~Renderer();

        Color clearColor = Color{0.0f, 0.0f, 0.0f, 1.0f};

        /* Refreshes the screen by setting the color for GL to clear the screen with to the backgroundColor of the renderer and clearing it.
         */
        void draw();
        void queue(const Mesh mesh);


    private:
        std::vector<DrawCommand> renderQueue;
        SDL_GLContextState* context;
    };

}



