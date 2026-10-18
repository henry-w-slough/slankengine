#include <glad/glad.h>

#include "rendering/mesh.h"
#include "rendering/mesh_data.h"


namespace slankengine::rendering {


    /*
    * Holds and handles the buffers which store the data for a group of vertices.
    *
    * The Mesh does not do any rendering itself, only abstracts the process of allocating and cleaning up data for one or more vertices.
    */
    Mesh::Mesh(const MeshData data) {

        //generating the new vao
        glGenVertexArrays(1, &vao);

        //binding vao
        bind();
        
        //vbo setup
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, data.vertices.size() * sizeof(Vertex), data.vertices.data(), toGL(data.bufferUsage));

        //ebo setup, also skips for empty indices
        if (!data.indices.empty()) {
            glGenBuffers(1, &ebo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.indices.size() * sizeof(std::uint32_t), data.indices.data(), toGL(data.bufferUsage));
        }
        else {
            //default
            ebo = 0;
        }

        //binding attributes, must be done while the vao is bound
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        vertexCount = data.vertices.size();
        indexCount = data.indices.size();

        drawMode = data.drawMode;

        unbind();
    }


    Mesh::~Mesh() {
        unbind();

        //cleaning up resources
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        if (ebo != 0) {
            glDeleteBuffers(1, &ebo);
        }
    }


    int Mesh::getVertexCount() {
        return vertexCount;
    }


    int Mesh::getIndexCount() {
        return indexCount;
    }


    void Mesh::bind() {
        glBindVertexArray(vao);
    }


    void Mesh::unbind() {
        glBindVertexArray(0);
    }


}