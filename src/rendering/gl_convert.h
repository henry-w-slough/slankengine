// src/rendering/gl_convert.h  (private header, shared by mesh.cpp and renderer.cpp)
#pragma once
#include <glad/glad.h>
#include "mesh_data.h"


namespace slankengine {


    /* Converts the given rendering specific to it's OpenGL counterpart
    */
    inline GLenum toGL(DrawMode mode) {
        switch (mode) {
            case DrawMode::Points:        return GL_POINTS;
            case DrawMode::Lines:         return GL_LINES;
            case DrawMode::LineStrip:     return GL_LINE_STRIP;
            case DrawMode::LineLoop:      return GL_LINE_LOOP;
            case DrawMode::Triangles:     return GL_TRIANGLES;
            case DrawMode::TriangleStrip: return GL_TRIANGLE_STRIP;
            case DrawMode::TriangleFan:   return GL_TRIANGLE_FAN;
        }
        return GL_TRIANGLES;   // unreachable, silences warnings
    }

    
    inline GLenum toGL(BufferUsage usage) {
        switch (usage) {
            case BufferUsage::Static:  return GL_STATIC_DRAW;
            case BufferUsage::Dynamic: return GL_DYNAMIC_DRAW;
            case BufferUsage::Stream:  return GL_STREAM_DRAW;
        }
        return GL_STATIC_DRAW;
    }

}