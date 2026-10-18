#include "shader_data.h"


namespace slankengine::rendering {

    class Shader {

    public:

        Shader(ShaderData data);
        ~Shader();

        void compile();

        unsigned int getShader();

    private:
        unsigned int shader;
    };

}