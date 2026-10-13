#pragma once

#include <vector>

#include "vertex.h"


namespace slankengine {

    /*
    * The methods of drawing vertices on the screen.
    * Specifies how vertex data should be handled and rendered.
    */
    enum class DrawMode {
        Points,
        Lines,
        LineStrip,
        LineLoop,
        Triangles,
        TriangleStrip,
        TriangleFan
    };

    
    /*The hint that allows the rendering process to determine
    how to most efficiently render a buffer.*/
    enum class BufferUsage {
        Static,
        Dynamic,
        Stream
    };

    
    
    /*The data needed to create a Mesh instance.*/
    struct MeshData {
        std::vector<Vertex> vertices;
        std::vector<std::uint32_t> indices;
        
        DrawMode drawMode;
        BufferUsage bufferUsage;
    };

}


