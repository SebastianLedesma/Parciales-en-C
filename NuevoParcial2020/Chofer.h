#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    long int dni;
    char legajo[10];
    char nacionalidad[20];
    long int telefono;
    int edad;
    char sexo;
    int estado;
}eChofer;

/** \brief Funcion que inicializa los primeros indices del array de choferes.
 *
 * \param [] eChofer Array a recorrer para inicializar.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void hadcodearListaChoferes(eChofer [],int);

/** \brief Funcion que muestra un chofer.
 *
 * \param eChofer Chofer a mostrar.
 * \return void No retorna valor.
 *
 */
void mostrarUnChofer(eChofer);

/** \brief Funcion que muestra un array de choferes.
 *
 * \param [] eChofer Array de choferes a mostrar.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void mostrarTodosLosChoferes(eChofer [],int);

/** \brief Funcion que busca un id recibido por parametro.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \param int Id a buscar en el array.
 * \return int Retorna el indice del id buscado o -1 si no hubo coincidencia.
 *
 */
int buscarUnChoferPorId(eChofer [],int,int);

/** \brief Funcion que muestra un array de choferes disponibles.
 *
 * \param [] eChofer Array de choferes a mostrar.
 * \param int Longitud del array de choferes.
 * \return int Id del chofes seleccionado.
 *
 */
int seleccionarUnChofer(eChofer [],int);

/** \brief Funcion que asigna un id a un nuevo chofer.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del arrayde choferes.
 * \param int Indice donde se insertara un nuevo chofer.
 * \return int Retorna el id calculado.
 *
 */
int asignarIDChofer(eChofer [],int,int);

/** \brief Funcion que busca el max id de la lista de choferes.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return int Retorna el max id encontrado.
 *
 */
int buscarMaxIdChofer(eChofer [],int);

/** \brief Funcion que busca una posicion libre en el array de choferes.
 *
 * \param [] eChofer Array de  choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return int Retorna la posicion libre del array o -1 si no encontro lugar.
 *
 */
int buscarIndiceLibreChofer(eChofer [],int);

/** \brief Funcion que permite cargar un chofer.
 *
 * \param int Id que se asignara al nuevo chofer.
 * \return eChofer Retorna un chofer con los atributos creados.
 *
 */
eChofer cargarUnChofer(int);

/** \brief Funcion que permite cargar un array de choferes.
 *
 * \param [] eChofer Array de choferes a recorrer para buscar un lugar libre.
 * \param int Longitud del arrya de choferes.
 * \return int Retorna 1 si se pudo hacer la operacion,0 si se cancelo o -1 si no se pudo.
 *
 */
int cargarListaChoferes(eChofer [],int);

/** \brief Funcion que permite midificar un chofer.
 *
 * \param [] eChofer Array de choferes a recorrer para buscar el chofer a modificar.
 * \param int Longitud del array de choferes.
 * \return int Retorna 1 si se pudo modificar,0 si se cancelo o -1 si no se pudo hacer la modificacion.
 *
 */
int modificarUnChofer(eChofer [],int);

/** \brief Funcion que permite modificar un chofer.
 *
 * \param eChofer Chofer a modificar.
 * \return eChofer Retorna chofer modificado.
 *
 */
eChofer modificarCampoChofer(eChofer);

/** \brief Funcion que cuenta la cantidad de choferes disponibles.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de  choferes.
 * \return int Retorna la cantidad de choferes disponibles contados.
 *
 */
int contadorChoferesActivos(eChofer [],int);

/** \brief Funcion que acumula las edades de los choferes disponibles.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return int Retorna las edades acumuladas en un acumulador.
 *
 */
int acumuladorEdadChoferes(eChofer [],int);

/** \brief Funcion que calcula el promedio de edades de los choferes disponibles.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return float Retorna el promedio calculado.
 *
 */
float calcularPromedioEdadesChoferes(eChofer [],int);

/** \brief Funcion que asigna el valor LIBRE al atributo estado.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void inicializarEstadoChoferes(eChofer [],int);

/** \brief Funcion que muestra el promedio de edades de los choferes.
 *
 * \param [] eChofer Array de choferes que sera utilizado por otras funciones dentro de esta.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void mostrarPromedioEdadChoferes(eChofer [],int);

/** \brief Funcion que muestra un chofer con la cantidad de camiones que maneja
 *
 * \param eChofer Chofer a mostrar.
 * \param int Cantidad de camiones qu maneja.
 * \return void No retorna valor.
 *
 */
void mostrarUnChoferConCantidadCamiones(eChofer,int);

/** \brief Funcion que muestra el promedio de choferes de sexo masculino.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array.
 * \return void No retorna valor.
 *
 */
void mostrarPromedioChoferesMasculinos(eChofer [],int);

/** \brief Funcion que cuenta los choferes segun el sexo recibido por parametro.
 *
 * \param [] eChofer Array de choferes a recorrer para buscar por sexo.
 * \param int Longitud del array de choferes.
 * \param char Sexo a buscar en el array.
 * \return int Cantidad de choferes contabilizados.
 *
 */
int contadorChoferesPorSexo(eChofer [],int,char);

int validarCamposChofer(char [],char [],long int,char [],long int,int);

