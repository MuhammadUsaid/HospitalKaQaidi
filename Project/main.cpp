#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
    Game game("Hospital Ka Qaidi", 640, 480);
    SDL_Event e;
    while(game.IsRunning())
    {
        game.PollEvents(&e);
        game.Clear();
    }
    return 0;
}
