#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "persona.h"
#include "datastore.h"
#include "deporte.h"



#define FALSE 0
#define TRUE 1

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificar\n");
    printf("d Listar\n");
    printf("e Ordenar\n");
    printf("f Informes\n");
    printf("g Listar por sexo\n");
    printf("h Mostrar Personas por anio\n");
    printf("i Listar Deportes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int inicializarPersonas(ePersona* array,int tam)
{
    int retorno=1;


    if(array != NULL && tam > 0 )
    {


        for(int i=0; i<tam; i++)
        {

            array[i].isEmpty=1;



        }

        retorno=0;

    }


    return retorno;


}


int mostrarPersonas(ePersona* array,int tam,eDeporte arrayd[],int tamD)
{

    int retorno=1;
    int flag=0;

    if(array != NULL && tam > 0 )
    {
        retorno=0;

        printf("***Listado de personas***\n");
        printf("LEGAJO      NOMBRE SEXO ALTURA   Nacimiento  DEPORTE\n");
        printf("------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {

            if(array[i].isEmpty == 0)
            {

                mostrarPersona(array[i],arrayd,tamD);
                flag=1;// FLAG PARA VER SI TODOS ESTAN VACIOS


            }



        }

        if(!flag)
        {

            printf("No hay personas para mostrar en la lista \n");


        }


    }


    return retorno;


}

int mostrarPersona(ePersona unaPersona, eDeporte array[], int tamD)
{
    char descDeporte[20];

    cargarDescripcionDeporte(array,tamD,unaPersona.idDeporte,descDeporte);

    printf("%4d   %10s  %c  %1.2f %02d/%02d/%02d  %s\n",unaPersona.id,unaPersona.nombre,unaPersona.sexo,unaPersona.altura,unaPersona.fechaNac.dia,unaPersona.fechaNac.mes,unaPersona.fechaNac.anio,descDeporte);


    return 0; //esta mal averiguar como hacerlo int
}

int buscarLibre(ePersona* array,int tam)
{
    int retorno = -1;


    for(int i=0; i<tam; i++)
    {

        if(array[i].isEmpty)
        {

            retorno = i;
            break;


        }



    }

    return retorno;
}



int altaPersonas(ePersona array[], int tam, int legajx,eDeporte arrayd[],int tamD )
{

    int retorno=1;
    ePersona nuevaPersona; //AUXILIAR
    int indice;

    if(array != NULL && tam > 0 && legajx > 0 )
    {
        indice= buscarLibre(array,tam);

        if(indice == -1)
        {
            printf("SISTEMA COMPLETO\n");

        }
        else
        {
            nuevaPersona.id=legajx;
            nuevaPersona.isEmpty=FALSE;
            printf("Ingrese nombre : \n");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            printf("Ingrese sexo: \n");
            fflush(stdin);
            scanf("%c", &nuevaPersona.sexo);
            printf("Ingrese altura : \n");
            scanf("%f", &nuevaPersona.altura);
            printf("Ingrese fecha de nacimiento dd/mm/aaaa: \n");
            scanf("%d/%d/%d",&nuevaPersona.fechaNac.dia,&nuevaPersona.fechaNac.mes,&nuevaPersona.fechaNac.anio);
            mostrarDeportes(arrayd,tamD);
            printf("Ingrese el numero de id de deporte : \n");
            scanf("%d",&nuevaPersona.idDeporte);


            array[indice]=nuevaPersona; // SE COPIA UNA ESTRUCTURA EN LA OTRA
            //LA CLAVE DE ESTRUCTURAS

            retorno=0;

        }



    }


    return retorno;



}
int buscarPersonas(ePersona array[],int tam,int legajo)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(array[i].id == legajo && !array[i].isEmpty)
        {

            retorno= i;
            break;

        }


    }



    return retorno;
}



int bajaPersonas(ePersona array[], int tam,eDeporte arrayd[],int tamD)
{
    int retorno = 1;
    int aux;
    int indice;
    char rta;
    mostrarPersonas(array,tam,arrayd,tamD);

    printf("Ingrese el legajo que desea borrar : \n");
    scanf("%d",&aux);

    if((indice=buscarPersonas(array,tam,aux)) != -1)
    {

        if(array != NULL && tam > 0)
        {
            system("cls");
            printf("***BAJA DE PERSONAS***\n");
            mostrarPersonas(array,tam,arrayd,tamD);
            printf("Confirma la baja? s/n");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta == 's')
            {

                array[indice].isEmpty=1;
                retorno = 0;

            }
            else
            {
                retorno = 2;
            }


        }





    }
    else
    {
        printf("Legajo mal ingresado\n");
    }



    return retorno;


}


int modificarPersonas(ePersona array[], int tam,eDeporte arrayd[],int tamD)
{
    int retorno = 1;
    int aux;
    int indice;
    int opcion;
    char auxNombre[100];
    char auxChar;
    float auxFloat;


    if(array != NULL && tam > 0 )
    {

            system("cls");

            mostrarPersonas(array,tam,arrayd,tamD);


        printf("Ingrese el legajo que desea modificar : \n");
        scanf("%d",&aux);

        if((indice=buscarPersonas(array,tam,aux)) != -1)
        {


            printf("Que desea modificar : \n");
            printf("1_nombre\n");
            printf("2_sexo\n");
            printf("3_altura\n");
            printf("4_salir\n");

            printf("Ingrese una opcion\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {

            case 1 :

                printf("Ingrese nuevo nombre : \n");
                fflush(stdin);
                fgets(auxNombre,sizeof(auxNombre),stdin);
                strncpy(array[indice].nombre,auxNombre,sizeof(array[indice].nombre));



                break;


            case 2:

                printf("Ingrese nuevo sexo : \n");
                fflush(stdin);
                scanf("%c", &auxChar);
                array[indice].sexo=auxChar;

                break;

            case 3:
                printf("Ingrese nueva altura: \n");
                fflush(stdin);
                scanf("%f", &auxFloat);
                array[indice].altura=auxFloat;

                break;




            }

        }
        else
        {
            printf("NO HAY LEGAJO\n");
        }









    }





    return retorno;


}

int ordenarPersonaNombre(ePersona array[], int tam,int ascendente)
{
    ePersona aux;
    int retorno = 1;

    if(array != NULL && tam > 0 && ascendente <= 1)
    {

        for(int i=0; i<tam-1; i++)
        {

            for(int j=i+1; j<tam; j++)
            {

                if((strcmp(array[i].nombre,array[j].nombre) >0  && ascendente)|| (strcmp(array[i].nombre,array[j].nombre) < 0 && !ascendente))
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno = 0;


                }


            }



        }








    }


    return retorno;


}

int ordenarPersonaSexo(ePersona array[], int tam,int ascendente)
{
    int retorno=1;

    ePersona aux;


    if(array != NULL && tam > 0 && ascendente >= 0)
    {

        for(int i=0; i<tam-1; i++)
        {

            for(int j=i+1; j<tam; j++)
            {

                if((array[i].sexo > array[j].sexo && ascendente)|| (array[i].sexo < array[j].sexo && !ascendente))
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno =0;


                }




            }





        }








    }

    return retorno;
}

/*

int ordenarPersonaSexoEdad(ePersona array[], int tam, int ascendenteS,int ascendenteE)
{

    int retorno = 1;
    ePersona aux;


    if(array != NULL && tam > 0 )
    {

        for(int i=0; i<tam-1; i++)
        {

            for(int j=i+1; j<tam; j++)
            {

                if((array[i].sexo > array[j].sexo && ascendenteS && array[i].fechaNac.anio > array[j].fechaNac.anio && ascendenteE) || (array[i].sexo > array[j].sexo && ascendenteS && array[i].fechaNac.anio < array[j].fechaNac.anio && !ascendenteE))
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno= 0;


                }
                else if((array[i].sexo < array[j].sexo && !ascendenteS && array[i].fechaNac.anio < array[j].fechaNac.anio && !ascendenteE) || (array[i].sexo < array[j].sexo && !ascendenteS && array[i].fechaNac.anio > array[j].fechaNac.anio && ascendenteE))
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno = 0;

                }



            }





        }








    }



    return retorno;



}

*/


int ordenarPersonaSexoEdad(ePersona array[], int tam, int ascendenteS,int ascendenteE)
{

    int retorno = 1;
    ePersona aux;


    if(array != NULL && tam > 0 )
    {

        for(int i=0; i<tam-1; i++)
        {

            for(int j=i+1; j<tam; j++)
            {



                if(ascendenteS && array[i].sexo > array[j].sexo)
                {

                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno= 0;

                }
                else if(!ascendenteS && array[i].sexo < array[j].sexo)
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno= 0;

                }
                else if(array[i].sexo == array[j].sexo && array[i].fechaNac.anio > array[j].fechaNac.anio && ascendenteE)
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno= 0;

                }
                else if(array[i].sexo == array[j].sexo && array[i].fechaNac.anio < array[j].fechaNac.anio && !ascendenteE)
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno= 0;


                }
                else if((array[i].sexo < array[j].sexo && !ascendenteS && array[i].fechaNac.anio < array[j].fechaNac.anio && !ascendenteE) || (array[i].sexo < array[j].sexo && !ascendenteS && array[i].fechaNac.anio > array[j].fechaNac.anio && ascendenteE))
                {
                    aux=array[i];
                    array[i]=array[j];
                    array[j]=aux;
                    retorno = 0;

                }


            }



        }

    }


    return retorno;

}





void mostrarPorSexo(ePersona array[],int tam,eDeporte arrayd[],int tamD, char sexo)
{
    int flag=1;

    if(array != NULL && tam > 0 && (sexo == 'm' || sexo=='f'))
    {

            printf("***Listado de Personas***\n");
            printf("LEGAJO  NOMBRE  SEXO ALTURA NACIMIENTO\n");
            printf("----------------------------------------\n");

        for(int i=0; i<tam; i++)
        {


            if(array[i].sexo == sexo && !array[i].isEmpty)
            {

                mostrarPersona(array[i],arrayd,tamD);
                flag=0;


            }



        }

        if(flag)
        {
            printf("No hay personas en la lista\n");
        }





    }






}

int harcodearPersonas(ePersona array[],int tam,int cant)
{
    int retorno=-1;

    if(array != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0 ;




        for(int i=0;i<cant;i++)
        {

            array[i].id=legajos[i];
            strncpy(array[i].nombre,nombres[i],sizeof(array[i].nombre));
            array[i].sexo=sexos[i];
            array[i].altura=alturas[i];
            array[i].fechaNac=fechas[i];
            array[i].idDeporte=idDeportes[i];
            array[i].isEmpty=0;

            retorno++;


        }






    }



    return retorno;
}

int mostrarPorAnio(ePersona array[], int tam,eDeporte arrayd[],int tamD,int anio)
{
    int retorno=-1;
    int flag=1;

    if(array != NULL && tam > 0 && anio > 0)
    {

            printf("***Listado de Personas***\n");
            printf("LEGAJO  NOMBRE  SEXO ALTURA NACIMIENTO\n");
            printf("----------------------------------------\n");

        for(int i=0;i<tam;i++)
        {


            if(anio == array[i].fechaNac.anio && !array[i].isEmpty)
            {


                mostrarPersona(array[i],arrayd,tamD);
                retorno = 0;
                flag=0;



            }




        }


    }
    if(flag)
    {
        printf("no hay personas en la lista\n");
    }


    return retorno;

}


