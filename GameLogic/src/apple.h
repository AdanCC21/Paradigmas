#include <stdio.h>
#include "raylib.h"
#define TRUE 1
#define FALSE 0

struct Manzana
{
    Vector2 Fpos;
};

//Prototype-----
Vector2 spawnfood(int gridx,int gridy);
void drawFood(struct Manzana apple);

//Funciones
void drawFood(struct Manzana apple)
{
    DrawRectangle(apple.Fpos.x,apple.Fpos.y,50,50,BLACK);
}

Vector2 spawnfood(int gridx,int gridy)
{
    Vector2 temp;
    temp.x =GetRandomValue(0,(gridx -1));
    temp.y= GetRandomValue(0,(gridy -1));
    temp.x=temp.x*50;
    temp.y=temp.y*50;
    return temp;
}