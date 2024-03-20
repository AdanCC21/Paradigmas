#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

struct img{
    Image img;
    Texture2D text;
    Vector2 pos;
    int Width;
    int Height;
};

struct img fondo;
struct img title;
struct img iniciar;
struct img salir;

void initImage(int screenWidth, int screenHeight);
int drawMenu();

void initImage(int screenWidth, int screenHeight)
{
    //Fondo---------------------------------------------------------------------------------------------------------------
    fondo.img=LoadImage("assets/photos/Backgrounds/FondoColor.png");
    fondo.text=LoadTextureFromImage(fondo.img);
    
    fondo.pos.x=0.0;
    fondo.pos.y=0.0;
    
    fondo.Height=fondo.img.height;
    fondo.Width=fondo.img.width;
    UnloadImage(fondo.img);
    
    //Titulo---------------------------------------------------------------------------------------------------------------
    title.img=LoadImage("assets/photos/Snakecs.png");
    title.text=LoadTextureFromImage(title.img);
    int titMed=(title.img.width/2)/2;
    
    title.pos.x=(screenWidth/2)-titMed;
    title.pos.y=50.0;
    
    title.Height=title.img.height;
    title.Width=title.img.width;
    UnloadImage(title.img);
    
    //Boton de iniciar---------------------------------------------------------------------------------------------------------------
    iniciar.img=LoadImage("assets/photos/Bottons/INICIARx300.png");
    iniciar.text=LoadTextureFromImage(iniciar.img);
    
    iniciar.pos.x=(screenWidth/2)-(iniciar.img.width/2);
    iniciar.pos.y=400-(iniciar.img.height/2);
    
    iniciar.Height=iniciar.img.height;
    iniciar.Width=iniciar.img.width;
    UnloadImage(iniciar.img);
    
    //Boton de Salir---------------------------------------------------------------------------------------------------------------
    salir.img=LoadImage("assets/photos/Bottons/SALIRx300.png");
    salir.text=LoadTextureFromImage(salir.img);
    
    salir.pos.x=(screenWidth/2)-(salir.img.width/2);
    salir.pos.y=550-(salir.img.height/2);
    
    salir.Height=salir.img.height;
    salir.Width=salir.img.width;
    
    UnloadImage(salir.img);

}

int drawMenu()
{
    int op=3;
    Vector2 mouse ={0.0f,0.0f};

    DrawTextureEx(fondo.text,fondo.pos,0.0f,1.0f,WHITE);//Fondo
    DrawTextureEx(title.text,title.pos,0.0f,0.5f,WHITE);//Titulo

    Rectangle iniciarRect = {iniciar.pos.x,iniciar.pos.y,iniciar.Width,iniciar.Height};//Rectangulo base
    DrawTextureEx(iniciar.text,iniciar.pos,0.0f,1.0f,WHITE);//Boton iniciar
    
    Rectangle salirRect ={salir.pos.x,salir.pos.y,salir.Width,salir.Height};//Rectangulo base
    DrawTextureEx(salir.text,salir.pos,0.0f,1.0f,WHITE);//Boton Salir

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
    return op;
}

int drawMenu2()
{
    int op=3;
    Vector2 mouse ={0.0f,0.0f};

    DrawTextureEx(fondo.text,fondo.pos,0.0f,1.0f,WHITE);//Fondo
    DrawTextureEx(title.text,title.pos,0.0f,0.5f,WHITE);//Titulo

    return op;
}


