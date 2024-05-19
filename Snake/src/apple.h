#include <stdio.h>
#include "raylib.h"
#define TRUE 1
#define FALSE 0

// Estructura para representar una manzana en el juego
struct Manzana
{
    struct img appleIcon; // Icono de la manzana
    Vector2 Fpos;         // Posición de la manzana en el tablero
};

// Prototipos de funciones
// Genera una nueva posición para la manzana
Vector2 spawnfood(struct Nodo **head, int gridx, int gridy); 
void drawFood(struct Manzana apple); // Dibuja la manzana en la pantalla

// Funciones
// Inicializa la imagen de la manzana
struct img initIMGapple()
{
    struct img apple;
    apple.img = LoadImage("assets/photos/icons/Apple.png");
    apple.text = LoadTextureFromImage(apple.img);
    apple.pos.x = 0.0;
    apple.pos.y = 0.0;
    apple.Height = apple.img.height;
    apple.Width = apple.img.width;
    UnloadImage(apple.img);
    return apple;
}

// Dibuja la manzana en la pantalla
void drawFood(struct Manzana apple)
{
    DrawTextureEx(apple.appleIcon.text, apple.Fpos, 0.0f, 1.0f, WHITE);
}

// Genera una nueva posición para la manzana
Vector2 spawnfood(struct Nodo **head, int gridx, int gridy)
{
    Vector2 temp;
    bool clean = true;
    do
    {
        clean = true;
        // Genera una posición aleatoria para la manzana dentro del tablero
        temp.x = GetRandomValue(2, (gridx - 2));
        temp.y = GetRandomValue(1, (gridy));
        temp.x = temp.x * 50;
        temp.y = temp.y * 50;

        struct Nodo *body = *head; // Cuerpo de la serpiente
        while (body->next != NULL)
        {
            // Verifica si la posición generada colisiona con 
            // el cuerpo de la serpiente
            if (temp.x == body->pos.x && temp.y == body->pos.y)
            {
                clean = false;
                break;
            }
            body = body->next;
        }
    } while (clean == false);

    return temp;
}
