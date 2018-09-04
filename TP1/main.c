#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"

int main()
{
    float numeroUno;
    float numeroDos;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int factorialNumerouno;
    int factorialNumerodos;
    int opcion;

    do
        {
            TP1_menu(&numeroUno,&numeroDos);
            while(scanf("%d",&opcion)==0 ||(opcion<1 ||opcion>5))
                {
                fflush(stdin);
                printf("\n error, ingrese opcion entre 1 y 5\n");
                }
            switch(opcion)
            {
                case 1:
                printf("\n ingrese primer operando:\n");
                numeroUno=TP1_cargarNumero(&numeroUno);
                break;

                case 2:
                printf("\n ingrese segundo numero:\n");
                numeroDos=TP1_cargarNumero(&numeroDos);
                break;

                case 3:
                TP1_sumarDosnumeros(&numeroUno,&numeroDos,&suma);
                TP1_restarDosnumeros(&numeroUno,&numeroDos,&resta);
                TP1_multiplicarDosnumeros(&numeroUno,&numeroDos,&multiplicacion);
                TP1_dividirDosnumeros(&numeroUno,&numeroDos,&division);
                TP1_obtenerFactorialdeunNumero(&numeroUno,&factorialNumerouno);
                TP1_obtenerFactorialdeunNumero(&numeroDos,&factorialNumerodos);

                break;

                case 4:
                printf("\n la suma de %f+%f es: %f\n",numeroUno,numeroDos,suma);
                printf("\n la resta de %f-%f es: %f\n ",numeroUno,numeroDos,resta);
                printf("\n la multiplicacion de %f*%f es: %f\n ",numeroUno,numeroDos,multiplicacion);
                if(TP1_dividirDosnumeros(&numeroUno,&numeroDos,&division)==0)
                    {
                        printf("\n la division de %f/%f es: %f\n",numeroUno,numeroDos,division);
                    }
                else
                    {
                        printf("\n error,no se puede dividir por cero \n");
                    }
                if(TP1_obtenerFactorialdeunNumero(&numeroUno,&factorialNumerouno)==0)
                    {
                        printf("\n el factorial de %f es %d:\n",numeroUno,factorialNumerouno);
                    }
                else
                {
                    printf("\n error, no se puede calcular factorial de %f\n",numeroUno);
                }

                if(TP1_obtenerFactorialdeunNumero(&numeroDos,&factorialNumerodos)==0)
                    {
                        printf("\n el factorial de %f es %d:\n",numeroDos,factorialNumerodos);
                    }
                else
                {
                    printf("\n error,no se puede calcular factorial de %f\n",numeroDos);
                }
                break;
            }
        }
        while (opcion!=5);

        return 0;
        }


