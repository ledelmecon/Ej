#include "ClientesJuegos.h"
#include "utn.H"
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
void initClientes(eClientes clientes[], int maxi)
    {
                for(int i=0; i<maxi; i++)
                {
                    clientes[i].isEmpty=0;
                    clientes[i].codCliente=0;
                }
    }
int buscaLibre(eClientes clientes[], int maxi)
    {
    int retorno=-1;
        for (int i=0;i<maxi ;i++ )
                {if ((clientes[i].codCliente==0)&&(clientes[i].isEmpty==0))
                    {
                   retorno=i;
                   break;

                    }
                }
            return retorno;
    }
 void pedirDatosPersona(eClientes clientes[],eClientes cliente,int espaciolibre)
        {

                pedirStringValido(&cliente.name,"Ingrese Nombre:\n","\nSe exedio con el limite de caracteres permitido. \nIntente nuevamente:\n",31,1);//inicio de carga
                pedirStringValido(&cliente.lastname,"Ingrese Apellido:\n","Se exedio con el limite de caracteres permitido. \nIntente nuevamente:\n",31,1);
                cliente.sexo=pedirChar(cliente.sexo);
                pedirStringValido(&cliente.domicilio,"\nIngrese Domicilio:\n","Se exedio con el limite de caracteres permitido. \nIntente nuevamente:\n",51,1);
                pedirStringSoloNumero(cliente.telefono,"\nIngrese numero de telefono:\n",22);
                cargaPersona(clientes,cliente,espaciolibre);

         }

int cargaPersona(eClientes clientes[],eClientes clienteAux,int espacioLibre)
{
    clientes[espacioLibre].codCliente=espacioLibre+1;
    clientes[espacioLibre].isEmpty=1;
    strcpy(clientes[espacioLibre].name,clienteAux.name);
    strcpy(clientes[espacioLibre].lastname,clienteAux.lastname);
    clientes[espacioLibre].sexo=clienteAux.sexo;
    strcpy(clientes[espacioLibre].domicilio,clienteAux.domicilio);
    strcpy(clientes[espacioLibre].telefono,clienteAux.telefono);
    system("cls");
    printf("SE CARGO EXITOSAMENTE EL CLIEnTE\n*Cliente: %s %s\n",clientes[espacioLibre].name,clientes[espacioLibre].lastname);
    printf("*Numero de codigo: %d\n",clientes[espacioLibre].codCliente);
    printf("*Sexo: %c\n",clientes[espacioLibre].sexo);
    printf("*Domicilio: %s\n",clientes[espacioLibre].domicilio);
    printf("*Telefono: %s\n",clientes[espacioLibre].telefono);
    printf("                            \n\n\n");
    system("pause");
    system("cls");
    return 0;

 }


 int buscaClienteOperar(eClientes clientes[],int maxi)
        {   int i;
            int bandera=0;
            system("cls");
            for (i=0;i<maxi ;i++ )
                  {
                 if (clientes[i].isEmpty==1)
                    {
                    printf("\nCodigo de Cliente:%d Cliente:%s %s",clientes[i].codCliente, clientes[i].name,clientes[i].lastname);
                    bandera=1;


                    }

                  }
                  if(bandera==0){
                    printf("\n******No Hay Usuarios Activos******\n");
                    Sleep(1000);
                  }
           return bandera;
           }


int buscarClienteModificar (eClientes clientes[])
 {
        int bandera;
            do
            {
               bandera=0;
               int aux=pedirNumInt("\nIngrese Numero de Codigo a Modificar:\n");
               char nombreAuxi[51];
               char apellidoAux[51];
               char MoFaux;
               char direccionAux[51];
               char telefonoAux[21];
                if((clientes[aux-1].codCliente>=1)&&(clientes[aux-1].isEmpty==1))
                    {
                        system("cls");
                        printf("Codigo de Cliente Encontrado:\n");
                        printf("1-Nombre: %s\n",clientes[aux-1].name);
                        printf("2-Apellido: %s\n",clientes[aux-1].lastname);
                        printf("3-Sexo: %c\n",clientes[aux-1].sexo);
                        printf("4-Domicilio: %s\n",clientes[aux-1].domicilio);
                        printf("5-Telefono: %s\n",clientes[aux-1].telefono);
                        int aux2;
                        pedirNumIntValido(&aux2,"Ingrese opcion:","\nOpcion Incorrecta.Ingrese opcion detallada arriba:",6,0);

                        printf("\nla  opcion elegida es: %d\n",aux2);

                        switch (aux2)
                        {
                        case 1:
                            pedirStringValido(&nombreAuxi,"Ingrese Nombre:\n","\nSe exedio con el limite de caracteres permitido. \nIntente nuevamente:\n",10,1);
                            strcpy(clientes[aux-1].name,nombreAuxi);
                            system("cls");
                            printf("****Se cambio nombre*****\n*Nombre:%s\n",clientes[aux-1].name);
                            printf("*Apellido: %s\n",clientes[aux-1].lastname);
                            printf("*Sexo: %c\n",clientes[aux-1].sexo);
                            printf("*Direccion: %s\n",clientes[aux-1].domicilio);
                            printf("*Telefono: %s\n",clientes[aux-1].telefono);
                            printf("                            \n\n\n");
                            system("pause");
                            system("cls");
                            break;


                        case 2:
                            pedirStringValido(&apellidoAux,"Modifique Apellido:\n","\nSe exedio con el limite de caracteres permitido. \nIntente nuevamente:\n",10,1);
                            strcpy(clientes[aux-1].lastname,apellidoAux);
                            system("cls");
                            printf("*****Se cambio Apellido*****\n");
                            printf("*Nombre:%s\n",clientes[aux-1].name);
                            printf("*Apellido: %s\n",clientes[aux-1].lastname);
                            printf("*Sexo: %c\n",clientes[aux-1].sexo);
                            printf("*Direccion: %s\n",clientes[aux-1].domicilio);
                            printf("*Telefono: %s\n",clientes[aux-1].telefono);
                            printf("                            \n\n\n");
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            MoFaux=pedirChar(MoFaux);
                            clientes[aux-1].sexo=MoFaux;
                            system("cls");
                            printf("*****Se cambio Sexo*****\n");
                            printf("*Nombre:%s\n",clientes[aux-1].name);
                            printf("*Apellido: %s\n",clientes[aux-1].lastname);
                            printf("*Sexo: %c\n",clientes[aux-1].sexo);
                            printf("*Direccion: %s\n",clientes[aux-1].domicilio);
                            printf("*Telefono: %s\n",clientes[aux-1].telefono);
                            printf("                            \n\n\n");
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            pedirStringValido(&direccionAux,"Modifique Direccion:\n","\nSe exedio con el limite de caracteres permitido. \nIntente nuevamente:\n",51,1);
                            strcpy(clientes[aux-1].domicilio,direccionAux);
                            system("cls");
                            printf("*****Se cambio Direccion*****\n");
                            printf("*Nombre:%s\n",clientes[aux-1].name);
                            printf("*Apellido: %s\n",clientes[aux-1].lastname);
                            printf("*Sexo: %c\n",clientes[aux-1].sexo);
                            printf("*Direccion: %s\n",clientes[aux-1].domicilio);
                            printf("*Telefono: %s\n",clientes[aux-1].telefono);
                            printf("                            \n\n\n");
                            system("pause");
                            system("cls");

                            break;
                       case 5:
                            pedirStringSoloNumero(telefonoAux,"\nIngrese telefono:",22);
                            strcpy(clientes[aux-1].telefono,telefonoAux);
                            system("cls");
                            printf("*****Se cambio Telefono*****\n");
                            printf("*Nombre:%s\n",clientes[aux-1].name);
                            printf("*Apellido: %s\n",clientes[aux-1].lastname);
                            printf("*Sexo: %c\n",clientes[aux-1].sexo);
                            printf("*Direccion: %s\n",clientes[aux-1].domicilio);
                            printf("*Telefono: %s\n",clientes[aux-1].telefono);
                            printf("                            \n\n\n");
                            system("pause");
                            system("cls");
                            break;

                      }



                    }else{printf("\nError!Cliente no encontrado\n");
                          printf("Pruebe nuevamente:");
                          bandera=1;

                        }


            }while (bandera==1);
 }//fin funcion modificarcliente


int darBajaCliente(eClientes clientes[])
   {
    int retorno=-1;
    int bandera;
    int aux;
    do{
        bandera=0;
        printf("\n\nIngrese codigo de cliente a dar de Baja:");
        scanf("%d",&aux);
            if((clientes[aux-1].codCliente>=0)&&(clientes[aux-1].isEmpty==1))
                        {
                       clientes[aux-1].isEmpty=0;
                       printf("\n*******Usuario Borrado Con Exito****\n");


                        }else{

                printf("\nCodigo no encontrado pruebe con otro\n");
                bandera=1;
                }

        }    while(bandera==1);

            return retorno;

    }

void ordenarNombreAscendente(eClientes clientes[])
        {int i,j,r;
           eClientes aux;
            eClientes clientesaux[20];
            for(i=0;i<20;i++)
                {
                clientesaux[i]=clientes[i];
                }
                        for (i = 0; i < 20- 1; i++)
                                {
                                     for (j = i + 1; j < 20 ;j++)
                                    {

                                      r =strcmpi(clientesaux[i].lastname,clientesaux[j].lastname);
                                      if ((r > 0) || ((r==0) && (strcmpi(clientesaux[i].name, clientesaux[j].name) > 0)))
                                        {

                                         /* Intercambiar el valor de alumno[i] y alumno[j] */
                                         aux = clientesaux[i];
                                         clientesaux[i] = clientesaux[j];
                                         clientesaux[j] = aux;
                                       }
                                     }
                               }
               system("cls");
               printf("\nEmpleados ordenados alfabeticamente:\n");
               listarPersonas(clientesaux);
               printf("                            \n\n\n");
               system("pause");

          }


void listarPersonas(eClientes clientes[])
     {
      for(int i=0; i<20; i++)
                {
                    if( clientes[i].isEmpty==1)
                    {
                        printf("\nNombre:%s Apellido:%s\n",clientes[i].name,clientes[i].lastname);
                    }

                }

    }


void ordenarJuegosAscendente(eJuegos juegos[])
        {int i,j,r;
           eJuegos aux;
            eJuegos juegosaux[5];
            for(i=0;i<5;i++)
                {
                juegosaux[i]=juegos[i];
                }
                        for (i = 0; i < 5- 1; i++)
                                {
                                     for (j = i + 1; j < 5 ;j++)
                                    {

                                      r=strcmpi(juegosaux[i].descripcion,juegosaux[j].descripcion);
                                      if (r > 0)
                                        {

                                         /* Intercambia el valor de alumno[i] y alumno[j] */
                                         aux=juegosaux[i];
                                         juegosaux[i] = juegosaux[j];
                                         juegosaux[j] = aux;
                                       }
                                     }
                               }
               system("cls");
               printf("\nJuegos ordenados alfabeticamente:\n");
               listarJuegos(juegosaux);
               printf("                         \n\n\n");
               system("pause");

          }

void listarJuegos(eJuegos juegos[])
     {
      for(int i=0; i<5; i++)
                {

                        printf("\nCodigo:%d Descripcion:%s \n",juegos[i].codJuego,juegos[i].descripcion);

                }
     }

void initAlquiler(eAlquileres alquileres[])
     {
           for(int i=0; i<5; i++)
                {
                alquileres[i].fechas.dia=0;
                alquileres[i].fechas.mes=0;
                alquileres[i].fechas.anos=0;
                }

    }


int generarAlquilerJuegos(eAlquileres alquileres[],eJuegos juegos[],eClientes clientes[])
{           system("cls");
            printf("           ****JUEGOS EN ALQUILER****         \n");
            listarJuegos(juegos);
            int auxJuegos=pedirNumIntValido2("\nIngrese cod de juego a alquilar:","\nCodigo incorrecto,Pruebe nuevamente:",6,0);
            int auxCodAlquiler;
            int auxPosicion;
            int aux;
            int bandera;
            for (int i=0;i<50 ;i++ )
                    {
                     if(alquileres[i].fechas.anos==0)
                        {
                        auxCodAlquiler=i+1;
                        auxPosicion=i;
                        break;
                        }
                    }
            buscaClienteOperar(clientes,20);
            do{
                    aux=pedirNumInt("\nIngrese Numero de Codigo a Asignar:\n");
               if((clientes[aux-1].codCliente>=1)&&(clientes[aux-1].isEmpty==1))
                {
                bandera=1;
                alquileres[auxPosicion].codCliente=aux;
                alquileres[auxPosicion].codJuego=auxJuegos;
                alquileres[auxPosicion].codAlquiler=auxCodAlquiler;
                alquileres[auxPosicion].fechas.dia=pedirNumIntValido2("Ingrese Fecha de alquiler\n Ingrese Dia:","\nError Ingrese dia correcto:",31,0);
                alquileres[auxPosicion].fechas.mes=pedirNumIntValido2("Ingrese Mes:","\nError Ingrese mes correcto:",13,0);
                alquileres[auxPosicion].fechas.anos=pedirNumIntValido2("Ingrese Año:","\nError Ingrese año correcto:",2050,2018);

                }else
                        {printf("\nError!Cliente no encontrado\n");
                                  printf("Pruebe nuevamente:");
                                  bandera=0;

                        }
               }while(bandera==0);
               system("cls");
               printf("\n****Se alquilo juego****\n");
               printf("Fecha de alquiler:%d/%d/%d",alquileres[auxPosicion].fechas.dia,alquileres[auxPosicion].fechas.mes,alquileres[auxPosicion].fechas.anos);
               printf("\nCodigo de alquiler:%d Descripcion:%s \n",alquileres[auxPosicion].codAlquiler,juegos[auxJuegos-1].descripcion);
               printf("Alquilado a:\nNumero de cliente:%d Nombre:%s %s\n\n",clientes[aux-1].codCliente, clientes[aux-1].name,clientes[aux-1].lastname);

               system("pause");

}


void buscarOcurrencia(eAlquileres alquileres[],eJuegos juegos[],eClientes clientes[])
        {

        int auxalqui;
        int i,j,k;
        int bandera=0;
                system("cls");
                listarJuegos(juegos);
                auxalqui=pedirNumIntValido2("\nIngrese numero de Juego a Buscar:\n","Error Ingrese numero de juego valido:",6,0);
                for (i=0;i<5 ;i++ )
                    {

                    if(juegos[i].codJuego==auxalqui)
                        {
                        system("cls");
                        printf("Numero de Juego encontrado\n");
                            for (j=0;j<50 ;j++ )
                                {
                                 if(auxalqui==alquileres[j].codJuego)
                                    {
                                    printf("alquiler:\n");

                                    for (k=0;k<20;k++ )
                                        {

                                        if((alquileres[j].codCliente==clientes[k].codCliente)&&(clientes[k].isEmpty==1))
                                            {
                                            bandera=1;
                                            printf("Fecha de alquiler:%d/%d/%d",alquileres[j].fechas.dia,alquileres[j].fechas.mes,alquileres[j].fechas.anos);
                                            printf("\nCodigo de alquiler:%d Descripcion:%s \n",alquileres[j].codAlquiler,juegos[i].descripcion);
                                            printf("Alquilado a:\nNumero de cliente:%d Nombre:%s %s\n\n",clientes[k].codCliente, clientes[k].name,clientes[k].lastname);


                                            }

                                        }


                                    }


                                }

                        }


                    }if(bandera==0){
                    printf("\n\n********No hay alquileres para ese juego******\n\n");


                    }
                system("pause");

        }


void promedioTotalJuegos(eAlquileres alquileres[],eJuegos juegos[])
{  int acumulador=0;
   int contador=0;
    int i,j;
    for (i=0;i<50 ;i++ )
    {

    if(alquileres[i].codAlquiler>0)
        {
    for (j=0;j<5 ;j++ )
        {
        if(alquileres[i].codJuego==juegos[j].codJuego){
         acumulador=acumulador+juegos[j].importe;
         contador++;
         break;
            }


        }
        }
    }
    system("cls");
    printf("\nEl promedio de los juegos utilizados es: %d y el total es:%d \n\n",acumulador/contador,acumulador);
    system("pause");
    return acumulador/contador;

}



void  juegosNoSUperanPromedio(eAlquileres alquileres[],eJuegos juegos[])
{  int acumulador=0;
   int contador=0;
   int promedio;
   int cantidad=0;
    int i,j,k;
    for (i=0;i<50 ;i++ )
    {

    if(alquileres[i].codAlquiler>0)
        {
    for (j=0;j<5 ;j++ )
        {
        if(alquileres[i].codJuego==juegos[j].codJuego){
         acumulador=acumulador+juegos[j].importe;
         contador++;
         break;
            }


        }
        }
    }
    promedio=acumulador/contador;
    system("cls");
    printf("****Juegos que no superan el promedio****");
    for (k=0 ;k<5 ;k++ ){

    if(juegos[k].importe<=promedio)
        {
        printf("\nJuego:%s\n",juegos[k].descripcion);
        cantidad++;
        }
    }

    printf("Cantidad de juegos: %d\n",cantidad);
    system("pause");


}


void listarClientesQueAlquilaron(eAlquileres alquileres[],eClientes clientes[],eJuegos juegos[])
    {
        int bandera,aux,i,j;
        for (i=0;i<20 ;i++ )
        {

       if(clientes[i].isEmpty==1)
            {
            bandera=0;
            for (j=0;j<50 ;j++ )
                    {
                if((clientes[i].codCliente==alquileres[j].codCliente)&&(alquileres[j].fechas.anos>=2019))
                    {
                    if(bandera==0)
                    {
                     printf("\n\nCliente: %s %s \n",clientes[i].name,clientes[i].lastname);
                     bandera=1;
                     }
                     aux=alquileres[j].codJuego;
                     printf("    alquiler %d Juego: %s\n",alquileres[j].codAlquiler,juegos[aux-1].descripcion);

                    }
                }
            }
        }

      system("pause");
    }

void listarJuegosDeCliente(eClientes clientes[],eAlquileres alquileres[],eJuegos juegos[])
    {
     int j,aux,bandera;
     do
     {bandera=0;
     aux=pedirNumInt("\n\nIngrese Numero de cliente:");
     if(clientes[aux-1].isEmpty==1)
        { bandera=1;
              for (j=0;j<50 ;j++ )
                    {
                if((clientes[aux-1].codCliente==alquileres[j].codCliente)&&(alquileres[j].fechas.anos>=2019))
                    {

                     aux=alquileres[j].codJuego;
                     printf("    alquiler %d Juego: %s\n",alquileres[j].codAlquiler,juegos[aux-1].descripcion);

                    }
                     }
        }else{printf("\n**No se encontreo el usuario pruebe nuevamente**\n");}

     } while (bandera==0);
    system("pause");
    }
void listarJuegosMenosAlquilados(eAlquileres alquileres[],eJuegos juegos[])
{
    eJuegos juegosaux[5];
    juegosaux[0]=juegos[0];
    juegosaux[1]=juegos[1];
    juegosaux[2]=juegos[2];
    juegosaux[3]=juegos[3];
    juegosaux[4]=juegos[4];
    juegosaux[0].importe=0;
    juegosaux[1].importe=0;
    juegosaux[2].importe=0;
    juegosaux[3].importe=0;
    juegosaux[4].importe=0;
    eJuegos juego;
    int bandera=0;
    printf("\n\n****JUEGOS MENOS ALQUILADOS****\n");
    for (int i=0;i<50 ;i++ )
        {
           if(alquileres[i].codJuego==juegos[0].codJuego){
               juegosaux[0].importe=juegosaux[0].importe+1;

                }
               if(alquileres[i].codJuego==juegos[1].codJuego){
               juegosaux[1].importe=juegosaux[1].importe+1;
                }
                    if(alquileres[i].codJuego==juegos[2].codJuego){
               juegosaux[2].importe=juegosaux[2].importe+1;

                }
                    if(alquileres[i].codJuego==juegos[3].codJuego){
               juegosaux[3].importe=juegosaux[3].importe+1;

                }
                    if(alquileres[i].codJuego==juegos[4].codJuego){
               juegosaux[4].importe=juegosaux[4].importe+1;

                }
        }
          for (int i=0;i<5-1 ;i++ ){
                        for (int j=i+1;j<5 ;j++ ){
                             if(juegosaux[i].importe>juegosaux[j].importe){
                                 juego=juegosaux[i];
                                 juegosaux[i]=juegosaux[j];
                                 juegosaux[j]=juego;
                             }
                            }
                        }
           for (int i=0;i<5 ;i++ )
               {
                   if(juegosaux[0].importe==juegosaux[i].importe){
                    printf("\nJuego :%s cantidad de veces : %d\n",juegosaux[i].descripcion,juegosaux[i].importe);
                   }
               }
               system("pause");


}


void listarClientesQAlquilaronMas(eAlquileres alquileres[],eJuegos juegos[],eClientes clientes[])
{

int bandera=0;
printf("\n\n****CLIENTES QUE ALQUILARON MAS****\n");
    for (int i=0;i<20 ;i++ )
        {
        clientes[i].contador=0;
        }//pone en 0;
    for (int i=0;i<20 ;i++ )
        {
            if(clientes[i].isEmpty==1)
                {
                for (int j=0;j<50 ;j++ )
                    {
                    if(clientes[i].codCliente==alquileres[j].codCliente)
                        {
                           clientes[i].contador=clientes[i].contador+1;
                         }

                    }


                }
        }//fin de los contadores
           eClientes clientesaux;
           for (int i=0;i<20-1 ;i++ )
                        {
                        for (int j=i+1;j<20 ;j++ )
                            {
                                 if(clientes[i].contador<clientes[j].contador)
                                 {
                                     clientesaux=clientes[i];
                                     clientes[i]=clientes[j];
                                     clientes[j]=clientesaux;
                                 }
                                }
                            }//fin del burbujeo
        for (int i=0;i<20 ;i++ )
            {
                if((clientes[0].contador==clientes[i].contador)&&(clientes[i].contador>0))
                    {
                        printf("\nCLIENTE:%s %s COD:%d CANTIDAD DE JUEGOS:%d\n",clientes[i].name,clientes[i].lastname,clientes[i].codCliente,clientes[i].contador);
                        bandera=1;

                    }
            }
            if(bandera==0)
                    {
                    printf("\n\n***NO HAY DETALLES A MOSTRAR***\n\n");
                    }
     system("pause");
}



void listarJuegosenEnUnaFecha(eAlquileres alquileres[],eJuegos juegos[])

{
   eAlquileres aux;
   int i,j,bandera=0;
aux.fechas.dia=pedirNumIntValido2("Ingrese Fecha de alquiler\n Ingrese Dia:","\nError Ingrese dia correcto:",31,0);
aux.fechas.mes=pedirNumIntValido2("Ingrese Mes:","\nError Ingrese mes correcto:",13,0);
aux.fechas.anos=pedirNumIntValido2("Ingrese Año:","\nError Ingrese año correcto:",2050,2018);
for (i=0;i<50 ;i++ )
    {
        if((aux.fechas.dia==alquileres[i].fechas.dia)&&(aux.fechas.mes==alquileres[i].fechas.mes)&&(aux.fechas.anos==alquileres[i].fechas.anos))
            {
            for (j=0;j<5 ;j++ ){
                if(alquileres[i].codJuego==juegos[j].codJuego){
                printf(" \ncod alquiler:%d juego: %s\n",alquileres[i].codAlquiler,juegos[j].descripcion);
                bandera=1;
            }


            }
    }
    }
     if(bandera==0){
        printf("\n\n***NO HAY ALQUILERES EN ESA FECHA***\n\n");

     }
system("Pause");
}
void listarCLientesEnUnaFecha(eAlquileres alquileres[],eClientes clientes[])
{
eAlquileres aux;
int bandera= 0;
aux.fechas.dia=pedirNumIntValido2("Ingrese Fecha de alquiler\n Ingrese Dia:","\nError Ingrese dia correcto:",31,0);
aux.fechas.mes=pedirNumIntValido2("Ingrese Mes:","\nError Ingrese mes correcto:",13,0);
aux.fechas.anos=pedirNumIntValido2("Ingrese Año:","\nError Ingrese año correcto:",2050,2018);
 printf("\nALQUILERES EN LA FECHA INGRESADA:\n");
     for (int i=0;i<20 ;i++ )
        {
        clientes[i].contador=0;
        }//pone en 0;

for (int i=0;i<50 ;i++ )
    {
        if((aux.fechas.dia==alquileres[i].fechas.dia)&&(aux.fechas.mes==alquileres[i].fechas.mes)&&(aux.fechas.anos==alquileres[i].fechas.anos))
            {
            for (int j=0;j<20 ;j++ )
                {
                if(alquileres[i].codCliente==clientes[j].codCliente)
                {
                clientes[j].contador=clientes[j].contador+1;
                bandera=1;
                }


                }
            }
    }

 for (int i=0;i<20 ;i++ )
    {
     if(clientes[i].contador>=1){
        printf("\n*Cliente:%s %s Cod:%d *Cantidad de juegos alquilados en fecha:%d\n\n\n",clientes[i].name,clientes[i].lastname,clientes[i].codCliente,clientes[i].contador);

     }
     }
     if(bandera==0){
        printf("\n\n***NO HAY ALQUILERES EN ESA FECHA***\n\n");

     }
system("Pause");
}

void listarJuegosImporteDescendente(eJuegos juegos[])
{
 int j;
 eJuegos aux;
 eJuegos juegosAUX[5];
 int bandera=1;
for (int i=0;i<5 ;i++ ){
    juegosAUX[i]=juegos[i];
   }

 while (bandera==1)
     {
         bandera= 0;
         for (j = 1; j < 5; j++)
         {
         if (juegosAUX[j].importe>juegosAUX[j - 1].importe)
             {
             aux= juegosAUX[j];
             juegosAUX[j]= juegosAUX[j - 1];
             juegosAUX[j - 1]=aux;
             bandera=1;
            }
        }
     }
     printf("\n****JUEGOS ORDENADOS POR EL MAS CARO****\n");
     for (int i=0;i<5 ;i++ ){
        printf("\nJuego: %s Importe: %d\n",juegosAUX[i].descripcion,juegosAUX[i].importe);

     }
 system("Pause");
}
void listarPorInsercion(eClientes clientes[])
{
 int i,j;
 eClientes temp;
 eClientes clientesAux[20];
 for (int i=0;i<20 ;i++ )
    {
    clientesAux[i]=clientes[i];
    }

printf("\n***Usuarios Ordenados Por Apellido(Insercion)***\n");
 for(i=1;i<20;i++)
 {
temp = clientesAux[i];
j=i-1;
while((j>=0) && (0>strcmpi(temp.lastname,clientesAux[j].lastname))) // temp<data[j] o temp>data[j]
{
 clientesAux[j+1] = clientesAux[j];
 j--;
}
clientesAux[j+1]=temp; // inserción
 }
for (i=0;i<20 ;i++)
    {
    if(clientesAux[i].isEmpty==1){
        printf("\nUsuario: %s %s Cod: %d\n",clientesAux[i].name,clientesAux[i].lastname,clientesAux[i].codCliente);
        }
    }
system("pause");
}

