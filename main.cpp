#include<iostream>
#include<map>
#include<ctime>
#include<SDL.h>
#include<SDL_image.h>
#include <SDL_mixer.h>
#include "include/sdl_utils.h"
#include "include/game_logic.h"
#include "include/render_utils.h"
#include "include/click.h"
#include "include/event.h"
//Hướng dẫn chơi:Sử dụng AWDS trong khi di chuyển ô số,dùng chuột để nhấn nút

using namespace std;

const char* WINDOW_TITLE = "8-puzzle";

int main(int argc, char *argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    Mix_Music* backgroundMusic = loadMusic("music/Background music.mp3");
    Mix_PlayMusic(backgroundMusic, -1);

    GameResources resources(renderer);
    GameState gameState;
    SDL_Event event;
    SDL_Event press;

    while (!gameState.quit)
    {
        while (SDL_PollEvent(&event))
        {
            handleEvents(event, gameState, resources);
            if (event.type == SDL_KEYDOWN && gameState.isGamePlay)
            {
                press = event;
            }
        }

        SDL_RenderClear(renderer);

        if (gameState.isGamePlay)
        {
            if (resources.gamePlayBackground)
            {
                SDL_Delay(100);
                SDL_RenderCopy(renderer, resources.gamePlayBackground, nullptr, nullptr);
                SDL_RenderCopy(renderer, resources.gameWoodFrame, nullptr, &resources.woodFrame1);
                SDL_RenderCopy(renderer, resources.gameWoodFrame, nullptr, &resources.woodFrame2);
                bool WinCheck = true;
                if (gameState.randomBlock || gameState.newGame)
                {
                    gameState.blankPosition = 9;
                    random(gameState.puzzleState, gameState.targetState);
                    gameState.randomBlock = false;
                    gameState.newGame = false;
                }
                else
                {
                    if (gameState.keyPress)
                    {
                        Gameplay(WinCheck, gameState.puzzleState, gameState.targetState, press, gameState.blankPosition, gameState.keyPress);
                        renderBlock(resources.blocks, resources.leftBlocks, resources.rightBlocks, renderer, gameState.puzzleState, gameState.targetState);
                        if (WinCheck)
                        {
                            gameState.isGamePlay = false;
                            gameState.gameComplete = true;
                        }
                    }
                    else
                    {
                        renderBlock(resources.blocks, resources.leftBlocks, resources.rightBlocks, renderer, gameState.puzzleState, gameState.targetState);
                    }
                }
            }
        }
        else if (!gameState.isGamePlay && gameState.gameComplete)
        {
            SDL_Delay(500);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, resources.endGameBackground, nullptr, nullptr);
            gameState.buttonPlay = true;
            gameState.buttonExit = true;
        }
        else
        {
            SDL_RenderCopy(renderer, resources.lobbyBackground, nullptr, nullptr);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    return 0;
}

