#include <glad/glad.h>

#include "vertex.h"
#include "mesh.h"


Mesh::Mesh() {

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    bind();

    //Note that the VBO is not assigned to the VAO
    //until attributes are added.

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)offsetof(Vertex, position)
    );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        1, 2, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)offsetof(Vertex, uv)
    );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(
        2, 4, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)offsetof(Vertex, color)
    );
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(
        3, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)offsetof(Vertex, normal)
    );
    glEnableVertexAttribArray(3);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    unbind();
}


Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}


void Mesh::addVertices(std::vector<Vertex> vertices) {
    bind();
    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size() * sizeof(Vertex),
        vertices.data(),
        GL_STATIC_DRAW
    );
    unbind();
}


void Mesh::bind() {
    glBindVertexArray(vao);
}


void Mesh::unbind() {
    glBindVertexArray(0);
}
