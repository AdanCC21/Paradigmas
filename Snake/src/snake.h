#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define TRUE 1
#define FALSE 0

// Estructura de un Nodo que representa un segmento de la serpiente
struct Nodo {
    Vector2 lastpos; // Posición anterior del segmento
    Vector2 pos;     // Posición actual del segmento
    struct img head; // Imagen del segmento
    struct Nodo *next; // Siguiente segmento en la serpiente
};

// Prototipos de funciones
void drawSnakeP(struct Nodo *snake, int direction); // Dibujar serpiente
struct Nodo* crear(); // Crear un nuevo nodo para la serpiente
void add(struct Nodo **head); // Agregar un nodo a la serpiente
void moveHeadR(struct Nodo **head); // Mover la cabeza hacia la derecha
void moveHeadL(struct Nodo **head); // Mover la cabeza hacia la izquierda
void moveHeadD(struct Nodo **head); // Mover la cabeza hacia abajo
void moveHeadU(struct Nodo **head); // Mover la cabeza hacia arriba
bool colision(struct Nodo **head, int startx, int limitX, 
int startY, int limitY); // Detectar colisiones
struct img initIMGHead(); // Inicializar imagen de la cabeza de la serpiente
int movSmooth(double tiempoEstimado, double *time); // Movimiento suavizado

// Inicializa la imagen de la cabeza de la serpiente
struct img initIMGHead()
{
    struct img head;
    // Inicialización de la imagen de la cabeza
    head.img = LoadImage("assets/photos/icons/SnakeHead.png");
    head.text = LoadTextureFromImage(head.img);
    head.pos.x = 0.0;
    head.pos.y = 0.0;
    head.Height = head.img.height;
    head.Width = head.img.width;
    UnloadImage(head.img);
    return head;
}

// Dibuja la serpiente en la pantalla
void drawSnakeP(struct Nodo *snake, int direction)
{
    // Dibuja cada segmento de la serpiente
    Vector2 tempPos;
    bool head = true;
    struct Nodo *temp = snake;
    Vector2 headVect;
    Color BodyColor = {74, 156, 106, 255};

    while (temp != NULL)
    {
        tempPos.x = temp->pos.x;
        tempPos.y = temp->pos.y;

        if (head == true)
        {
            // Dibuja la cabeza de la serpiente
            if (direction == 1) // Derecha
            {
                DrawTextureEx(temp->head.text, temp->pos, 0.0f, 1.0f, WHITE);
            }
            else if (direction == 2) // Izquierda
            {
                headVect.x = temp->pos.x + 50;
                headVect.y = temp->pos.y + 50;
                DrawTextureEx(temp->head.text, headVect, 180.0f, 1.0f, WHITE);
            }
            else if (direction == 3) // Arriba
            {
                headVect.x = temp->pos.x;
                headVect.y = temp->pos.y + 50;
                DrawTextureEx(temp->head.text, headVect, 270.0f, 1.0f, WHITE);
            }
            else if (direction == 4) // Abajo
            {
                headVect.x = temp->pos.x + 50;
                headVect.y = temp->pos.y;
                DrawTextureEx(temp->head.text, headVect, 90.0f, 1.0f, WHITE);
            }
            head = false;
        }
        else
        {
            // Dibuja el cuerpo de la serpiente
            DrawRectangle(tempPos.x, tempPos.y, 50, 50, BodyColor);
        }

        temp = temp->next;
    }
}

// Detecta colisiones de la serpiente con bordes y consigo misma
bool colision(struct Nodo **head, int startx, 
int limitX, int startY, int limitY)
{
    struct Nodo *temp = *head;
    temp = temp->next;
    while (temp != NULL)
    {
        if ((*head)->pos.x == temp->pos.x && (*head)->pos.y == temp->pos.y)
        {
            // Colisión con su propio cuerpo
            return true;
        }
        temp = temp->next;
    }

    // Colisión con los bordes de la pantalla
    if (((*head)->pos.x < startx) || ((*head)->pos.x >= limitX) ||
        ((*head)->pos.y < startY) || ((*head)->pos.y >= limitY))
    {
        return true;
    }

    return false;
}

// Crea un nuevo nodo para la serpiente
struct Nodo* crear()
{
    struct Nodo *newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->pos.x = 0;
    newNodo->pos.y = 0;
    newNodo->lastpos.x = 0;
    newNodo->lastpos.y = 0;
    newNodo->next = NULL;
    return newNodo;
}

// Agrega un nuevo nodo a la serpiente
void add(struct Nodo **head)
{
    struct Nodo *newNodo = crear();
    struct Nodo *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNodo->pos.x = temp->lastpos.x;
    newNodo->pos.y = temp->lastpos.y;
    temp->next = newNodo;
}

// Mueve la cabeza de la serpiente hacia la derecha
void moveHeadR(struct Nodo **head)
{
    (*head)->lastpos.x = (*head)->pos.x;
    (*head)->pos.x = (*head)->pos.x + 50;

    struct Nodo *temp = *head;
    struct Nodo *temp2 = *head;

    temp = temp->next;

    while (temp != NULL)
    {
        temp->lastpos.x = temp->pos.x;
        temp->lastpos.y = temp->pos.y;

        temp->pos.x = temp2->lastpos.x;
        temp->pos.y = temp2->lastpos.y;

        temp = temp->next;
        temp2 = temp2->next;
    }
}

// Mueve la cabeza de la serpiente hacia arriba
void moveHeadU(struct Nodo **head)
{
    (*head)->lastpos.y = (*head)->pos.y;
    (*head)->pos.y = (*head)->pos.y - 50;

    struct Nodo *temp = *head;
    struct Nodo *temp2 = *head;

    temp = temp->next;

    while (temp != NULL)
    {
        temp->lastpos.x = temp->pos.x;
        temp->lastpos.y = temp->pos.y;

        temp->pos.x = temp2->lastpos.x;
        temp->pos.y = temp2->lastpos.y;

        temp = temp->next;
        temp2 = temp2->next;
    }
}

// Mueve la cabeza de la serpiente hacia abajo
void moveHeadD(struct Nodo **head)
{
    (*head)->lastpos.y = (*head)->pos.y;
    (*head)->pos.y = (*head)->pos.y + 50;

    struct Nodo *temp = *head;
    struct Nodo *temp2 = *head;

    temp = temp->next;

    while (temp != NULL)
    {
        temp->lastpos.x = temp->pos.x;
        temp->lastpos.y = temp->pos.y;

        temp->pos.x = temp2->lastpos.x;
        temp->pos.y = temp2->lastpos.y;

        temp = temp->next;
        temp2 = temp2->next;
    }
}

// Mueve la cabeza de la serpiente hacia la izquierda
void moveHeadL(struct Nodo **head)
{
    (*head)->lastpos.y = (*head)->pos.y;
    (*head)->pos.x = (*head)->pos.x - 50;

    struct Nodo *temp = *head;
    struct Nodo *temp2 = *head;

    temp = temp->next;

    while (temp != NULL)
    {
        temp->lastpos.x = temp->pos.x;
        temp->lastpos.y = temp->pos.y;

        temp->pos.x = temp2->lastpos.x;
        temp->pos.y = temp2->lastpos.y;

        temp = temp->next;
        temp2 = temp2->next;
    }
}

// Verifica si ha pasado cierto tiempo desde la última 
// actualización para un movimiento suavizado
int movSmooth(double tiempoEstimado, double *time)
{
    double timePass = GetTime();
    if ((timePass - *time) > tiempoEstimado)
    {
        *time = timePass;
        return TRUE;
    }
    return FALSE;
}
