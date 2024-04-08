/*  
    Libreria de busquedas en c
    Gonzalez Cesena Adan
    Version 03/04/2024
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//  Busqueda secuencial en un arreglo   //
int bus_sec (int vect [],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i]==num) //Si llega a encontrar que en posicion i esta el numero buscado retornara la posicion
        {
            return i;
        }
    }
    return -1; 
    //de lo contrario lanzara un -1, que este esta fuera del rango de cualquier arreglo/cadena evitando lanzar una posicion erronea
}

//  Busqueda Binaria en un arreglo ordenado //
int buscbin(int vect[], int lef, int rig, int num)
{
    int med;
    while (lef <= rig)
    {
        med = lef + (rig - lef) / 2;
        
        if (vect[med] == num)
        {
            return med;
        }

        if (vect[med] < num)
        {
            lef = med + 1;
        }
        else
        {
            rig = med - 1;
        }
    }
    return -1;
}

//  Generaicon de numeros aleatorios sin repetir
int num_alea_sr (int vect[], int n, int ri, int rf)
{
    int c, i;
    for(i=0;i<n;i++)
    {
        do
        {
            c=rand() % (rf-ri+1)+ri;
            //Generara un numero aleatorio entre los rangos recibidos
        }
        while(bus_sec(vect,n,c)!=-1);
        //hara una busqueda entre el arreglo para ver si el numero aleatorio generado ya esta puesto en alguna otra posicion
        
        vect[i]=c; 
        //de no ser el caso la busqueda lanzara un -1 y por lo tanto saldra del ciclo do while
    }
    return 0;
}
