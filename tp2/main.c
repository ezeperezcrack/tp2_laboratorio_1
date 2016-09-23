#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>


int main()
{
    char seguir='s';
    int opcion=0;
    int i,j,dni,posBorrar,posCargar,hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor,x;
    EPersona items[CANT],aux;
    char respuesta;


    for(i=0;i<CANT;i++)
    {
        items[i].estado=VACIO;
    }


    while(seguir=='s')
    {

        funcionMostrar();
        fflush(stdin);
        x=scanf("%d",&opcion);
        if(x==1)
        {
            switch(opcion)
            {
                case 1:
                        posCargar=buscarEspLibre(items);
                        items[posCargar]=cargaDeDatos();
                        if(items[posCargar].estado==LLENO)
                        {
                            if(items[posCargar].edad<=18)
                            {
                                hasta18++;
                            }   else
                                {
                                    if(items[posCargar].edad>18&&items[posCargar].edad<35)
                                    {
                                        de19a35++;
                                    }   else
                                        {
                                            mayorDe35++;
                                        }
                                }
                        printf("Carga realizada con exito\n");
                        }   else
                            {
                                printf("La carga no se ha realizado, intente denuevo\n");
                            }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    printf("Ingrese dni de la persona a eliminar\n");
                    fflush(stdin);
                    scanf("%d", &dni);
                    posBorrar=buscarPorDni(items, dni);
                    if (items[posBorrar].estado==LLENO)
                    {
                        printf("Desea proceder con la eliminacion de %s? s o n.\n",items[posBorrar].nombre);
                        fflush(stdin);
                        scanf("%c", &respuesta);
                        respuesta=tolower(respuesta);
                       if (respuesta=='s')
                       {
                            items[posBorrar].estado=VACIO;
                       }
                    } else
                        {
                            printf("No existe ese registro\n");
                        }
                    system("pause");
                    system("cls");
                    break;
                case 3:
                   for(i=0;i<CANT-1;i++)
                    {
                        for(j=i+1;j<CANT;j++)
                        {
                            if((strcmp(items[i].nombre,items[j].nombre))>0)
                            {
                                aux=items[i];
                                items[i]=items[j];
                                items[j]=aux;
                            }
                        }
                    }
                    for(i=0;i<CANT;i++)
                    {
                        if(items[i].estado==LLENO)
                        {
                            printf("\nNombre:\n%s\nEdad:\n%d\nDni:\n%d\n",items[i].nombre,items[i].edad,items[i].dni);
                        }

                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
                        {
                            mayor = hasta18;
                        }   else
                            {
                                if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
                                {
                                    mayor = de19a35;
                                }   else
                                    {
                                        mayor = mayorDe35;
                                    }
                        }

                    for(i=mayor; i>0; i--)
                        {
                            if(i<CANT)
                            {
                                printf("%02d|",i);
                            }   else
                                printf("%02d|",i);

                            if(i<= hasta18)
                            {
                                printf("*");
                            }
                            if(i<= de19a35)
                            {
                                flag=1;
                                printf("\t*");
                            }
                            if(i<= mayorDe35)
                            {
                                if(flag==0)
                                    printf("\t\t*");
                                if(flag==1)
                                    printf("\t*");

                            }
                            printf("\n");
                    }
                    printf("--+-----------------");
                    printf("\n  |<18\t19-35\t>35");
                    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    seguir = 'n';
                    break;
            }
        }   else
            {
                printf("No es una opcion valida\n");
                system("pause");
                system("cls");
            }

    }

    return 0;
}
