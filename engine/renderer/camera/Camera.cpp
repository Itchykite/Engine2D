#include "Camera.hpp"

Camera::Camera(float w, float h) : x(0), y(0), width(w), height(w), worldWidth(5000), worldHeight(2000) 
{

}

Camera::~Camera()
{

}

void Camera::follow(float targetX, float targetY)
{
    x = targetX - width / 2;
    y = targetY / 2;
}

void Camera::clampToWorld(float worldWidth, float worldHeight)
{
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x + width > worldWidth) x = worldWidth - width;
    if (y + height > worldHeight) y = worldHeight - height;
}
