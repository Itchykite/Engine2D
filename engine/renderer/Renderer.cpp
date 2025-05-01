#include "Renderer.hpp"

Renderer::Renderer(SDL_Renderer* sdlRenderer) : renderer(sdlRenderer)
{
    // Constructor logic if needed
}

Renderer::~Renderer()
{
    // Destructor logic if needed
}

void Renderer::setCamera(Camera* cam)
{
    camera = cam; // Set the camera for the renderer
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
    SDL_Rect rect = 
    {
            camera ? x - static_cast<int>(camera->x) : x,
            camera ? y - static_cast<int>(camera->y) : y, 
            width, 
            height 
    }; // Define the rectangle to draw
    SDL_RenderDrawRect(renderer, &rect); // Draw the rectangle on the renderer
}

void Renderer::drawCollisonRect(int x, int y, int width, int height)
{
    int drawX = camera ? x - static_cast<int>(camera->x) : x; // Adjust x position based on camera
    int drawY = camera ? y - static_cast<int>(camera->y) : y; // Adjust y position based on camera

    SDL_Rect rect = { drawX, drawY, width, height }; // Define the rectangle to draw
    SDL_RenderDrawRect(renderer, &rect); // Draw the rectangle on the renderer

    SDL_RenderDrawLine(renderer, drawX, drawY, drawX + width, drawY + height); // Line from left top to right bottom
    SDL_RenderDrawLine(renderer, drawX + width, drawY, drawX, drawY + height); // Line from right top to left bottom
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
