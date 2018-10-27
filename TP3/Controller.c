#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Funciones.h"

static int buscarEmployeebyId(LinkedList*array,int id);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,pArrayListEmployee))
    {
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee*pEmployeeauxiliar;
    pEmployeeauxiliar=NULL;
    pEmployeeauxiliar=Employee_new();

    char nombreAuxiliar[128];
    int horasAuxiliar;
    int sueldoAuxiliar;

    if(!utn_getLetras(nombreAuxiliar,128,3,"\ningrese nombre empleado\n","\nerror solo letras\n")
        &&!utn_getInt(&horasAuxiliar,"\ningrese horas trabajadas\n","\nerror\n",0,999999999,3)
        &&!utn_getInt(&sueldoAuxiliar,"\ningrese sueldo \n","\nerror\n",0,999999999,3)
        && pEmployeeauxiliar!=NULL
        && !Employee_setNombre(pEmployeeauxiliar,nombreAuxiliar)
        && !Employee_setHorasTrabajadas(pEmployeeauxiliar,horasAuxiliar)
        && !Employee_setSueldo(pEmployeeauxiliar,sueldoAuxiliar)
        && !Employee_setId(pEmployeeauxiliar,-1))
        {
            ll_add(pArrayListEmployee,(Employee*)pEmployeeauxiliar);
            retorno=0;
        }
    else
    {
        Employee_delete(pEmployeeauxiliar);
        pEmployeeauxiliar=NULL;
        retorno=-1;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int indice;
    int opcion;
    char nombreAuxiliar[128];
    int horasAuxiliar;
    int sueldoAuxiliar;
    Employee*pEmployeeAuxiliar;

    if(!utn_getInt(&id,"\ningrese id del empleado para modificar los datos\n","\nerror\n",0,999999999,3))
    {
        indice=buscarEmployeebyId(pArrayListEmployee,id);
        if(indice>=0 && !utn_getInt(&opcion,"\ningrese:\n1 para modificar nombre\n2 para modificar horas trabajadas\n3 para modificar sueldo\n","\nerror opcion invalida\n",1,3,3))
        {
            pEmployeeAuxiliar=(Employee*)ll_get(pArrayListEmployee,indice);
            switch(opcion)
            {
                case 1:
                if(!utn_getLetras(nombreAuxiliar,128,3,"\ningrese nuevo nombre\n","\nerror solo letras\n")
                    && !Employee_setNombre(pEmployeeAuxiliar,nombreAuxiliar))
                {
                    retorno=0;
                }
                break;

                case 2:
                if(!utn_getInt(&horasAuxiliar,"\ningrese cantidad de horas\n","\nerror\n",0,999999999,3)
                   &&!Employee_setHorasTrabajadas(pEmployeeAuxiliar,horasAuxiliar))
                {
                    retorno=0;
                }
                break;

                case 3:
                if(!utn_getInt(&sueldoAuxiliar,"\ningrese nuevo sueldo\n","\nerror\n",0,999999999,3)
                   &&!Employee_setHorasTrabajadas(pEmployeeAuxiliar,sueldoAuxiliar))
                {
                    retorno=0;
                }
                break;
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int indice;
    if(!utn_getInt(&id,"\ningrese id del empleado\n","\nerror\n",0,999999999,3))
        {
            indice=buscarEmployeebyId(pArrayListEmployee,id);
            if(indice>=0)
                {
                    ll_remove(pArrayListEmployee,indice);
                    retorno=0;
                }
        }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int len=ll_len(pArrayListEmployee);
    Employee*pEmployeeAuxiliar;

    if(pArrayListEmployee!=NULL)
        {
            for(i=0;i<len;i++)
                {
                    pEmployeeAuxiliar=(Employee*)ll_get(pArrayListEmployee,i);
                    if(pEmployeeAuxiliar!=NULL)
                        {
                            printf("\n%d -- %s -- %d -- %d\n",pEmployeeAuxiliar->id,pEmployeeAuxiliar->nombre,pEmployeeAuxiliar->horasTrabajadas,pEmployeeAuxiliar->sueldo);
                            retorno=0;
                        }
                }
        }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int len=ll_len(pArrayListEmployee);
    int flagSwap;
    Employee*pEmployeeAuxiliarUno;
    Employee*pEmployeeAuxiliarDos;
    char nombreAuxiliarUno[128];
    char nombreAuxiliarDos[128];

    do
        {
            flagSwap=0;
            if(pArrayListEmployee!=NULL)
            {
                for(i=0;i<len-1;i++)
                {
                    pEmployeeAuxiliarUno=(Employee*)ll_get(pArrayListEmployee,i);
                    Employee_getNombre(pEmployeeAuxiliarUno,nombreAuxiliarUno);

                    pEmployeeAuxiliarDos=(Employee*)ll_get(pArrayListEmployee,i+1);
                    Employee_getNombre(pEmployeeAuxiliarDos,nombreAuxiliarDos);

                    if(strcmp(nombreAuxiliarUno,nombreAuxiliarDos)>0)
                    {
                        ll_set(pArrayListEmployee,i+1,pEmployeeAuxiliarUno);
                        ll_set(pArrayListEmployee,i,pEmployeeAuxiliarDos);

                        flagSwap=1;
                        retorno=0;
                    }
            }
            }
        }while(flagSwap);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

static int buscarEmployeebyId(LinkedList*array,int id)
{
    int indice=-1;
    int len=ll_len(array);
    int i;
    Employee*pEmployeeAuxiliar;
    int idEmployee;

    if(array!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pEmployeeAuxiliar=(Employee*)ll_get(array,i);
            Employee_getId(pEmployeeAuxiliar,&idEmployee);
            if(idEmployee==id)
                {
                    indice=i;
                    break;
                }
        }
    }
    return indice;
}
