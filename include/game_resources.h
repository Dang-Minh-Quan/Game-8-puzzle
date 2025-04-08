#ifndef GAME_RESOURCES_H
#define GAME_RESOURCES_H

#include <SDL.h>

struct GameResources
{
    SDL_Texture* blocks[8];
    SDL_Texture* lobbyBackground;
    SDL_Texture* gamePlayBackground;
    SDL_Texture* endGameBackground;
    SDL_Texture* gameWoodFrame;

    SDL_Rect leftBlocks[9];
    SDL_Rect rightBlocks[9];
    SDL_Rect hitboxPlay;
    SDL_Rect hitboxExit;
    SDL_Rect playAgainButton;
    SDL_Rect exitGameButton;
    SDL_Rect woodFrame1;
    SDL_Rect woodFrame2;

    GameResources(SDL_Renderer* renderer);
    ~GameResources();
};

#endif
