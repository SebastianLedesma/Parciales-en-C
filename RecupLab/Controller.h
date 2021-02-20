#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "utn.h"


/** \brief Funcion principal para leer los datos de un archivo y cargarlos en una lista.
 *
 * \param char* Ruta del archivo a leer.
 * \param LinkedList* Puntero a la lista donde se guardaran los datos leidos.
 * \return int Retorno 1 si pudo hacer la lectura y la carga de la lista o 0 si hubo un error.
 *
 */
int controller_loadFromText(char*,LinkedList*);


/** \brief Funcion principal que permite mostrar una lista.
 *
 * \param LinkedList* Puntero de la lista a mostrar.
 * \return int Retorna 1 su pudo mostrar la lista o 0 si hubo error.
 *
 */
int controller_mostrarListaLogs(LinkedList*);


/** \brief Funcion que permite mostrar una lista con vista diferente a la original.
 *
 * \param LinkedList* Puntero a la lista a mostrar.
 * \return int Retorna 1 su pudo mostrar la lista o 0 si hubo error.
 *
 */
int controller_mostrarListaLogsFiltrada(LinkedList*);


/** \brief Funcion priincipal que permite trabajar sobre los datos de las listas.
 *
 * \param LinkedList* Puntero a la lista original sobre la cual se leeran los datos para cargarlos a otras listas.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \return int Retorna 1 su pudo hacer las operaciones o 0 si hubo error.
 *
 */
int controller_procesarInformacion(LinkedList*,LinkedList**,LinkedList**,LinkedList**,LinkedList**);


/** \brief Funcion que lee las listas filtradas y muestra los resultados.
 *
 * \param LinkedList* LinkedList* Puntero a la lista original sobre la cual se leeran los datos para cargarlos a otras listas.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \param LinkedList** Puntero de un puntero que apunta a un dato puntero de tipo LinkedList.
 * \return int Retorna 1 su pudo hacer las operaciones o 0 si hubo error.
 *
 */
int controller_mostrarEstadisticas(LinkedList*,LinkedList**,LinkedList**,LinkedList**,LinkedList**);
