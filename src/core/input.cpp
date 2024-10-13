#include "../include/input.h"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

bool InputHandler::getkey(int key)
{
	const Uint8* Keys = getKeys();
	return Keys[key];
}

const Uint8* InputHandler::getKeys()
{
	return SDL_GetKeyboardState(NULL);
}
