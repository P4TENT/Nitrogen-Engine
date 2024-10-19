#define STB_IMAGE_IMPLEMENTATION
#include "../include/texture.h"

Texture::Texture(const char* path)
    : tex_path(path), tex_imageData(nullptr), tex_Texture(nullptr), tex_width(0), tex_height(0), tex_channels(0), tex_mainRenderer(nullptr)
{
    std::filesystem::path filePath = tex_path;

    if (std::filesystem::exists(filePath)) {
        // Load image using stb_image (returns raw pixel data)
        tex_imageData = stbi_load(tex_path, &tex_width, &tex_height, &tex_channels, 4); // Force 4 channels (RGBA)
        if (tex_imageData == nullptr) {
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

Texture::~Texture()
{
    if (tex_imageData) {
        stbi_image_free(tex_imageData); // Free image data
    }
    if (tex_Texture) {
        SDL_DestroyTexture(tex_Texture); // Destroy SDL texture
    }
}

bool Texture::createTexture(SDL_Renderer* renderer)
{
    if (!tex_imageData) {
        Output::error("Image data is not loaded. Cannot create texture!");
        return 1;
    }

    // Create an SDL texture
    tex_Texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, tex_width, tex_height);
    if (tex_Texture == nullptr) {
        std::string new_tex_path = tex_path;
        Output::error("Unable to create texture from " + new_tex_path + "! SDL Error: " + SDL_GetError());
        return 1;  // Early exit if texture creation fails
    }

    // Update the texture with the image data
    SDL_UpdateTexture(tex_Texture, NULL, tex_imageData, tex_width * 4);  // 4 bytes per pixel (RGBA)

    // Set texture blending (optional if you need transparency)
    SDL_SetTextureBlendMode(tex_Texture, SDL_BLENDMODE_BLEND);

    tex_mainRenderer = renderer;

    return 0;
}

void Texture::render(int x = 0, int y = 0)
{
    if (tex_mainRenderer && tex_Texture) {
        SDL_Rect dstRect;

        // If width and height are not provided, use the texture's actual size
        int texW, texH;
        SDL_QueryTexture(tex_Texture, NULL, NULL, &texW, &texH);

        dstRect.x = x;                          // X position to render the texture
        dstRect.y = y;                          // Y position to render the texture
        dstRect.w = texW;  // Width: use texture width if not provided
        dstRect.h = texH; // Height: use texture height if not provided

        // Render the texture at the specified position and size
        SDL_RenderCopy(tex_mainRenderer, tex_Texture, NULL, &dstRect);
    }
    else if (tex_mainRenderer) {
        Output::error("Texture is not set. Cannot render texture!");
    }
    else {
        Output::error("Renderer is not set. Cannot render texture!");
    }
}


void Texture::render_i(SDL_Renderer* renderer, int x, int y)
{
    if (tex_Texture) {
        SDL_Rect dstRect;

        // If width and height are not provided, use the texture's actual size
        int texW, texH;
        SDL_QueryTexture(tex_Texture, NULL, NULL, &texW, &texH);

        dstRect.x = x;                          // X position to render the texture
        dstRect.y = y;                          // Y position to render the texture
        dstRect.w = texW;  // Width: use texture width if not provided
        dstRect.h = texH; // Height: use texture height if not provided

        // Render the texture at the specified position and size
        SDL_RenderCopy(renderer, tex_Texture, NULL, &dstRect);
    }
    else {
        Output::error("Texture is not set. Cannot render texture!");
    }
}