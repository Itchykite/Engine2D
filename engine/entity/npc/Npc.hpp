#pragma once

#include "../Entity.hpp"

class Npc : public Entity
{
public:
    Npc(int x, int y, int width, int height);

    void update() override;
    void render(Renderer* renderer) override;
};
