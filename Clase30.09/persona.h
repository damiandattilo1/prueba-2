#include "fecha.h"
#include "deporte.h"

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{

    int id;
    char nombre[20];
    char sexo;
    float altura;
    eFecha fechaNac;
    int idDeporte;
    int isEmpty;



} ePersona;


#endif // PERSONA_H_INCLUDED

int inicializarPersonas(ePersona* array,int tam);
int mostrarPersonas(ePersona* array,int tam,eDeporte arrayd[],int tamD);
int mostrarPersona(ePersona unaPersona, eDeporte array[], int tamD);
int altaPersonas(ePersona array[], int tam, int legajx,eDeporte arrayd[],int tamD );
int buscarLibre(ePersona* array,int tam);
int bajaPersonas(ePersona array[], int tam,eDeporte arrayd[],int tamD);
int buscarPersonas(ePersona array[],int tam,int legajo);
int modificarPersonas(ePersona array[], int tam,eDeporte arrayd[],int tamD);
int rta;


int ordenarPersonaNombre(ePersona array[], int tam,int ascendente); //
int ordenarPersonaSexo(ePersona array[], int tam,int ascendente);
int ordenarPersonaSexoEdad(ePersona array[], int tam, int ascendenteS,int ascendenteE);

void mostrarPorSexo(ePersona array[],int tam,eDeporte arrayd[],int tamD, char sexo);


char menu();
int harcodearPersonas(ePersona array[],int tam,int cant);
int mostrarPorAnio(ePersona array[], int tam,eDeporte arrayd[],int tamD,int anio);
