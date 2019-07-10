#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peliculas.h"
#include "parser.h"
#include "menu.h"
#include "validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPeliculas LinkedList*
 * \return int
 *
 */
int controller_load(char* path, LinkedList* pArrayListPeliculas)
{
    int retorno = FALSE;
    FILE* pFile;

    pFile = fopen (path, "r");
    if(pFile!=NULL)
    {
        parserPeliculas(pFile,pArrayListPeliculas);
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

void controller_listOne(LinkedList* pArrayListPeliculas, int index)
{
    ePelicula* auxPelicula;
    int auxId;
    char auxNombre[64];
    int auxAnio;
    char auxGenero[32];

    auxPelicula = ll_get(pArrayListPeliculas, index);

    pelicula_getId(auxPelicula, &auxId);
    pelicula_getNombre(auxPelicula,auxNombre);
    pelicula_getAnio(auxPelicula,&auxAnio);
    pelicula_getGenero(auxPelicula,auxGenero);


    printf("| %-4d | %-50s |  %-5d | %-15s |\n", auxId, auxNombre, auxAnio, auxGenero);

}

int controller_ListPeliculas(LinkedList* pArrayListPeliculas)
{

    int i;

    int retorno = FALSE;
    printf("========================================================================================\n"
           "|                       LISTADO                                                        |\n"
           "=======================================================================================\n"
           "|  ID  |                     NOMBRE                         |  ANIO  |     GENERO      |\n"
           "========================================================================================\n");

    for(i=0; i<ll_len(pArrayListPeliculas); i++)
    {
        controller_listOne(pArrayListPeliculas,i);
        retorno = TRUE;
    }
    printf("========================================================================================\n");
    return retorno;
}

int controller_sortPeliculas(LinkedList* pArrayListPeliculas)
{

    int retorno = FALSE;
    if(pArrayListPeliculas!=NULL)
    {
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListPeliculas,sortPeliculaPorId,1);
        retorno = TRUE;
    }
    return retorno;
}

//int controller_guardarTexto(char* path, LinkedList* this)
//{
//    FILE* pFileText;
//    eDominio* vehiculo;
//
//    int auxId;
//    char auxDominio[8];
//    int auxAnio;
//    char auxTipo;
//
//    int retorno = FALSE;
//    int i;
//
//
//    pFileText = fopen(path, "w");
//    if(pFileText != NULL && this != NULL)
//    {
//        fprintf(pFileText, "id,dominio,anio,tipo\n");
//        for(i=0; i < ll_len(this); i++)
//        {
//            vehiculo = ll_get(this,i);
//            if(vehiculo!=NULL)
//            {
//                vehiculo_getId(vehiculo, &auxId);
//                vehiculo_getDominio(vehiculo, auxDominio);
//                vehiculo_getAnio(vehiculo, &auxAnio);
//                vehiculo_getTipo(vehiculo, &auxTipo);
//                fprintf(pFileText, "%d,%s,%d,%c\n", auxId, auxDominio,auxAnio,auxTipo);
//            }
//
//        }
//        retorno = TRUE;
//    }
//    fclose(pFileText);
//    return retorno;
//}

//int controller_mapEmployee(LinkedList* pArrayListeDominio)
//{
//    int retorno=1;
//
//    if(pArrayListeDominio!=NULL)
//    {
//
//        if(ll_map(pArrayListeDominio,eDominio_mapearTipo))
//        {
//        retorno=1;
//
//        }
//        else
//        {
//            retorno=-1;
//        }
//
//    }
//    else
//    {
//        retorno=-1;
//    }
//
//    return retorno;
//}


