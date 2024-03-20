/*
    Ejecutar
    1.-(g++ -Wall -I./include -L./lib main.c -o main -lraylib -lopengl32 -lgdi32 -lwinmm)
    2.-(.\main.exe)
*/
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "./src/menu.h"
#include "./src/snake.h"
#include "./src/apple.h"

#define TRUE 1
#define FALSE 0
#define CELSIZE 50//Luego lo modifico-------------------------------------


int main()
{
    // Ventana Info--------------------------------------------------------------------------------------
    int screenWidth = 1250;
    int screenHeight = 700;
    SetTargetFPS(60);

    // Inits--------------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "SnakeCs");
    initImage(screenWidth, screenHeight);
    // Variables----------------------------------------------------------------------------------------s
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
    
    //Banderas de direccion
    int SbandR=TRUE;
    int SbandL=FALSE;
    int SbandU=FALSE;
    int SbandD=FALSE;

    //banderas de inicio
    int menu = 0;
    bool game = true;
    bool over = false;
    

    // Main game loop------------------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            if(menu==0)
            {
                menu=drawMenu();
            }
            
            if(menu==1)
            {
                do{

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

                    {
                        //Manzana
                        if(snake->pos.x==apple.Fpos.x)
                        {
                            if(snake->pos.y==apple.Fpos.y)
                            {
                                apple.Fpos=spawnfood(celxcount,celycount);
                                add(&snake);
                            }
                        }
                        
                        //Movimiento
                        if((bandTime=movSmooth(0.5))==TRUE)
                        {
                            if(SbandR==TRUE)
                            {
                                moveHeadR(&snake);
                                // genMoveR(&snake);
                            }
                            else
                            {
                                if(SbandL==TRUE)
                                {
                                    moveHeadL(&snake);
                                }
                                else
                                {
                                    if(SbandU==TRUE)
                                    {
                                        // genMoveU(&snake);
                                        moveHeadU(&snake);
                                    }
                                    else
                                    {
                                        if(SbandD==TRUE)
                                        {
                                            moveHeadD(&snake);
                                        }
                                    }
                                }
                            }
                        }

                        //debugeo
                        {
                            if(IsKeyPressed(KEY_D))
                            {
                                SbandR=TRUE;
                                SbandL=FALSE;
                                SbandU=FALSE;
                                SbandD=FALSE;
                                
                                moveHeadR(&snake);
                                // genMoveR(&snake);
                            }
                            if(IsKeyPressed(KEY_A))
                            {
                                SbandL=TRUE;
                                SbandR=FALSE;
                                SbandU=FALSE;
                                SbandD=FALSE;

                                moveHeadL(&snake);
                            }
                            if(IsKeyPressed(KEY_S))
                            {
                                SbandD=TRUE;
                                SbandL=FALSE;
                                SbandR=FALSE;
                                SbandU=FALSE;

                                moveHeadD(&snake);
                            }
                            if(IsKeyPressed(KEY_W))
                            {
                                SbandU=TRUE;
                                SbandL=FALSE;
                                SbandR=FALSE;
                                SbandD=FALSE;
                                // genMoveU(&snake);
                                moveHeadU(&snake);
                            }

                            if(IsKeyPressed(KEY_SPACE))
                            {
                                apple.Fpos=spawnfood(celxcount,celycount);
                                add(&snake);
                            }
                        }

                        snake->lastpos.x=snake->pos.x;
                        snake->lastpos.y=snake->pos.y;
                    }
                }while(game==true);
            }
            else
            {
                if(menu==2)
                {
                    printf("\nADIOOOOS\n");
                    break;
                }
            }
            
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
