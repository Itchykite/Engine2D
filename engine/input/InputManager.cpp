#include "InputManager.hpp"

std::unordered_map<SDL_Keycode, bool> Input::keyState;
std::unordered_map<Uint8, bool> Input::mouseButtonState;
int Input::mouseX = 0;
int Input::mouseY = 0;

void Input::update(const SDL_Event& event) 
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            keyState[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            keyState[event.key.keysym.sym] = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouseButtonState[event.button.button] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseButtonState[event.button.button] = false;
            break;
        case SDL_MOUSEMOTION:
            mouseX = event.motion.x;
            mouseY = event.motion.y;
            break;
    }
}

bool Input::isKeyPressed(SDL_Keycode key) 
{
    return keyState[key];
}

bool Input::isMouseButtonPressed(Uint8 button) 
{
    return mouseButtonState[button];
}

int Input::getMouseX() 
{
    return mouseX;
}

int Input::getMouseY() 
{
    return mouseY;
}
