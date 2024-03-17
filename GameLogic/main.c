/*
    Ejecutar
    1.-(g++ -Wall -I./include -L./lib main.c -o main -lraylib -lopengl32 -lgdi32 -lwinmm)
    2.-(.\main.exe)
*/
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "./src/menu.h"
#include "./src/Game.h"
#define TRUE 1
#define FALSE 0

int main(void)
{
    // Ventana Info--------------------------------------------------------------------------------------
    int screenWidth = 1280;
    int screenHeight = 720;
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------------------

    // Inits--------------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "SnakeCs");
    menuInit(screenWidth, screenHeight);
    //--------------------------------------------------------------------------------------------------

    // Variables----------------------------------------------------------------------------------------
    Font font = LoadFont("assets/fonts/BerlinSansFBDemiBold.ttf");
    int MenuPos;
    int bandMenu = TRUE;
    int bandGame = FALSE;
    int BandExit = FALSE;
    //--------------------------------------------------------------------------------------------------

    // Main game loop------------------------------------------------------------------------------------
    while (!WindowShouldClose() || BandExit == FALSE)
    {
        BeginDrawing();
        {
            MenuPos = fondo1(screenWidth, screenHeight, font);
            if (MenuPos == 1)
            {
                bandGame = TRUE;

            }
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
