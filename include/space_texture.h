/* * space_texture.h * *
 * space_texture.h is basically the same thing as texture.h but with more options
 */

#pragma once

#include "../thirdparty/stb_image/include/stb_image/stb_image.h"
#include <SDL2/SDL.h>
#include <filesystem>
#include "output.h"
#include "texture.h"

class SpaceTexture : public Texture {
public:
    // Additional members for SpaceTexture
    int x_, y_, width_, height_;  // Position and size of the texture in space

public:
    // Constructor that calls the base Texture constructor
    SpaceTexture(const char* path);
    // Destructor
    ~SpaceTexture();
    // Override the createTexture function (if you need to extend functionality)
    bool createTexture(SDL_Renderer* renderer);
    // New methods for SpaceTexture-specific functionality
    void render();
    void render_specific(int x, int y);
    void render_i(SDL_Renderer* renderer);
    void render_specific_i(SDL_Renderer* renderer, int x, int y);
    // Space-specific operations
    SDL_Rect getInSpace();
    void placeInSpace(int x, int y);
    void modInSpace(int dx, int dy);
    // Additional method to update the texture with a new path
    bool update(const char* newPath);

private:
    SDL_Texture* texture_;
    unsigned char* imageData_;
    const char* path_;
    int channels_;
    SDL_Renderer* mainRenderer_;
};
