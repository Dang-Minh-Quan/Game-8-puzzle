#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 800;

SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
Mix_Music* loadMusic(const char* file);
SDL_Renderer* createRenderer(SDL_Window* window);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer);
SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);

#endif
