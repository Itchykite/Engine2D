#pragma once

#include "../Entity.hpp"
#include "../../input/InputManager.hpp"

class Player : public Entity 
{
public:
    Player(int x, int y, int width, int height);

    void update() override;
    void render(Renderer* renderer) override;

    void setMovingLeft(bool moving) { movingLeft = moving; }
    void setMovingRight(bool moving) { movingRight = moving; }
    void setMovingUp(bool moving) { movingUp = moving; }
    void setMovingDown(bool moving) { movingDown = moving; }


private:
    int speed = 5;

    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;
};
