#include <glad/glad.h>
#include <glm

#include "mesh.h"


struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};


Mesh::Mesh() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    bind();

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    unbind();
}


Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}


void Mesh::bind() {
    glBindVertexArray(vao);
}


void Mesh::unbind() {
    glBindVertexArray(0);
}




