#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "window/window.h"


namespace slankengine {


   void Window::update() {
      //polling for all queued events this frame
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
         if (event.type == SDL_EVENT_QUIT) {
               isActive = false;
         }
      }
   }  
   

   int Window::getWidth() {
      return width;
   }


   int Window::getHeight() {
      return height;
   }


   void Window::setWindowTitle(const std::string title) {
      this->title = title;
      SDL_SetWindowTitle(window, title.c_str());
   }


   SDL_GLContextState* Window::getContext() {
      return context;
   }


   Window::Window(const int width, const int height):
      window(SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL)),
      context(SDL_GL_CreateContext(window)) {

         SDL_GL_MakeCurrent(window, context);

         //glad initialization check
         if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
            
         }
      };


   Window::~Window() {

      SDL_DestroyWindow(window);

      if (!SDL_GL_DestroyContext(context)) {
         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Slankengine window destruction failed: %s", SDL_GetError());      
      }
      
   };

   
}