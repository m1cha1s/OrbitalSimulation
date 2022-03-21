#include <stdio.h>
#include <raylib.h>
#include <math.h>

#include "config.h"
#include "rocket.h"


int main() {

    Rocket rkt(0, 3, -5, 0, 0, 0);

    InitWindow(W, H, "Orbital simulation");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        rkt.updateRocket();

        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircle(getAbsoluteX(EarthX), getAbsoluteY(EarthY), 50, WHITE);
        rkt.drawRocket();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}