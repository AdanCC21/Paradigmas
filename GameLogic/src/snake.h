#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define TRUE 1
#define FALSE 0

struct Nodo{
    int data;
    Vector2 pos;
    struct Nodo*next;
};


struct Nodo* crear(Vector2 newpos);
void add (struct Nodo **head);
void drawSnakeP(struct Nodo *snake);

struct Nodo* crear(Vector2 newpos)
{
    struct Nodo* newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->pos.x= newpos.x-50;
    newNodo->pos.y= newpos.y-50;
    newNodo->next=NULL;
    return newNodo;
}

void add (struct Nodo **head)
{
    Vector2 newpos;
    newpos.x=(*head)->pos.x-50;
    newpos.y=(*head)->pos.y-50;
    struct Nodo*newNodo=crear(newpos);
    newNodo->data=15+(*head)->data;
    (*head)->next=newNodo;
}

void drawSnakeP(struct Nodo *snake)
{
    Vector2 tempPos;
    
    struct Nodo *temp=snake;
    while(temp!=NULL)
    {
        tempPos.x=temp->pos.x;
        tempPos.y=temp->pos.y;
        
        DrawRectangle(tempPos.x,tempPos.y,50,50,WHITE);
        printf("%d",temp->data);
        temp=temp->next;
    }
}

//Movimientos---------------------------------------------------------------------
double time=0.0;
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
//---------------------------------------------------------------------------------