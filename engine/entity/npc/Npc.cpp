#include "Npc.hpp"

Npc::Npc(int x, int y, int width, int height)
    :Entity(x, y, width, height)
{
    texture = nullptr;
}

void Npc::update()
{

}

void Npc::render(Renderer* renderer)
{
    Entity::render(renderer);
}
