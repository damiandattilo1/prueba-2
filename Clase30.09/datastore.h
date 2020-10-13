#include "fecha.h"
#include "deporte.h"

#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

char nombres[10][20]=
{"Juan",
"Astor",
"Rogelio",
"Analia",
"Mario",
"Facundo",
"Beatriz",
"Florencia",
"Tomas",
"Gustavo"};

char sexos[10]={'m','m','m','f','m','m','f','f','m','m'};

int legajos[10]={20000,20001,20002,20003,20004,20005,20006,20007,20008,20009};

float alturas[10]={1.78,1.68,1.59,1.99,1.65,1.49,1.55,1.75,1.69,1.70};

int dias[10]={4,5,6,20,18,10,29,31,15,11};

int meses[10]={12,5,8,11,1,5,6,7,10,2};

int anios[10]={2000,1998,1999,1995,1994,1994,2001,2002,2004,1993};

int edad[10]={20,21,22,30,24,25,30,19,18,22};

float peso[10]={70,68,59,99,86,78,65,65,77,78};


eFecha fechas[10]={
{11,11,2000},
{21,3,1998},
{21,1,2000},
{16,9,2002},
{21,3,2001},
{15,2,1995},
{21,12,1994},
{4,9,1999},
{21,3,2000}};


int idDeportes[]={1005,1001,1000,1001,1003,1004,1005,1004,1001,1002};



#endif // DATASTORE_H_INCLUDED
