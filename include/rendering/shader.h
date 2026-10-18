#include "shader_data.h"


namespace slankengine::rendering {

    class Shader {

    public:

        Shader(const ShaderData data, ShaderType type);
        ~Shader();

        void compile();

    private:
        unsigned int shader;
    };

}