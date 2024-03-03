#include "raylib.h"
#define TRUE 1
#define FALSE 0

/*  Prototipos  */
void menuInit(int screenWidth,int screenHeight);
void fondo1 (int screenWidth,int screenHeight,Font font);

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

    struct fondoT f1;//FondoMenu
    struct fondoT title;//Titulo
    struct fondoT bStart;//Boton Inicio
    struct fondoT bExit;//Boton Salida

/*  Funciones   */
void menuInit(int screenWidth,int screenHeight)
{
    //Fondo
    f1.Fimage = LoadImage("assets/photos/Backgrounds/FondoColor2.png");
    f1.Ftexture = LoadTextureFromImage(f1.Fimage);
    UnloadImage(f1.Fimage);
    f1.Fpos.x=0;
    f1.Fpos.y=0;
    //Titulo
    title.Fimage = LoadImage("assets/photos/Snakecs.png");
    title.Ftexture = LoadTextureFromImage(title.Fimage);
    int Fmit=title.Fimage.width/2;
    UnloadImage(title.Fimage);
    title.Fpos.x=930-Fmit;
    title.Fpos.y=40;
    //Botones
    //Iniciar
    bStart.Fimage=LoadImage("assets/photos/Bottons/INICIARx300.png");
    bStart.Ftexture=LoadTextureFromImage(bStart.Fimage);
    bStart.Fpos.x=(screenWidth/2)-(bStart.Fimage.width/2);
    bStart.Fpos.y=350;
    UnloadImage(bStart.Fimage);
    //Salidar
    bExit.Fimage=LoadImage("assets/photos/Bottons/SALIRx300.png");
    bExit.Ftexture=LoadTextureFromImage(bExit.Fimage);
    bExit.Fpos.x=(screenWidth/2)-(bExit.Fimage.width/2);
    bExit.Fpos.y=550;
    UnloadImage(bExit.Fimage);
}


void fondo1 (int screenWidth,int screenHeight,Font font)
{
    //Texto
    char exit[27]={"Adios"};
    float Texit = MeasureText(exit,50.0f);
    //Banderas
    int bandMENU=TRUE;
    int bandEXIT=FALSE;
    int bandGAME=FALSE;
    int bandOut=FALSE;
    
    //Mouse
    Vector2 Mouse={0.0f,0.0f};
    
    //Rectangulos
    Rectangle StartRect={bStart.Fpos.x,bStart.Fpos.y,300,100};
    Rectangle ExitRect={bExit.Fpos.x,bExit.Fpos.y,300,100};

    while(!WindowShouldClose()&& bandOut==FALSE)
    {
        Mouse=GetMousePosition();
        BeginDrawing();
        {
            ClearBackground(BLACK);
            //Dibujar Menu-------------------------------------------
            if(bandMENU==TRUE)
            {
                /*Fondos Y botones*/
                DrawTextureEx(f1.Ftexture,f1.Fpos,0.0f,1.0f,WHITE);
                DrawTextureEx(title.Ftexture,title.Fpos,0.0f,0.5f,WHITE);
                DrawTextureEx(bStart.Ftexture,bStart.Fpos,0.0f,1.0f,WHITE);
                DrawTextureEx(bExit.Ftexture,bExit.Fpos,0.0f,1.0f,WHITE);
            }

            if(CheckCollisionPointRec(Mouse,StartRect))
            {
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    bandMENU=FALSE;
                    bandEXIT=FALSE;
                    bandGAME=TRUE;
                }
            }
            if(CheckCollisionPointRec(Mouse,ExitRect))
            {
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    bandMENU=FALSE;
                    bandEXIT=TRUE;
                    bandGAME=FALSE;
                }
            }

            //Dibujar Salida-------------------------------------------
            if(bandEXIT==TRUE)
            {
                DrawTextureEx(f1.Ftexture,f1.Fpos,0.0f,1.0f,WHITE);
                DrawTextureEx(title.Ftexture,title.Fpos,0.0f,0.5f,WHITE);
                DrawTextureEx(bStart.Ftexture,bStart.Fpos,0.0f,1.0f,WHITE);
                DrawTextureEx(bExit.Ftexture,bExit.Fpos,0.0f,1.0f,WHITE);
                DrawRectangle(0,0,screenWidth,screenHeight,Fade (BLACK,0.5f));
                DrawText(exit,(screenWidth/2)-(Texit/2),(screenHeight/2),50.0f,WHITE);
                
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
                {
                    bandOut=TRUE;
                }
            }
            if(bandGAME==TRUE)
            {
                
            }
        }
        EndDrawing();
    }
}