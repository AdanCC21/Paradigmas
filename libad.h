/*  
    Libreria personal
    Gonzalez Cesena Adan
    Version 03/04/2024
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//      ------Funciones------      //

//  Validacion de numeros
int valid (int ri, int rf)//Rango inicial, Rango final
{
    char cad[50];
    int n;
    do
    {
        fflush(stdin);
        fgets(cad, sizeof(cad),stdin);        
        n=atoi(cad);
        if(n>rf || n<ri)
        {
            printf("%s\n","Opcion no valida");
        }
    }
    while(n>rf || n<ri);
    return n;
}

//  Validacion de characteres
int validCh(char cadena[])
{
    int i=0;
    unsigned char caract;

    if (cadena[0] == ' ')
    {
        printf("Tu texto no puede iniciar con un espacio\n");
        return 1;
    }
    if (cadena[0] == '\0')
    {
        printf("Texto vacio\n");
        return 1;
    }

    while (cadena[i] != '\0')
    {
        caract=(unsigned char)cadena[i];

        if ( (cadena[i] >= 'A' && cadena[i] <= 'Z') ||(cadena[i] >= 'a' && cadena[i] <= 'z') )
        {
            //No hace nada
        }
        else
        {
            if(caract == 164 || caract == 165 ) //ñ
            {
                //No hace nada
            }
            else
            {
                if (cadena[i] == ' ')
                {
                    if (cadena[i + 1] == ' ')
                    {
                        printf("Espacios dobles no estan permitidos\n");
                        return 1;
                    }
                }
                else
                {
                    printf("Simbolos no permitidos\n");
                    return 1;
                }
            }
        }
        i++;
    }
    return 0;
}

//Contador de caracteres
/*  cadena[]=Mensaje a contar
    limit=maximo de caracteres
    true=Supero el maximo, false=No lo paso*/
int validChCont(char cadena[], int limit)
{
    int i;
    for(i=0;cadena[i]!='\0';i++);
    if(i>limit)
    {
        printf("Numero de caracteres superado\nLimite %d caracteres\n",limit);
        return 1;
    }
    else
    {
        return 0;
    }
}

//Minusculas a mayusculas
void minus (char cad[])
{
    for(int i=0; cad[i]!='\0';i++)
    {
        if(cad[i]>='a')
        {
            if(cad[i]<='z')
            {
                cad[i]-=32;
            }
        }
        if(cad[i] == -92) //ñ
        {
            cad[i] = -91; //Ñ
        }
    }
}
