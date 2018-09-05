#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED
/**
la funcion TP1_menu recibe como argumento dos float con *pnumeroUno y *pnumeroDos como punteros
y muestra con printf las opciones del menu
*/
void TP1_menu(float *pnumeroUno,float *pnumeroDos);

/**
la funcion TP1_sumarDosnumeros recibe como argumento tres float con *pnumeroUno, *pnumeroDos,*psuma como punteros
y calcula la suma.
*/
void TP1_sumarDosnumeros(float *pnumeroUno,float *pnumeroDos,float *psuma);

/**
la funcion TP1_restarDosnumeros recibe como argumento tres float con *pnumeroUno, *pnumeroDos,*presta como punteros
y calcula la resta.
*/
void TP1_restarDosnumeros(float *pnumeroUno,float *pnumeroDos,float *presta);

/**
la funcion TP1_multiplicarDosnumeros recibe como argumento tres float con *pnumeroUno, *pnumeroDos,*pmultiplicar como punteros
y calcula la multiplicacion.
*/
void TP1_multiplicarDosnumeros(float *pnumeroUno,float *pnumeroDos,float *pmultiplicar);

/**
la funcion TP1_dividirDosnumeros recibe como argumento tres float con *pnumeroUno, *pnumeroDos,*pdivision como punteros
y si *pnumeroDos no es cero calcula la division y retorna 0 caso contrario retorna -1
*/
int TP1_dividirDosnumeros(float *pnumeroUno,float *pnumeroDos,float *pdivision);

/**
la funcion TP1_obtenerFactorialdeunNumero recibe como argumento un float con *pnumero y un int *pfactorialNumero como punteros
y calcula el factorial siempre y cuando p*numero sea entero positivo en ese caso retorna 0 sino -1
*/
int TP1_obtenerFactorialdeunNumero(float *pnumero,int *pfactorialNumero);

/**
la funcion TP1_cargarNumero tiene como argumento un float con *pnumero como puntero y recibe los datos que el usuario ingresa
y verifica que sea realmente un numero, luego retorna ese valor
*/
float TP1_cargarNumero(float *pnumero);

/**
la funcion TP1_verificarNumeroentero recibe como argumento un float con *pnumero como puntero y
calcula si un numero es entero, retorna un 0 si lo es y un -1 si no lo es */
int TP1_verificarNumeroentero(float *pnumero);
#endif // TP1_H_INCLUDED
