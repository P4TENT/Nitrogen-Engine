#pragma once

#include "../thirdparty/stb_image/include/stb_image/stb_image.h"
#include <SDL2/SDL.h>
#include <filesystem>
#include "output.h"

class Texture {
public:
	int tex_width, tex_height;

public:
	Texture(const char* path);
	~Texture();
	bool createTexture(SDL_Renderer* renderer);
	void render(int x, int y); // it renders the texture on the mainRenderer
	void render_i(SDL_Renderer* renderer, int x, int y); // _i stands for independent because it renders on the specified renderer

private:
	const char* tex_path;
	SDL_Renderer* tex_mainRenderer;
	int tex_channels;
	SDL_Texture* tex_Texture;
	unsigned char* tex_imageData;
};