#include "Camera.hpp"

Camera::Camera(float w, float h) : x(0), y(0), width(w), height(h), worldWidth(5000), worldHeight(2000) 
{

}

Camera::~Camera()
{

}

void Camera::follow(float targetX, float targetY)
{
    x = targetX - width / 2;
    y = targetY / 4;
}

void Camera::clampToWorld(float worldWidth, float worldHeight, float GROUND_LEVEL, float TOP_LEVEL)
{
    if (x < 0) x = 0;
    if (x + width > worldWidth) x = worldWidth - width;

    if (y < TOP_LEVEL) y = TOP_LEVEL;
    if (y + height > GROUND_LEVEL) y = GROUND_LEVEL - height + 20;
}

