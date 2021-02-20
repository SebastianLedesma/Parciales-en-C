#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
//#include "Piloto.h"
#

/** \brief Funcion principal que permite extraer los datos de un archivo de texto y guardarlos en memoria.
 *
 * \param char* Cadena de carateres que representa la ruta o nombre del archivo.
 * \param LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros donde se guardaran los datos.
  * \param char* Cadena de carateres que representa la ruta o nombre del archivo para establcer la relacion.
  * \param LinkedList* Puntero que contiene la direccion de memoria de otra lista de punteros para establecer la relacion.
 * \return int Retonna -1 si los punteros son NULL o el nombre de archivo ingresado es incorrecto, 1 si la lista esta vacia o 0 si se pudo leer el archivo.
 *
 */
int controller_cargarDesdeText(char*,LinkedList*,char*,LinkedList*);


/** \brief Funcion que muestra todos los vuelos disponibles.
 *
 * \param LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros que apuntan a los vuelos.
 * \return int Retorna 0 si pudo mostrar los vuelos o -1 si hubo un error o 1 si no hay vuelos en la lista.
 *
 */
int controller_MostrarListaVuelos(LinkedList*,LinkedList*);


/** \brief Funcion que permite darde alta un piloto.
 *
 * \param LinkedList* Puntero donde se guardara el nuevo piloto.
 * \return int Retorna 0 si pudo dar de alta o -1 si hubo error.
 *
 */
int controller_agregarNuevoPiloto(LinkedList*);



/** \brief Funcion que permite leer un archivo de texto.
 *
 * \param void* Cadena de caracteres que representa la ruta del archivo.
 * \param void*
 * \return int controller_leerUnArchivo(char*,LinkedList*,int
 *
 */
int controller_leerUnArchivo(char*,LinkedList*,int (*pFunc)(void*,void*));

/** \brief Funcion que permite leer una lista de pilotos.
 *
 * \param LinkedList* Lista que contiene los punteros de las estructuras a mostrar.
 * \return int Retorna 0 si pudo mostrar o -1 si hubo error.
 *
 */
int controller_mostrarListaPilotos(LinkedList*);

/** \brief Funcion que permite contar los valores.
 *
 * \param LinkedList* Puntero que contiene los punteros de las estructuras a recorrer.
 * \param int Nro de opcion para elegir dentro de la funcion.
 * \return int Retorna 0 si pudo hacer el conteo o -1 si hubo error.
 *
 */
int controller_contar(LinkedList*,int);

/** \brief Funcion que permite filtrar un listado que usa dos LinkedList.
 *
 * \param LinkedList* LinkedList para establecer la relacion.
 * \param LinkedList* LinkedList donde se guardaran las estructuras filtradas segun criterio.
 * \param LinkedList* LinkedList para establecer la relacion.
 * \param int Nor de opcion para seleccionar dentre de la funcion.
 * \return int Retorna 0 si pudo hacer el filtrado o -1 si hubo error.
 *
 */

int controller_filtrar(LinkedList*,LinkedList*,LinkedList*,int);


int controller_mostrarListaVuelosConPrecio(LinkedList*,LinkedList*);

