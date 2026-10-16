#include "window/window.h"

#include "utility/logging.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <glad/glad.h>


namespace slankengine::window {


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
      };


   Window::~Window() {

      //checking if the window or gl context haven't been init yet
      if (window == nullptr || context == nullptr) {
         return;
      }

      if (!SDL_GL_DestroyContext(context)) {
         logging::log(std::string("SLANKENGINE FAILURE: Failed to destroy context during Window destruction: ") + SDL_GetError(), logging::Severity::ERROR);
      }

      SDL_DestroyWindow(window);
      
   };

   
}