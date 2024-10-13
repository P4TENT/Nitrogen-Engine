#include <SDL2/SDL.h>
#include "../src/core/coreConfig/keys.h"

class InputHandler {
public:
	InputHandler();
	~InputHandler();
	bool getkey(int key);
private:
	const Uint8* getKeys();
};