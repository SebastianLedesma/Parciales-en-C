#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Funcion que pide y retorna un entero.
 *
 * \param [] char Mensaje que pide un nro entero.
 * \param [] char Mensaje de error en caso de ingresar un valor incorrecto.
 * \param int Valor de inicio del rango de valores posibles.
 * \param int Valor final del rango posible de valores.
 * \param int Cantidad de reintentos para ingresar un nro.
 * \return int Valor ingresado por el usuario validado.
 *
 */
int getInt(char [],char [],int,int,int);

/** \brief Funcion que permite ingresar una cadena de caracteres.
 *
 * \param [] char Mensaje a mostrar para ingresar la cadena.
 * \param [] char Mensaje de error.
 * \param [] char variable en donde se guardara la cadena ingresada.
 * \return void No retorna valor.
 *
 */
void getCadena(char [],char [],char []);

/** \brief Funcion que valida una cadena recibida(para cadenas sin nros).
 *
 * \param [] char Cadena a validar.
 * \return int Retorna 1 si la cadena es valida o 0 si contiene algun caracter invalido.
 *
 */
int validarCadena(char []);

/** \brief Funcion que permite ingresar un nro flotante.
 *
 * \param [] char Mensaje a mostrar para el ingreso de un flotante.
 * \param [] char Mensaje de error en caso de ingresar un valor incorrecto.
 * \param int Cantidad de intentos para ingresar el nro.
 * \return float Nro validado ingresado.
 *
 */
float getFloat(char [],char [],int);

/** \brief Funcion que permite ingresar un caracter.
 *
 * \param [] char Mensaje a mostrar para el ingreso de un caracter.
 * \return char Caracter ingresado.
 *
 */
char getChar(char []);

/** \brief Funcion que limpia la consola.
 *
 * \param void No recibe parametros.
 * \return void No retorna valor.
 *
 */
void cleanScreen(void);

/** \brief Funcion que muestra un menu de opciones.
 *
 * \param [] char Mensaje que muestra las opciones disponibles.
 * \return void No retorna valor.
 *
 */
void showMenu(char []);

/** \brief Funcion que permite el ingreso de long int que simula el dni de una persona.
 *
 * \param [] char Mensaje a mostrar para el ingreso del dni.
 * \param [] char Mensaje de error en caso de formato invalido.
 * \param int Valor inicial del rango de valores posibles.
 * \param int long Valor del final de valores posibles.
 * \return long int Dni validado.
 *
 */
long int getDni(char [],char [],int,long int);

/** \brief Funcion que permite el ingreso de una cadena de letrar y nros.
 *
 * \param [] char Mensaje a mostrar para el ingreso de la cadena.
 * \param [] char Mensaje de error.
 * \return void No retorna valor.
 *
 */
void getCadenaLetrasYNumeros(char [],char []);

/** \brief Funcion que permite el ingreso de un nro de telefono.
 *
 * \param [] char Mensaje a mostrar para el ingreso del telefono.
 * \param [] char Mensaje de error.
 * \param int Valor inicial del rango de valores posibles.
 * \return long int Nro de telefono validado.
 *
 */
long int getTelefono(char [],char [],int);
