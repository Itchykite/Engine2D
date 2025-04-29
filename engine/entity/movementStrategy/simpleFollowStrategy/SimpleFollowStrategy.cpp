#include "SimpleFollowStrategy.hpp"
#include "../../enemy/Enemy.hpp"
#include "../../player/Player.hpp"

void SimpleFollowStrategy::move(Enemy* enemy, Player* player, float deltaTime)
{
    if (enemy == nullptr || player == nullptr)
    {
        return;
    }

    if (player->getX() > enemy->getX())
    {
        enemy->setX(enemy->getX() + enemy->getSpeed() * deltaTime * 1.75f);
    }
    else if (player->getX() < enemy->getX())
    {
        enemy->setX(enemy->getX() - enemy->getSpeed() * deltaTime);
    }

    // Ruch w osi Y
    if (player->getY() > enemy->getY())
    {
        enemy->setY(enemy->getY() + enemy->getSpeed() * deltaTime);
    }
    else if (player->getY() < enemy->getY())
    {
        enemy->setY(enemy->getY() - enemy->getSpeed() * deltaTime);
    }
}
