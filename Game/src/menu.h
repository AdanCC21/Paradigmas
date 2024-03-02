#include "raylib.h"
#define TRUE 1
#define FALSE 0

/*  Prototipos  */
void fondo1 (int screenWidth,int screenHeight,Font Font);

/*  Estructuras */
struct fondoT{
    Image Fimage;
    Texture2D Ftexture;
    Vector2 Fpos;
};

enum Mescenas{
    MENU,
    SALIR
};

/*  Funciones   */
void fondo1 (int screenWidth,int screenHeight,Font Font)
{
    //Banderas
    // int bandMenu=TRUE;
    
    //Fuente Posicion
    

    Vector2 textpos;
    
    

    //Fondo
    struct fondoT f1;
    f1.Fimage = LoadImage("assets/photos/Backgrounds/FondoColor.png");
    f1.Ftexture = LoadTextureFromImage(f1.Fimage);
    UnloadImage(f1.Fimage);
    f1.Fpos.x=0;
    f1.Fpos.y=0;
    //Titulo
    struct fondoT title;
    title.Fimage = LoadImage("assets/photos/Snakecs.png");
    title.Ftexture = LoadTextureFromImage(title.Fimage);
    int Fmit=title.Fimage.width/2;
    UnloadImage(title.Fimage);
    title.Fpos.x=950-Fmit;
    title.Fpos.y=40;
    
    BeginDrawing();
        ClearBackground(BLACK);
            DrawTextureEx(f1.Ftexture,f1.Fpos,0.0f,1.0f,WHITE);
            DrawTextureEx(title.Ftexture,title.Fpos,0.0f,0.5f,WHITE);
            // DrawTextEx(font,"SnakeCs",);
    EndDrawing();
}