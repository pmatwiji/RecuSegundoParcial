#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peliculas.h"
#include "menu.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPeliculas LinkedList*
 * \return int
 *
 */
int parserPeliculas(FILE* pFile, LinkedList* pArrayListPeliculas)
{
    char auxId[8];
    char auxNombre[64];
    char auxAnio[8];
    char auxGenero[32];

    int retorno = FALSE;
    ePelicula* auxPelicula;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxAnio,auxGenero);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxAnio,auxGenero);
            auxPelicula = pelicula_newParametros(auxId,auxNombre,auxAnio,auxGenero);
            if(auxPelicula!=NULL)
            {
                ll_add(pArrayListPeliculas,auxPelicula);
                retorno = TRUE;
            }

        }
    }
    fclose(pFile);
    return retorno;
}


