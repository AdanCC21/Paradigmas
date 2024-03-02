#include "raylib.h"


void fondo1 ();

struct fondoT{
    Image Fimage;
    Texture2D Ftexture;
    Vector2 Fpos;
};

void fondo1 ()
{
    //Variables
    struct fondoT f1;
    f1.Fimage = LoadImage("assets/photos/Nyejejeje.png");
    f1.Ftexture = LoadTextureFromImage(f1.Fimage);
    f1.Fpos.x=0;
    f1.Fpos.y=0;
    
    BeginDrawing();
        //Fondo
        ClearBackground(BLACK);
        DrawTextureEx(f1.Ftexture,f1.Fpos,0.0f,1.0f,WHITE);
        DrawText("SI COMPILAAAAAAA VAMOOOOO", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}