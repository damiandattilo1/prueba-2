#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "persona.h"
#include "deporte.h"


#define TAM 10
#define TAM_D 6



//FUNCION VOID
//mostrar por genero void mostrarPorSexo(ePersona array[,int tam , char sexo);






int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo = 20000;
    ePersona lista[TAM];
    eDeporte list[TAM_D]={


            {1000,"No practica"},
            {1001,"Bicicleta"},
            {1002,"Patin"},
            {1003,"Esqui"},
            {1004,"Surf"},
            {1005,"Parapente"}


    };

    int auxYear;

    /* {{1234,"aahuel",'m',1.75,{16,4,1998},0},
        {2222,"bEPE",'f',1.75,{16,4,2000},0},
        {3333,"cepe",'f',1.75,{16,4,1999},0}* //hicimos el datastore para harcodear
    };*/



    char sexo;


    proximoLegajo+=(harcodearPersonas(lista,TAM,10));

    /*if(!inicializarPersonas(lista,TAM))
     {

         printf("todo ok al inicializar\n");

     }

    */
    do
    {
        switch(menu())
        {

        case 'a':

            if(!altaPersonas(lista,TAM,proximoLegajo,list,TAM_D))
            {

                proximoLegajo++;


            }


            break;
        case 'b':

            rta=bajaPersonas(lista,TAM,list,TAM_D);

            if(!rta)
            {
                printf("Baja exitosa\n");
            }
            else if(rta == 1)
            {
                printf("Hubo un problema al hacer la baja\n");


            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }






            break;
        case 'c':

            modificarPersonas(lista,TAM,list,TAM_D);

            break;
        case 'd':

            mostrarPersonas(lista,TAM,list,TAM_D);

            break;

        case 'e':

            if(!(ordenarPersonaSexoEdad(lista,TAM,0,1)))
            {
                printf("ordenado correctamente \n");
            }
            else
            {
                printf("No se pudo ordenar \n");
            }

            break;

        case 'f':
            break;


        case 'g':


            printf("Ingrese sexo : \n");
            fflush(stdin);
            scanf("%c", &sexo);
            mostrarPorSexo(lista,TAM,list,TAM_D,sexo);




            break;

        case 'h':

            printf("Ingrese anio que desea listar\n");
            scanf("%d", &auxYear);
            mostrarPorAnio(lista,TAM,list,TAM_D,auxYear);

            break;


        case 'i':
            system("cls");
            mostrarDeportes(list,TAM_D);

            break;
        case 'z':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}


