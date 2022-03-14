#include "rocket.h"

#include "config.h"

int getAbsoluteX(float x) {
    return (W/10)*(x+5);
}

int getAbsoluteY(float y) {
    return (H/10)*(y+5);
}

float getAlpha(Vector2 pos) {
    return atan2f(pos.y, pos.x);
}

Vector2 getGravityVector(Vector2 pos) {
    Vector2 revPos = {EarthX-pos.x, EarthY-pos.y};

    float alpha = getAlpha(revPos);

    Vector2 gVec = {g * cosf(alpha), g * sinf(alpha)};

    return gVec;
}

void DrawRocket(Rocket rkt) {
    DrawCircle(getAbsoluteX(rkt.pos.x), getAbsoluteY(rkt.pos.y), 5, RED);
}

void UpdateRocket(Rocket *rkt) {
    Vector2 gVec = getGravityVector(rkt->pos);

    rkt->acc.x += gVec.x;
    rkt->acc.y += gVec.y;

    rkt->vel.x += rkt->acc.x * DT;
    rkt->vel.y += rkt->acc.y * DT;

    rkt->pos.x += rkt->vel.x * DT;
    rkt->pos.y += rkt->vel.y * DT;

    rkt->acc.x = 0;
    rkt->acc.y = 0;
}