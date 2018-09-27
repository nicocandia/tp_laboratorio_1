#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arregloempleados.h"
#define CANTIDAD_EMPLEADOS 1000
#define TRUE 1
#define FALSE 0
#define ORDEN 1 // 1 PARA ORDEN ASCENDENTE, 0 PARA ORDEN DESCENDENTE

int main()
{
    int opcion;
    int indice;
    int id;
    float totalSalarios;
    int promedioSalarios;
    int acumuladorEmpleados=0;
    int CantidadEmpleadossuperanSalariopromedio;
    float acumuladorSalarios=0;
    float arregloSalarios[100];

    Empleado empleados[CANTIDAD_EMPLEADOS];
    inicializarEmpleados(empleados,CANTIDAD_EMPLEADOS);

    printf("\n <<<<<<BIENVENIDO>>>>>>\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-ALTAS\n \n2-MODIFICAR\n \n3-BAJA\n \n4-INFORMAR\n \n5-SALIR\n\nOPCION:???\n","\nerror ingrese opcion valida",1,5,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            indice=buscarLugarlibre(empleados,CANTIDAD_EMPLEADOS);
                            if(indice>=0)
                            {
                                    if(agregarEmpleado(empleados,indice,CANTIDAD_EMPLEADOS)==0)
                                        {
                                            printf("\nAlta exitosa!!\n");
                                            acumuladorSalarios=acumuladorSalarios+empleados[indice].salario;
                                            arregloSalarios[indice]=empleados[indice].salario;
                                            acumuladorEmpleados++;
                                        }
                                        else
                                            {
                                                printf("\nerror no se pudo cargar empleado\n");
                                            }
                            }
                            else
                                {
                                    printf("\n No hay mas lugar!!\n");
                                }
                            break;

                        case 2:
                            if(verificarQuesecargoAlmenosUnempleado(empleados,CANTIDAD_EMPLEADOS)==-1)
                                {
                                    printf("\n error no hay empleados registrados!!\n");
                                }
                                else
                                    {
                                        if(utn_getInt(&id,"\nIngrese id del empleado a modificar\n","\nerror id no valido\n",0,999,3)==0)
                                        {
                                            indice=buscarEmpleadoporid(empleados,CANTIDAD_EMPLEADOS,id);
                                            if(indice>=0)
                                                {
                                                   switch(modificarEmpleado(empleados,CANTIDAD_EMPLEADOS,indice))
                                                   {
                                                    case 0:
                                                        printf("\nSe ha modificado el nombre del empleado\n");
                                                        break;

                                                     case 1:
                                                        printf("\nSe ha modificado el apellido del empleado\n");
                                                        break;

                                                    case 2:
                                                        printf("\nSe ha modificado el salario del empleado\n");
                                                        acumuladorSalarios=(acumuladorSalarios-arregloSalarios[indice])+empleados[indice].salario;
                                                        arregloSalarios[indice]=empleados[indice].salario;
                                                        break;

                                                    case 3:
                                                        printf("\nSe ha modificado el sector del empleado\n");
                                                        break;

                                                    default:
                                                        printf("\nNo se han podido modificar los datos del empleado\n");
                                                   }
                                                }
                                                else
                                                {
                                                    printf("\nEl id no existe");
                                                }
                                        }
                                        else{printf("\nError,no se registro bien id\n");}
                                    }
                                break;

                        case 3:
                            if(verificarQuesecargoAlmenosUnempleado(empleados,CANTIDAD_EMPLEADOS)==-1)
                                {
                                    printf("\n Error no hay empleados registrados!!\n");
                                }
                                else
                                    {
                                        if(utn_getInt(&id,"\nIngrese id del empleado a dar de baja\n","\nerror id no valido\n",0,999,3)==0)
                                            {
                                                indice=buscarEmpleadoporid(empleados,CANTIDAD_EMPLEADOS,id);
                                                if(indice>=0)
                                                {
                                                    if(eliminarEmpleado(empleados,id,CANTIDAD_EMPLEADOS)==0)
                                                        {
                                                            acumuladorSalarios=(acumuladorSalarios-empleados[indice].salario);
                                                            acumuladorEmpleados--;
                                                            printf("\nSe ha dado de baja el empleado\n");
                                                        }
                                                        else
                                                        {
                                                                printf("\nError,no se pudo dar de baja el empleado");
                                                        }

                                                }
                                                else
                                                {
                                                    printf("\nEl id no existe\n");
                                                }
                                           }
                                           else
                                            {printf("\nError,no se registro bien id\n");}
                                           }
                            break;

                        case 4:
                                   if(ordenarArregloporApellidoySector(empleados,CANTIDAD_EMPLEADOS,1)==0)
                                    {
                                        if(imprimirEmpleados(empleados,CANTIDAD_EMPLEADOS)==0)
                                        {
                                            totalSalarios=acumuladorSalarios;
                                            promedioSalarios=(int)totalSalarios/acumuladorEmpleados;
                                            CantidadEmpleadossuperanSalariopromedio=empleadosqueSuperanSalarioPromedio(empleados,CANTIDAD_EMPLEADOS,promedioSalarios);
                                            printf("\nTOTAL SALARIOS:%.2f  PROMEDIO SALARIO:%d  EMPLEADOS QUE SUPERAN EL PROMEDIO DE SALARIO:%d\n",totalSalarios,promedioSalarios,CantidadEmpleadossuperanSalariopromedio);
                                        }
                                    }
                                    else
                                       {
                                           printf("\nNo hay empleados registrados\n");
                                       }
                            break;

                    }
                }
        }while(opcion!=5);
    return 0;
}
