#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SDL.h>

int cansolve(int A[], int n);
void random(int A[], int B[]);
void Gameplay(bool &check, int *A, int *B, SDL_Event press, int &t, bool &keyPress);

#endif
