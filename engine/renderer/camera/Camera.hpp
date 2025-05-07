#pragma once

class Camera
{
public:
    float x, y;
    float width, height;
    float worldWidth, worldHeight;
 
    Camera(float w, float h);
    ~Camera();

    void follow(float targetX, float targetY);
    void clampToWorld(float worldWidth, float worldHeight, float GROUND_LEVEL, float TOP_LEVEL);

    float getX() const { return x; }
    float getY() const { return y; }
};
