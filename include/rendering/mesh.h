#pragma once

#include <vector>

#include "vertex.h"
#include "mesh_data.h"


namespace slankengine {


    class Mesh {


    public:
        Mesh(const MeshData meshData);
        ~Mesh();

    private:
        void bind();
        void unbind();
        
        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;
    };


}