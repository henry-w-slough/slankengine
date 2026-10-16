#pragma once

#include <string>


struct SDL_Window;
struct SDL_GLContextState;


namespace slankengine::window {


    /**
     * The window manager. Creates a window and a rendering context
     * along with configuration functions for properties of the window itself.
     */
    class Window { 

    public:
        bool isActive = true;
        std::string title = "slankengine window";

        void setWindowTitle(const std::string title);

        int getWidth();
        int getHeight();

        SDL_GLContextState* getContext();

        /*
        * The main update function for a Window. 
        * Updates isActive based off whether the user has quit.
        */
        void update();

        Window(const int width, const int height);
        ~Window();
    
    private:
        SDL_Window* window = nullptr;  
        SDL_GLContextState* context = nullptr;

        int width;
        int height;
    };


}


