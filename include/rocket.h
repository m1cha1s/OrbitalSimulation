#ifndef ROCKET_H
#define ROCKET_H

#include <raylib.h>

int getAbsoluteX(float x);
int getAbsoluteY(float y);

class Rocket
{
public:
    Vector2 pos, vel, acc;
    float mass;

    Rocket(float x , float y, float vx, float vy, float ax, float ay);
    ~Rocket();

    float getAlpha();
    Vector2 getGravityVector();


    void drawRocket();
    void updateRocket();
};

#endif