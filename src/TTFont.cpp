#include "../../Lab5-part-7---Graphics-Core-2-main/include/TTFont.h"
#include "../../Lab5-part-7---Graphics-Core-2-main/include/Renderer.h"

TTFont::TTFont()
{
    m_font = nullptr;
    destRect = { };
}

void TTFont::Initialize(int _pointSize)
{
    // Initialize SDL TTF
    if (TTF_Init() < 0) {
        std::cerr << "Unable to initialize SDL TTF: " << TTF_GetError() << std::endl;
        return;
    }

    // Get the full path to the font file
    char fullPath[1024];
    _fullpath(fullPath, "./assets/Fonts/arial.ttf", 1024); // Make sure to adjust the path if needed
    std::cout << "Attempting to load font from: " << fullPath << std::endl;

    // Open the font with the specified point size
    m_font = TTF_OpenFont(fullPath, _pointSize);
    if (m_font == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    std::cout << "Font loaded successfully!" << std::endl;
}


void TTFont::Shutdown()
{
    TTF_Quit();
}

void TTFont::Write(SDL_Renderer* _renderer, const char* _text, SDL_Color _color, SDL_Point _pos)
{
    // Check if the font is loaded
    if (m_font == nullptr) {
        M_ASSERT(false, "Font is not loaded correctly.");
        return;
    }

    //SDL_Surface* surface;
    //surface = TTF_RenderUTF8_Blended(m_font, _text, _color);
    // Create the surface
    SDL_Surface* surface = TTF_RenderUTF8_Blended(m_font, _text, _color);
    if (surface == nullptr) {
        M_ASSERT(false, TTF_GetError()); // Print the error message
        return;
    }

    //SDL_Texture* texture;
    //texture = SDL_CreateTextureFromSurface(_renderer, surface);
    // Create the texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (texture == nullptr) {
        M_ASSERT(false, SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    // Set the destination rectangle
    SDL_Rect destRect{ _pos.x, _pos.y, surface->w, surface->h };

    // Render the texture
    M_ASSERT((SDL_RenderCopyEx(_renderer, texture, nullptr, &destRect, 0, nullptr, SDL_FLIP_NONE) >= 0),
        "Could not render texture");

    // Clean up
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
