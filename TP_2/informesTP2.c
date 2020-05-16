#include "bibliotecaFx.h"
#include "arrayEmployees.h"
#include "informesTP2.h"
#include <string.h>

void informeAlfabeticoPorSector(eEmployees* arrayEmployees, int TAM)
{
    char vAux[CANT_LASTNAME];

    for(int i = 0; i < TAM-1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
            if(arrayEmployees[i].isEmpty == OCUPADO && arrayEmployees[j].isEmpty == OCUPADO)
            {
                if(strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) > 0)
                {
                    strcpy(vAux, arrayEmployees[i].lastName);
                    strcpy(arrayEmployees[i].lastName, arrayEmployees[j].lastName);
                    strcpy(arrayEmployees[j].lastName, vAux);
                }
            }
        }
    }

    for(int i=1; i<6; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            if(arrayEmployees[j].sector == i && arrayEmployees[j].isEmpty == OCUPADO)
            {
                printf("LastName: %s\nSector: %d\n\n", arrayEmployees[j].lastName, arrayEmployees[j].sector);
            }
        }
    }

    system("pause");
}

void sueldosPromedioTotal(eEmployees* arrayEmployees, int TAM)
{
    float sueldosPromedio =0;
    float sueldosTotal =0;

    for(int i = 0; i < TAM-1; i++)
    {
        if(arrayEmployees[i].isEmpty == OCUPADO)
        {
            sueldosTotal += arrayEmployees[i].salary;
        }
    }

    sueldosPromedio = sueldosTotal/TAM;

    printf("TOTAL SUELDOS: %2.f \n\n", sueldosTotal);
    printf("SUELDO PROMEDIO: %2.f \n\n", sueldosPromedio);
    system("pause");

    for(int i=0; i<TAM; i++)
    {
        if(arrayEmployees[i].isEmpty== OCUPADO)
        {
            if(arrayEmployees[i].salary >= sueldosPromedio)
            {
                printf("EMPLEADOS QUE SUPERAN SUELDO PROMEDIO: %s\n\n", arrayEmployees[i].lastName);
            }
        }
    }

    system("pause");

}
