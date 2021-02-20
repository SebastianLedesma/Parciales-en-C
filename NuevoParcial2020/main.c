#include <stdio.h>
#include <stdlib.h>
#include "Chofer_Camion.h"

#define TCAMIONES 25
#define TCHOFERES 12
//#define TMARCAS 3
#define OCUPADO 1


int main()
{
    eCamion listaCamiones[TCAMIONES];
    eChofer listaChoferes[TCHOFERES];
    //eMarca listaMarcas[TMARCAS];
    int opcion;
    int respuesta;


    //inicializarListaMarcas(listaMarcas,TMARCAS);
    inicializarEstadoCamiones(listaCamiones,TCAMIONES);
    inicializarEstadoChoferes(listaChoferes,TCHOFERES);

    //hardcodearListaMarcas(listaMarcas,TMARCAS);
    hadcodearListaChoferes(listaChoferes,TCHOFERES);
    hardcodearListsCamiones(listaCamiones,TCAMIONES);



    do{
        showMenu("1.MOSTRAR LISTADO DE CHOFERES\n"
                 "2.MOSTRAR LISTADO DE CAMIONES\n"
                 "3.MOSTRAR LISTADO DE CHOFERES CON SUS CAMIONES\n"
                 "4.ALTA DE CAMIONES\n"
                 "5.BAJA DE CAMIONES\n"
                 "6.MODIFICAR UN CAMION\n"
                 "7.ALTA DE CHOFER\n"
                 "8.BAJA DE CHOFER CON CAMIONES\n"
                 "9.ORDENAR CAMIONES POR TIPO.\n"
                 "10.MODIFICAR UN CHOFER\n"
                 "11.MOSTRAR CHOFERES CON MAS DE 1 CAMION\n"
                 "12.MOSTRAR CAMIONES(CON SUS CHOFERES) CON MAS DE 10 ANIOS\n"
                 "13.MOSTRAR CAMIONES POR MARCA\n"
                 "14.ORDENAR Y MOSTRAR CHOFERES POR CANTIDAD DE CAMIONES\n"
                 "15.ORDENAR Y MOSTRAR CHOFERES POR CANTIDAD DE CAMIONES Y NOMBRE\n"
                 "16.PROMEDIO DE EDAD ENTRE CHOFERES\n"
                 "17.PROMEDIO DE ANIOS DE ANTIGUEDAD DE FLOTA DE CAMIONES\n"
                 "18.MOSTRAR PROMEDIO ENTRE VARONES Y MUJERES\n"
                 "19.SALIR\n");

        opcion = getInt("Elija una opcion:","Opcion incorrecta.\n",1,19,3);

        switch(opcion){
        case 1:
            mostrarTodosLosChoferes(listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 2:
            mostrarTodosLosCamiones(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 3:
            mostrarListadoChoferesConCamiones(listaChoferes,TCHOFERES,listaCamiones,TCAMIONES);
            cleanScreen();
            break;
        case 4:
            respuesta = cargarListaCamiones(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            if(respuesta == 1){
                printf("Alta de camion exitosa.\n");
            }else if(respuesta == 0){
                printf("Alta de camion cancelada.\n");
            }else{
                printf("No se pudo dar de alta el camion.\n");
            }
            cleanScreen();
            break;
        case 5:
            mostrarTodosLosCamiones(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            respuesta = eliminarUnCamion(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            if(respuesta == 1){
                printf("Baja de camion exitosa.\n");
            }else if(respuesta == 0){
                printf("Baja de camion cancelada.\n");
            }else{
                printf("No se pudo dar de baja el camion.\n");
            }
            cleanScreen();
            break;
        case 6:
            mostrarTodosLosCamiones(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            respuesta = modificarUnCamion(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            if(respuesta == 1){
                printf("Modificacion de camion exitosa.\n");
            }else if(respuesta == 0){
                printf("Modificacion de camion cancelada.\n");
            }else{
                printf("No se pudo modificar el camion.\n");
            }
            cleanScreen();
            break;
        case 7:
            respuesta = cargarListaChoferes(listaChoferes,TCHOFERES);
            if(respuesta == 1){
                printf("Alta de chofer exitosa.\n");
            }else if(respuesta == 0){
                printf("Alta de chofer cancelada.\n");
            }else{
                printf("No se pudo dar de alta el chofer.\n");
            }
            cleanScreen();
            break;
        case 8:
            mostrarListadoChoferesConCamiones(listaChoferes,TCHOFERES,listaCamiones,TCAMIONES);
            respuesta = eliminarUnChofer(listaChoferes,TCHOFERES,listaCamiones,TCAMIONES);
            if(respuesta == 1){
                printf("Eliminacion de camion y choferes exitosa.\n");
            }else if(respuesta == 0){
                printf("Eliminacion de camion y choferes cancelada.\n");
            }else{
                printf("No se pudo hacer la eliminacion de choferes y camiones.\n");
            }
            cleanScreen();
            break;
        case 9:
            ordenarCamionesPorTipo(listaCamiones,TCAMIONES);
            mostrarTodosLosCamiones(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 10:
            mostrarTodosLosChoferes(listaChoferes,TCHOFERES);
            respuesta = modificarUnChofer(listaChoferes,TCHOFERES);
            if(respuesta == 1){
                printf("Modificacion de chofer exitosa.\n");
            }else if(respuesta == 0){
                printf("Modificacion de chofer cancelada.\n");
            }else{
                printf("No se pudo modificar el chofer.\n");
            }
            cleanScreen();
            break;
        case 11:
            mostrarChoferesConMasUnCamion(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 12:
            mostrarCamionesConMasDe10Anios(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 13:
            mostrarCamionPorMarca(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 14:
            mostrarChoferesOrdenadosPorCantidad(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 15:
            mostrarChoferesOrdenadosPorCantidadYNombre(listaCamiones,TCAMIONES,listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 16:
            mostrarPromedioEdadChoferes(listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 17:
            mostrarPromedioFlotaCamiones(listaCamiones,TCAMIONES);
            cleanScreen();
            break;
        case 18:
            mostrarPromedioChoferesMasculinos(listaChoferes,TCHOFERES);
            cleanScreen();
            break;
        case 19:
            break;
        }

    }while(opcion != 19);

    return 0;
}
