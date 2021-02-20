#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Chofer.h"

typedef struct{
    int id;
    char patente[10];
    char marca[15];
    //int idMarca;
    int anio;
    float peso;
    int cantidadRuedas;
    char tipo[20];
    int idChofer;
    int estado;
}eCamion;

/** \brief Funcion que inicializa datos.
 *
 * \param [] eCamion Array a inicializar.
 * \param int cantidad de elementos del array.
 * \return void No retorna valor.
 *
 */
void hardcodearListsCamiones(eCamion [],int);

/** \brief Funcion que muestra un camion con su chofer.
 *
 * \param eCamion Camion a mostrar.
 * \param [] eChofer Array a recorrer para obtener su chofer.
 * \param int Cantidad de elem del array eChofer.
 * \return void No retorna valor.
 *
 */
void mostrarUnCamion(eCamion,eChofer [],int);

/** \brief Funcion que muestra todos los camiones del array.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return void No retorno valor.
 *
 */
void mostrarTodosLosCamiones(eCamion [],int,eChofer [],int);

/** \brief Funcion que busca un indice libre para cargar un camion.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \return int Retorna el indice libre encontrado o -1 si no encontro lugar.
 *
 */
int buscarIndiceLibreCamion(eCamion [],int);

/** \brief Funcion que carga el array de camiones.
 *
 * \param [] eCamion Array a recorrer para buscar un indice libre.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de choferes para mostrar los choferes disponibles.
 * \param int Longitud del array de choferes.
 * \return int Retorna 1 si pudo cargar,0 si candelo la carga o -1 si no se pudo cargar.
 *
 */
int cargarListaCamiones(eCamion [],int,eChofer [],int);

/** \brief Funcion que permite la carga de datos para crear un camion.
 *
 * \param [] eChofer Array de choferes a recorrer para asignarle un chofer al camion.
 * \param int Longitud del array de choferes.
 * \param int Id para asignarle al nuevo camion.
 * \return eCamion Retorna un nuevo camion.
 *
 */
eCamion cargarUnCamion(eChofer [],int,int);

/** \brief Funcion que asigna un nuevo id para crear un camion.
 *
 * \param [] eCamion Array a recorrer para buscar la posicion libre.
 * \param int Lingitud del array a recorrer.
 * \param int indice libre para posicionarse ella posicion libre del array.
 * \return int Retorna el id para asignarselo a un nuevo camion.
 *
 */
int asignarIDCamion(eCamion [],int,int);

/** \brief Funcion que busca el max id para asignar el consecutivo a un nuevo camion.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \return int Retonrna el max id encontrado o -1 si no encontro.
 *
 */
int buscarMaxIdCamion(eCamion [],int);

/** \brief Funcion principal que permite eliminar un camion.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de chofer a recorrer.
 * \param intLongitud del array de choferes.
 * \return int Retorna 1 si se pudo eliminar,0 si se cancelo o -1 si no se pudo realizar la operacion.
 *
 */
int eliminarUnCamion(eCamion [],int,eChofer [],int);

/** \brief Funcion que busca in id de camiones.
 *
 * \param [] eCamion Array a recorrer para buscar el id.
 * \param int Longitud del array de camiones a recorrer.
 * \param int ID a buscar en el array.
 * \return int Retorna 1 si lo encontro o 0 si no lo encontro.
 *
 */
int buscarCamionPorID(eCamion [],int,int);

/** \brief Funcion que permite midificar un camion.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Lingitud del array de camiones.
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return int Retorna 1 si hubo midificacion,0 si se cancelo o -1 si no se pudo reslicar la operacion.
 *
 */
int modificarUnCamion(eCamion [],int,eChofer [],int);

/** \brief Funcion que permite modifcar los campos de un camion.
 *
 * \param eCamion Camion a modificar.
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return eCamion Retorna un camion con los cambios realizados.
 *
 */
eCamion modificarCamposCamion(eCamion,eChofer [],int);

/** \brief Funcion que permite ingresar una marca y la busca en el array de camiones.
 *
 * \param [] eCamion Array de camiones.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de choferes para mostrar el camion con el nombre del chofer.
 * \param int Longitud del array de  chofers.
 * \return void No retorna valor.
 *
 */
void mostrarCamionPorMarca(eCamion [],int,eChofer [],int);

/** \brief Funcion que inicializa el estado de los camiones.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de  camiones.
 * \return void No retorna valor.
 *
 */
void inicializarEstadoCamiones(eCamion [],int);

/** \brief Funcion que ordena camiones segun su tipo(cortaDistancia-largaDistancia)
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \return void No retorna valor.
 *
 */
void ordenarCamionesPorTipo(eCamion [],int);

/** \brief Funcion que muestra los camiones con mas de 10 anios de antuiuedad.
 *
 * \param [] eCamion Arrar de camiones a recorrer.
 * \param int Longitud de array de camiones.
 * \param [] eChofer Array de choferes  para mostrar el camion con su chofer.
 * \param int Longitud del array de chofers.
 * \return void No retorna valor.
 *
 */
void mostrarCamionesConMasDe10Anios(eCamion [],int,eChofer [],int);

/** \brief Funcion que acumula los anios de antiguedad de los camiones.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \return int No retorna valor.
 *
 */
int acumuladorAniosCamion(eCamion [],int);

/** \brief Funcion que calculael promedio de antiguedad de los camiones.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array.
 * \return float Promedio calculado.
 *
 */
float calcularPromedioAntiguedadCamiones(eCamion [],int);

/** \brief Funcion que cuenta los camiones disponibles.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de  camiones.
 * \return int Promedio calculado.
 *
 */
int contadorCamiones(eCamion [],int);

/** \brief Funcion que muestra el promedio calculado de anios de antiguedad de los camiones.
 *
 * \param [] eCamion Array de camiones utilizado por otras funciones invocadas en esta funcion.
 * \param int Longitud de la array de  camiones.
 * \return void No retorna valor.
 *
 */
void mostrarPromedioFlotaCamiones(eCamion [],int);

/** \brief Funcion que valida los campos marca y tipo.
 *
 * \param [] char Cadena de caracteres a validar
 * \return int Retorna 1 si los datos ingresados son correctos.
 *
 */
int validarCamposCamion(char [],int);

/** \brief Funcion que cuenta los camiones manejados por un chofer segun su ID
 *
 * \param [] eCamion Lista de camiones a recorrer.
 * \param int Loongitud del array de camiones.
 * \param int Id del chofer a buscar en cada idChofer de camion.
 * \return int Contador con la cantidad de camiones manejados por el chofer con el id recibido.
 *
 */
int contadorCamionesPorIdChofer(eCamion [],int,int);
