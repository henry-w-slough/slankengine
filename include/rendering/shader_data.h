#pragma once

#include <string>


namespace slankengine::rendering {


    enum class ShaderType {
        VERTEX,
        FRAGMENT
    };

    
    struct ShaderData {
        const char* source;
    };


    unsigned int toGl(const ShaderType type);
}