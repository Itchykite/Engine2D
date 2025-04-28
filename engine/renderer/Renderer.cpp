#include "Renderer.hpp"

Renderer::Renderer(SDL_Renderer* sdlRenderer) : renderer(sdlRenderer)
{
    // Constructor logic if needed
}

Renderer::~Renderer()
{
    // Destructor logic if needed
}

void Renderer::clearScreen()
{
    SDL_RenderClear(renderer); // Clear the screen with the current draw color
}

void Renderer::presentScreen()
{
    SDL_RenderPresent(renderer); // Update the screen with the drawn content
}

void Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a); // Set the draw color for rendering
}

void Renderer::drawRect(int x, int y, int width, int height)
{
    SDL_Rect rect = { x, y, width, height }; // Define the rectangle to draw
    SDL_RenderDrawRect(renderer, &rect); // Draw the rectangle on the renderer
}

void Renderer::drawCollisonRect(int x, int y, int width, int height)
{
    SDL_Rect rect = { x, y, width, height }; // Define the rectangle to draw
    SDL_RenderDrawRect(renderer, &rect); // Draw the rectangle on the renderer

    SDL_RenderDrawLine(renderer, x, y, x + width, y + height); // Line from left top to right bottom
    SDL_RenderDrawLine(renderer, x + width, y, x, y + height); // Line from right top to left bottom
}

void Renderer::renderText(const std::string& text, int x, int y, TTF_Font* font, SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color); // Render text to a surface
    if (surface == nullptr) 
    {
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // Create a texture from the surface
    if (texture == nullptr)
    {
        SDL_FreeSurface(surface); // Free the surface if texture creation fails
        return;
    }

    SDL_Rect dstRect = { x, y, surface->w, surface->h }; // Define the destination rectangle for rendering
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect); // Copy the texture to the renderer

    SDL_DestroyTexture(texture); // Destroy the texture after rendering
    SDL_FreeSurface(surface); // Free the surface after rendering
}
