#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

void funcionMostrar()
{
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
}


int buscarPorDni(EPersona lista[], int doc)
{
    int i,pos=-1;
    for(i=0;i<CANT;i++)
    {
        if(doc==lista[i].dni)
        {
            pos=i;
            break;
        }
    }

return pos;
}

int buscarEspLibre(EPersona lista[])
{
  int i,pos=-1;
    for(i=0;i<CANT;i++)
    {
        if(VACIO==lista[i].estado)
        {
            pos=i;
            break;
        }
    }

return pos;
}

EPersona cargaDeDatos()
{

    EPersona listado;
    int x,y;
    printf("ingrese su nombre: \n");
    fflush(stdin);
    gets(listado.nombre);
    printf("ingrese su dni: \n");
    fflush(stdin);
    x=scanf("%d", &listado.dni);
        if(x==1)
        {
            if(listado.dni<MIN || listado.dni>MAX)
            {
                printf("El numero de dni no es válido\n");
                listado.estado=VACIO;
                return listado;
            }
        }   else
            {
               printf("No ingreso un numero\n");
               listado.estado=VACIO;
               return listado;
            }
    printf("ingrese su edad: \n");
    fflush(stdin);
    y=scanf("%d", &listado.edad);
        if(y==1)
        {
            if(listado.edad<1 || listado.edad>120)
            {
                printf("La edad no es válida\n");
                listado.estado=VACIO;
                return listado;
            }
        }   else
            {
                printf("No ingreso un numero\n");
                listado.estado=VACIO;
                return listado;
            }
    listado.estado=LLENO;
    return listado;
}







