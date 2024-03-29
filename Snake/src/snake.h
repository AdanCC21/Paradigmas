#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define TRUE 1
#define FALSE 0

struct Nodo{
    Vector2 lastpos;
    Vector2 pos;
    struct img head;
    struct Nodo*next;
};
//Prototipos------------------------------------------------
void drawSnakeP(struct Nodo *snake,int direction);//Dibujar Serpiente

struct Nodo* crear();//Crear Nodo
void add (struct Nodo **head);//Agregar Nodo a la serpiente

//Movimientos
void moveHeadR(struct Nodo **head);//Mover Derecha/Right
void moveHeadL(struct Nodo **head);//Mover Arriba/Up
void moveHeadD(struct Nodo **head);//Mover Abajo/Down
void moveHeadU(struct Nodo **head);//Mover Izquierda/Left

int movSmooth (double tiempoEstimado, double *time);//Movimiento cada cierto tiempo

struct img initIMGHead();

//Funciones-------------------------------------------------

struct img initIMGHead()
{
    struct img head;
    //Head--------------------------------------------------
    head.img=LoadImage("assets/photos/icons/SnakeHead.png");
    head.text=LoadTextureFromImage(head.img);
    
    head.pos.x=0.0;
    head.pos.y=0.0;
    
    head.Height=head.img.height;
    head.Width=head.img.width;
    UnloadImage(head.img);
    
    return head;
}

void drawSnakeP(struct Nodo *snake,int direction)
{
    Vector2 tempPos;
    bool head=true;
    struct Nodo *temp=snake;
    Vector2 headVect;
    Color BodyColor={74,156,106,255};

    while(temp!=NULL)
    {
        tempPos.x=temp->pos.x;
        tempPos.y=temp->pos.y;
        
        if(head==true)
        {
            if(direction==1)//Right
            {
                DrawTextureEx(temp->head.text,temp->pos,0.0f,1.0f,WHITE);
            }
            else
            {
                if(direction==2)//Left
                {
                    headVect.x=temp->pos.x+50;
                    headVect.y=temp->pos.y+50;
                    DrawTextureEx(temp->head.text,headVect,180.0f,1.0f,WHITE);
                }
                else
                {
                    if(direction==3)//Up
                    {
                        headVect.x=temp->pos.x;
                        headVect.y=temp->pos.y+50;
                        DrawTextureEx(temp->head.text,headVect,270.0f,1.0f,WHITE);
                    }
                    else
                    {
                        if(direction==4)//Down
                        {
                            headVect.x=temp->pos.x+50;
                            headVect.y=temp->pos.y;
                            DrawTextureEx(temp->head.text,headVect,90.0f,1.0f,WHITE);
                        }
                    }
                }
            }
            head=false;
        }
        else
        {
            DrawRectangle(tempPos.x,tempPos.y,50,50,BodyColor);
        }
        
        temp=temp->next;
    }
}

//Colision--------------------------------------------------

bool colision (struct Nodo **head,int startx, int limitX, int startY, int limitY)
{
    struct Nodo *temp=*head;
    temp=temp->next;
    while(temp!=NULL)
    {
        if((*head)->pos.x==temp->pos.x)
        {   
            if((*head)->pos.y==temp->pos.y)
            {
                return true;
            }
        }
        temp=temp->next;
    }

    if(((*head)->pos.x<startx )|| ((*head)->pos.x>=limitX))
    {
        return true;
    }
    if(((*head)->pos.y<startY) || ((*head)->pos.y>=limitY))
    {
        return true;
    }

    return false;
}

//Nodos-----------------------------------------------------

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
    newNodo->pos.x=temp->lastpos.x;
    newNodo->pos.y=temp->lastpos.y;
    temp->next=newNodo;
}

//Movimientos----------------------------------------------

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

int movSmooth (double tiempoEstimado, double *time)
{
    double timePass=GetTime();
    if((timePass - *time) > tiempoEstimado)
    {
        *time=timePass;
        return TRUE;
    }
    return FALSE;
}