#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    char date[11];
    char time[6];
    char serviceName[65];
    int gravedad;
    char msg[65];
}LogEntry;

/** \brief Funcion que permite reservar un espacio de memoria para guardar un dato de tipo LogEntry.
 *
 * \return LogEntry* Puntero que contiene el espacio de memoria obtenido o NULL.
 *
 */
LogEntry* log_new();


/** \brief Funcion que premite contruir un dato de tipo LogEntry.
 *
 * \param char* Cadena de caracteres que representa la fecha.
 * \param char* Cadena de caracteres que representa la hora.
 * \param char* Cadena de caracteres que representa el nombre del servicio.
 * \param char* Cadena de caracteres que representa la gravedad del error.
 * \param char* Cadena de caracteres que representa un mensaje.
 * \return LogEntry* Puntero que apunta al dato de tipo LogEntry construido.
 *
 */
LogEntry* log_newParametros(char*,char*,char*,char*,char*);


/** \brief Funcion que permite establcer un valor para el campo Date.
 *
 * \param LogEntry* Puntero que apunta al dato a setear.
 * \param char* Cadena de caracteres que representa el valor a setear.
 * \return int Retorna 1 si pudo establcer el valor o 0 si hubo error.
 *
 */
int log_setDate(LogEntry*,char*);


/** \brief Funcion que permite obtener el valor del campo Date.
 *
 * \param LogEntry* Puntero que apunta al dato del cual se quiere obtener la fecha.
 * \param char* Cadena que almacenara el valor obtenido.
 * \return int Retorna 1 si pudo hacer la lectura o 0 si hubo error.
 *
 */
int log_getDate(LogEntry*,char*);


/** \brief Funcion que permite establcer un valor para el campo Time.
 *
 * \param LogEntry* Puntero que apunta al dato a setear.
 * \param char* Cadena de caracteres que representa el valor a setear.
 * \return int Retorna 1 si pudo establcer el valor o 0 si hubo error.
 *
 */
int log_setTime(LogEntry*,char*);


/** \brief Funcion que permite obtener el valor del campo Time.
 *
 * \param LogEntry* Puntero que apunta al dato del cual se quiere obtener la hora.
 * \param char* Cadena que almacenara el valor obtenido.
 * \return int Retorna 1 si pudo hacer la lectura o 0 si hubo error.
 *
 */
int log_getTime(LogEntry*,char*);

/** \brief Funcion que permite establcer un valor para el campo ServiceName.
 *
 * \param LogEntry* Puntero que apunta al dato a setear.
 * \param char* Cadena de caracteres que representa el valor a setear.
 * \return int Retorna 1 si pudo establcer el valor o 0 si hubo error.
 *
 */
int log_setServiceName(LogEntry*,char*);


/** \brief Funcion que permite obtener el valor del campo ServideName.
 *
 * \param LogEntry* Puntero que apunta al dato del cual se quiere obtener el nombre del servicio.
 * \param char* Cadena que almacenara el valor obtenido.
 * \return int Retorna 1 si pudo hacer la lectura o 0 si hubo error.
 *
 */
int log_getServiceName(LogEntry*,char*);

/** \brief Funcion que permite establcer un valor para el campo Gravedad.
 *
 * \param LogEntry* Puntero que apunta al dato a setear.
 * \param char* Cadena de caracteres que representa el valor a setear.
 * \return int Retorna 1 si pudo establcer el valor o 0 si hubo error.
 *
 */
int log_setGravedad(LogEntry*,char*);


/** \brief Funcion que permite obtener el valor del campo Gravedad.
 *
 * \param LogEntry* Puntero que apunta al dato del cual se quiere obtener el nivel de gravedad.
 * \param int* Puntero que apunta al espacio de memoria donde se guardara el valor retornado.
 * \return int Retorna 1 si pudo hacer la lectura o 0 si hubo error.
 *
 */
int log_getGravedad(LogEntry*,int*);

/** \brief Funcion que permite establcer un valor para el campo Msg.
 *
 * \param LogEntry* Puntero que apunta al dato a setear.
 * \param char* Cadena de caracteres que representa el valor a setear.
 * \return int Retorna 1 si pudo establcer el valor o 0 si hubo error.
 *
 */
int log_setMsg(LogEntry*,char*);


/** \brief Funcion que permite obtener el valor del campo Msg.
 *
 * \param LogEntry* Puntero que apunta al dato del cual se quiere obtener el msg.
 * \param char* Cadena que almacenara el valor obtenido.
 * \return int Retorna 1 si pudo hacer la lectura o 0 si hubo error.
 *
 */
int log_getMsg(LogEntry*,char*);


/** \brief Funcion que muestra un dato de tipo LogEntry.
 *
 * \param LogEntry* Puntero que apunta al dato de tipo LogEntry a mostrar.
 * \return int Retorna 1 si pudo mostrar el dato o 0 si hubo error.
 *
 */
int log_mostrarUnLog(LogEntry*);


/** \brief Funcion que permite mostrar un dato de tipo LogEntry(formato distinto al a funcion log_mostrarUnLog).
 *
 * \param LogEntry* Puntero que apunta al dato a mostrar.
 * \return int Retorna 1 su pudo mostrar el dato o 0 si hubo error.
 *
 */
int log_mostrarUnLogFiltrado(LogEntry*);



/** \brief Funcionq principal que permite guardar datos en un archivo.
 *
 * \param char* Cadena que representa la ruta del archivo para guardar los datos.
 * \param LinkedList* Puntero a la lista a leer para escribir en el archivo.
 * \return int Retorna1 si pudo escribir en el archivo o 0 si hubo error.
 *
 */
int log_guardarListaEnArchivo(char*,LinkedList*);


/** \brief Funcion que permite evalua si la gravedad del dati LogEntry es igual a 3.
 *
 * \param LogEntry* Puntero que apunta al dato LogEntry.
 * \return int Retorna 1 si la gravedad es igual a 3 o 0 si no lo es.
 *
 */
int log_buscarGravedadTres(LogEntry*);


/** \brief Funcion que permite evaluar la gravedad del dato LogEntry entre 4 y 7 inclusive.
 *
 * \param LogEntry* Puntero que apunta al dato LogEntry.
 * \return int Retorna 1 si la gravedad esta entre 4 y 7 o 0 si no lo es.
 *
 */
int log_buscarGravedadIntermedio(LogEntry*);


/** \brief Funcion que permite evaluar la gravedad del dato.Evalua si es mayor a 7.
 *
 * \param LogEntry* Puntero que apunta al dato LogEntry.
 * \return int Retorna 1 si la gravedad es mayor a 7 o 0 si no lo es.
 *
 */
int log_buscarGravedadSuperior(LogEntry*);


/** \brief Funcionq que evalua si la gravedad del dato LogEntry es menor a 3.
 *
 * \param LogEntry* Puntero que apunta al dato LogEntry.
 * \return int  Retorna 1 si la gravedad es menor a 3 o 0 si no lo es.
 *
 */
int log_buscarGravedadMenor(LogEntry*);


/** \brief Funcionq que pemite mostrar una estadistica(en este caso la cantidad de elementos que integran la lista filtrada)
 *
 * \param char* Mensaje a mostrar para imprimir el resultado.
 * \param LinkedList* Puntero que apunta a la lista filtrada.
 * \return int Retorna 1 si pudo mostrar la estadistica o 0 si no pudo.
 *
 */
int log_mostrarEstadistica(char*,LinkedList*);
