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

    //Manzana
    struct Manzana apple;
    apple.Fpos=spawnfood(&snake,celxcount,celycount);

    //banderas de inicio
    int menu = 0;
    bool game = true;
    bool over = false;

    bool bandColi =false;
    

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
                //Reinicio
                game=true;
                snake->pos.x=celsize*2;
                snake->pos.y=celsize*(celycount/2);
                snake->next=NULL;

                int SbandR=TRUE;
                int SbandL=FALSE;
                int SbandU=FALSE;
                int SbandD=FALSE;
                
                do
                {
                    BeginDrawing();
                    {

                        DrawTextureEx(fondo.text,fondo.pos,0.0f,1.0f,WHITE);
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

                        

                        //Movimiento
                        if((bandTime=movSmooth(0.3))==TRUE)
                        {
                            if(SbandR==TRUE)
                            {
                                moveHeadR(&snake);
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

                        {
                            if(IsKeyPressed(KEY_D))
                            {
                                if(SbandL==TRUE)
                                {}
                                else
                                {
                                    SbandR=TRUE;
                                    SbandL=FALSE;
                                    SbandU=FALSE;
                                    SbandD=FALSE;
                                    moveHeadR(&snake);
                                }
                            }
                            if(IsKeyPressed(KEY_A))
                            {
                                if(SbandR==TRUE)
                                {}
                                else
                                {
                                    SbandL=TRUE;
                                    SbandR=FALSE;
                                    SbandU=FALSE;
                                    SbandD=FALSE;
                                    moveHeadL(&snake);
                                }
                            }
                            if(IsKeyPressed(KEY_S))
                            {
                                if(SbandU==TRUE)
                                {}
                                else
                                {
                                    SbandD=TRUE;
                                    SbandL=FALSE;
                                    SbandR=FALSE;
                                    SbandU=FALSE;
                                    moveHeadD(&snake);
                                }
                            }
                            if(IsKeyPressed(KEY_W))
                            {
                                if(SbandD==TRUE)
                                {}
                                else
                                {
                                    SbandU=TRUE;
                                    SbandL=FALSE;
                                    SbandR=FALSE;
                                    SbandD=FALSE;
                                    moveHeadU(&snake);
                                }
                            }
                            if(IsKeyPressed(KEY_SPACE))
                            {
                                // apple.Fpos=spawnfood(&snake,celxcount,celycount);
                                add(&snake);
                            }
                        }

                        //Manzana
                        if(snake->pos.x==apple.Fpos.x)
                        {
                            if(snake->pos.y==apple.Fpos.y)
                            {
                                apple.Fpos=spawnfood(&snake,celxcount,celycount);
                                add(&snake);
                            }
                        }
                        
                        // Colisiones
                        if((bandColi=colision(&snake,screenWidth,screenHeight))==true)
                        {
                            game=false;
                            menu=0;
                        }
                        
                        


                        //Salida
                        if(IsKeyPressed(KEY_ESCAPE))
                        {
                            game=false;
                            menu=0;
                        }

                        snake->lastpos.x=snake->pos.x;
                        snake->lastpos.y=snake->pos.y;
                    }   
                    EndDrawing();
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
