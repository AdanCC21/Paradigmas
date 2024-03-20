#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define TRUE 1
#define FALSE 0

struct Nodo{
    Vector2 lastpos;
    Vector2 pos;
    struct Nodo*next;
};

void drawSnakeP(struct Nodo *snake)
{
    Vector2 tempPos;
    
    struct Nodo *temp=snake;
    while(temp!=NULL)
    {
        tempPos.x=temp->pos.x;
        tempPos.y=temp->pos.y;
        
        DrawRectangle(tempPos.x,tempPos.y,50,50,WHITE);
        // printf("%d",temp->data);
        temp=temp->next;
    }
}

void colision()
{
    
}

struct Nodo* crear()
{
    struct Nodo* newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->pos.x= 0;
    newNodo->pos.y= 0;
    newNodo->lastpos.x=0;
    newNodo->lastpos.y=0;
    newNodo->next=NULL;
    return newNodo;
}

void add (struct Nodo **head)
{
    struct Nodo *newNodo=crear();
    struct Nodo *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNodo;
    newNodo->pos.x=temp->lastpos.x;
    newNodo->pos.y=temp->lastpos.y;
}

//Movimientos---------------------------------------------------------------------
double time=0.0;

//Derecha/Right
void moveHeadR(struct Nodo **head)
{
    (*head)->lastpos.x=(*head)->pos.x;
    (*head)->pos.x=(*head)->pos.x+50;
    
    struct Nodo *temp=*head;
    struct Nodo *temp2=*head;
    
    temp=temp->next;
    
    while(temp!=NULL)
    {
        temp->lastpos.x=temp->pos.x;
        temp->lastpos.y=temp->pos.y;

        temp->pos.x=temp2->lastpos.x;
        temp->pos.y=temp2->lastpos.y;
                
        temp=temp->next;
        temp2=temp2->next;
    }
}
//Arriba/Up
void moveHeadU(struct Nodo **head)
{
    (*head)->lastpos.y=(*head)->pos.y;
    (*head)->pos.y=(*head)->pos.y-50;
    
    struct Nodo *temp=*head;
    struct Nodo *temp2=*head;
    
    temp=temp->next;
    
    while(temp!=NULL)
    {
        temp->lastpos.x=temp->pos.x;
        temp->lastpos.y=temp->pos.y;

        temp->pos.x=temp2->lastpos.x;
        temp->pos.y=temp2->lastpos.y;
        
        temp=temp->next;
        temp2=temp2->next;
    }
}
//Abajo/Down
void moveHeadD(struct Nodo **head)
{
    (*head)->lastpos.y=(*head)->pos.y;
    (*head)->pos.y=(*head)->pos.y+50;
    
    struct Nodo *temp=*head;
    struct Nodo *temp2=*head;
    
    temp=temp->next;
    
    while(temp!=NULL)
    {
        temp->lastpos.x=temp->pos.x;
        temp->lastpos.y=temp->pos.y;

        temp->pos.x=temp2->lastpos.x;
        temp->pos.y=temp2->lastpos.y;
        
        temp=temp->next;
        temp2=temp2->next;
    }
}
//Izquierda/Left
void moveHeadL(struct Nodo **head)
{
    (*head)->lastpos.y=(*head)->pos.y;
    (*head)->pos.x=(*head)->pos.x-50;
    
    struct Nodo *temp=*head;
    struct Nodo *temp2=*head;
    
    temp=temp->next;
    
    while(temp!=NULL)
    {
        temp->lastpos.x=temp->pos.x;
        temp->lastpos.y=temp->pos.y;

        temp->pos.x=temp2->lastpos.x;
        temp->pos.y=temp2->lastpos.y;
        
        temp=temp->next;
        temp2=temp2->next;
    }
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

// //Mover Derecha
// Vector2 moveR(Vector2 pos)
// {
//     Vector2 temp;
//     temp.x=pos.x + 50;
//     temp.y=pos.y;
//     return temp;
// }
// //Mover Izquierda
// Vector2 moveL(Vector2 pos)
// {
//     Vector2 temp;
//     temp.x=pos.x - 50;
//     temp.y=pos.y;
//     return temp;
// }
// //Mover Arriba
// Vector2 moveU(Vector2 pos)
// {
//     Vector2 temp;
//     temp.x=pos.x;
//     temp.y=pos.y - 50;
//     return temp;
// }

// //Mover Abajo
// Vector2 moveD(Vector2 pos)
// {
//     Vector2 temp;
//     temp.x=pos.x;
//     temp.y=pos.y + 50;
//     return temp;
// }

// void genMoveR(struct Nodo **head)
// {
//     struct Nodo *temp=*head;
//     temp=temp->next;
//     while(temp!=NULL)
//     {
//         temp->pos.x=temp->lastpos.x;
//         temp->lastpos.x=temp->pos.x;
//         temp=temp->next;
//     }
// }

// void genMoveL(struct Nodo **head)
// {
//     struct Nodo *temp=*head;
//     while(temp!=NULL)
//     {
//         temp->pos.x=temp->pos.x-50;
//         temp=temp->next;
//     }
// }
// //Arriba/Up
// void genMoveU(struct Nodo **head)
// {
//     struct Nodo *temp=*head;
//     while(temp!=NULL)
//     {
//         temp->pos.y=temp->pos.y-50;
//         temp=temp->next;
//     }
// }
// //Abajo/Down

// void genMoveD(struct Nodo **head)
// {
//     struct Nodo *temp=*head;
//     while(temp!=NULL)
//     {
//         temp->pos.y=temp->pos.y+50;
//         temp=temp->next;
//     }
// }

//---------------------------------------------------------------------------------