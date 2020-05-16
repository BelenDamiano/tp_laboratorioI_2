#include "arrayEmployees.h"
#include "bibliotecaFx.h"
#include "informesTP2.h"

#define QTY_EMPLOYEES 5 //CAMBIAR ANTES DE ENTREGAR!!!

int main()
{
    eEmployees arrayEmployees[QTY_EMPLOYEES];

    eEmployees_inicializar(arrayEmployees, QTY_EMPLOYEES);

//HARCODEO PARA TESTING
    eEmployees_hardCode(arrayEmployees);

    int opcion;
    int opcionInformes;

    do
    {
        opcion = getMenu();

        switch(opcion)
        {
        case 0:
            system("cls");
            printf("SALIENDO DEL PROGRAMA!");
            break;
        case 1:
            system("cls");
            eEmployees_alta(arrayEmployees,QTY_EMPLOYEES,"Ingrese Datos para ALTA Empleado\n\n");
            break;
        case 2:
            system("cls");
            eEmployees_modificar(arrayEmployees,QTY_EMPLOYEES,"Ingrese ID para MODIFICAR Empleado\n\n");
            break;
        case 3:
            system("cls");
            eEmployees_baja(arrayEmployees, QTY_EMPLOYEES,"Ingrese ID para BAJA Empleado\n\n");
            break;
        case 4:
            system("cls");
            opcionInformes = subMenuDos();

            switch(opcionInformes)
            {
            case 0:
                system("cls");
                printf("SALIENDO DE INFORMES");

                break;
            case 1:
                system("cls");
                informeAlfabeticoPorSector(arrayEmployees, QTY_EMPLOYEES);
                break;

            case 2:
                system("cls");
                sueldosPromedioTotal(arrayEmployees, QTY_EMPLOYEES);
                break;

            default:
                system("cls");
                printf("OPCION INVALIDA, VUELVA A INTENTAR!");
                break;
            }
            break;

        default:

            printf("OPCION INVALIDA, VUELVA A INTENTAR!");
            break;

        }
    }
    while(opcion !=0);

    return 0;
}
