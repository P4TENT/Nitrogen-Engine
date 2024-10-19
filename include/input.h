#pragma once

#include <SDL2/SDL.h>
#include "../src/core/coreConfig/keys.h"
#include <iostream>

class InputHandler {
public:
	InputHandler();
	~InputHandler();
	bool isKeyPressed(int key);
	bool isKeyDown(int key);
private:
	const Uint8* getKeys();
	SDL_Event e;
};