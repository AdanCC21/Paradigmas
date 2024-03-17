#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define TRUE 1
#define FALSE 0

struct Nodo{
    Vector2 pos;
    struct Nodo*next;
};


//Movimientos---------------------------------------------------------------------
//Mover Derecha
Vector2 moveR(Vector2 pos)
{
    Vector2 temp;
    temp.x=pos.x + 50;
    temp.y=pos.y;
    return temp;
}
//Mover Izquierda
Vector2 moveL(Vector2 pos)
{
    Vector2 temp;
    temp.x=pos.x - 50;
    temp.y=pos.y;
    return temp;
}
//Mover Arriba
Vector2 moveU(Vector2 pos)
{
    Vector2 temp;
    temp.x=pos.x;
    temp.y=pos.y - 50;
    return temp;
}
//Mover Abajo
Vector2 moveD(Vector2 pos)
{
    Vector2 temp;
    temp.x=pos.x;
    temp.y=pos.y + 50;
    return temp;
}
//---------------------------------------------------------------------------------

void drawSnake(struct Nodo snake)
{
    DrawRectangle(snake.pos.x,snake.pos.y,50,50,WHITE);
}

int movSmooth (double tiempoEstimado)
{
    double timePass=GetTime();
    if(timePass - time>tiempoEstimado)
    {
        time=timePass;
        return TRUE;
    }
    return FALSE;
}


struct Nodo* crear(Vector2 newpos)
{
    struct Nodo* newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->pos.x= newpos.x;
    newNodo->pos.y= newpos.y;
    return newNodo;
}

void add (struct Nodo **head,Vector2 newpos)
{
    struct Nodo*newNodo=crear(newpos);

}