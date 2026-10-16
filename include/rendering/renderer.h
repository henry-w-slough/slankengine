#pragma once

struct SDL_GLContextState;


namespace slankengine::rendering {


    class Renderer {

    public:
        Renderer(SDL_GLContextState* context);


    private:
        SDL_GLContextState* context;

    };

}