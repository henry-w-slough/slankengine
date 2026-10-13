#pragma once

#include "utility/color.h"
#include "utility/math.h"


namespace slankengine {
    
    /*Representation of a vertex on the screen
    by the data that defines it. */
    struct Vertex {
        Vector3 position;
        Color color;    
    };

}