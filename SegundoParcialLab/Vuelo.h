#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

typedef struct{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[13];
    char destino[10];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int precio;
}eVuelo;

/** \brief Funcion que reserva un espacio de memoria para un nuevo vuelo.
 *
 * \return eVuelo* Retorna el puntero encontrado o NULL si no escontro espacio.
 *
 */
eVuelo* vuelo_new();

/** \brief Funcion que crea un nuevo vuelo.Se usa en la funcion parser al leer el archivo.
 *
 * \param char* Cadena que representa el idVuelo a asignarle al nuevo vuelo.
 * \param char* Cadena que representa el idAvion a asignarle al nuevo vuelo.
 * \param char* Cadena que representa el idPiloto a asignarle al nuevo vuelo.
 * \param char* Cadena que representa la fecha del vuelo.(dia/mes/anio).
 * \param char* Cadena que representa el destino del vuelo.
 * \param char* Cadena que representa la cantidad de pasajeros del vuelo.
 * \param char* Cadena que representa la hora de salida del vuelo.
 * \param char* Cadena que representa la hora de llegada a destino del vuelo.
 * \return eVuelo* Puntero donde esta el nuevo vuelo almacenado.
 *
 */
eVuelo* vuelo_newParametros(char*,char*,char*,char*,char*,char*,char*,char*);

/** \brief Funcion que retorna el valor del atributo idVuelo.
 *
 * \param eVuelo* Puntero del tipo vuelo a leer.
 * \param int* Direccion donde se guardara el valor del atributo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getIdVuelo(eVuelo*,int*);

/** \brief Funcion que establece un valor para el campo idVuelo. Lo recibe en modo texto.
 *
 * \param eVuelo* Puntero al que se le asginara el id.
 * \param char* Cadena que representa el idVuelo a asignar.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setIdVueloText(eVuelo*,char*);


/** \brief Funcion que establece un valor para el campo idAvion.
 *
 * \param eVuelo* Puntero a leer para retornar el valor.
 * \param int* Puntero donde se devolvera el valor del campo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getIdAvion(eVuelo*,int*);

/** \brief Funcion que establce un valor parael campo idAvion.
 *
 * \param eVuelo* Puntero donde se asginara el idAvion.
 * \param char* Cadena que reresenta el idAvion.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setIdAvionText(eVuelo*,char*);


/** \brief Funcion que retorna el valor del campo idPiloto.
 *
 * \param eVuelo* Puntero a leer para obtener el idPiloto.
 * \param int* Puntero donde se guardara el valor retornado.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getIdPiloto(eVuelo*,int*);


/** \brief Funcion que establece un valor para el campo idPiloto.Recibe una cadena.
 *
 * \param eVuelo* Puntero donde esta el vuelo al que se le asignara el idPiloto.
 * \param char* Cadena que representa el idPiloto.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setIdPilotoText(eVuelo*,char*);


/** \brief Funcion que retorna el valor del campo fecha.
 *
 * \param eVuelo* Puntero donde esta el vuelo.
 * \param char* Cadena donde se guardara el valor de la fecha.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getFecha(eVuelo*,char*);


/** \brief Funcion que establece una fecha para un vuelo.
 *
 * \param eVuelo* Puntero del vuelo donde se guardara la fecha nueva.
 * \param char* Cadena que contiene la fecha a asignar.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setFecha(eVuelo*,char*);

/** \brief Funcion que retorna el destino del vuelo.
 *
 * \param eVuelo* Puntero donde esta el destino del vuelo a obtener.
 * \param char* Cadena donde se guardara el destino del vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getDestino(eVuelo*,char*);


/** \brief Funcion que establece un valor para el destino del vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo donde se guardara el nuevo destino.
 * \param char* Cadena que contiene el destino del vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setDestino(eVuelo*,char*);


/** \brief Funcion que retorna la cantidad de pasajeros deun vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo para obtener sus pasajeros.
 * \param int* Puntero donde se guardara la cant de pasajeros del vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getCantPasajeros(eVuelo*,int*);


/** \brief Funcion que establece la cant de pasajeros de un vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo para asignare los pasajeros.
 * \param char* Cadena que contiene los pasajeros del vuelo. Recibe en modo texto.
 * \return int
 *
 */
int vuelo_setCantPasajerosText(eVuelo*,char*);


/** \brief Funcion que retorna la hora de despegue del vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo para obtener la hora.
 * \param int* Puntero donde se guardara la hora.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getHoraDesepegue(eVuelo*,int*);


/** \brief Funcion que establece una hora de despegue para el vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo para asignarle la hora.
 * \param char* Cadena que contiene la hora a asignar.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setHoraDespegueText(eVuelo*,char*);


/** \brief Funcion que retorna la hora de llegada de un vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo para obtener la hora.
 * \param int* Puntero donde se guardara la hora del vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_getHoraLlegada(eVuelo*,int*);


/** \brief Funcion que establece una hora de llegada del vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo para asignarle la llegada.
 * \param char* Cadena que contiene la hora de llegada del vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_setHoraLlegadaText(eVuelo*,char*);


/** \brief Funcion que muetra un vuelo por pantalla.
 *
 * \param eVuelo* Puntero donde esta el vuelo a mostrar.
 * \param char* Cadena que contiene el nombre del piloto.Reemplaza el idPiloto por el nombre.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_imprimirVuelo(eVuelo*,char*);


/** \brief Funcion que obtiene la cantidad de pasajeros de un vuelo.
 *
 * \param eVuelo* Puntero donde esta el vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_obtenerPasajeros(eVuelo*);


/** \brief Funcion que determina si un vuelo tiene como destino Irlanda.
 *
 * \param eVuelo* Puntero donde esta el vuelo.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_obtenerPasajerosAIrlanda(eVuelo*);


/** \brief Funcion que determina si un vuelo es de corta duracion.
 *
 * \param eVuelo* Puntero donde esta el vuelo a obtener.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_obtenerVueloCorto(eVuelo*);


/** \brief Funcion que guarda en un archivo una lista devuelos.
 *
 * \param char* Ruta del archivo a usar.
 * \param LinkedList* Puntero de la lista a guardar.
 * \return int Retorna-1 si hubo error o 0 si pudo hacer l lectura.
 *
 */
int vuelo_guardarListaVuelos(char*,LinkedList*);

/** \brief Funcion que determinar si se debe incluir un vuelo en una lista.
 *
 * \param eVuelo* Puntero del vuelo a evaluar.
 * \param char* Destino que determina si el vuelo debe incluirse.
 * \return int Retorna 0 si se debe incluir o -1 si no.
 *
 */
int vuelo_incluirVueloPorDestino(eVuelo*,char*);

/** \brief Funcion que filtra excluyendo la cadena que recibe com parametro.
 *
 * \param LinkedList* Puntero de la lista para establecer la relacion.
 * \param eVuelo* Puntero donde esta el vuelo.
 * \param char* Nombre de piloto a excluir.
 * \return int Retorna 0 si pudo hacer la lectura,-1 si hubo error.
 *
 */
int vuelo_filtrarPorExcluirPiloto(LinkedList*,eVuelo*,char*);

/** \brief Funcion que determina si un tiene un destino determinado.
 *
 * \param eVuelo* Puntero del vuelo a consultar.
 * \return int Retorna 0 si el vuelo tiene el destino indicado o -1 si hubo error.
 *
 */
int vuelo_esVueloADestino(eVuelo*);

/** \brief Funcion que establece un valor para el pasaje del vuelo(unidad).
 *
 * \param eVuelo* Puntero del vuelo para establcer el precio.
 * \param int Precio del vuelo por unidad.
 * \return int Retorna 0 si pudo establecer el valor o -1 si hubo error.
 *
 */
int vuelo_setPrecio(eVuelo*,int);

/** \brief Funcion que permite obtener el precio de un vuelo.
 *
 * \param eVuelo* Puntero del vuelo.
 * \param int* Puntero donde se guardara el valor del vuelo.
 * \return int Retorna 0 si pudo retornar el valor o -1 si hubo error.
 *
 */
int vuelo_getPrecio(eVuelo*,int*);

/** \brief Funcion que muestra un vuelo con el precio total.
 *
 * \param eVuelo* Puntero a vuelo para obtener los datos.
 * \param char* Nombre del piloto para reemplazarlo por su id.
 * \param int Precio total del vuelo calculado.
 * \return int Retorna 0 si pudo mostrar o -1 si hubo error.
 *
 */
int vuelo_mostrarUnVueloConPrecio(eVuelo*,char*,int);

/** \brief Funcion que calcula el precio total de un vuelo.
 *
 * \param eVuelo* Puntero a obtener los datos.
 * \return int Retorna -1 si hubo error o el valor calculado entre pasajeros y precio.
 *
 */
int vuelo_calcularPrecioVuelo(eVuelo*);

/** \brief Funcion que guarda una lista de vuelos.
 *
 * \param char* Cadena que representa la ruta del archivo.
 * \param LinkedList* Puntero de la lista a guardar.
 * \return int Retorna 0 si pudo guardar la lista o -1 si hubo error.
 *
 */
int vuelo_guardarListaVuelosCoPrecio(char*,LinkedList*);

int vuelo_buscarVueloPorIdPiloto(eVuelo*,int);

LinkedList* vuelo_buscarVueloPorNombre(LinkedList*,LinkedList*,char*);

int vuelo_incluirVueloPorIdPiloto(eVuelo*,int);

int vuelo_excluirVueloPorIdPiloto(eVuelo*,int);

LinkedList* vuelo_buscarVueloPorPilotoIngresado(LinkedList*,LinkedList*,int (*pFunc)(void*,int*));
