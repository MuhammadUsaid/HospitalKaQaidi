#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
#include <time.h>

using namespace std;
int main(int argc, char* argv[])
{
    srand(time(NULL));
    /** Stuff To Limit Frame Rate **/
    const int FPS = 10;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    Game game("Hospital Ka Qaidi", 800, 600);
    while(game.isRunning())
    {
        frameStart = SDL_GetTicks();  //Calculate the milliseconds since the SDL starts
        game.HandleEvents();
        game.Update();
        game.Render();
        frameTime = SDL_GetTicks() - frameStart; //Calculate the difference between every instance
        /** Limiting Frame Rate To 60 FPS **/
        if(frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
