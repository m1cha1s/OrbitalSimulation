#ifndef ROCKET_H
#define ROCKET_H

#include <raylib.h>

typedef struct Rocket {
    Vector2 pos, vel, acc;
    float mass;
}Rocket;

int getAbsoluteX(float x);
int getAbsoluteY(float y);

float getAlpha(Vector2 pos);
Vector2 getGravityVector(Vector2 pos);


void DrawRocket(Rocket rkt);
void UpdateRocket(Rocket *rkt);

#endif