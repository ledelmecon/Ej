#include <stdio.h>
#include <stdlib.h>
#include "ClientesJuegos.h"
#include "utn.h"
#define stringMaximo 10
#include <string.h>
#include <windows.h>
#include <ctype.h>
int main()
{
    char seguir='s';
    int bandera;
    int error;
    int libreAux;
    eClientes clientes[20];
    eClientes clienteAux;
    eAlquileres alquileres[50];
    eJuegos juegos[5];
    initClientes(clientes,20);
    initAlquiler(alquileres);
    strcpy(juegos[0].descripcion,"Pelotero");//Juegos Hardcode
    strcpy(juegos[1].descripcion,"Metegol");
    strcpy(juegos[2].descripcion,"PlayStation");
    strcpy(juegos[3].descripcion,"Pool");
    strcpy(juegos[4].descripcion,"castillo inflable");
    juegos[0].codJuego=1;
    juegos[1].codJuego=2;
    juegos[2].codJuego=3;
    juegos[3].codJuego=4;
    juegos[4].codJuego=5;
    juegos[0].importe=250;
    juegos[1].importe=100;
    juegos[2].importe=150;
    juegos[3].importe=200;
    juegos[4].importe=300;


 while (seguir=='s')
    {
      int opcion=menu("\n Ingrese Opcion:"
          "\n 1 - Alta de Cliente"
          "\n 2 - Modificar Datos Cliente (codigo de cliente)"
          "\n 3 - Dar de baja Cliente "
          "\n 4 - Ordenar por Apellido y nombre"
          "\n 5 - Ordenar Juegos por Descripcion"
          "\n 6 - Generar Alquiler/Buscar ocurrencias"
          "\n 7 - Promedio y total de los juegos Alquilados"
          "\n 8 - Juegos que no superan el promedio"
          "\n 9 - Clientes que alquilaron un juego"
          "\n 10- Listar juegos alquilados"
          "\n 11- Listar el o los Juegos menos aquilados"
          "\n 12- Listar el o los clientes que alquilaron mas juegos"
          "\n 13- Listar los juegos alquilados en una fecha determinada"
          "\n 14- Listar los clientes que alquilaron al menos un juego en una fecha determinada"
          "\n 15- Listar los juegos ordenados por importe(descendente)burbujero mas eficiente"
          "\n 16- Listar todos los clientes por Apellido(ascendente)utilizando insercion"

          );


          switch (opcion)
          {
              case 1:
               Sleep(500);
                system("cls");
                libreAux=buscaLibre(clientes,20);//codCLiente autoincremental
                printf("El espacio libre es:%d \n",libreAux);
                if(libreAux>=0)
                 {
                    pedirDatosPersona(clientes,clienteAux,libreAux);//Pide datos de la persona y las carga con la funcion incluida de carga

                 }else
                    {
                     printf("\nERROR!!\nNo hay mas espacio en el sistema para guardar un cliente");
                    }
                bandera=1;
                break;
             case 2:
                error=buscaClienteOperar(clientes,20);
                if(error==1)
                    {
                     buscarClienteModificar(clientes);}
                     Sleep(1000);
                     system("cls");
                     break;
              case 3:
                error=buscaClienteOperar(clientes,20);
                if(error==1)
                {
                    darBajaCliente(clientes);
                 }
                     Sleep(1000);
                     system("cls");
                     break;
               case 4:
                    error=buscaClienteOperar(clientes,20);
                    if(error==1)
                        {
                         ordenarNombreAscendente(clientes);
                         }
                         Sleep(1000);
                         system("cls");
                         break;
            case 5:
                     ordenarJuegosAscendente(juegos);
                       Sleep(1000);
                         system("cls");
                       break;
            case 6:
                     error=buscaClienteOperar(clientes,20);
                     Sleep(20);
                     system("cls");
                    if(error==1)
                        {   int opcion2=menu2("\n6-1-Generar alquiler\n"
                                             "\n6-2 Buscar ocurrencia\n");
                            switch (opcion2)
                        {
                        case 1:
                            generarAlquilerJuegos(alquileres,juegos,clientes);
                             break;
                        case 2:
                            buscarOcurrencia(alquileres,juegos,clientes);
                            break;
                        }

                    }
                         Sleep(1000);
                         system("cls");
                         break;
            case 7:
                      error=buscaClienteOperar(clientes,20);
                    if(error==1)
                        {
                         promedioTotalJuegos(alquileres,juegos);}
                         Sleep(1000);
                         system("cls");
                         break;
            case 8:
                   error=buscaClienteOperar(clientes,20);
                    if(error==1)
                        {
                         juegosNoSUperanPromedio(alquileres,juegos);}
                         Sleep(1000);
                         system("cls");
                         break;
                case 9:

                         listarClientesQueAlquilaron(alquileres,clientes,juegos);
                         Sleep(1000);
                         system("cls");
                         break;
                case 10:

                           error=buscaClienteOperar(clientes,20);
                    if(error==1)
                        {
                         listarJuegosDeCliente(clientes,alquileres,juegos);}
                         Sleep(1000);
                         system("cls");
                         break;
                case 11:
                            error=buscaClienteOperar(clientes,20);
                            system("cls");
                    if(error==1)
                        {
                            listarJuegosMenosAlquilados(alquileres,juegos);
                         }
                         Sleep(1000);
                         system("cls");
                         break;
                  case 12:
                            error=buscaClienteOperar(clientes,20);
                            system("cls");
                    if(error==1)
                        {
                            listarClientesQAlquilaronMas(alquileres,juegos,clientes);
                         }
                         Sleep(2000);
                         system("cls");
                         break;

                case 13:
                            error=buscaClienteOperar(clientes,20);
                            system("cls");
                    if(error==1)
                        {
                            listarJuegosenEnUnaFecha(alquileres,juegos);
                         }
                         Sleep(1000);
                         system("cls");
                         break;

                   case 14:
                            error=buscaClienteOperar(clientes,20);
                            system("cls");
                    if(error==1)
                        {
                            listarCLientesEnUnaFecha(alquileres,clientes);
                         }
                         Sleep(2000);
                         system("cls");
                         break;

                   case 15:
                         system("cls");
                         listarJuegosImporteDescendente(juegos);
                         Sleep(2000);
                         system("cls");
                         break;
                   case 16:
                            error=buscaClienteOperar(clientes,20);
                            system("cls");
                         if(error==1)
                        {
                            listarPorInsercion(clientes);
                         }

                         Sleep(2000);
                         system("cls");
                         break;



            case 0:
                        seguir='n';
                            break;

                  default:
                      break;





          }//fin del switch

            }//fin del while



}
