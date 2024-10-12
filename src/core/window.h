#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <string>
#include <functional>

class Window {
public:
    Window(const std::string& title, int width, int height);  // Constructor
    ~Window();  // Destructor

    SDL_Renderer* create_renderer();  // Create the renderer
    int fill(int color[3]);  // Fill the window with a specific color
    int fill_alpha(int color[3], int alpha);  // Fill the window with a specific color with alpha
    int mainloop(std::function<void()> on_render);
    std::string get_error_track();
    void set_track(const std::string& track);
    int display_track();
    int kill();

private:
    SDL_Window* window = nullptr;  // SDL window pointer
    SDL_Renderer* renderer;  // SDL renderer pointer
    int width, height;  // Window dimensions
    bool window_running = false;
    std::string error_track;

private:
    int set_inner_track(const std::string& track);
};

