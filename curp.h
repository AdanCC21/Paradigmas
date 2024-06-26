#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//      ------Prototipos------      //

//  Generacion de curp y sus validaciones

    /*Datos a meter
            
        cadena de la curp donde se retornara la cadena llena

        Verificacion de datos
        1=Si, 2=No
        names2 = Tiene 2 nombres?
        ap2= tiene 2 apellidos?
        ap1= tiene 1 apellido?

        Datos
        name = Nombre
        name2 = Segundo nombre
        app = Apellido paterno
        apm = Apellido materno

        day = dia de nacimiento
        month = mes de nacimiento
        year = anio de nacimiento

        gen = genero (1.-Hombre, 2.-Mujer)
        estado = lugar de nacimiento (Se presentara en el programa original una lista de estados y tomara el indice del estado, indice del 1 al 33)
    */
    void CU_Auto_Gen (char curp[], int names2, int ap2, int ap1, char name[],char name2[], char app[], char apm[], int day, int month, int  year, int gen, int estado);
    //  Validaciones
    void CUvalidAc (char cad[]);

    void CUdes (char name[]);

    void CUantisonantes (char curp[]);

//      ------Funciones------       //

// ---------------------------------------- CURP ------------------------------------------ //

void CU_Auto_Gen (char curp[], int names2, int ap2, int ap1, char name[],char name2[], char app[], char apm[], int day, int month, int  year, int gen, int estado)
{
    /*
        Datos
        cadena de la curp donde se retornara la cadena llena

        Verificacion de datos
        1=Si, 2=No
        names2 = Tiene 2 nombres?
        ap2= tiene 2 apellidos?
        ap1= tiene 1 apellido?

        Datos
        name = Nombre
        name2 = Segundo nombre
        app = Apellido paterno
        apm = Apellido materno

        day = dia de nacimiento
        month = mes de nacimiento
        year = anio de nacimiento

        gen = genero (1.-Hombre, 2.-Mujer)
        estado = lugar de nacimiento (Se presentara en el programa original una lista de estados y tomara el indice del estado, indice del 1 al 33)
    */

    //      -----------------------------nombre y apellidos-----------------------------       //
    CUvalidAc(name);
    CUdes(name);

    //Si tiene segundo nombre
    if(names2==1)
    {
        CUvalidAc(name2);    
        CUdes(name2);
    }
    //Si tiene 1 apellido
    if(ap1==1)
    {
        CUvalidAc(app);
        CUdes(app);
    }
    //Si tiene 2 apellidos
    if(ap2==1)
    {
        CUvalidAc(apm);
        CUdes(apm);
    }

    int np,band,usada,i,h,k,c;
    np=strlen(app);
    c=0;
    h=0;
    //Iniciales/Vocales del primer apellido
    if(ap1==1)
    {
        //Inicial del primer apellido
        curp[0]=app[0];
    
        //Vocal del primer apellido
        for(i=0;i<np;i++)
        {
            if(band<=0)
            {
                usada=0;
                for(k=c;h<np;h++)
                {
                    if(app[k]==curp[0])
                    {
                        usada=1;
                    }
                }
                if(usada==0)
                {
                    if(app[i]== 'A')
                    {
                        curp[1]=app[i];
                        band++;
                    }
                    else
                    {
                        if(app[i]=='E')
                        {
                            curp[1]=app[i];
                            band++;
                        }
                        else
                        {
                            if(app[i]=='I')
                            {
                                curp[1]=app[i];
                                band++;
                            }
                            else
                            {
                                if(app[i]=='O')
                                {
                                    curp[1]=app[i];
                                    band++;
                                }
                                else
                                {
                                    if(app[i]=='U')
                                    {
                                        curp[1]=app[i];
                                        band++;
                                    }
                                }
                            }
                        }
                    }
                }
                c++;
            }
        }
        if(band==0)
        {
            curp[1]='X';
        }
    }
    else
    {
        curp[0]='X';
        curp[1]='X';
    }

    //Inicial del 2do apellido
    if(ap2==1)
    {
        curp[2]=apm[0];
    }
    else
    {
        curp[2]='X';
    }

    //Inicial del Nombre
    if(names2==1)
    {
        if( strcmp(name,"MARIA") == 0 || strcmp(name,"MA.") == 0 || strcmp(name,"MA") == 0 || strcmp(name,"M.") == 0 || strcmp(name,"M") == 0)
        {
            curp[3]=name2[0];
        }
        else
        {
            if(strcmp(name,"JOSE") == 0 || strcmp(name,"J") == 0 || strcmp(name,"J.") == 0)
            {
                curp[3]=name2[0];
            }
            else
            {
                curp[3]=name[0];
            }    
        }
    }
    else
    {
        curp[3]=name[0];
    }

    //      -----------------------------Anio de nacimiento------------------------------       //
    char cad[4];

    //  Anio    //
    
    curp[4]=cad[2];
    curp[5]=cad[3];

    // Month    //
    itoa(month,cad,10);

    if(month<10)
    {
        curp[6]='0';
        curp[7]=cad[0];
    }
    else
    {
        curp[6]=cad[0];
        curp[7]=cad[1];
    }

    // Days     //
    // tendra que venir validado el dia con el mes desde el programa exterior//
    itoa(day,cad,10);
    
    if(day<10)
    {
        curp[8]='0';
        curp[9]=cad[0];
    }
    else
    {
        curp[8]=cad[0];
        curp[9]=cad[1];
    }

    //      -----------------------------   Genero  ------------------------------       //
    //                                1=Hombre  2.-Mujer                                 //

    if(gen==1)
    {
        curp[10]='H';
    }
    else
    {
        curp[10]='M';
    }

    //      -----------------------------     Zona   ------------------------------       //
    //      Vas a tener que imprimir la lista de estados desde el programa inicial        //

    char cadEstado[33][3] = {"AS","BC","BS","CC","CS","CH","CL","CM","DG","GT","GR","HG","JC","MC","MN",
    "MS","NT","NL","OC","PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS","DF","NE"};

    curp[11] = cadEstado[estado - 1][0];
    curp[12] = cadEstado[estado - 1][1];

    //      --------------------     Consonantes internas   ----------------------       //
    int j,n;
    int usadaC=0,BandVoc=0, bandU=0;
    char vocal[5]={'A','E','I','O','U'};

    //Primera consonante
    bandU=0;
    if(ap1==1) //Si tiene 1 apellido (Paterno)
    {
        n=strlen(app);
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                if(app[i]==vocal[j])
                {
                    BandVoc=1;
                }
            }
            if(BandVoc==0)
            {
                for(k=0;k<5;k++)
                {
                    if(app[i]==curp[k])
                    {
                        
                        usadaC=1;
                    }
                }
                if(usadaC==0)
                {            
                    curp[13]=app[i];
                    i=n+1;
                    bandU=1;
                }
                usadaC=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[13]='X';
        }
    }
    else //Si no tiene apellidos
    {
        curp[13]='X';
    }
    
    //Segunda consonante
    bandU=0;
    usadaC=0;
    if(ap2==1) //Si tiene 2 apeidos
    {
        n=strlen(apm);
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                if(apm[i]==vocal[j])
                {
                    BandVoc=1;
                }
            }
            if(BandVoc==0)
            {
                for(k=0;k<5;k++)
                {
                    if(apm[i]==curp[k])
                    {
                        
                        usadaC=1;
                    }
                }
                if(usadaC==0)
                {            
                    curp[14]=apm[i];
                    i=n+1;
                    bandU=1;

                }
                usadaC=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[14]='X';
        }

    }
    else //Si solo tiene 1 apeido
    {
        curp[14]='X';
    }

    //Tercera Consonante
    bandU=0;
    usadaC=0;
    if(names2==2)//Si tiene 1 nombre
    {
        n=strlen(name);
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                if(name[i]==vocal[j])
                {
                    BandVoc=1;
                }
            }
            if(BandVoc==0)
            {
                for(k=0;k<5;k++)
                {
                    if(name[i]==curp[k])
                    {
                        
                        usadaC=1;
                    }
                }
                if(usadaC==0)
                {            
                    curp[15]=name[i];
                    i=n+1;
                    bandU=1;
                }
                usadaC=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[15]='X';
        }
    }
    else //Si tiene 2 nombres
    {
        //Maria Jose
        if(strcmp(name,"MARIA") == 0 || strcmp(name,"MA.") == 0 || strcmp(name,"MA") == 0 || strcmp(name,"M.") == 0 || strcmp(name,"M") == 0 || strcmp(name,"JOSE") == 0 || strcmp(name,"J") == 0 || strcmp(name,"J.") == 0)
        {
            n=strlen(name2);
            for(i=0;i<n;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(name2[i]==vocal[j])
                    {
                        BandVoc=1;
                    }
                }
                if(BandVoc==0)
                {
                    curp[15]=name2[i];
                    i=n+1;
                    bandU=1;    
                }
                BandVoc=0;    
            }
            if(bandU==0)
            {
            curp[15]='X';
            }
        }
        else
        {
            n=strlen(name);
            for(i=0;i<n;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(name[i]==vocal[j])
                    {
                        BandVoc=1;
                    }
                }
                if(BandVoc==0)
                {
                    for(k=0;k<5;k++)
                    {
                        if(name[i]==curp[k])
                        {
                            
                            usadaC=1;
                        }
                    }
                    if(usadaC==0)
                    {            
                        curp[15]=name[i];
                        i=n+1;
                        bandU=1;
                    }
                    usadaC=0;
                }
                BandVoc=0;
            }

            if(bandU==0)
            {
                curp[15]='X';
            }
        }
    }

    //      --------------------     Penultima letra/Siglo   ----------------------       //
    char Scad[1];
    c=0;

    if(year<2000)
    {
        c=rand()% (9-0+1)-0;
        itoa(c,Scad,10);
        curp[16]=Scad[0];
    }
    else
    {   
        if(year<=2010)
        {
            Scad[0]='A';
        }
        else
        {
            if(year<=2020)
            {
                Scad[0]='B';
            }
            if(year<=2030)
            {
                Scad[0]='C';
            }
        }
        curp[16]=Scad[0]; 
    }
    //      --------------------     Ultima letra/Aleatoria   ----------------------       //
    c=rand()% (9-0+1)-0;
    itoa(c,Scad,10);
    curp[17]=Scad[0];

    //      --------------------        Antisonantes          ----------------------       //
    CUantisonantes(curp);
}
// ------------------------------Validaciones del CURP ------------------------------------------ //
void CUvalidAc (char cad[])
{
    int i,n;
    unsigned char caract;
    n=strlen(cad);
    for(i=0;i<n;i++)
    {
        caract=(unsigned char)cad[i];

        if(caract==181)
        {
            cad[i]='A';
        }
        if(caract==142)
        {
            cad[i]='A';
        }

        if(caract==144)
        {
            cad[i]='E';
        }
        if(caract==211)
        {
            cad[i]='E';
        }

        if(caract==214)
        {
            cad[i]='I';
        }
        if(caract==216)
        {
            cad[i]='I';
        }

        if(caract==224)
        {
            cad[i]='O';
        }
        if(caract==153)
        {
            cad[i]='O';
        }

        if(caract==233)
        {
            cad[i]='U';
        }
        if(caract==154)
        {
            cad[i]='U';
        }
        if(caract==164)
        {
            cad[i]='X';
        }
        if(caract==165)
        {
            cad[i]='X';
        }
        if(caract==44)
        {
            cad[i]='X';
        }
        if(caract==45)
        {
            cad[i]='X';
        }
        if(caract==46)
        {
            cad[i]='X';
        }
        if(caract==47)
        {
            cad[i]='X';
        }
        if(caract==39)
        {
            cad[i]='X';
        }
        if(caract==239)
        {
            cad[i]='X';
        }
    }
}

void CUdes (char name[])
{
    char conj[19][4]={"DA","DAS","DE","DEL","DER","DI","DIE","DD","EL","LA","LOS","LAS","LE","LES","MAC","MC","VAN","VON","Y"};
    int lon,i,k,esp=0;
    lon=strlen(name);
    
    for(k=0;k<=lon;k++)
    {
        if(name[k]==' ')
        {
            esp=k;
        }
    }

    i=0;
    if(esp>0)
    {
        for(k=0;k<=lon;k++)
        {
            if(strstr(name,conj[k])==0)
            {
                do
                {
                    name[i]=name[esp+1];
                    i++;
                    esp++;
                }
                while(esp<lon);
            }
        }
    }
}

void CUantisonantes (char curp[])
{
    char antisonantes[][100] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE","COJI", "COJO", "COLA", "CULO", "FALO", 
    "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA","KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", 
    "LOCO","LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA","NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", 
    "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO","RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    char cad[5];
    strncpy(cad,curp,4);
    cad[4]='\0';
    for (int i = 0; i <= 81; i++)
    {
        if (strcmp(cad, antisonantes[i]) == 0)
        {
            curp[1]='X';
        }
    }
}

//// --------------------------------Fin del CURP ------------------------------------------ //