#pragma once

#include <vector>

#include "vertex.h"
#include "mesh_data.h"


namespace slankengine::rendering {


    class Mesh {

    public:
        Mesh(const MeshData meshData);
        ~Mesh();

        unsigned int vao = 0;
        unsigned int vbo = 0;
        unsigned int ebo = 0;

        int getVertexCount();
        int getIndexCount();

        DrawMode drawMode;
    
    private:
        void bind();
        void unbind();

        int vertexCount;
        int indexCount;
    };


}