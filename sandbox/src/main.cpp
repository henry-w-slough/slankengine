#include <slankengine/slankengine.h>
#include <iostream>

int main() {

    Screen screen(900, 900);

    Texture texture(screen.renderer, 32, 32);

    RGBA backgroundColor{25, 25, 35, 255};
    screen.setBackgroundColor(backgroundColor);   
    
    while (screen.isRunning) {   
        screen.Update();
    }
    
    return 0;
}