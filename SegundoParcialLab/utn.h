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


/** \brief Funcion que evalua una cadena de caracteres y valida que tenga solo letras separadas por espacio o guion.
 *
 * \param cadena char* Cadena de caracteres a validar.
 * \param longitud int Cantidad de caracteres maxima que puede tener la cadena.
 * \return int Retorna 0 si la cadena no representa un nombre.
 *
 */
int esNombre(char* cadena,int longitud);


/** \brief Funcion que hace una pausa y limpia la consola.
 *
 * \param void No recibe parametros.
 * \return void No retorna valor.
 *
 */
void cleanScreen(void);


/** \brief Funcion principal que permite,junto con otras,el ingreso de un nro entero.
 *
 * \param int* Puntero donde se guardara el valor validado que representa un entero.
 * \param char* Mensaje a mostrar para el ingreso de un dato.
 * \param char* Mensaje de error en caso de ingresar un valor incorrecto.
 * \param int Valor inicial dentro del rango de valores aceptables.
 * \param int Valor del ultimo nro aceptables dentro del rango.
 * \param int Cantidad de reintentos para ingresar un dato valido.
 * \return int Retorna 0 si pudo obtener un valor valido o -1 si hubo error.
 *
 */
int utn_GetNumero(int* pResultado,char* cadena,char* cadenaError,int minimo,int maximo,int reintentos);


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

int esNombreArchivo(char*,int);

int utn_getNombreArchivo(char* pResultado,int longitud,char* cadena,char* cadenaError,int reintentos);

/** \brief Funcion principal que permite el ingreso de una cadena y junto con otras valida que esta represente un nombre.
 *
 * \param pResultado char* Puntero al que se asignara la cadena ingresada.
 * \param longitud int Cantidad max de caracteres que puede tener la cadena.
 * \param cadena char* Mensaje que pide el ingreso de un nombre.
 * \param cadenaError char* Mensaje de error en caso de ingresar un dato incorrecto.
 * \param reintentos int Cantidad de reintentos disponibles para ingresar el nombre
 * \return int Retorna 0 si pudo se pudo obtener un nombre.
 *
 */
int utn_GetNombre(char* pResultado,int longitud,char* cadena,char* cadenaError,int reintentos);


/** \brief Funcion que valida que una cadena ingresada esté dentro de lo esperado y que represente un nombre.
 *
 * \param cadena char* Puntero adonde se guardara el valor ingresado ya validado.
 * \param longitud int Cantidad max de caracteres que puede tener la cadena.
 * \return int Retorna 0 si se le hizo una asignacion al puntero o -1 en caso de error.
 *
 */
int getNombre(char* cadena,int longitud);


/** \brief Funcion principal que permite ingresar un caracter en forma de respuesta al tomar una decision.
 *
 * \param respuesta char* Puntero al que se le asignara el valor ingreaso ya validado.
 * \param mensaje char* Mensaje que le pide al usuario que tome una decision.
 * \param mensajeError char* Mensaje de error en caso de ingresar un valor incorrecto.
 * \param reintentos int Cantidad de reintentos disponibles.
 * \return int Retorna 0 si se pudo obtener un valor.
 *
 */
int utn_GetRespuesta(char* respuesta,char* mensaje,char* mensajeError,int reintentos);


/** \brief Funcion que evalua si el caracter ingresado es una letra.
 *
 * \param letra char* Puntero que contiene la direccion del valor a evaluar.
 * \return int Retorna 0 si el caracter es una letra.
 *
 */
int esLetra(char* letra);
