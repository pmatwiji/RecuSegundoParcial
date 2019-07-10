#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peliculas.h"
#include "menu.h"
#include "validaciones.h"




int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
            "1. Cargar Archivo.\n"
            "2. Ordenar por ID y listar.\n"
            "3. Depurar peliculas.\n"
            "4. Guardar listas filtradas.\n"
            "5. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 5)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
            "1. Cargar Archivo.\n"
            "2. Ordenar por ID y listar.\n"
            //"3. Filtrar por tipo.\n"
            //"4. Guardar listas filtradas.\n"
            "3. Salir\n"
           "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

int subMenuModificar()
{
    int opcion;
    opcion = getInt("1. Nombre\n"
                    "2. Horas Trabajadas\n"
                    "3. Sueldo\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 3)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. Nombre\n"
                        "2. Horas Trabajadas\n"
                        "3. Sueldo\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}

int subMenuOrdenar()
{
    int opcion;
    opcion = getInt("Ingrese de que manera desea ordenar a los empleados: \n"
                    "1. ID\n"
                    "2. Nombre\n"
                    "3. Horas Trabajadas\n"
                    "4. Sueldo\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 4)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. ID\n"
                        "2. Nombre\n"
                        "3. Horas Trabajadas\n"
                        "4. Sueldo\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}


