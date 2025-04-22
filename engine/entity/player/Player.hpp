#pragma once

#include "../Entity.hpp"
#include "../../input/InputManager.hpp"

class Player : public Entity 
{
public:
    Player(int x, int y, int width, int height);

    void update() override;
    void render(Renderer* renderer) override;
};
