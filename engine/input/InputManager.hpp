#pragma once 

#include <SDL2/SDL.h>
#include <unordered_map>

class Input 
{
public:
    static void update(const SDL_Event& event);

    static bool isKeyPressed(SDL_Keycode key);
    static bool isMouseButtonPressed(Uint8 button);
    static int getMouseX();
    static int getMouseY();

private:
    static std::unordered_map<SDL_Keycode, bool> keyState;
    static std::unordered_map<Uint8, bool> mouseButtonState;
    static int mouseX, mouseY;
};
