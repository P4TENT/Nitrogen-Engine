/* * space_texture.cpp * *
 * space_texture.cpp is basically the same thing as texture.cpp but with more options
 */

#include "../include/space_texture.h"

SpaceTexture::SpaceTexture(const char* path)
    :Texture(path), path_(path), x_(0), y_(0), width_(0), height_(0)
{
    std::filesystem::path filePath = path_;

    if (std::filesystem::exists(filePath)) {
        // Load image using stb_image (returns raw pixel data)
        imageData_ = stbi_load(path_, &width_, &height_, &channels_, 4); // Force 4 channels (RGBA)
        if (imageData_ == nullptr) {
            std::string x = stbi_failure_reason();
            Output::error("Failed to load image: " + x);
            return;  // Early exit if loading fails
        }
    }
    else {
        Output::error("The given path does not exist!");
        return;
    }
}


SpaceTexture::~SpaceTexture() {}


bool SpaceTexture::createTexture(SDL_Renderer* renderer)
{
    mainRenderer_ = renderer;

    if (!imageData_) {
        Output::error("Image data is not loaded. Cannot create texture!");
        return 1;
    }

    // Create an SDL texture
    texture_ = SDL_CreateTexture(mainRenderer_, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width_, height_);
    if (texture_ == nullptr) {
        std::string new_tex_path = path_;
        Output::error("Unable to create texture from " + new_tex_path + "! SDL Error: " + SDL_GetError());
        return 1;  // Early exit if texture creation fails
    }

    // Update the texture with the image data
    SDL_UpdateTexture(texture_, NULL, imageData_, width_ * 4);  // 4 bytes per pixel (RGBA)

    // Set texture blending (optional if you need transparency)
    SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND);

    return 0;
}


void SpaceTexture::render()
{
    if (mainRenderer_ && texture_) {
        SDL_Rect dstRect;

        // If width and height are not provided, use the texture's actual size
        int texW, texH;
        SDL_QueryTexture(texture_, NULL, NULL, &texW, &texH);

        dstRect.x = x_;                          // X position to render the texture
        dstRect.y = y_;                          // Y position to render the texture
        dstRect.w = texW;  // Width: use texture width if not provided
        dstRect.h = texH; // Height: use texture height if not provided

        // Render the texture at the specified position and size
        SDL_RenderCopy(mainRenderer_, texture_, NULL, &dstRect);
    }
    else if (mainRenderer_) {
        Output::error("Texture is not set. Cannot render texture!");
    }
    else {
        Output::error("Renderer is not set. Cannot render texture!");
    }
}

void SpaceTexture::render_specific(int x, int y)
{
    if (mainRenderer_ && texture_) {
        SDL_Rect dstRect;

        // If width and height are not provided, use the texture's actual size
        int texW, texH;
        SDL_QueryTexture(texture_, NULL, NULL, &texW, &texH);

        dstRect.x = x;                          // X position to render the texture
        dstRect.y = y;                          // Y position to render the texture
        dstRect.w = texW;  // Width: use texture width if not provided
        dstRect.h = texH; // Height: use texture height if not provided

        // Render the texture at the specified position and size
        SDL_RenderCopy(mainRenderer_, texture_, NULL, &dstRect);
    }
    else if (mainRenderer_) {
        Output::error("Texture is not set. Cannot render texture!");
    }
    else {
        Output::error("Renderer is not set. Cannot render texture!");
    }
}


void SpaceTexture::render_i(SDL_Renderer* renderer)
{
    if (texture_) {
        SDL_Rect dstRect;

        // If width and height are not provided, use the texture's actual size
        int texW, texH;
        SDL_QueryTexture(texture_, NULL, NULL, &texW, &texH);

        dstRect.x = x_;                          // X position to render the texture
        dstRect.y = y_;                          // Y position to render the texture
        dstRect.w = texW;  // Width: use texture width if not provided
        dstRect.h = texH; // Height: use texture height if not provided

        // Render the texture at the specified position and size
        SDL_RenderCopy(renderer, texture_, NULL, &dstRect);
    }
    else {
        Output::error("Texture is not set. Cannot render texture!");
    }
}


void SpaceTexture::render_specific_i(SDL_Renderer* renderer, int x, int y)
{
    if (texture_) {
        SDL_Rect dstRect;

        // If width and height are not provided, use the texture's actual size
        int texW, texH;
        SDL_QueryTexture(texture_, NULL, NULL, &texW, &texH);

        dstRect.x = x;                          // X position to render the texture
        dstRect.y = y;                          // Y position to render the texture
        dstRect.w = texW;  // Width: use texture width if not provided
        dstRect.h = texH; // Height: use texture height if not provided

        // Render the texture at the specified position and size
        SDL_RenderCopy(renderer, texture_, NULL, &dstRect);
    }
    else {
        Output::error("Texture is not set. Cannot render texture!");
    }
}


SDL_Rect SpaceTexture::getInSpace()
{
    SDL_Rect rectInSpace = { x_, y_, width_, height_ };

    return rectInSpace;
}

void SpaceTexture::placeInSpace(int x, int y)
{
    x_ = x;
    y_ = y;
}

void SpaceTexture::modInSpace(int dx, int dy)
{
    x_ += dx;
    y_ += dy;
}

bool SpaceTexture::update(const char* path)
{
    path_ = path;
    std::filesystem::path filePath = path_;

    if (std::filesystem::exists(filePath)) {
        // Load image using stb_image (returns raw pixel data)
        imageData_ = stbi_load(path_, &width_, &height_, &channels_, 4); // Force 4 channels (RGBA)
        if (imageData_ == nullptr) {
            std::string x = stbi_failure_reason();
            Output::error("Failed to load image: " + x);
            return 1;  // Early exit if loading fails
        }
    }
    else {
        Output::error("The given path does not exist!");
        return 1;
    }

    if (!imageData_) {
        Output::error("Image data is not loaded. Cannot create texture!");
        return 1;
    }

    // Create an SDL texture
    texture_ = SDL_CreateTexture(mainRenderer_, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width_, height_);
    if (texture_ == nullptr) {
        std::string new_tex_path = path_;
        Output::error("Unable to create texture from " + new_tex_path + "! SDL Error: " + SDL_GetError());
        return 1;  // Early exit if texture creation fails
    }

    // Update the texture with the image data
    SDL_UpdateTexture(texture_, NULL, imageData_, width_ * 4);  // 4 bytes per pixel (RGBA)

    // Set texture blending (optional if you need transparency)
    SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND); 

    return 0;
}