/*
    Ejecutar
    1.-(g++ -Wall -I./include -L./lib main.c -o main -lraylib -lopengl32 -lgdi32 -lwinmm)
    2.-(.\main.exe)
*/
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "./src/logic.h"
#include "./src/snake.h"

#define TRUE 1
#define FALSE 0

int main()
{
    // Ventana Info--------------------------------------------------------------------------------------
    int screenWidth = 1250;
    int screenHeight = 700;
    SetTargetFPS(60);

    // Inits--------------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "SnakeCs");


    // Variables----------------------------------------------------------------------------------------s
    Font font = LoadFont("assets/fonts/BerlinSansFBDemiBold.ttf");
    
    int celsize= 50;//Grid tamaño
    int celxcount=screenWidth/50;//Grid cantidad x
    int celycount=screenHeight/50;//Grid cantidad y

    struct Manzana apple;
    apple.Fpos=spawnfood(celxcount,celycount);

    int bandTime=FALSE;

    //Snake
    struct Nodo *snake=(struct Nodo*)malloc(sizeof(struct Nodo));
    snake->pos.x=celsize*2;
    snake->pos.y=celsize*(celycount/2);
    snake->next=NULL;
    
    int SbandR=TRUE;
    int SbandL=FALSE;
    int SbandU=FALSE;
    int SbandD=FALSE;
    

    // Main game loop------------------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(ORANGE);
            //Grid------------------------------------------------
                for (int x = 0; x < screenWidth; x += celsize) 
                {
                    DrawLine(x, 0, x, screenHeight, LIGHTGRAY);
                }
                for (int y = 0; y < screenHeight; y += celsize) 
                {
                    DrawLine(0, y, screenWidth, y, LIGHTGRAY);
                }
            //-----------------------------------------------------
            drawSnakeP(snake);
            drawFood(apple);

            if((bandTime=movSmooth(0.5))==TRUE)
            {
                if(SbandR==TRUE)
                {
                    snake->pos=moveR(snake->pos);
                }
                else
                {
                    if(SbandL==TRUE)
                    {
                        snake->pos=moveL(snake->pos);
                    }
                    else
                    {
                        if(SbandU==TRUE)
                        {
                            snake->pos=moveU(snake->pos);
                        }
                        else
                        {
                            if(SbandD==TRUE)
                            {
                                snake->pos=moveD(snake->pos);

                            }
                        }
                    }
                }
            }

            if(IsKeyPressed(KEY_D))
            {
                SbandR=TRUE;
                SbandL=FALSE;
                SbandU=FALSE;
                SbandD=FALSE;
                
                snake->pos=moveR(snake->pos);
            }
            if(IsKeyPressed(KEY_A))
            {
                SbandL=TRUE;
                SbandR=FALSE;
                SbandU=FALSE;
                SbandD=FALSE;

                snake->pos=moveL(snake->pos);
            }
            if(IsKeyPressed(KEY_S))
            {
                SbandD=TRUE;
                SbandL=FALSE;
                SbandR=FALSE;
                SbandU=FALSE;

                snake->pos=moveD(snake->pos);
            }
            if(IsKeyPressed(KEY_W))
            {
                SbandU=TRUE;
                SbandL=FALSE;
                SbandR=FALSE;
                SbandD=FALSE;
                snake->pos=moveU(snake->pos);
            }

            if(IsKeyPressed(KEY_SPACE))
            {
                apple.Fpos=spawnfood(celxcount,celycount);
                add(&snake);
            }
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
