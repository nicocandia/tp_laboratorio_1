#ifndef ARREGLOEMPLEADOS_H_INCLUDED
#define ARREGLOEMPLEADOS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estaVacio;
}Empleado;

int inicializarEmpleados(Empleado*empleado,int tamanio);

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);



int getInt(int* pBuffer);

int buscarLugarlibre(Empleado*empleado,int tamanio);

int generarID();

int verificarArregloSoloNumeros(char *pArreglo);


int inicializarEmpleados(Empleado*empleado,int tamanio);

int buscarEmpleadoporid(Empleado*empleado,int tamanio,int id);


int getFloat(float* pBuffer);


int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos);


int verificarArreglosoloFlotantes(char* pBuffer);


int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int agregarEmpleado(Empleado*empleado,int indice,int tamanio);

int imprimirEmpleados(Empleado *empleado,int tamanio);

int verificarQuesecargoAlmenosUnempleado(Empleado*empleado,int tamanio);

int eliminarEmpleado(Empleado*empleado,int id,int tamanio);

int modificarEmpleado(Empleado*empleado,int tamanio,int indice);

int ordenarArregloporApellidoySector(Empleado*empleado,int tamanio,int orden);

int empleadosqueSuperanSalarioPromedio(Empleado*empleado,int tamanio,int promedioSalario);

int verificarSiseModifico_salarioEmpleado(Empleado*empleado,int salario,int indice);

#endif // ARREGLOEMPLEADOS_H_INCLUDED
