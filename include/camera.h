#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <tuple>
#include "output.h"

class Camera {
public:
	int x, y;

public:
	Camera(int width, int height);
	~Camera();
	void move(float dx, float dy);
	SDL_Rect get_camera_rect();
	SDL_Rect apply_camera(const SDL_Rect& object);
	bool set_bounds(int minx, int miny, int maxx, int maxy);

private:
	int width, height;
	int minx = 0, miny = 0, maxx = 0, maxy = 0;
};