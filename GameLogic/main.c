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
    int screenWidth = 1280;
    int screenHeight = 700;
    SetTargetFPS(60);

    // Inits--------------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "SnakeCs");
    initImage(screenWidth, screenHeight);
    Font font = LoadFont("assets/fonts/BerlinSansFBDemiBold.ttf");
    // Variables----------------------------------------------------------------------------------------s
    int celsize= 50;//Grid tamaño
    int celxcount=1000/50;//Grid cantidad x
    int celycount=600/50;//Grid cantidad y

    int celstartX=50*2;//cantidad en casillas que dejara de espacio desde 0 de x
    int celstartY=50*1;//cantidad en casillas que dejara de espacio desde 0 de y

    int cellimitX=(celstartX)+celxcount*50;
    int cellimitY=(celstartY)+celycount*50;

    int bandTime=FALSE;

    //Snake
    struct Nodo *snake=(struct Nodo*)malloc(sizeof(struct Nodo));
    snake->pos.x=celsize*2;
    snake->pos.y=celsize*(celycount/2);
    
    snake->next=NULL;
    snake->head=initIMGHead();
    
    //Banderas de direccion
    int SbandR=TRUE;
    int SbandL=FALSE;
    int SbandU=FALSE;
    int SbandD=FALSE;

    //Manzana
    struct Manzana apple;
    apple.appleIcon=initIMGapple();
    apple.Fpos=spawnfood(&snake,celxcount,celycount);

    //banderas de inicio
    int menu = 0;
    bool game = true;
    bool over = false;

    bool bandColi =false;

    //Fondos
    struct img fondoG=initGameBackground();
    

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
                int direction=1;//right

                int SbandR=TRUE;
                int SbandL=FALSE;
                int SbandU=FALSE;
                int SbandD=FALSE;

                int puntuacion=0;
                Vector2 textPos;
                textPos.x=screenWidth-320;
                textPos.y=screenHeight-50;

                Vector2 puntsPos;
                puntsPos.x=screenWidth-50;
                puntsPos.y=screenHeight-50;
                char contCad[3] ={"0"};
                
                do
                {
                    BeginDrawing();
                    {

                        DrawTextureEx(fondoG.text,fondoG.pos,0.0f,1.0f,WHITE);
                        //Grid------------------------------------------------
                            for (int x = 100; x < 1150; x += celsize) 
                            {
                                DrawLine(x, 50, x, 650, LIGHTGRAY);
                            }
                            for (int y = 50; y < 750; y += celsize) 
                            {
                                DrawLine(100, y, 1100, y, LIGHTGRAY);
                            }
                        //-----------------------------------------------------

                        drawFood(apple);
                        drawSnakeP(snake,direction);
                        DrawTextEx(font,"Puntuacion :",textPos,50,1.0,WHITE);
                        itoa(puntuacion,contCad,10);
                        DrawTextEx(font,contCad,puntsPos,50,1.0,WHITE);

                        //Movimiento
                        if((bandTime=movSmooth(0.2))==TRUE)
                        {
                            if(SbandR==TRUE)
                            {
                                direction=1;
                                moveHeadR(&snake);
                            }
                            else
                            {
                                if(SbandL==TRUE)
                                {
                                    direction=2;
                                    moveHeadL(&snake);
                                }
                                else
                                {
                                    if(SbandU==TRUE)
                                    {
                                        direction=3;
                                        moveHeadU(&snake);
                                    }
                                    else
                                    {
                                        if(SbandD==TRUE)
                                        {
                                            direction=4;
                                            moveHeadD(&snake);
                                        }
                                    }
                                }
                            }
                        }

                        //Teclas de movimiento
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
                                    
                                }
                            }
                            if(IsKeyPressed(KEY_SPACE))
                            {
                                apple.Fpos=spawnfood(&snake,celxcount,celycount);
                                
                            }
                        }

                        //Manzana
                        if(snake->pos.x==apple.Fpos.x)
                        {
                            if(snake->pos.y==apple.Fpos.y)
                            {
                                apple.Fpos=spawnfood(&snake,celxcount,celycount);
                                add(&snake);
                                puntuacion++;
                            }
                        }
                        
                        // Colisiones
                        if((bandColi=colision(&snake,celstartX,cellimitX,celstartY,cellimitY))==true)
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
                        
                        //Actualizacion de ultima posicion
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
