#pragma once

#include <vector>

#include "vertex.h"
#include "mesh_data.h"


namespace slankengine::rendering {


    class Mesh {

    public:
        Mesh(const MeshData meshData);
        ~Mesh();

        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;

    private:
        void bind();
        void unbind();
    };


}