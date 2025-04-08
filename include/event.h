#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL.h>
#include "game_state.h"
#include "game_resources.h"

void handleEvents(SDL_Event& event, GameState& gameState, const GameResources& resources);

#endif
