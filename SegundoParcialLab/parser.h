#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"
#include "Piloto.h"

/** \brief Funcion que lee los datos de un archivo de texto y los alamacena en una lista.
 *
 * \param FILE* Puntero que contiene la direccion del archivo de donde se extraeran los datos.
 * \param LinkedList* Puntero que contiene la direccion de la lista donde se guardaran los datos.
 * \return int Retorna 0 si pudo leer los datos o -1 si hubo un error.
 *
 */
int parser_VuelosDesdeText(FILE*, LinkedList*);

/** \brief Funcion que permite leer de un archivo de texto y los almacena en una lista.
 *
 * \param FILE* Puntero al archivo.
 * \param LinkedList* Lista donde se guardaran los datos traidos.
 * \return int Retorna 0 si pudo leer o -1 si hubo error.
 *
 */
int parser_PilotosDesdeText(FILE*,LinkedList*);
