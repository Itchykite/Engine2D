#pragma once

#include "../Entity.hpp"
#include "../../input/InputManager.hpp"

class Player : public Entity 
{
public:
    Player(int x, int y, int width, int height);

    void update() override;
    void render(Renderer* renderer) override;
    void applyGravity() override;

    void setMovingLeft(bool moving) { movingLeft = moving; }
    void setMovingRight(bool moving) { movingRight = moving; }
    void jump();

private:
    int speed;
    int jumpForce;

    bool movingLeft = false;
    bool movingRight = false;
};
