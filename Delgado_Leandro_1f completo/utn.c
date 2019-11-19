#include "utn.h"
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

int menu(char TextoMenu[])
    {
        printf("\n %s ",TextoMenu);
        printf("\n 0 - Salir");
        printf("\n Ingrese Opcion: ");
        int opcion;
        pedirNumIntValido(&opcion,"","Error!Ingrese opcion valida\nIngrese opcion:",17,-1);
        return opcion;

    }
int menu2(char TextoMenu[])
    {
        printf("\n %s ",TextoMenu);
        printf("\n 0 - Salir");
        printf("\n Ingrese Opcion: ");
        int opcion;
        opcion=pedirNumIntValido2("","Error!Ingrese opcion valida\nIngrese opcion:",3,-1);
        return opcion;

    }

void pedirString(char nombres[], char mensajeIngreso[])
{
    printf("%s", mensajeIngreso);
    fflush(stdin);
    gets(nombres);
}


char pedirChar (char mOf)
            {
                int bandera;

                do
                {
                  bandera=0;
                  printf("Ingrese Sexo(M/F): ");
                mOf=getche();
                  if((toupper(mOf)=='M'))
                  {
                     printf("\nMasculino");
                  }
                  else
                  {
                        if((toupper(mOf)=='F'))
                        {
                            printf("\nFemenino");
                        }
                        else
                        {
                            printf("\nOpcion no Valida ingrese M o F\n");
                            bandera=1;
                        }
                  }//fin if(mOf=='M')
                }while (bandera==1);
               return mOf;
            }

void pedirStringValido(char* imput, char mensajeIngreso[], char mensajeDeError[], int max,int min)
{
    printf("%s",mensajeIngreso);
   fflush(stdin);
    gets(imput);
    while(strlen(imput)>max || strlen(imput)<min)
    {
        printf("%s",mensajeDeError);
        fflush(stdin);
        gets(imput);
    }
}



int pedirNumInt(char mensajeIngreso[])
    {
        int reto;
        printf("%s",mensajeIngreso);
        scanf("%d",&reto);
        fflush(stdin);

        return reto;
    }


int pedirNumIntValido(int* imput,char mensajeIngreso[],char mensajeDeError[],int Maxi, int Mini)
    {
        printf("%s",mensajeIngreso);
        scanf("%d",imput);
        fflush(stdin);
        while(*imput<=Mini || *imput>=Maxi || isdigit(*imput)!=0)
        {
            printf(mensajeDeError);
            scanf("%d",imput);
            fflush(stdin);
        }
        return 0;
    }

int pedirNumIntValido2(char mensajeIngreso[],char mensajeDeError[],int Maxi, int Mini)
    {
        int aux=pedirNumInt(mensajeIngreso);
        while(aux<=Mini || aux>=Maxi)
        {
            aux=pedirNumInt(mensajeDeError);

        }
        return aux;
    }

int pedirNumIntValido3(char mensajeIngreso[],char mensajeDeError[],int Maxi, int Mini)
    {
        int aux=pedirNumInt(mensajeIngreso);
       /* while(aux<=Mini || aux>=Maxi)
        {
            aux=pedirNumInt(mensajeDeError);

        }*/
        return aux;
    }

void pedirStringSoloNumero(char reto[], char mensajeIngreso[], int MAXi)
{
    char stringaxuliar[100];
    int bandera1;
    do{pedirString(stringaxuliar,mensajeIngreso);
    int i=0,j;
    bandera1=0;
    j=strlen(stringaxuliar);
    while((i<j&&bandera1==0))
        {
            if(isdigit(stringaxuliar[i])!=0)
            {
            i++;
            }else
                {
                bandera1=1;
                printf("Solo se admiten numeros\n");

               }

        }

      if (strlen(stringaxuliar)>MAXi-1)
                {
                   printf("Se exedio con el limite de caeacteres\n");
                   bandera1=1;
                }


        }while (bandera1==1);

    strcpy(reto,stringaxuliar);
}

/*
int pedirNumIntValido(char mensajeIngreso[],char mensajeDeError[],int Maxi, int Mini)
    {
        int aux=pedirNumInt(mensajeIngreso);
        while(aux<=Mini || aux>Maxi)
        {
            aux=pedirNumInt(mensajeDeError);

        }
        return aux;
    }*/


/*void pedirStringValido(char reto[], char mensajeIngreso[], char mensajeDeError[], int MAXi)
{
    char stringaxuliar[100];
    pedirString(stringaxuliar,mensajeIngreso);
    while(strlen(stringaxuliar)>MAXi-1)
    {
        //printf("El nombre ingresado supera el limite permitido de caracteres\n"),
        pedirString(stringaxuliar,mensajeDeError);
    }
    strcpy(reto,stringaxuliar);
}*/
