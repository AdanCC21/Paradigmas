/*
    Ejecutar
    1.-(g++ -Wall -I./include -L./lib main.c -o main -lraylib -lopengl32 -lgdi32 -lwinmm)
    2.-(.\main.exe)
*/
#include <stdio.h>
#include "raylib.h"
#include "./src/menu.h"

int main(void)
{
    //Ventana Info--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetTargetFPS(60);
    
    InitWindow(screenWidth, screenHeight, "SnakeCs");
    
    // Variables--------------------------------------------------------------------------------------
    Font font =LoadFont("assets/fonts/BerlinSansFBDemiBold.ttf");

    //------------------------------------------------------------------------------------------------


    //Main game loop-----------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
        // Draw----------------------------------------------------------------------------------
        fondo1(screenWidth,screenHeight,font);
        //---------------------------------------------------------------------------------------
    }

    CloseWindow();

    return 0;
}
