#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"
/**
la funcion TP1_verificarNumeropositivoOigualcero recibe como argumento un float con *pnumero como puntero y
calcula si un numero es positivo mayor o igaul a cero, retorna un 0 si lo es y un -1 si no lo es */
static int TP1_verificarNumeropositivoOigualcero(float *pnumero);

void TP1_menu(float *pnumeroUno,float *pnumeroDos)
{
    float operandoUno;
    float operandoDos;
    operandoUno=*pnumeroUno;
    operandoDos=*pnumeroDos;
    printf("\n introduce algunas de las siguientes opciones: \n");
    printf("\n 1. ingresar primer operando A= %f  \n",operandoUno);
    printf("\n 2. ingresar segundo operando B= %f \n",operandoDos);
    printf("\n 3. calcular todas las operaciones \n");
    printf("\n 4. informar resultados \n");
    printf("\n 5. salir\n");
    printf("\n opcion:\n");
}

void TP1_sumarDosnumeros(float *pnumeroUno,float *pnumeroDos,float *psuma)
{
    float operador1=*pnumeroUno;
    float operador2=*pnumeroDos;
    *psuma=operador1+operador2;

}

void TP1_restarDosnumeros(float *pnumeroUno,float *pnumeroDos,float *presta)
{
    float primerCargado=*pnumeroUno;
    float segundoCargado=*pnumeroDos;
    *presta=primerCargado-segundoCargado;

}

void TP1_multiplicarDosnumeros(float *pnumeroUno,float *pnumeroDos,float *pmultiplicar)
{
    float primerCargado=*pnumeroUno;
    float segundoCargado=*pnumeroDos;
    *pmultiplicar=primerCargado*segundoCargado;
}

int TP1_dividirDosnumeros(float *pnumeroUno,float *pnumeroDos,float *pdivision)
{
   float primerCargado=*pnumeroUno;
   float segundoCargado=*pnumeroDos;
   int retorno;

   if(segundoCargado==0)
    {
        retorno=-1;
    }
   else
    {
        retorno=0;
        *pdivision=primerCargado/segundoCargado;
    }
    return retorno;
}

int TP1_obtenerFactorialdeunNumero(float *pnumero,int *pfactorialNumero)
{
    int retorno;
    float auxiliar;
    int i;
    int acumulador=1;
    auxiliar=*pnumero;

    if(TP1_verificarNumeropositivoOigualcero(&auxiliar)==-1)
        {
            retorno=-1;
        }
    else
        if(TP1_verificarNumeroentero(&auxiliar)==0)
        {
            for(i=1;i<=auxiliar;i++)
                {
                   acumulador=acumulador*i;
                }
                *pfactorialNumero=acumulador;
                retorno=0;
        }
        else
            {
                retorno=-1;
            }
    return retorno;
}

float TP1_cargarNumero(float *pnumero)
{
    float auxiliar;
    while(scanf("%f",&auxiliar)==0)
        {
            printf("\n error ingrese numero\n");
            fflush(stdin);
            if(scanf("%f",&auxiliar)==1)
                {
                    *pnumero=auxiliar;
                    break;
                }
        }
        return auxiliar;
}

static int TP1_verificarNumeropositivoOigualcero(float *pnumero)
{
    int retorno;
    float auxiliar;
    auxiliar=*pnumero;

    if(auxiliar>=0)
        {
            retorno=0;
        }
    else
        {
            retorno=-1;
        }
    return retorno;
}

int TP1_verificarNumeroentero(float *pnumero)
{
    int retorno;
    float auxiliar;
    int auxiliarDos;
    float resta;

    auxiliar=*pnumero;
    auxiliarDos=(int) auxiliar;
    resta=auxiliarDos-auxiliar;
    if(resta==0)
        {
            retorno=0;
        }
    else
        {
            retorno=-1;
        }
    return retorno;
}





