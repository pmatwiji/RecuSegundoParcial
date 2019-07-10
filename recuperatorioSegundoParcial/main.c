#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peliculas.h"
#include "menu.h"
#include "validaciones.h"

int main()
{
    int option;
    int test;
    char path[50];
    char genero[50];

    LinkedList* listaPeliculas = ll_newLinkedList();
    LinkedList* listaDepurada = ll_newLinkedList();
    LinkedList* listaPorGenero = ll_newLinkedList();

    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv': ",path);
            test = controller_load(path,listaPeliculas);
            if(test==TRUE)
            {
                printf("\nPeliculas cargadas con exito.\n\n");
            }
            while(test!=TRUE)
            {
                printf("\nError, no se pudo cargar los datos.\n");
                getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv': ",path);
                test = controller_load(path,listaPeliculas);
                if(test==TRUE)
                {
                    printf("\nPeliculas cargadas con exito.\n\n");
                }

            }
            system("pause");
            system("cls");
            break;
        case 2:
//            if(ll_isEmpty(listaPeliculas) == 1)
//            {
//                printf("\nNo hay datos cargados.\n\n");
//            }
//            else
//            {
//                ll_map(listaPeliculas,asignarTipo);
//                printf("\nTipo de vehiculo asignado con exito.\n\n");
//            }
            if(ll_isEmpty(listaPeliculas) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                controller_sortPeliculas(listaPeliculas);
                controller_ListPeliculas(listaPeliculas);
            }

            system("pause");
            system("cls");
            break;
               case 3:
                   if(ll_isEmpty(listaPeliculas) == 1)
                   {
                       printf("\nNo hay datos cargados.\n\n");
                   }
                   else
                   {
//                       listaFiltradaAutos = ll_filter(listaPeliculas,filtrarAutos);
//                       listaFiltradaMotos = ll_filter(listaPeliculas,filtrarMotos);
//                       printf("\nVehiculos filtrados con exito.\n\n");
                         depurarPeliculas(listaPeliculas);
                         controller_ListPeliculas(listaPeliculas);
                   }

                   system("pause");
                   system("cls");
                   break;
               case 4:
                   if(ll_isEmpty(listaPeliculas) == 1)
                   {
                       printf("\nNo hay datos suficientes cargados.\n\n");
                   }
                   else
                   {
//                       controller_guardarTexto("autos.csv",listaFiltradaAutos);
//                       controller_guardarTexto("motos.csv",listaFiltradaMotos);

                        listaPorGenero = ll_filter(listaPeliculas,filtrarGenero);
                        controller_ListPeliculas(listaPorGenero);
                       printf("\nListas nuevas impresas con exito.\n\n");

                   }

                   system("pause");
                   system("cls");
                   break;/**/
        case 5:
            printf("\nGracias por utilizar el sistema.\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 5);
    return 0;
}
