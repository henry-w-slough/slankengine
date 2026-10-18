#pragma once

#include "utility/color.h"


namespace slankengine::rendering {

    struct MaterialData {
        Color color;
        float roughness;
        float metallic;
    };

}