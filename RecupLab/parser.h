#include <stdio.h>
#include <stdlib.h>
#include "LogEntry.h"


/** \brief Funcion que permite leer un archivo y guardar los datos obtenidos en una lista.
 *
 * \param FILE* Puntero al archivo a leer.
 * \param LinkedList* Puntero a la lista donde se guardaran los datos leidos.
 * \return int Retorna 1 si pudo hacer la lectura y el guardado de los datos.
 *
 */
int parser_loadFromText(FILE*,LinkedList*);
