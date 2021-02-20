#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Funcion que evalua una cadena de caracteres y valida que estos sean solo numeros.
 *
 * \param cadena char* Cadena de caracteres a evaluar.
 * \param longitud int Cantidad de caracteres maximo que puede tener la cadena.
 * \return int Retorna 0 si la candena no representa un nro.
 *
 */
int esNumerica(char* cadena,int longitud);


/** \brief Funcion que permite ingresar una cadena de caracteres y valida que no se pase del rango y corrige la ultima posicion.
 *
 * \param cadena char* Puntero donde se guardara la candena ingresada por el usuario.
 * \param longitud int Cantidad maxima de caracteres qu puede tener la cadena.
 * \return int Retorna 0 si la cadena ingresada esta dentro de los parametros esperados.
 *
 */
int myGets(char* cadena,int longitud);


/** \brief Funcion que evalua si una cadena de texto puede representar a un nro entero,valida longitud y que estos sean solo numeros.
 *
 * \param pResultado int* Puntero al que se asignara el dato ingresado ya validado.
 * \return int Retorna 0 si se le asgino algun valor al puntero recibido.
 *
 */
int getInt(int* pResultado);


/** \brief Funcion principal que permite,junto con otras,el ingreso de un nro entero.
 *
 * \param pResultado int* Puntero donde se guardara el valor validado que representa un entero.
 * \param cadena char* Mensaje a mostrar para el ingreso de un dato.
 * \param cadenaError char* Mensaje de error en caso de ingresar un valor incorrecto.
 * \param minimo int Valor inicial dentro del rango de valores aceptables.
 * \param maximo int Valor del ultimo nro aceptables dentro del rango.
 * \param reintentos int Cantidad de reintentos para ingresar un dato valido.
 * \return int Retorna 0 si pudo obtener un valor valido o -1 si hubo error.
 *
 */
int utn_GetNumero(int* pResultado,char* cadena,char* cadenaError,int minimo,int maximo,int reintentos);


/** \brief Funcion que hace una pausa y limpia la consola.
 *
 * \param void No recibe parametros.
 * \return void No retorna valor.
 *
 */
void cleanScreen(void);
