#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peliculas.h"
#include "menu.h"
#include <ctype.h>


ePelicula *pelicula_new()
{
    ePelicula* peliculaReturn;
    peliculaReturn = (ePelicula*) malloc(sizeof(ePelicula));
    return peliculaReturn;
}

ePelicula* pelicula_newParametros(char* idStr, char* nombreStr, char* anioStr, char* generoStr)
{
    ePelicula* peliculaReturn;
    peliculaReturn = pelicula_new();

    if(peliculaReturn!=NULL)
    {
        pelicula_setId(peliculaReturn, atoi((idStr)));
        pelicula_setNombre(peliculaReturn, nombreStr);
        pelicula_setAnio(peliculaReturn,atoi(anioStr));
        pelicula_setGenero(peliculaReturn, generoStr);

    }

    return peliculaReturn;
}


int pelicula_setNombre(ePelicula* this, char* nombre)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = TRUE;
    }

    return retorno;
}

int pelicula_setId(ePelicula* this, int id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno = TRUE;
    }

    return retorno;
}

int pelicula_setAnio(ePelicula* this, int anio)
{
    int retorno = FALSE;

    if(this!=NULL && anio>0)
    {
        this->anio=anio;
        retorno = TRUE;
    }

    return retorno;
}

int pelicula_setGenero(ePelicula* this, char* genero)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->genero,genero);
        retorno = TRUE;
    }

    return retorno;
}


int pelicula_getId(ePelicula* this,int* id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        *id = this->id;
        retorno = TRUE;
    }

    return retorno;
}


int pelicula_getNombre(ePelicula* this,char* nombre)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = TRUE;
    }

    return retorno;
}

int pelicula_getAnio(ePelicula* this,int* anio)
{
    int retorno = FALSE;

    if(this!=NULL && anio>0)
    {
        *anio = this->anio;
        retorno = TRUE;
    }

    return retorno;
}

int pelicula_getGenero(ePelicula* this,char* genero)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(genero,this->genero);
        retorno = TRUE;
    }

    return retorno;
}

int sortPeliculaPorId(void* auxPeliculaUno, void* auxPeliculaDos)
{
    int retorno = FALSE;
    if(((ePelicula*)auxPeliculaUno)->id > ((ePelicula*)auxPeliculaDos)->id)
    {
        retorno = TRUE;
    }
    return retorno;
}

void depurarPeliculas (LinkedList* pArrayListPeliculas)
{

    ePelicula* pelicula;
    ePelicula* peliculaDos;

    int auxId;
    int auxIdDos;

    char auxGenero[64];
    char auxGeneroDos[64];

    int i;


    if(pArrayListPeliculas!=NULL)
    {

        for(i=0; i<ll_len(pArrayListPeliculas); i++)
        {
            pelicula=ll_get(pArrayListPeliculas, i);


            peliculaDos=ll_get(pArrayListPeliculas,i+1);
            pelicula_getId(pelicula,&auxId);
            pelicula_getId(peliculaDos,&auxIdDos);

            if(auxId==auxIdDos)
            {
                pelicula_getGenero(pelicula,auxGenero);
                pelicula_getGenero(peliculaDos,auxGeneroDos);
                strcat(auxGenero," | ");
                strcat(auxGenero,auxGeneroDos);
                ll_remove(pArrayListPeliculas, i+1);
                pelicula_setGenero(pelicula, auxGenero);
            }

        }
    }
}


//void asignarTipo(void* auxPelicula)
//{
//    ePelicula* pelicula;
//    char auxDominio[20];
//
//    if(auxPelicula!=NULL)
//    {
//        pelicula = (ePelicula*) auxPelicula;
//        pelicula_getDominio(pelicula,auxDominio);
//
//        if(isalpha(auxDominio[0])!=0)
//        {
//            pelicula_setTipo(pelicula,'A');
//
//        }
//        else
//        {
//            pelicula_setTipo(pelicula,'M');
//        }
//    }
//}


int filtrarGenero(void* auxPelicula)
{
    int retorno = FALSE;
    ePelicula* pelicula;
    char genero[64];
    char auxGenero[64];
    getString("\nIngrese el genero: ",genero);

    if(auxPelicula!=NULL)
    {
        pelicula = (ePelicula*) auxPelicula;
        pelicula_getGenero(pelicula,auxGenero);

        if(auxGenero==genero)
        {
            retorno= TRUE;
        }
    }

    return retorno;

}

//int filtrarMotos(void* auxPelicula)
//{
//    int retorno = FALSE;
//    ePelicula* pelicula;
//    char auxTipo;
//
//    if(auxPelicula!=NULL)
//    {
//        pelicula = (ePelicula*) auxPelicula;
//        pelicula_getTipo(pelicula,&auxTipo);
//
//        if(auxTipo=='M')
//        {
//            retorno= TRUE;
//        }
//    }
//
//    return retorno;
//
//}





