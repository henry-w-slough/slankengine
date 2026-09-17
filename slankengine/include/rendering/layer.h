#pragma once

#include <unordered_map>
#include <any>


class Layer {

public:
    std::vector<std::any> objects;
    Layer();
};