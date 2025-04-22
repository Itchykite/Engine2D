#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

class Input
{
public:
    // --- Keyboard
    static std::unordered_map<SDL_Scancode, bool> keyHeld;

    // --- Mouse
    static std::unordered_map<Uint8, bool> mouseButtonHeld;
    static int mouseX;
    static int mouseY;

    static void update(const SDL_Event& event);

    static bool isKeyHeld(SDL_Scancode key);
    static bool isMouseButtonHeld(Uint8 button);
    static int getMouseX();
    static int getMouseY();
};
