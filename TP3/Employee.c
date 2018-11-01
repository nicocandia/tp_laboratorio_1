#include "Employee.h"
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee*pEmployee=NULL;
    pEmployee=Employee_new();

    if( pEmployee==NULL ||
    Employee_setId(pEmployee,id)||
    Employee_setNombre(pEmployee,nombre)||
    Employee_setHorasTrabajadas(pEmployee,horasTrabajadas)||
    Employee_setSueldo(pEmployee,sueldo))
    {
        Employee_delete(pEmployee);
        pEmployee=NULL;
    }

    return pEmployee;
}

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_Compare(void* thisA ,void* thisB)
{
    int retorno;
    char NombreThisA[128];
    char NombreThisB[128];

    Employee_getNombre((Employee*)thisA,NombreThisA);
    Employee_getNombre((Employee*)thisB,NombreThisB);

    if(strcmp(NombreThisA,NombreThisB)>0)
    {
        retorno=1;
    }
    else if(strcmp(NombreThisA,NombreThisB)<0)
    {
        retorno=-1;
    }

    return retorno;
}


