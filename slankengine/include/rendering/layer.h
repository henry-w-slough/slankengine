#pragma once

#include <iostream>
#include "game_object/game_object.h"


class Layer {

public:

    std::string name;

    void addObject(std::unique_ptr object);
    void removeObject(GameObject* object);

    //this is constant so unique_ptrs aren't attempted for copy, and instead a ref is returned
    const std::vector<std::unique_ptr<GameObject>>& getAllObjects() const;
    int getSize();
    void clear();

private:    
    std::vector<std::unique_ptr<GameObject>> objects;
};