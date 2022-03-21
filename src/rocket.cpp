#include "rocket.h"

#include <math.h>
#include <stdio.h>

#include "config.h"

int getAbsoluteX(float x) {
    return (W/10)*(x+5);
}

int getAbsoluteY(float y) {
    return (H/10)*(y+5);
}

Rocket::Rocket(float x , float y, float vx, float vy, float ax, float ay)
{
    pos = {x, y};
    vel = {vx, vy};
    acc = {ax, ay};
}

Rocket::~Rocket()
{
}

float Rocket::getAlpha() {
    return atan2f(pos.y, pos.x);
}

Vector2 Rocket::getGravityVector() {
    Vector2 revPos = {EarthX-pos.x, EarthY-pos.y};

    float alpha = getAlpha();

    Vector2 gVec = {-g * cosf(alpha), -g * sinf(alpha)};

    return gVec;
}

void Rocket::drawRocket() {
    DrawCircle(getAbsoluteX(pos.x), getAbsoluteY(pos.y), 5, RED);
}

void Rocket::updateRocket() {
    Vector2 gVec = getGravityVector();

    acc.x += gVec.x;
    acc.y += gVec.y;

    vel.x += acc.x * DT;
    vel.y += acc.y * DT;

    pos.x += vel.x * DT;
    pos.y += vel.y * DT;

    acc.x = 0;
    acc.y = 0;
}