#include <stdio.h>
#include "raylib.h"
#define TRUE 1
#define FALSE 0

struct Manzana
{
    struct img appleIcon;
    Vector2 Fpos;
};

//Prototype--------------------------------------------------
Vector2 spawnfood(struct Nodo **head,int gridx,int gridy);
void drawFood(struct Manzana apple);

//Funciones--------------------------------------------------
struct img initIMGapple()
{
    struct img apple;
    //apple--------------------------------------------------
    apple.img=LoadImage("assets/photos/icons/Apple.png");
    apple.text=LoadTextureFromImage(apple.img);
    
    apple.pos.x=0.0;
    apple.pos.y=0.0;
    
    apple.Height=apple.img.height;
    apple.Width=apple.img.width;
    UnloadImage(apple.img);
    
    return apple;
}

void drawFood(struct Manzana apple)
{
    DrawTextureEx(apple.appleIcon.text,apple.Fpos,0.0f,1.0f,WHITE);
}

Vector2 spawnfood(struct Nodo **head,int gridx,int gridy)
{
    Vector2 temp;
    bool clean=true;
    do
    {
        clean=true;
        temp.x =GetRandomValue(2,(gridx -2));
        temp.y= GetRandomValue(1,(gridy));
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