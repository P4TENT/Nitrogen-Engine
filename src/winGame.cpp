#include <SDL2/SDL.h>
#include <iostream>

#include "../include/winGame.h"
#include "gameCustom/textures.h"

InputHandler inputHandler;
Camera camera(1280, 720);

int frameCount = 0;
Uint32 lastTime = SDL_GetTicks();
int fps = 0;
const int FRAME_TIME = 1000 / 360;
char direction = 'N'; //N S E W


void clean()
{
    SDL_Quit();
}

void init(SDL_Renderer* renderer) {
    camera.set_bounds(0, 0, 1547, 1154); 
    Textures::st_Terrain.createTexture(renderer);
}

void update(SDL_Renderer* renderer) {
    Uint32 frameStart = SDL_GetTicks();

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0xAA, 0xFF, 0xFF, 0xFF);  // Background color
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xAA, 0xFF, 0xFF);


    // Move the camera based on input
    if (inputHandler.isKeyPressed(K_w)) { camera.move( 0,-1); direction = 'N'; }
    if (inputHandler.isKeyPressed(K_s)) { camera.move( 0, 1); direction = 'S'; }
    if (inputHandler.isKeyPressed(K_a)) { camera.move(-1, 0); direction = 'W'; }
    if (inputHandler.isKeyPressed(K_d)) { camera.move( 1, 0); direction = 'E'; }
    if (inputHandler.isKeyDown(SDL_SCANCODE_SPACE)) {
        if (direction == 'E') {
            camera.move(2, 0);
            camera.move(1, 0);
            camera.move(1, 0);
        }
        else if (direction == 'W') {
            camera.move(-2, 0);
            camera.move(-1, 0);
            camera.move(-1, 0);
        }
        else if (direction == 'N') {
            camera.move(0, -2);
            camera.move(0, -1);
            camera.move(0, -1);
        }
        else if (direction == 'S') {
            camera.move(0, 2);
            camera.move(0, 1);
            camera.move(0, 1);
        }
    }

    //// Apply camera to game objects
    //SDL_Rect cameraAdjustedPlayer = camera.apply_camera(Textures::st_Terrain.getInSpace());
    //SDL_Rect cameraAdjustedEnemy = camera.apply_camera(enemyRect);
    //SDL_Rect cameraAdjustedBackground = camera.apply_camera(backgroundRect);

    SDL_Rect st_Terrain = camera.apply_camera(Textures::st_Terrain.getInSpace());
    
    Textures::st_Terrain.render_specific(st_Terrain.x, st_Terrain.y);
    //Textures::st_Chef.render_specific(300, 300);

    // Present the rendered content to the screen
    SDL_RenderPresent(renderer);


    frameCount++;
    // Calculate and display FPS every second
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastTime >= 1000) { // If 1 second has passed
        fps = frameCount; // Update the FPS
        frameCount = 0; // Reset the frame count
        lastTime = currentTime; // Reset lastTime
        std::cout << fps << std::endl;
    }
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < FRAME_TIME) {
        SDL_Delay(FRAME_TIME - frameTime);
    }
}