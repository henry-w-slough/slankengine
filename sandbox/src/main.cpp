#include <slankengine/slankengine.h>
#include <iostream>

int main() {

    Screen screen(900, 900);
    
    while (screen.isRunning) {


        screen.Update();
        screen.setBackgroundColor(RGBA{std::rand() % (255 - 1 + 1) + 1, std::rand() % (255 - 1 + 1) + 1, std::rand() % (255 - 1 + 1) + 1});
    }

    return 0;
} 