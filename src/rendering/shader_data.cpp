#include "rendering/shader_data.h"

#include <glad/glad.h>

#include "utility/logging.h"

namespace slankengine::rendering {

    GLenum toGL(const ShaderType type) {

        switch (type) {
            case ShaderType::VERTEX: return GL_VERTEX_SHADER;
            case ShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
            default: logging::log("SLANKENGINE FAILURE: ShaderType given was invalid and could not be translated to GL shader type.", logging::Severity::ERROR);
        }
            
    }

}