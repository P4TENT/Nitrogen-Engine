#include "../include/camera.h"

Camera::Camera(int width, int height)
{

}


Camera::~Camera()
{

}


void Camera::move(float dx, float dy)
{
    if (maxx > 0 && maxy > 0) {
        if ((dx + x) < maxx && dx > 0)         x += dx;
        else if ((dx + x) > minx && dx < 0)    x += dx;

        if ((dy + y) < maxy && dy > 0)         y += dy;
        else if((dy + y) > miny && dy < 0)     y += dy;
    }
    else {
        y += dy;
        x += dx;
    }
}


SDL_Rect Camera::get_camera_rect() 
{
    SDL_Rect cameraRect = { static_cast<int>(x), static_cast<int>(y), width, height };
    return cameraRect;
}


SDL_Rect Camera::apply_camera(const SDL_Rect& object)
{
    SDL_Rect result;
    result.x = object.x - static_cast<int>(x);
    result.y = object.y - static_cast<int>(y);
    result.w = object.w;
    result.h = object.h;
    return result;
}

bool Camera::set_bounds(int min_x, int min_y, int max_x, int max_y)
{
    minx = min_x;
    miny = min_y;
    if (max_y > 0 && max_x > 0) {
        maxx = max_x;
        maxy = max_y;
        return 0;
    }
    else {
        Output::error("The max_x and max_y arguments must be positive!");
        return 1;
    }
}
