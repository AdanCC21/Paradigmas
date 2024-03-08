#include "raylib.h"
#define TRUE 1
#define FALSE 0

void initLobby(int screenWidth, int screenHeight);
void lobby(int screenWidth, int screenHeight);

/*Nodos------------------------------------------------------------------*/
struct Nodo
{
    Vector2 Pos;
    struct nodo *next;
};

struct Nodo *createNodo(Vector2 posicion);
void nodoFinal(struct Nodo **head,Vector2 pos);
void destruir(struct Nodo **head,Vector2 pos);

struct Nodo *createNodo(Vector2 posicion)
{
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo->Pos = posicion;
    return nodo;
}

void nodoFinal (struct Nodo **head,Vector2 pos)
{
    struct Nodo* nodo = createNodo(pos);
}

/*Nodos------------------------------------------------------------------*/

struct Tlobby
{
    Image Ilo;
    Texture2D Tlo;
    Vector2 Plo;
};

struct Tlobby spawn; // Fundo

void initLobby(int screenWidth, int screenHeight)
{
    spawn.Ilo = LoadImage("assets/photos/Backgrounds/background1.png");
    spawn.Tlo = LoadTextureFromImage(spawn.Ilo);
    spawn.Plo.x = 0.0f;
    spawn.Plo.y = 0.0f;
    UnloadImage(spawn.Ilo);
}

void lobby(int screenWidth, int screenHeight)
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            DrawTextureEx(spawn.Tlo, spawn.Plo, 0.0f, 1.0f, WHITE); // Fundo
        }
        EndDrawing();
    }
}
