#include "include/game_resources.h"
#include "include/sdl_utils.h"

GameResources::GameResources(SDL_Renderer* renderer)
{
    blocks[0] = loadTexture("image/block 1.jpg", renderer);
    blocks[1] = loadTexture("image/block 2.jpg", renderer);
    blocks[2] = loadTexture("image/block 3.jpg", renderer);
    blocks[3] = loadTexture("image/block 4.jpg", renderer);
    blocks[4] = loadTexture("image/block 5.jpg", renderer);
    blocks[5] = loadTexture("image/block 6.jpg", renderer);
    blocks[6] = loadTexture("image/block 7.jpg", renderer);
    blocks[7] = loadTexture("image/block 8.jpg", renderer);
    lobbyBackground = loadTexture("image/lobby background.jpg", renderer);
    gamePlayBackground = loadTexture("image/Gameplay.jpg", renderer);
    endGameBackground = loadTexture("image/end game.jpg", renderer);
    gameWoodFrame = loadTexture("image/wood frame.jpg", renderer);

    hitboxPlay = {570, 470, 250, 100};
    hitboxExit = {570, 630, 250, 100};
    playAgainButton = {90, 710, 140, 65};
    exitGameButton = {-90 - 140 + SCREEN_WIDTH, 710, 140, 65};
    woodFrame1 = {80, 120, 540, 540};
    woodFrame2 = {-80 - 540 + SCREEN_WIDTH, 120, 540, 540};

    for (int i = 0; i <= 8; i++)
    {
        int d = i % 3;
        int t = i / 3;
        int blockWidth = 180 - 20;
        int blockHeight = 180 - 20;
        leftBlocks[i] = {80 + 30 + blockWidth * d, 120 + 30 + blockHeight * t, blockWidth, blockHeight};
        rightBlocks[i] = {-540 + SCREEN_WIDTH + 80 + 30 + blockWidth * d - blockWidth, 120 + 30 + blockHeight * t, blockWidth, blockHeight};
    }
}

GameResources::~GameResources()
{
    for (int i = 0; i < 8; ++i)
    {
        SDL_DestroyTexture(blocks[i]);
    }
    SDL_DestroyTexture(lobbyBackground);
    SDL_DestroyTexture(gamePlayBackground);
    SDL_DestroyTexture(endGameBackground);
    SDL_DestroyTexture(gameWoodFrame);
}
