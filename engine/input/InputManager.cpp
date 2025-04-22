#include "InputManager.hpp"

// --- Keyboard
std::unordered_map<SDL_Scancode, bool> Input::keyHeld;

// --- Mouse
std::unordered_map<Uint8, bool> Input::mouseButtonHeld;
int Input::mouseX = 0;
int Input::mouseY = 0;

void Input::update(const SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            Input::keyHeld[event.key.keysym.scancode] = true;
            break;

        case SDL_KEYUP:
            Input::keyHeld[event.key.keysym.scancode] = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            Input::mouseButtonHeld[event.button.button] = true;
            break;

        case SDL_MOUSEBUTTONUP:
            Input::mouseButtonHeld[event.button.button] = false;
            break;

        case SDL_MOUSEMOTION:
            Input::mouseX = event.motion.x;
            Input::mouseY = event.motion.y;
            break;

        default:
            break;
    }
}

bool Input::isKeyHeld(SDL_Scancode key)
{
    return Input::keyHeld[key];
}

bool Input::isMouseButtonHeld(Uint8 button)
{
    return Input::mouseButtonHeld[button];
}

int Input::getMouseX()
{
    return Input::mouseX;
}

int Input::getMouseY()
{
    return Input::mouseY;
}
