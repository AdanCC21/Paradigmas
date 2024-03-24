#include <stdio.h>
#include "raylib.h"
#define TRUE 1
#define FALSE 0

struct Manzana
{
    Vector2 Fpos;
};

//Prototype-----
Vector2 spawnfood(struct Nodo **head,int gridx,int gridy);
void drawFood(struct Manzana apple);

//Funciones
void drawFood(struct Manzana apple)
{
    DrawRectangle(apple.Fpos.x,apple.Fpos.y,50,50,BLACK);
}

Vector2 spawnfood(struct Nodo **head,int gridx,int gridy)
{
    Vector2 temp;
    bool clean=true;
    do
    {
        clean=true;
        temp.x =GetRandomValue(2,(gridx -2));
        temp.y= GetRandomValue(1,(gridy + 1));
        temp.x=temp.x*50;
        temp.y=temp.y*50;

        struct Nodo *body=*head;//Snake Body
        while(body->next!=NULL)
        {
            if(temp.x==body->pos.x)
            {
                if(temp.y==body->pos.y)
                {
                    clean=false;
                }
            }
            if(temp.y==body->pos.y)
            {
                if(temp.x==body->pos.x)
                {
                    clean=false;
                }
            }
            body=body->next;
        }
    } while (clean==false);
    
    return temp;
}