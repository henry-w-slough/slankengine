#include <slankengine/slankengine.h>
#include <iostream>


int main() {

    if (!slankengine::init()) {
        std::cout << "Failed to initialize slankengine!" << std::endl;
        return -1;
    }

    Screen screen(800, 800);

    while (screen.isRunning) {
        screen.update();
    } 

    return 0;
} 