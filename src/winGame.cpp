#include <SDL2/SDL.h>
#include <iostream>

#include "Nitrogen.h"

#include "../include/input.h"

void init() {

}

void update(SDL_Renderer* renderer)
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0xAA, 0xFF, 0xFF, 0xFF);  // White background
    SDL_RenderClear(renderer);

    // Here you would typically render your game objects

    // Present the rendered content to the screen
    SDL_RenderPresent(renderer);
}