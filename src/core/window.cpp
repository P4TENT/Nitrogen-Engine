#include "window.h"
#include "defs.h"

#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer.h"
#include "imguiThemes.h"

Window::Window(const std::string& title, int width, int height)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        throw std::runtime_error("SDL initialization failed");
    }

    // Create the window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (!window) {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        throw std::runtime_error("Failed to create window");
    }

    window_running = true;
}
Window::~Window()
{
    // Clean up SDL resources
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}


SDL_Renderer* Window::create_renderer()
{
    // Create the renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        throw std::runtime_error("Failed to create renderer");
    }

    return renderer;
}


int Window::fill(int color[3])
{
    if (renderer) {
        SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
        return NITRO_SUCCESS;
    }
    else
        return NITRO_FAIL;
}


int Window::fill_alpha(int color[3], int alpha)
{
    if (!renderer)
    {
        set_inner_track("You Haven't Defined a Renderer!");
        return NITRO_FAIL;
    }
    else if (alpha > 255 || alpha < 0)
    {
        set_inner_track("{alpha} Value Is Not Correct ({alpha} can be from 0 to 255)!");
        return NITRO_FAIL;
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], alpha);
        return NITRO_SUCCESS;
    }
}


void Window::set_track(const std::string& track)
{
    error_track = MAGENTA + "|" + BLUE + "[CUSTOM-TRACK] " + RESET + track + MAGENTA + " |" + RESET;
}


int Window::set_inner_track(const std::string& track)
{
    error_track = MAGENTA + "|" + CYAN + "[NITRO-TRACK] " + RESET + track + MAGENTA + " |" + RESET;
    return display_track();
}


int Window::display_track()
{
    if (error_track != "") {
        std::cout << error_track << std::endl;
        error_track = "";
    }
    return NITRO_SUCCESS;
}

int Window::kill()
{
    window_running = false;
    return NITRO_SUCCESS;
}

std::string Window::get_error_track()
{
    return error_track;
}

int Window::mainloop(std::function<void()> on_render) {
    if (window_running) {
        while (window_running) {
            if (on_render) {
                on_render();
            }
        }
        return NITRO_SUCCESS;
    }
    return NITRO_FAIL;
}