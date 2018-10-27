#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char bufferId[128];
    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];
    int flagOnce=1;
    Employee* auxiliarPunteroEmployee;

    while(!feof(pFile))
    {
        if(flagOnce)
        {
            fscanf(pFile,"%s\n",bufferId);
            flagOnce = 0;
        }
        else if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo)==4)
        {
            auxiliarPunteroEmployee= Employee_newConParametros(atoi(bufferId),bufferNombre,atoi(bufferHorasTrabajadas),atoi(bufferSueldo));

            if(auxiliarPunteroEmployee != NULL)
            {
                ll_add(pArrayListEmployee,auxiliarPunteroEmployee);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
