#include <stdio.h>
#include <string.h>
#include "deporte.h"


int mostrarDeportes(eDeporte array[],int tam)
{
    int retorno=-1;

    if(array != NULL && tam > 0)
    {
       printf("***LISTA DE DEPORTES***\n");
        printf("ID    DESCRIPCION\n");
        printf("---------------------------\n");
    for(int i=0;i<tam;i++)
    {


      mostrarDeporte(array[i]);


    }



    }


 return retorno ;

}
void mostrarDeporte(eDeporte unDeporte)
{

    printf("%d   %s\n",unDeporte.id,unDeporte.descripcion);

}

    int cargarDescripcionDeporte(eDeporte array[],int tam,int idDeporte,char* descripcionDeporte)
    {
        int retorno=1;


        if(array != NULL && tam >0 && idDeporte > 0 && descripcionDeporte != NULL)
        {


            for(int i=0;i<tam;i++)
        {

            if(array[i].id ==idDeporte)
            {

                strcpy(descripcionDeporte,array[i].descripcion);
                retorno =0;
                break;

            }



        }


        }





        return retorno;
    }
