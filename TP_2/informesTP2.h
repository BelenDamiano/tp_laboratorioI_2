#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/************************************************************ GETS*/
/** \brief INFORMA EN ORDEN DE SECTOR Y APELLIDO ALFABETICAMENTE
 *
 * \param struct Array Empleados
 * \param int TAMAÑO ARRAY
 * \return void
 *
 */
void informeAlfabeticoPorSector(eEmployees* arrayEmployees, int TAM);
/************************************************************ GETS*/
/** \brief INFORMA TOTAL SUELDOS Y EL PROMEDIO DE SUELDOS, Y LOS EMPLEADOS QUE SUPERAN EL PROMEDIO
 *
 * \param struct Array Empleados
 * \param int TAMAÑO ARRAY
 * \return void
 *
 */

void sueldosPromedioTotal(eEmployees* arrayEmployees, int TAM);
