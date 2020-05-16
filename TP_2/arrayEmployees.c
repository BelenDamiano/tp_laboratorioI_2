#include "arrayEmployees.h"
#include "bibliotecaFx.h"
#include "informesTP2.h"

void eEmployees_hardCode(eEmployees* arrayEmployees)
{
    int cantHardcodeo = 5;

    int hardcode_ID[5]                      = {1,2,3,4,5};
    char hardcode_NAME[5][CANT_NAME]        = {"Juan","Carlos", "Belen", "Mathias", "Adrian"};
    char hardcode_LASTNAME[5][CANT_LASTNAME]= {"Bautista","Zarate", "Damiano", "Bustamante", "Lopez"};
    float hardcode_SALARY[5]                = {15200.5,10100.75,12700.50,20700.25,14300.20};
    int hardcode_SECTOR[5]                  = {3,5,2,4,1};

    for(int i=0; i<cantHardcodeo; i++)
    {
        arrayEmployees[i].id=hardcode_ID[i];
        strcpy(arrayEmployees[i].name, hardcode_NAME[i]);
        strcpy(arrayEmployees[i].lastName, hardcode_LASTNAME[i]);
        arrayEmployees[i].salary=hardcode_SALARY[i];
        arrayEmployees[i].sector=hardcode_SECTOR[i];
        arrayEmployees[i].isEmpty=OCUPADO;
    }
}

void eEmployees_inicializar(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    int i;
    for(i=0; i<TAM_eEmployees; i++)
    {
        arrayEmployees[i].isEmpty=LIBRE;
    }
}

int eEmployees_buscarEspacioLibre(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    int indiceVectorLibre=-1;
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==LIBRE)
        {
            indiceVectorLibre=i;
            break;
        }

    }

    return indiceVectorLibre;
}

int eEmployees_buscarPrimerEspacioOcupado(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    int indiceVectorOcupado=-1;
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            indiceVectorOcupado=i;
            break;
        }

    }

    return indiceVectorOcupado;
}

eEmployees data()
{
    /**[DATOS DE LA ESTRUCTURA A CARGAR]*/

    eEmployees arrayEmployees;

    getName(arrayEmployees.name, CANT_NAME);
    getLastName(arrayEmployees.lastName, CANT_LASTNAME);
    arrayEmployees.salary = getFloatPositivo("INGRESE SALARIO: ");
    arrayEmployees.sector = getIntRangoMinMax("INGRESE SECTOR (1-5): ", 1, 5);

    return arrayEmployees;
}

int eEmployees_alta(eEmployees* arrayEmployees,int TAM_eEmployees, const char* MENSAJE)
{
    int index;
    int founded=0;

    index=eEmployees_buscarEspacioLibre(arrayEmployees, TAM_eEmployees);

    if(index!=-1)
    {
        system("cls");
        printf(MENSAJE);

        //arrayEmployees[index] = data();
        getName(arrayEmployees[index].name, CANT_NAME);
        getLastName(arrayEmployees[index].lastName, CANT_LASTNAME);
        arrayEmployees[index].salary    = getFloatPositivo("INGRESE SALARIO: ");
        arrayEmployees[index].sector    = getIntRangoMinMax("INGRESE SECTOR (1-5): ", 1, 5);
        arrayEmployees[index].isEmpty=OCUPADO;
        arrayEmployees[index].id=index+1; //ID AUTOMATICO

        printf("ID DEL EMPLEADO: %d\n\n", arrayEmployees[index].id);
        puts("\n[CARGA EXITOSA] ");
        system("pause");
        system("cls");
        founded=1;
    }
    else if (index==-1)
    {
        printf("LISTA LLENA!\n\n");
        system("pause");
    }

    return founded;
}

int eEmployees_cantidadOcupado(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    int cantEstadosOcupados=0;
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            cantEstadosOcupados++;
        }
    }

    return cantEstadosOcupados;
}

int eEmployees_cantidadOcupadoTrueFalse(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    int cantOcupados=0;
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            cantOcupados=1;
            break;
        }
    }

    return cantOcupados;
}

int eEmployees_modificar(eEmployees* arrayEmployees, int TAM_eEmployees, const char* TITULO)
{
    int flag=0;
    int flagDos=0;
    int eID;
    int i;
    int founded=0;
    int verificar=eEmployees_cantidadOcupadoTrueFalse(arrayEmployees, TAM_eEmployees);

    if (verificar==0)
    {
        system("cls");
        puts("\n[ERROR] SIN DATOS PARA MODIFICAR\n\n");
    }

    while(verificar==1&&flag==0)
    {
        flag=1;
        system("cls");
        printf(TITULO);
        eID=getInt("INGRESE ID A MODIFICAR: ");
        system("cls");
        printf("\nID: N%c %d\n", 248, eID);

        for(i=0; i<TAM_eEmployees; i++)
        {
            if(arrayEmployees[i].id==eID&&arrayEmployees[i].isEmpty==OCUPADO)
            {
                puts("\n[EXITO] ID ENCONTRADO\n");
                switch(subMenuUno())

                {
                case 1:
                    system("cls");

                    getName(arrayEmployees[i].name, CANT_NAME);
                    printf("TEST: %s", arrayEmployees[i].name);
                    founded=1;

                    break;

                case 2:
                    system("cls");

                    getLastName(arrayEmployees[i].lastName, CANT_LASTNAME);
                    founded=1;

                    break;

                case 3:
                    system("cls");

                    arrayEmployees[i].salary=getFloatPositivo("INGRESE SALARIO: ");
                    founded=1;
                    system("pause");
                    system("cls");

                    break;
                case 4:
                    system("cls");

                    arrayEmployees[i].sector=getInt("INGRESE SECTOR (1-5): ");
                    founded=1;
                    break;

                case 5:
                    system("cls");

                    getName(arrayEmployees[i].name, CANT_NAME);
                    getLastName(arrayEmployees[i].lastName, CANT_LASTNAME);
                    arrayEmployees[i].salary = getFloatPositivo("INGRESE SALARIO: ");
                    arrayEmployees[i].sector = getInt("INGRESE SECTOR (1-5): ");
                    founded=1;
                    break;

                case 0:
                    puts("\n[DATOS SIN MODIFICAR]\n");
                    flagDos=1;
                    break;

                default:
                    puts("\n[ERROR] OPCION NO VALIDA\n");
                    flagDos=1;
                    break;
                }
            }

        }
        if (founded==0&&flagDos==0)
        {
            puts("\n[ERROR] ID NO ENCONTRADO\n");
            break;
        }
    }
    return founded;
}

int eEmployees_baja(eEmployees* arrayEmployees, int TAM_eEmployees, const char* TITULO)
{
    int flag=0;
    int eID;
    int i;
    int founded=0;
    char confirmar='N';
    int verificar=eEmployees_cantidadOcupadoTrueFalse(arrayEmployees, TAM_eEmployees);

    if (verificar==0)
    {
        system("cls");
        puts("\n[ERROR] NINGUN ID PARA DAR BAJA\n\n");
    }

    while(verificar==1&&flag==0)
    {
        flag=1;
        system("cls");
        puts(TITULO);
        eID=getInt("INGRESE ID A DAR DE BAJA: ");
        system("cls");
        printf("\nID: N%c %d\n", 248, eID);

        for(i=0; i<TAM_eEmployees; i++)
        {
            if(arrayEmployees[i].id==eID&&arrayEmployees[i].isEmpty==OCUPADO)
            {
                puts("\n[EXITO] ID ENCONTRADO\n");

                confirmar=getConfirmacion("\nSEGURO QUE DESEA ELIMINAR? [S] CONFIRMAR O [N] PARA SALIR");

                while(confirmar==1)
                {
                    arrayEmployees[i].isEmpty=ELIMINADO;
                    founded=1;
                    puts("\n[BAJA EXITOSA]");
                    break;
                }
                if(founded!=1&&confirmar!=0)
                {
                    puts("\n[BAJA CANCELADA] ");
                    founded=1;
                }
            }

        }
        if (founded==0)
        {
            puts("\n[ERROR] ID NO ENCONTRADO\n");
            break;
        }
    }

    return founded;
}

void eEmployees_ordenarAlfabeticamente(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    int i;
    int j;
    eEmployees auxGenerica;

    for(i=0; i<TAM_eEmployees-1; i++)
    {
        for (j=i+1; j<TAM_eEmployees; j++)
        {
            if(strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName)>0)
            {
                auxGenerica=arrayEmployees[i];
                arrayEmployees[i]=arrayEmployees[j];
                arrayEmployees[j]=auxGenerica;
            }
        }
    }
}

void eEmployees_listarName(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            printf("%c %s, %s\n", 250, arrayEmployees[i].lastName, arrayEmployees[i].name);
        }
    }

}

void eEmployees_ordenarImprimirName(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    eEmployees_ordenarAlfabeticamente(arrayEmployees, TAM_eEmployees);
    eEmployees_listarName(arrayEmployees,TAM_eEmployees);

}

void eEmployees_ImprimirPorID(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            printf("%c %d/t%s, %s\n", 250, arrayEmployees[i].id, arrayEmployees[i].lastName, arrayEmployees[i].name);
        }
    }

}

void eEmployees_ordenarPorID(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    int i;
    int j;
    eEmployees auxGenerica;

    for(i=0; i<TAM_eEmployees-1; i++)
    {
        for (j=i+1; j<TAM_eEmployees; j++)
        {
            if((arrayEmployees[i].isEmpty==OCUPADO)&&(arrayEmployees[j].isEmpty==OCUPADO)&&arrayEmployees[i].id>arrayEmployees[j].id)
            {
                auxGenerica=arrayEmployees[i];
                arrayEmployees[i]=arrayEmployees[j];
                arrayEmployees[j]=auxGenerica;
            }
        }
    }
}

void eEmployees_ordenarImprimirPorID(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    eEmployees_ordenarPorID(arrayEmployees,TAM_eEmployees);
    eEmployees_ImprimirPorID(arrayEmployees, TAM_eEmployees);
}

int eEmployees_buscarMaximoInt(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    /**REEMPLAZAR VALOR SECTOR POR BUSQUEDA*/
    int max=0;
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].sector>max&&arrayEmployees[i].isEmpty==OCUPADO)
        {
            max=arrayEmployees[i].sector;
        }
    }

    return max;
}

int eEmployees_buscarMinimoInt(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    /**REEMPLAZAR VALOR SECTOR POR BUSQUEDA*/
    int min;
    int i;
    int j;

    j=eEmployees_buscarPrimerEspacioOcupado(arrayEmployees, TAM_eEmployees);
    min=arrayEmployees[j].sector;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].sector<min&&arrayEmployees[i].isEmpty==OCUPADO)
        {
            min=arrayEmployees[i].sector;
        }
    }

    return min;
}

float eEmployees_buscarMinimoFloat(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    /**REEMPLAZAR VALOR SALARY POR BUSQUEDA*/
    float min;
    int i;
    int j;

    j=eEmployees_buscarPrimerEspacioOcupado(arrayEmployees, TAM_eEmployees);
    min=arrayEmployees[j].salary;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].salary<min&&arrayEmployees[i].isEmpty==OCUPADO)
        {
            min=arrayEmployees[i].salary;
        }
    }

    return min;
}

float eEmployees_buscarMaximoFloat(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    /**REEMPLAZAR VALOR SECTOR POR BUSQUEDA*/
    float max=0;
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].salary>max&&arrayEmployees[i].isEmpty==OCUPADO)
        {
            max=arrayEmployees[i].salary;
        }
    }

    return max;
}

int eEmployees_acumuladorInt(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    /**REEMPLAZAR VALOR SECTOR POR BUSQUEDA*/
    int i;
    int acumulador=0;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            acumulador=acumulador+arrayEmployees[i].sector;
        }
    }
    return acumulador;
}

float eEmployees_acumuladorFloat(eEmployees* arrayEmployees, int TAM_eEmployees)
{
    /**REEMPLAZAR VALOR SALARY POR BUSQUEDA*/
    int i;
    float acumulador=0;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO)
        {
            acumulador=acumulador+arrayEmployees[i].salary;
        }
    }
    return acumulador;
}

float eEmployees_calcularPromedioFloat(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    float promedio;
    float acumulador;
    int cantidadIndicesOcupados;

    cantidadIndicesOcupados=eEmployees_cantidadOcupado(arrayEmployees, TAM_eEmployees);
    acumulador=eEmployees_acumuladorFloat(arrayEmployees, TAM_eEmployees);

    promedio=acumulador/cantidadIndicesOcupados;

    return promedio;
}

float eEmployees_calcularPromedioInt(eEmployees* arrayEmployees, int TAM_eEmployees)
{

    float promedio;
    int acumulador;
    int cantidadIndicesOcupados;

    cantidadIndicesOcupados=eEmployees_cantidadOcupado(arrayEmployees, TAM_eEmployees);
    acumulador=eEmployees_acumuladorInt(arrayEmployees, TAM_eEmployees);

    promedio=acumulador/cantidadIndicesOcupados;

    return promedio;
}

void eEmployees_imprimirPorMayorAlPromedio(eEmployees* arrayEmployees, int TAM_eEmployees, float promedio)
{

    /**REEMPLAZAR VALOR SALARY POR BUSQUEDA*/
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO && arrayEmployees[i].salary>=promedio)
        {
            printf("\n\t[%.2f]\t\t[%s, %s]\n", arrayEmployees[i].salary, arrayEmployees[i].lastName, arrayEmployees[i].name);
        }
    }
    puts("\n\n");
    system("pause");
    system("cls");
}

void eEmployees_imprimirPorMenorAlPromedio(eEmployees* arrayEmployees, int TAM_eEmployees, float promedio)
{

    /**REEMPLAZAR VALOR SALARY POR BUSQUEDA*/
    int i;

    for(i=0; i<TAM_eEmployees; i++)
    {
        if(arrayEmployees[i].isEmpty==OCUPADO && arrayEmployees[i].salary<=promedio)
        {
            printf("\n\t[%.2f]\t\t[%s, %s]\n", arrayEmployees[i].salary, arrayEmployees[i].lastName, arrayEmployees[i].name);
        }
    }
    puts("\n\n");
    system("pause");
    system("cls");
}

