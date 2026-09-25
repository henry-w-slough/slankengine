#pragma once

#include <cstdint>


class Mesh {

public:

    Mesh();
    ~Mesh();

private:

    void generateBuffer();
    void destroyBuffer();

    void bind();
    void unbind();

    uint32_t vbo;
    uint32_t ebo;
    uint32_t vao;
};
