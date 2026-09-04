
#include "core/game.h"

int main(int argc, char* argv[]) {
 
    Game MyGame;


    MyGame.init("my Game",1000,800);
    MyGame.run();
    MyGame.end();

    return 0;
}