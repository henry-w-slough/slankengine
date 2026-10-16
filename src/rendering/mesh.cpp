#include <glad/glad.h>

#include "rendering/mesh.h"
#include "rendering/mesh_data.h"


namespace slankengine::rendering {


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

        //binding attributes

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        unbind();
    }


    Mesh::~Mesh() {
        unbind();
    }


    void Mesh::bind() {
        glBindVertexArray(vao);
    }


    void Mesh::unbind() {
        glBindVertexArray(0);
    }


}