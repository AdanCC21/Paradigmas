#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "../src/sounds.h"

// Estructura para almacenar información de una imagen
struct img {
    Image img;        // Imagen
    Texture2D text;   // Textura
    Vector2 pos;      // Posición
    float Width;      // Ancho
    float Height;     // Alto
};

// Prototipos de funciones
struct img initGameBackground(); // Inicializa el fondo del juego
int drawMenu(Music music, float musicTime, struct img fondoM, 
struct img title, struct img start, struct img exit); // Dibuja el menú principal
// Inicializacion de imagenes
struct img initMenu();
struct img initGameOver();
struct img initWinner();
struct img initTitleButton(int screenWidth);
struct img initStartButton(int screenWidth);
struct img initExitButton(int screenWidth);

// Funciones de inicialización
struct img initMenu() // Inicializa el fondo del menú
{
    struct img fondo;
    fondo.img = LoadImage("assets/photos/Backgrounds/FondoColor.png");
    fondo.text = LoadTextureFromImage(fondo.img);
    fondo.pos.x = 0.0;
    fondo.pos.y = 0.0;
    fondo.Height = fondo.img.height;
    fondo.Width = fondo.img.width;
    UnloadImage(fondo.img);
    return fondo;
}

struct img initGameOver() // Inicializa el fondo de pantalla de fin de juego
{
    struct img over;
    over.img = LoadImage("assets/photos/Backgrounds/GameOverScreen.png");
    over.text = LoadTextureFromImage(over.img);
    over.pos.x = 0.0;
    over.pos.y = 0.0;
    over.Height = over.img.height;
    over.Width = over.img.width;
    UnloadImage(over.img);
    return over;
}

struct img initWinner() // Inicializa el fondo de pantalla de ganador
{
    struct img over;
    over.img = LoadImage("assets/photos/Backgrounds/PuntuacionMaxima.png");
    over.text = LoadTextureFromImage(over.img);
    over.pos.x = 0.0;
    over.pos.y = 0.0;
    over.Height = over.img.height;
    over.Width = over.img.width;
    UnloadImage(over.img);
    return over;
}

struct img initTitleButton(int screenWidth) // Inicializa el título del botón
{
    struct img title;
    title.img = LoadImage("assets/photos/Snakecs.png");
    title.text = LoadTextureFromImage(title.img);
    int titMed = (title.img.width / 2) / 2;
    title.pos.x = (screenWidth / 2) - titMed;
    title.pos.y = 50.0;
    title.Height = title.img.height;
    title.Width = title.img.width;
    UnloadImage(title.img);
    return title;
}

struct img initStartButton(int screenWidth) // Inicializa el botón de inicio
{
    struct img iniciar;
    iniciar.img = LoadImage("assets/photos/Bottons/INICIARx300.png");
    iniciar.text = LoadTextureFromImage(iniciar.img);
    iniciar.pos.x = (screenWidth / 2) - (iniciar.img.width / 2);
    iniciar.pos.y = 400 - (iniciar.img.height / 2);
    iniciar.Height = iniciar.img.height;
    iniciar.Width = iniciar.img.width;
    UnloadImage(iniciar.img);
    return iniciar;
}

struct img initExitButton(int screenWidth) // Inicializa el botón de salida
{
    struct img salir;
    salir.img = LoadImage("assets/photos/Bottons/SALIRx300.png");
    salir.text = LoadTextureFromImage(salir.img);
    salir.pos.x = (screenWidth / 2) - (salir.img.width / 2);
    salir.pos.y = 550 - (salir.img.height / 2);
    salir.Height = salir.img.height;
    salir.Width = salir.img.width;
    UnloadImage(salir.img);
    return salir;
}

// Inicializa el fondo del juego
struct img initGameBackground()
{
    struct img fondoG;
    fondoG.img = LoadImage("assets/photos/Backgrounds/Game1000x650.png");
    fondoG.text = LoadTextureFromImage(fondoG.img);
    fondoG.pos.x = 0.0;
    fondoG.pos.y = 0.0;
    fondoG.Height = fondoG.img.height;
    fondoG.Width = fondoG.img.width;
    UnloadImage(fondoG.img);
    return fondoG;
}

// Dibuja el menú principal
int drawMenu(Music music, float musicTime, struct img fondoM, struct img title, struct img start, struct img exit)
{
    int op = 0;
    Vector2 mouse = {0.0f, 0.0f};
    while (op == 0)
    {
        andanMusic(music, musicTime);
        BeginDrawing();
        DrawTextureEx(fondoM.text, fondoM.pos, 0.0f, 1.0f, WHITE); // Fondo
        DrawTextureEx(title.text, title.pos, 0.0f, 0.5f, WHITE); // Título

        Rectangle iniciarRect = {start.pos.x, start.pos.y, start.Width, start.Height}; // Rectángulo del botón de inicio
        DrawTextureEx(start.text, start.pos, 0.0f, 1.0f, WHITE); // Botón de inicio
        
        Rectangle salirRect = {exit.pos.x, exit.pos.y, exit.Width, exit.Height}; // Rectángulo del botón de salida
        DrawTextureEx(exit.text, exit.pos, 0.0f, 1.0f, WHITE); // Botón de salida

        mouse = GetMousePosition();
        if (CheckCollisionPointRec(mouse, iniciarRect))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                op = 1;
            }
        }
        if (CheckCollisionPointRec(mouse, salirRect))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                op = 2;
            }
        }
        EndDrawing();
    }
    return op;
}
