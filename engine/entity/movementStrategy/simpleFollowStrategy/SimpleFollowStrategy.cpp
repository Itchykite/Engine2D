#include "SimpleFollowStrategy.hpp"
#include "../../enemy/Enemy.hpp"
#include "../../player/Player.hpp"

void SimpleFollowStrategy::move(Enemy* enemy, Player* player)
{
    if (enemy == nullptr || player == nullptr)
    {
        return;
    }

    if (player->getX() > enemy->getX())
    {
        enemy->setX(enemy->getX() + enemy->getSpeed());
    }

    else if (player->getX() < enemy->getX())
    {
        enemy->setX(enemy->getX() - enemy->getSpeed());
    }

    if (player->getY() > enemy->getY())
    {
        enemy->setY(enemy->getY() + enemy->getSpeed());
    }
    
    else if (player->getY() < enemy->getY())
    {
        enemy->setY(enemy->getY() - enemy->getSpeed());
    }
}
