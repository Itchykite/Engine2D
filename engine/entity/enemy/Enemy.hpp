#pragma once

#include "../Entity.hpp"

class Enemy : public Entity 
{
public:
    Enemy(int x, int y, int width, int height);

    void update() override;
    void render(Renderer* renderer) override;
};
