#pragma once


namespace slankengine {

    /**
     * Initializes all libraries used within slankengine. This function should be called
     * before any other slankengine core, as the engine may break without initializing the libraries needed.
     * 
     * This also sets OpenGL attributes.
     */
    bool init();

    /*
    * Deinitializes all libraries used by slankengine.
    */
    void deinit();
}