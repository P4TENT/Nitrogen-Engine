#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "Nitrogen.h"

void clean();
void init(SDL_Renderer* renderer);
void update(SDL_Renderer* renderer);