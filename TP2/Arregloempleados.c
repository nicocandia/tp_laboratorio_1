#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arregloempleados.h"
#define TRUE 1
#define FALSE 0

static int isLetras(char*pBuffer);
static int getString(char* pBuffer, int limite)
{
    char bufferString [4096];
    int retorno = -1;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;
}

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int buffer;
    if( pInt != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getInt(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pInt = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

int getInt(int* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArregloSoloNumeros(bufferString)==0)
    {
        *pBuffer = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}

int buscarLugarlibre(Empleado*empleado,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(empleado[i].estaVacio==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}
int generarID()
{
    static int contID=0;

    return contID++;
}

int verificarArregloSoloNumeros(char *pArreglo)
{
    int i=0;
    int retorno=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z') || auxiliar=='.')
            {
                retorno=-1;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int inicializarEmpleados(Empleado*empleado,int tamanio)
{
    int i;
    int retorno=-1;
    if(empleado!=NULL && tamanio>0)
    {
    for(i=0;i<tamanio;i++)
    {
        empleado[i].estaVacio=TRUE;
        retorno=0;
    }
    }
    return retorno;
}

int buscarEmpleadoporid(Empleado*empleado,int tamanio,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
    {
        if(empleado[i].estaVacio==FALSE && empleado[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int getFloat(float* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArreglosoloFlotantes(bufferString)==0)
    {
        *pBuffer = atof(bufferString);
        retorno = 0;
    }

    return retorno;
}


int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos)

{
    int retorno=-1;
    float buffer;
    if( pFloat != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getFloat(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pFloat = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
int verificarArreglosoloFlotantes(char* pBuffer)
{
    int retorno;
    int i=0;
    char auxiliar=pBuffer[i];
    int contadorPunto=0;
    while(auxiliar!='\0')
        {
            if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z'))
                {
                    retorno=-1;
                    break;
                }
            if(auxiliar=='.')
                {
                    contadorPunto++;
                }
            if(contadorPunto==1)
                {
                    retorno=0;
                }
            else
                {
                    retorno=-1;
                }
                i++;
                auxiliar=pBuffer[i];
        }
    return retorno;
}

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && isLetras(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
static int isLetras(char*pBuffer)
{
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer)){
            retorno=0;
        }
    }
    return retorno;
}

int imprimirEmpleados(Empleado *empleado,int tamanio)
{
    int i;
    int retorno=-1;
    printf("\nAPELLIDO:\tNOMBRE:\t\tSALARIO:\tSECTOR:\t\tID:\t\tESTAVACIO:\n");

    for(i=0;i<tamanio;i++)
        {
            if(empleado[i].estaVacio==FALSE)
            {
            printf("\n%s\t\t%s\t\t%.2f\t\t%d\t\t%d\t\t%d\n",empleado[i].apellido,empleado[i].nombre,empleado[i].salario,empleado[i].sector,empleado[i].id,empleado[i].estaVacio);
            retorno=0;
            }
            }

    return retorno;
}
int agregarEmpleado(Empleado*empleado,int indice,int tamanio)
{
    int retorno=-1;
    char nombreAuxiliar[51];
    char apellidoAuxiliar[51];
    int sectorAuxiliar;
    float salarioAuxiliar;

        if(indice>=0 && indice<tamanio)
        {
        if(utn_getLetras(nombreAuxiliar,51,3,"\ningrese nombre del empleado:\n","\nerror\n")==0)
        {
            if(utn_getLetras(apellidoAuxiliar,51,3,"\ningrese apellido del empleado:\n","\n error\n")==0)
                {
                    if(utn_getInt(&sectorAuxiliar,"\ningrese sector del empleado:\n","\nerror\n",1,1000,3)==0)
                    {
                        if(utn_getFloat(&salarioAuxiliar,"\ningrese salario del empleado\n","\nerror\n",0,80000,3)==0)
                            {
                                strncpy(empleado[indice].nombre,nombreAuxiliar,51);
                                strncpy(empleado[indice].apellido,apellidoAuxiliar,51);
                                empleado[indice].sector=sectorAuxiliar;
                                empleado[indice].salario=salarioAuxiliar,
                                empleado[indice].id=generarID();
                                empleado[indice].estaVacio=FALSE;
                                retorno=0;
                            }
                    }
                }
        }
        }
    return retorno;
}
int verificarQuesecargoAlmenosUnempleado(Empleado*empleado,int tamanio)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
        {
            if(empleado[i].estaVacio==FALSE)
                {
                    retorno=0;
                    break;
                }
        }
    return retorno;
}

int eliminarEmpleado(Empleado*empleado,int id,int tamanio)
{
    int i=0;
    int retorno=-1;
    if(empleado!=NULL && id>=0)
        {
            for (i=0;i<tamanio;i++)
                {
                    if(empleado[i].id==id)
                        {
                            empleado[i].estaVacio=TRUE;
                            retorno=0;
                            break;
                        }
                }
        }
        return retorno;
}
 int modificarEmpleado(Empleado*empleado,int tamanio,int indice)
 {
     int retorno=-1;
     int opcion;
     char nombreAuxiliar[51];
     char apellidoAuxiliar[51];
     float salarioAuxiliar;
     int sectorAuxiliar;

     if (indice>=0 && indice<tamanio)
        {
            if(utn_getInt(&opcion,"\nIngrese:\n1 para modificar nombre\n2 para modificar apellido\n3 para modificar salario\n4 para modificar sector\n","\Error, ingrese opcion valida\n",1,4,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getLetras(nombreAuxiliar,51,3,"\nIngrese nuevo nombre\n","\nError, nombre no valido")==0)
                                {
                                    strncpy(empleado[indice].nombre,nombreAuxiliar,51);
                                    retorno=0;
                                }
                            break;

                        case 2:
                            if(utn_getLetras(apellidoAuxiliar,51,3,"\nIngrese nuevo apellido\n","\nError\n")==0)
                                {
                                    strncpy(empleado[indice].apellido,apellidoAuxiliar,51);
                                    retorno=1;
                                }
                            break;

                        case 3:
                            if(utn_getFloat(&salarioAuxiliar,"\nIngrese nuevo salario\n","\nError salario no valido\n",0,80000,3)==0)
                                {
                                    if(verificarSiseModifico_salarioEmpleado(empleado,salarioAuxiliar,indice)==0)
                                        {
                                           empleado[indice].salario=salarioAuxiliar;
                                           retorno=2;
                                        }

                                }
                            break;

                        case 4:
                            if(utn_getInt(&sectorAuxiliar,"\nIngrese nuevo sector\n","\nError sector no valido",1,1000,3)==0)
                                {
                                    empleado[indice].sector=sectorAuxiliar;

                                    retorno=3;
                                }
                            break;

                    }
                }
        }

     return retorno;
 }

 int ordenarArregloporApellidoySector(Empleado*empleado,int tamanio,int orden)
 {
     char apellidoAuxiliar[51];
     char nombreAuxiliar[51];
     float salarioAuxiliar;
     int sectorAuxiliar;
     int idAuxiliar;
     int i;
     int retorno=-1;
     int flagterminedeOrdenar=1;

        while(flagterminedeOrdenar==1)
        {
            flagterminedeOrdenar=0;
            for(i=0;i<tamanio-1;i++)
            {
                if((empleado[i].estaVacio==FALSE) && (empleado[i+1].estaVacio==FALSE))
                {
                if((orden==1 && strcmp(empleado[i].apellido,empleado[i+1].apellido)==1)   || (orden==0 && strcmp(empleado[i].apellido,empleado[i+1].apellido)==-1))
                   {

                    strncpy(apellidoAuxiliar,empleado[i].apellido,51);
                    strncpy(empleado[i].apellido,empleado[i+1].apellido,51);
                    strncpy(empleado[i+1].apellido,apellidoAuxiliar,51);

                    strncpy(nombreAuxiliar,empleado[i].nombre,51);
                    strncpy(empleado[i].nombre,empleado[i+1].nombre,51);
                    strncpy(empleado[i+1].nombre,nombreAuxiliar,51);

                    salarioAuxiliar=empleado[i].salario;
                    empleado[i].salario=empleado[i+1].salario;
                    empleado[i+1].salario=salarioAuxiliar;

                    sectorAuxiliar=empleado[i].sector;
                    empleado[i].sector=empleado[i+1].sector;
                    empleado[i+1].sector=sectorAuxiliar;

                    idAuxiliar=empleado[i].id;
                    empleado[i].id=empleado[i+1].id;
                    empleado[i+1].id=idAuxiliar;

                    flagterminedeOrdenar=1;
                    retorno=0;
                   }

                if(strcmp(empleado[i].apellido,empleado[i+1].apellido)==0)
                   {
                        if((orden==1 && empleado[i].sector>empleado[i+1].sector) || (orden==0 && empleado[i].sector<empleado[i+1].sector) )
                            {
                                sectorAuxiliar=empleado[i].sector;
                                empleado[i].sector=empleado[i+1].sector;
                                empleado[i+1].sector=sectorAuxiliar;

                                strncpy(apellidoAuxiliar,empleado[i].apellido,51);
                                strncpy(empleado[i].apellido,empleado[i+1].apellido,51);
                                strncpy(empleado[i+1].apellido,apellidoAuxiliar,51);

                                strncpy(nombreAuxiliar,empleado[i].nombre,51);
                                strncpy(empleado[i].nombre,empleado[i+1].nombre,51);
                                strncpy(empleado[i+1].nombre,nombreAuxiliar,51);

                                salarioAuxiliar=empleado[i].salario;
                                empleado[i].salario=empleado[i+1].salario;
                                empleado[i+1].salario=salarioAuxiliar;

                                idAuxiliar=empleado[i].id;
                                empleado[i].id=empleado[i+1].id;
                                empleado[i+1].id=idAuxiliar;

                                flagterminedeOrdenar=1;
                                retorno=0;
                            }
                   }
            }
            else
                if(empleado[i].estaVacio==FALSE)
                    {
                        retorno=0;
                    }
        }
        }

return retorno;
}


 int empleadosqueSuperanSalarioPromedio(Empleado*empleado,int tamanio,int promedioSalario)
 {
    int i;
    int CantidadEmpleadossuperanSalariopromedio=0;

    for(i=0;i<tamanio;i++)
        {
            if(empleado[i].salario>=promedioSalario && empleado[i].estaVacio==FALSE)
                {
                    CantidadEmpleadossuperanSalariopromedio++;
                }
        }
 return CantidadEmpleadossuperanSalariopromedio;
 }

int verificarSiseModifico_salarioEmpleado(Empleado*empleado,int salario,int indice)
{
    int retorno=-1;
    if(empleado[indice].salario!=salario || empleado[indice].salario==salario)
        {
            retorno=0;
        }
    return retorno;
}
