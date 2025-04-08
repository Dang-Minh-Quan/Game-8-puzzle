#ifndef GAME_STATE_H
#define GAME_STATE_H

struct GameState
{
    bool quit;
    bool isGamePlay;
    bool gameComplete;
    bool buttonPlay;
    bool buttonExit;
    bool buttonPlayAgain;
    bool buttonExit2;
    bool randomBlock;
    bool keyPress;
    bool newGame;
    int blankPosition;
    int puzzleState[9]; //Trạng thái hiện tại
    int targetState[9]; //Trạng thái mục tiêu

    GameState();
};

#endif
