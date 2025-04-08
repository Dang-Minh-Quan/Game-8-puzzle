#include "include/event.h"
#include "include/game_logic.h"
#include "include/click.h"
#include <iostream>
#include <SDL_mixer.h>

using namespace std;

void handleEvents(SDL_Event& event, GameState& gameState, const GameResources& resources)
{
    if (event.type == SDL_QUIT)
    {
        gameState.quit = true;
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            Mix_Chunk* ClickMusic = Mix_LoadWAV("music/Button Click.wav");
            if (ClickButton(resources.hitboxPlay.x, resources.hitboxPlay.y, resources.hitboxPlay.w, resources.hitboxPlay.h, mouseX, mouseY, gameState.buttonPlay))
            {
                Mix_PlayChannel(-1, ClickMusic, 0);
                gameState.isGamePlay = true;
                gameState.buttonPlay = false;
                gameState.buttonExit = false;
                gameState.randomBlock = true;
                gameState.buttonPlayAgain = true;
                gameState.buttonExit2 = true;
            }
            else if (ClickButton(resources.hitboxExit.x, resources.hitboxExit.y, resources.hitboxExit.w, resources.hitboxExit.h, mouseX, mouseY, gameState.buttonExit))
            {
                Mix_PlayChannel(-1, ClickMusic, 0);
                gameState.quit = true;
            }
            else if (gameState.isGamePlay && ClickButton(resources.playAgainButton.x, resources.playAgainButton.y, resources.playAgainButton.w, resources.playAgainButton.h, mouseX, mouseY, gameState.buttonPlayAgain))
            {
                Mix_PlayChannel(-1, ClickMusic, 0);
                gameState.newGame = true;
            }
            else if (gameState.isGamePlay && ClickButton(resources.exitGameButton.x, resources.exitGameButton.y, resources.exitGameButton.w, resources.exitGameButton.h, mouseX, mouseY, gameState.buttonExit2))
            {
                Mix_PlayChannel(-1, ClickMusic, 0);
                gameState.quit = true;
            }
        }
    }
    else if (event.type == SDL_KEYDOWN && gameState.isGamePlay)
    {
        gameState.keyPress = true;
    }
}
