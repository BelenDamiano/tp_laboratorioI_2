#include "bibliotecaFx.h"
#include "arrayEmployees.h"
#include "informesTP2.h"

int getMenu()
{
    system("cls");
    int opcion;

    printf("\n\tMENU\n\n");

    printf(" 1 - ALTA EMPLEADO \n\n");
    printf(" 2 - MODIFICAR EMPLEADO \n\n");
    printf(" 3 - BAJA EMPLEADO \n\n");
    printf(" 4 - INFORMES \n\n");
    printf("\n\n");

    printf("\n 0 - SALIR\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int subMenuUno()
{
    int opcion;

    printf(" 1 - MODIFICAR NOMBRE: \n\n");
    printf(" 2 - MODIFICAR APELLIDO: \n\n");
    printf(" 3 - MODIFICAR SALARIO: \n\n");
    printf(" 4 - MODIFICAR SECTOR: \n\n");
    printf(" 5 - MODIFICAR DATOS COMPLETOS: \n\n");

    printf("\n 0 VOLVER ATRAS\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int subMenuDos()
{
    int opcion;

    printf(" 1  - INFORME ORDEN ALFABETICO APELLIDO \n\n");
    printf(" 2 - INFORME TOTAL Y PROMEDIO SUELDOS, EMPLEADOS QUE SUPERAN SUELDO PROMEDIO \n\n");
    printf("\n 0 VOLVER ATRAS\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void getName(char* pName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;

    do
    {
        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
            validarSoloLetras=0;
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }
    }
    while(validarSoloLetras!=0);
}

int getNameConRetorno(char* pName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;
    int cargaCorrecta=0;

    do
    {
        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
            cargaCorrecta=1;
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }
    }
    while(validarSoloLetras!=0);

    return cargaCorrecta;
}

void getLastName(char* pLastName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;

    do
    {
        printf("INGRESE APELLIDO: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pLastName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
            validarSoloLetras=0;

        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }

    }
    while(validarSoloLetras!=0);
}

int getLastNameConRetorno(char* pLastName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;
    int cargaCorrecta=0;

    do
    {
        printf("INGRESE APELLIDO: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pLastName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
            cargaCorrecta=1;
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }

    }
    while(validarSoloLetras!=0);

    return cargaCorrecta;
}

int validarString(char* pString)
{
    int i=0;
    int j;
    int retornoValidacion=1; /** 1=CHAR VALIDO || 0=CHAR INVALIDO*/

    j=strlen(pString);

    while (i<j && retornoValidacion==1)
    {
        if (isalpha(pString[i])!=0)
        {
            i++;
        }
        else
        {
            retornoValidacion=0;
            break;
        }
    }
    return retornoValidacion;
}

int getStringConRetorno(char* pString, int TAM)
{

    char buffer[1000];
    int maximoChars=TAM;
    int cargaCorrecta=0;

    printf("INGRESE TEXTO: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximoChars||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE TEXTO: ", maximoChars);
        fflush(stdin);
        gets(buffer);
    }

    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy(pString, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
    cargaCorrecta=1;

    return cargaCorrecta;
}

int getInt(const char* MSJ)
{
    int valorInt;
    char buffer[30];

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(validarNumero(buffer)==1)
    {
        printf("[ERROR] RE%s", MSJ);
        fflush(stdin);
        gets(buffer);
    }

    valorInt=atoi(buffer);

    return valorInt;
}

int validarNumero(char* pBuffer)
{
    int i=0;
    int j;
    int retornoValidacion=0;

    j=strlen(pBuffer);

    while (i<j && retornoValidacion==0)
    {
        if (isdigit(pBuffer[i])!=0)
        {
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

void concatenarNombreApellido(char* pNombreCompleto, char* pStringLastName, char*pStringName)
{
    int i;

    /** FORMATO "Apellido, Nombre" */

    strcpy(pNombreCompleto, pStringLastName);
    strcat(pNombreCompleto, ", ");
    strcat(pNombreCompleto, pStringName);

    strlwr(pNombreCompleto); //CONVIERTE TODA LA CADENA A MINUSCULA

    pNombreCompleto[0]=toupper(pNombreCompleto[0]);

    for(i=0; i<strlen(pNombreCompleto); i++)
    {
        if (isspace(pNombreCompleto[i])) //(pNombreCompleto[i]==' ')
        {
            pNombreCompleto[i+1]=toupper(pNombreCompleto[i+1]);//PASA EN MAYUSCULA EL CARACTER DESPUES DEL ESPACIO
        }
    }
}

int validarNumeroConSignos(char* pBuffer)
{
    int i=0;
    int j;
    int retornoValidacion=0;
    int acumuladorSignos=0;
    int acumuladorSignosNegativos=0;

    j=strlen(pBuffer);

    while (i<j && retornoValidacion==0)
    {
        if (isdigit(pBuffer[i])!=0||pBuffer[i]=='.'||pBuffer[i]==','||pBuffer[i]=='-')
        {
            if(pBuffer[i]=='.'||pBuffer[i]==',')
            {
                acumuladorSignos++;
            }
            if (pBuffer[i]=='-')
            {
                acumuladorSignosNegativos++;
            }
            if(acumuladorSignos>1||acumuladorSignosNegativos>1)
            {
                retornoValidacion=1;
                break;
            }
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

float getFloat(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(validarNumeroConSignos(buffer)==1)
    {
        printf("[ERROR] RE%s", MSJ);
        fflush(stdin);
        gets(buffer);
    }

    valorFlotante=atof(buffer);

    return valorFlotante;
}

char getChar(const char* MSJ)
{
    char letra;
    char buffer[1000];

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)!=1)
    {
        printf("[ERROR]SOLO UNA LETRA. REINGRESE: ");
        fflush(stdin);
        gets(buffer);
    }
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    letra=buffer[0];

    return letra;
}

int getConfirmacion(const char* MSJ)
{
    int confirmar;
    char validar;

    switch(getChar(MSJ))
    {

    case 'S':

        do
        {
            validar=getChar("\nESTA SEGURO? S/N: ");
            if(validar=='S')
            {
                confirmar=1;
            }
            else if(validar=='N')
            {
                confirmar=0;
                printf("\n[CANCELADA]\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nOPCION NO VALIDA\n\n");
                system("pause");
            }
        }
        while(validar!='S'&&validar!='N');

        break;

    case 'N':

        confirmar=0;
        printf("\n[CANCELADA]\n");
        system("pause");
        system("cls");

        break;

    default:
        system("cls");
        printf("\nOPCION NO VALIDA\n\n");
        confirmar=0;
        system("pause");
        system("cls");
        break;
    }

    return confirmar;
}

int getIntRangoMinMax(const char* MSJ, int valorMinimo, int valorMaximo)
{

    int valorInt;
    char buffer[30];

    do
    {
        printf("%s", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumero(buffer)==1)
        {
            printf("[ERROR] REINGRESE NUMERO: ");
            fflush(stdin);
            gets(buffer);
            system("cls");
        }

        valorInt=atoi(buffer);

        if(valorInt<valorMinimo||valorInt>valorMaximo)
        {
            printf("[ERROR] VALORES ENTRE [%d-%d]\n", valorMinimo, valorMaximo);
            system("pause");
            system("cls");
        }

    }
    while(valorInt<valorMinimo||valorInt>valorMaximo);

    return valorInt;
}

float getFloatPositivo(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    do
    {
        printf("%s", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumeroConSignos(buffer)==1)
        {
            printf("[ERROR] REINGRESE NUMERO: ");
            fflush(stdin);
            gets(buffer);
            system("cls");
        }

        valorFlotante=atof(buffer);

        if(valorFlotante<0)
        {
            puts("[ERROR] VALOR SOLO POSITIVO\n");
            system("pause");
            system("cls");
        }

    }
    while(valorFlotante<0);

    return valorFlotante;
}


