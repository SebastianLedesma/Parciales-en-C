#include "Camion.h"

/** \brief Funcion que muestra una lista de choferes con sus camiones.
 *
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \return void No retorna valor.
 *
 */
void mostrarListadoChoferesConCamiones(eChofer [],int,eCamion [],int);

/** \brief Funcion que permite eliminar un chofer.
 *
 * \param [] eChofer Array de choferes a recorrer para encontrar el chofer a eliminar.
 * \param int Longitud del array de choferes.
 * \param [] eCamion Array de  camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \return int Retorna 1 si pudo eliminar,0 si se cancelo o -1 si no se pudo.
 *
 */
int eliminarUnChofer(eChofer [],int,eCamion [],int);

/** \brief Funcion que elimina un chofer y los camiones asginados a este chofer.
 *
 * \param [] eCamion Array de camiones a recorrer para buscar los que hay que eliminar.
 * \param int Longitud del array de camiones.
 * \param int Id del chofer a buscar para eliminar los camiones.
 * \return void No retorna valor.
 *
 */
void eliminarChoferConSusCamiones(eCamion [],int,int);

/** \brief Funcion que muestra listado de choferes que manejan mas de 1 camion.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void mostrarChoferesConMasUnCamion(eCamion [],int,eChofer [],int);

/** \brief Funcion que muestra listado de choferes ordenados por cantidad de camiones asignados.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void mostrarChoferesOrdenadosPorCantidad(eCamion [],int,eChofer [],int);

/** \brief Funcion que muestra listado de choferes ordenados por canditad de camiones asignados y por nombre.
 *
 * \param [] eCamion Array de camiones a recorrer.
 * \param int Longitud del array de camiones.
 * \param [] eChofer Array de choferes a recorrer.
 * \param int Longitud del array de choferes.
 * \return void No retorna valor.
 *
 */
void mostrarChoferesOrdenadosPorCantidadYNombre(eCamion [],int,eChofer [],int);

