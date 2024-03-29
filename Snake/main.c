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

//Pagina 26-27 de la documentacion

/*Puntos clave de la documentacion

No define para cosas como
    #define inicio {
    #define fin }

No mas de 80 caracteres por linea

Usar parentesis en cada condicion con operadores logicos
if((condicion)&&(condicion))

Llaves rodeando el bloque de codigo
if
{
    codigo
}

Que tus variables sean entendibles por si solas, es decir su nombre

las variables que no se deban de modificar, deberan estar declaradas con
const int variable
o enviarlas a una funcion con (const int variable) y asi

*/

int main()
{
    // Ventana Informacion
    int screenWidth = 1280;
    int screenHeight = 700;
    SetTargetFPS(60);

    // Inits
    InitWindow(screenWidth, screenHeight, "SnakeCs");
    InitAudioDevice();
    
    // Variables
    
    //Fuente de texto
    Font font = LoadFont("assets/fonts/BerlinSansFBDemiBold.ttf");
    
    //Grid
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
    
    //Movimiento cronometro
    double time=0.0;

     //Banderas de movimiento
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
    struct img fondoG=initGameBackground();//Fondo del juego
    struct img fondoM=initMenu();
    struct img fondoO=initGameOver();
    struct img fondoW=initWinner();
    //Botones
    struct img title=initTitleButton(screenWidth);//Titulo
    struct img start=initStartButton(screenWidth);//Boton de iniciar
    struct img exit=initExitButton(screenWidth);//Boton de salir

    //Musica
    Music menuMusic = LoadMusicStream("assets/music/DKcountry.mp3");
    float menuTime=0.0f;
    Music gameMusic = LoadMusicStream("assets/music/Stage1.mp3");
    float gameTime=0.0f;
    Music overMusic = LoadMusicStream("assets/music/ChavoSad.mp3");
    float overTime=0.0f;
    Music winnerMusic = LoadMusicStream("assets/music/ThePrice.mp3");
    float winnerTime=0.0f;

    //Sonidos
    Sound sBom1= LoadSound("assets/sounds/Bom 1.mp3");//Sonido al comer una manzana
    Sound sBom4= LoadSound("assets/sounds/Bom 4.mp3");//Sonido al morir
    

    // Main game loop------------------------------------------------------------------------------------
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        {
            StopSound(sBom1);

            if(menu==0)
            {
                menu=drawMenu(menuMusic,menuTime,fondoM,title,start,exit);
            }
            
            if(menu==1)
            {
                //Reinicio
                game=true;
                over=false;
                
                //Snake posicion
                snake->pos.x=celsize*2;
                snake->pos.y=celsize*(celycount/2);
                snake->next=NULL;
                int direction=1;//right

                //Banderas de movimiento
                SbandR=TRUE;
                SbandL=FALSE;
                SbandU=FALSE;
                SbandD=FALSE;

                //Puntuacion Contador
                int puntuacion=0;
                Vector2 textPos;
                textPos.x=screenWidth-350;
                textPos.y=screenHeight-50;

                Vector2 puntsPos;
                puntsPos.x=screenWidth-70;
                puntsPos.y=screenHeight-50;
                char contCad[3] ={"0"};

                //Musica
                StopMusicStream(menuMusic);
                StopMusicStream(gameMusic);
                
                do
                {
                    BeginDrawing();
                    {
                        //Fondo
                        DrawTextureEx(fondoG.text,fondoG.pos,0.0f,1.0f,WHITE);
                        
                        //Musica
                        andanMusic(gameMusic,gameTime);
                        
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
                        
                        //Manzana
                        drawFood(apple);
                        
                        //Snake
                        drawSnakeP(snake,direction);
                        
                        //Puntuacion texto
                        DrawTextEx(font,"Puntuacion :",textPos,50,1.0,WHITE);
                        
                        //Contador de puntos
                        itoa(puntuacion,contCad,10);
                        DrawTextEx(font,contCad,puntsPos,50,1.0,WHITE);

                        //Movimiento
                        if((bandTime=movSmooth(0.2,&time))==TRUE)
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
                        }

                        //Manzana
                        if(snake->pos.x==apple.Fpos.x)
                        {
                            if(snake->pos.y==apple.Fpos.y)
                            {
                                apple.Fpos=spawnfood(&snake,celxcount,celycount);
                                PlaySound(sBom1);
                                add(&snake);
                                puntuacion++;
                            }
                        }
                        
                        // Colisiones
                        if((bandColi=colision(&snake,celstartX,cellimitX,celstartY,cellimitY))==true)
                        {
                            game=false;
                            menu=0;
                            over=true;
                        }

                        //Salida
                        if(IsKeyPressed(KEY_ESCAPE))
                        {
                            game=false;
                            over=false;
                            menu=0;
                        }
                        
                        //Actualizacion de ultima posicion
                        snake->lastpos.x=snake->pos.x;
                        snake->lastpos.y=snake->pos.y;
                        
                        if(over==true)
                        {
                            StopMusicStream(gameMusic);
                            while(over==true)
                            {
                                BeginDrawing();
                                if(puntuacion>=240)//Winner Screen
                                {
                                    andanMusic(winnerMusic,winnerTime);
                                    DrawTextureEx(fondoW.text,fondoW.pos,0.0f,1.0f,WHITE);
                                }
                                else//Game Over Screen
                                {
                                    andanMusic(overMusic,overTime);
                                    DrawTextureEx(fondoO.text,fondoO.pos,0.0f,1.0f,WHITE);
                                }
                                    if(IsKeyPressed(KEY_ESCAPE))
                                    {
                                        over=false;
                                    }
                                EndDrawing();
                            }
                            StopMusicStream(winnerMusic);
                            StopMusicStream(overMusic);
                        }
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

    //Unloads------------------------
    {
        UnloadMusicStream(gameMusic);
        UnloadMusicStream(menuMusic);
        UnloadMusicStream(overMusic);
        UnloadMusicStream(winnerMusic);
        UnloadSound(sBom1);
        UnloadSound(sBom4);
    }

    CloseWindow();

    return 0;
}
