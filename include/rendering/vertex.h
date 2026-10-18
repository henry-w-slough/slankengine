#pragma once

#include "utility/color.h"
#include "utility/math.h"


namespace slankengine::rendering {

    //The layout of attributes for vertex must match Vertex Shader template
    
    /*Representation of a vertex on the screen
    by the data that defines it. */
    struct Vertex {
        math::Vector3 position;
        Color color;    
    };

}