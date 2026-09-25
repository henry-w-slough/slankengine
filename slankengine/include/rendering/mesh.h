#pragma once

#include <vector>
#include "vertex.h"


class Mesh {

public:

    Mesh();
    ~Mesh();

    void addVertices(std::vector<Vertex> vertices);

private:

    void generateBuffer();
    void destroyBuffer();

    void bind();
    void unbind();

    uint32_t vbo;
    uint32_t ebo;
    uint32_t vao;
};
