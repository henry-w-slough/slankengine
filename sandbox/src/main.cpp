#include <slankengine/slankengine.h>
#include <iostream>


int main() {
    
    if (!slankengine::init()) {
        std::cout << "Failed to initialize slankengine!" << std::endl;
        return -1;
    }
    
    
    Screen screen(800, 800);
    screen.backgroundColor = Color{1.0f, 1.0f, 1.0f, 1.0f};


    while (screen.isRunning) {
        screen.update();
    } 


    slankengine::shutdown();
    return 0;
} 