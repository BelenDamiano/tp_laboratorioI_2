#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
#define CANT_NAME 51
#define CANT_LASTNAME 51

/******************************************************************************************* ESTRUCTURA*/
typedef struct
{
    int id;
    char name[CANT_NAME];
    char lastName[CANT_LASTNAME];
    float salary;
    int sector;

    int isEmpty;
} eEmployees;

//EN MAIN()
//eEmployees arrayEmployees[TAM_eEmployees];
//eEmployees_inicializar(arrayEmployees,TAM_eEmployees);

void eEmployees_hardCode(eEmployees*);
/******************************************************************************************* INICIALIZAR*/

/** \brief RECORRE LA ESTRUCTURA E INICIALIZA SU ESTADO EN LIBRE (LIBRE=0)
 *
 * \param eEmployees* PUNTERO DE LA ESTRUCTURA A RECORRER
 * \param QTY_eEmployees int TAMAÑO DE LA ESTRUCTURA
 * \return void
 *
 */
void eEmployees_inicializar(eEmployees*, int TAM_eEmployees);

/******************************************************************************************* BUSCAR ESPACIO LIBRE*/

/** \brief RECORRE LA ESTRUCTURA EN BUSCA DE UN ESPACIO LIBRE, AL ENCONTRARLO ROMPE LA BUSQUEDA Y DEVUELVE EL PRIMER INDICE LIBRE PARA SU USO
 *
 * \param eEmployees* PUNTERO DE LA ESTRUCTURA A RECORRER
 * \param int TAMAÑO DE LA ESTRUCTURA
 * \return int RETORNA EL INDICE DEL ARRAY LIBRE PARA SU USO O -1 SI NO ENCONTRO ESPACIO LIBRE
 *
 */
int eEmployees_buscarEspacioLibre(eEmployees*, int TAM_eEmployees);

int eEmployees_buscarPrimerEspacioOcupado(eEmployees*, int TAM_eEmployees);

/******************************************************************************************* ALTA*/

/** \brief BUSCA ESPACIO LIBRE, PIDE DATOS PARA CARGAR EN LA ESTRUCTURA Y RETORNA POR CARGA EXITOSA O FALLIDA. LE DA UN ID UNICO A CADA ESTRUCTURA
 *
 * \param arrayEmployees eEmployees* PUNTERO DE LA ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE LA ESTRUCTURA
 * \param MENSAJE const char* MENSAJE PARA PEDIR DATOS
 * \return int RETORNA 0 SI NO ENCONTRO ESPACIO LIBRE PARA DAR DE ALTA 0 1 SI SE CARGO CORRECTAMENTE

    if(eEmployees_alta(XXX)==0){
    puts("\n[LA CARGA FALLO] SIN ESPACIO");
    system("pause");
    system("cls");
 */
int eEmployees_alta(eEmployees*, int TAM_eEmployees, const char* TITULO);

/** \brief USA LA ESTRUCTURA Y LLENA TODOS SUS CAMPOS, PARA DESPUES HACER LA COPIA EN EL ALTA
 *
 * \return eEmployees ESTRUCTURA PARA LLENAR POR DATOS
 *
 */
eEmployees data();

/******************************************************************************************* BAJA*/

int eEmployees_baja(eEmployees*, int TAM_eEmployees, const char* TITULO);

/******************************************************************************************* MODIFICAR*/

/** \brief IMPRIME UN SUB MENU PARA ELEGIR CAMPOS A MODIFICAR, PIDE UN ID PARA BUSCAR LA OPCION A MODIFICAR. VALIDA SI ENCONTRO, SI MODIFICO O SI SE CANCELO LA MODIFICACION
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \param TITULO const char* TITULO A IMPRIMIR
 * \return int RETORNA 0 SI LA BAJA NO FUE EXITOSA O 1 SI SE DIO DE BAJA CORRECTAMENTE
 *
 */
int eEmployees_modificar(eEmployees*, int TAM_eEmployees, const char* TITULO);

/** \brief ACUMULA LA CANTIDAD DE ESTADOS OCUPADOS EN EL ARRAY Y RETORNA VALOR ENTERO DEL MISMO
 *
 * \param arrayEmployees eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return int RETORNA NUMERO ENTERO DE CANTIDAD ENCONTRADA EN EL ARRAY
 *
 */
int eEmployees_cantidadOcupado(eEmployees*, int TAM_eEmployees);
/** \brief VERIFICA SI HAY ALGUN ESTADO CARGADO EN EL ARRAY
 *
 * \param arrayEmployees eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return int RETORNA 1 SI HAY ALGUN INDICE CARGADO O 0 SI NO ENCONTRO ESTADO OCUPADO
 *
 */
int eEmployees_cantidadOcupadoTrueFalse(eEmployees*, int TAM_eEmployees);

/******************************************************************************************* LISTAR/CALCULOS/ORDENAMIENTOS*/

/** \brief ORDENA ALFABETICAMENTE EL ARRAY DE A-Z
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return void
 *
 */
void eEmployees_ordenarAlfabeticamente(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE LA ESTRUCTURA E IMPRIME EN PANTALLA LA LISTA DE NOMBRES CON FORMATO "Apellido, Nombre"
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return void
 *
 */
void eEmployees_listarName(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE ESTRUCTURA Y ORDENA POR NOMBRE A-Z IMPROME LISTA
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return void
 *
 */
void eEmployees_ordenarImprimirPorName(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE ID Y LOS IMPRIME
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return void
 *
 */
void eEmployees_ImprimirPorID(eEmployees*, int TAM_eEmployees);

/** \brief BUSCA EL MAXIMO ENTERO
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return int RETORNA VALOR MAXIMO ENTERO ENCONTRADO
 *
 */
int eEmployees_buscarMaximoInt(eEmployees*, int TAM_eEmployees);

/** \brief BUSCA EL MAXIMO FLOTANTE
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return float RETORNA EL VALOR MAXIMO FLOTANTE ENCONTRADO
 *
 */
float eEmployees_buscarMaximoFloat(eEmployees*, int TAM_eEmployees);

/** \brief BUSCA EL VALOR MINIMO ENTERO
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return int RETORNA EL VALOR MINIMO ENTERO ENCONTRADO
 *
 */
int eEmployees_buscarMinimoInt(eEmployees*, int TAM_eEmployees);

/** \brief BUSCA VALOR MINIMO FLOAT
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return float RETORNA VALOR MINIMO FLOTANTE ENCONTRADO
 *
 */
float eEmployees_buscarMinimoFloat(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE LA ESTRCTURA Y ACUMULA UN VALOR ENTERO
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return int RETORNA EL VALOR ENTERO ACUMULADO
 *
 */
int eEmployees_acumuladorInt(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE LA ESTRCTURA Y ACUMULA UN VALOR FLOTANTE
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return float RETORNA EL VALOR FLOTANTE ACUMULADO
 *
 */
float eEmployees_acumuladorFloat(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE LA ESTRUCTURA Y EL CALCULA PROMEDIO DE UN VALOR FLOAT
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return float RETORNA EL PROMEDIO
 *
 */
float eEmployees_calcularPromedioFloat(eEmployees*, int TAM_eEmployees);

/** \brief RECORRE LA ESTRUCTURA Y EL CALCULA PROMEDIO DE UN VALOR ENTERO
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \return float RETORNA EL PROMEDIO
 *
 */
float eEmployees_calcularPromedioInt(eEmployees*, int TAM_eEmployees);

/** \brief RECIBE EL PROMEDIO Y RECORRE LA ESTRCTURA BUSCANDO QUIEN SUPERA ESE PROMEDIO Y LO IMPRIME
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \param PROMEDIO float VALOR DEL PROMEDIO A COMPARAR
 * \return void
 *
 */
void eEmployees_imprimirPorMayorAlPromedio(eEmployees*, int TAM_eEmployees, float PROMEDIO);

/** \brief RECIBE EL PROMEDIO Y RECORRE LA ESTRCTURA BUSCANDO QUIEN ESTA POR DEBAJO DE ESE PROMEDIO Y LO IMPRIME
 *
 * \param eEmployees* PUNTERO DE ESTRUCTURA
 * \param TAM_eEmployees int TAMAÑO DE ESTRUCTURA
 * \param PROMEDIO float VALOR DEL PROMEDIO A COMPARAR
 * \return void
 *
 */
void eEmployees_imprimirPorMenorAlPromedio(eEmployees*, int TAM_eEmployees, float PROMEDIO);



