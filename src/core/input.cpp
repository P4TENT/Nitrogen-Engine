#include "../include/input.h"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

bool InputHandler::isKeyPressed(int key)
{
	const Uint8* Keys = getKeys();
	return Keys[key];
}

bool InputHandler::isKeyDown(int key)
{
    if (e.type == SDL_KEYDOWN) 
        if (e.key.keysym.sym == key) return true;      
    return false;
}

const Uint8* InputHandler::getKeys()
{
	return SDL_GetKeyboardState(NULL);
}
