#pragma once


namespace slankengine {

    /**
     * Initializes all libraries used within slankengine. This function should be called
     * before any other slankengine core, as the engine may break without initializing the libraries needed.
     * 
     * Note that this function DOES NOT initialize glad, as that is used only
     * in the rendering core, but it does set the OpenGL attributes using SDL.
     */
    bool init();

    /*
    * Deinitializes all libraries used by slankengine.
    */
    void deinit();
}