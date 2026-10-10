#pragma once

#include <vector>

#include "vertex.h"


namespace slankengine {

    /*
    * The methods of drawing vertices on the screen.
    * Specifies how vertex data should be handled and rendered.
    */
    enum class PrimitiveMode {
        Points,
        Lines,
        LineStrip,
        LineLoop,
        Triangles,
        TriangleStrip,
        TriangleFan
    };

    /*
     * The method of using a buffer to hint
     * the more efficient method of rendering it's contents.
     */
    enum class BufferUsage {
        Static,
        Dynamic,
        Stream
    };

    
    
    struct MeshData {
        std::vector<Vertex> vertices;
        std::vector<std::uint32_t> indices;
        
        PrimitiveMode mode;
        BufferUsage usage;
    };

}


