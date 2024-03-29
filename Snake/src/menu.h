#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "../src/sounds.h"

struct img{
    Image img;
    Texture2D text;
    Vector2 pos;
    float Width;
    float Height;
};

void initImage(int screenWidth, int screenHeight);
struct img initGameBackground();
int drawMenu(Music music,float musicTime);

//Funciones
//Inits

struct img initMenu()//Menu BackGround;
{
    struct img fondo;
    fondo.img=LoadImage("assets/photos/Backgrounds/FondoColor.png");
    fondo.text=LoadTextureFromImage(fondo.img);
    
    fondo.pos.x=0.0;
    fondo.pos.y=0.0;
    
    fondo.Height=fondo.img.height;
    fondo.Width=fondo.img.width;
    UnloadImage(fondo.img);
    return fondo;
}

struct img initGameOver()//Gameover BackGround;
{
    struct img over;
    over.img=LoadImage("assets/photos/Backgrounds/GameOverScreen.png");
    over.text=LoadTextureFromImage(over.img);
    
    over.pos.x=0.0;
    over.pos.y=0.0;
    
    over.Height=over.img.height;
    over.Width=over.img.width;
    UnloadImage(over.img);
    return over;
}

struct img initWinner()//Winner BackGround;
{
    struct img over;
    over.img=LoadImage("assets/photos/Backgrounds/PuntuacionMaxima.png");
    over.text=LoadTextureFromImage(over.img);
    
    over.pos.x=0.0;
    over.pos.y=0.0;
    
    over.Height=over.img.height;
    over.Width=over.img.width;
    UnloadImage(over.img);
    return over;
}

struct img initTitleButton(int screenWidth)//Title Text;
{
    struct img title;
    title.img=LoadImage("assets/photos/Snakecs.png");
    title.text=LoadTextureFromImage(title.img);
    int titMed=(title.img.width/2)/2;
    
    title.pos.x=(screenWidth/2)-titMed;
    title.pos.y=50.0;
    
    title.Height=title.img.height;
    title.Width=title.img.width;
    UnloadImage(title.img);
    return title;
}

struct img initStartButton(int screenWidth)//Start Button;
{
    struct img iniciar;
    iniciar.img=LoadImage("assets/photos/Bottons/INICIARx300.png");
    iniciar.text=LoadTextureFromImage(iniciar.img);
    
    iniciar.pos.x=(screenWidth/2)-(iniciar.img.width/2);
    iniciar.pos.y=400-(iniciar.img.height/2);
    
    iniciar.Height=iniciar.img.height;
    iniciar.Width=iniciar.img.width;
    
    UnloadImage(iniciar.img);

    return iniciar;
}

struct img initExitButton(int screenWidth)//Exit Button;
{
    struct img salir;
    salir.img=LoadImage("assets/photos/Bottons/SALIRx300.png");
    salir.text=LoadTextureFromImage(salir.img);
    
    salir.pos.x=(screenWidth/2)-(salir.img.width/2);
    salir.pos.y=550-(salir.img.height/2);
    
    salir.Height=salir.img.height;
    salir.Width=salir.img.width;
    
    UnloadImage(salir.img);

    return salir;
}

struct img initGameBackground()
{
    struct img fondoG;
    //Fondo En Game-----------------------------------------------------------
    fondoG.img=LoadImage("assets/photos/Backgrounds/Game1000x650.png");
    fondoG.text=LoadTextureFromImage(fondoG.img);
    
    fondoG.pos.x=0.0;
    fondoG.pos.y=0.0;
    
    fondoG.Height=fondoG.img.height;
    fondoG.Width=fondoG.img.width;
    UnloadImage(fondoG.img);
    return fondoG;
}

int drawMenu(Music music,float musicTime,struct img fondoM,struct img title, 
struct img start, struct img exit)
{
    int op=0;
    Vector2 mouse ={0.0f,0.0f};
    while(op==0)
    {
        andanMusic(music,musicTime);
        BeginDrawing();
        DrawTextureEx(fondoM.text,fondoM.pos,0.0f,1.0f,WHITE);//Fondo
        DrawTextureEx(title.text,title.pos,0.0f,0.5f,WHITE);//Titulo
        

        Rectangle iniciarRect = {start.pos.x,start.pos.y,start.Width,start.Height};//Rectangulo base
        DrawTextureEx(start.text,start.pos,0.0f,1.0f,WHITE);//Boton iniciar
        
        Rectangle salirRect ={exit.pos.x,exit.pos.y,exit.Width,exit.Height};//Rectangulo base
        DrawTextureEx(exit.text,exit.pos,0.0f,1.0f,WHITE);//Boton Salir

        mouse=GetMousePosition();
        if(CheckCollisionPointRec(mouse,iniciarRect))
        {
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                op=1;
            }
        }
        if(CheckCollisionPointRec(mouse,salirRect))
        {
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                op=2;
            }
        }
        EndDrawing();
    }
    return op;
}