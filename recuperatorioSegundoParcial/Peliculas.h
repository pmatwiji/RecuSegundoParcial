#ifndef Peliculas_H_INCLUDED
#define Peliculas_H_INCLUDED
typedef struct
{
    int id;
    char nombre[64];
    int anio;
    char genero[32];
}ePelicula;


ePelicula* pelicula_new();
ePelicula* pelicula_newParametros(char* idStr, char* nombreStr, char* anioStr, char* generoStr);
void pelicula_delete(ePelicula* this);

int pelicula_setId(ePelicula* this,int id);
int pelicula_getId(ePelicula* this,int* id);

int pelicula_setNombre(ePelicula* this, char* nombre);
int pelicula_getNombre(ePelicula* this,char* nombre);

int pelicula_setAnio(ePelicula* this, int anio);
int pelicula_getAnio(ePelicula* this,int* anio);

int pelicula_setGenero(ePelicula* this, char* genero);
int pelicula_getGenero(ePelicula* this,char* genero);

void asignarTipo(void* auxPelicula);
int filtrarGenero(void* auxPelicula);
int filtrarMotos(void* auxPelicula);

void pelicula_calcularSueldo(void* auxPelicula);
int pelicula_empleadosProgramadores (void* auxPelicula);

int sortPeliculaPorId(void* auxPeliculaUno, void* auxPeliculaDos);


int sortpeliculaByName(void* auxPeliculaUno, void* auxPeliculaDos);
int sortpeliculaByHorasTrabajadas(void* auxPeliculaUno, void* auxPeliculaDos);
int sortpeliculaBySueldo(void* auxPeliculaUno, void* auxPeliculaDos);

#endif // Peliculas_H_INCLUDED
