
#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[30];

}eDeporte;

#endif // DEPORTE_H_INCLUDED




int mostrarDeportes(eDeporte array[],int tam);
void mostrarDeporte(eDeporte unDeporte);
int cargarDescripcionDeporte(eDeporte array[],int tam,int idDeporte,char* descripcionDeporte);
