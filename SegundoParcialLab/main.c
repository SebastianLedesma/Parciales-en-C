#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
int main()
{
    LinkedList* pLinkedListVuelos;
    LinkedList* pLinkedListPilotos;
    LinkedList* pLinkedListVuelosCortos;
    LinkedList* pLinkedListVuelosPortugal;
    LinkedList* pLinkedListExcluirPiloto;
    LinkedList* pLinkedListVuelosConPrecio;
    LinkedList* pLinkedListPorPilotoExcluido;
    LinkedList* pLinkedListPorPilotoExcluidoIngresado;
    LinkedList* pLinkedListPorPilotoIncluidoIngresado;

    pLinkedListVuelos = ll_newLinkedList();
    pLinkedListPilotos = ll_newLinkedList();
    pLinkedListVuelosCortos = ll_newLinkedList();
    pLinkedListVuelosPortugal= ll_newLinkedList();
    pLinkedListPorPilotoExcluido = ll_newLinkedList();
    pLinkedListVuelosConPrecio = ll_newLinkedList();
    pLinkedListPorPilotoExcluidoIngresado = ll_newLinkedList();
    pLinkedListPorPilotoIncluidoIngresado = ll_newLinkedList();

    char archivoTextoVuelos[]={"Vuelos.csv"};
    char archivoTextoPilotos[]={"Pilotos.csv"};

    int opcion;
    int retorno;

    do{
        utn_GetNumero(&opcion,"MENU\n"
                                "1.Cargar archivo.\n"
                                "2.Imprimir vuelos.\n"
                                "3.Cantidad de pasajaeros\n"
                                "4.Cantidad de pasajeros a Irlanda.\n"
                                "5.Filtrar vuelos cortos\n"
                                "6.Listar vuelos a Portugal.\n"
                                "7.Filtrar a Alex Lifesson\n"
                                "8.Mostrar lista de vuelos por nombre piloto(excluir).\n"
                                "9.Mostrar lista de vuelo por nombre de piloto.(incluir).\n"
                                "10.Salir.\n"
                                "Elija una opcion:",
                                "Opcion incorrecta.\n",1,10,2);

        switch(opcion){
        case 1:
            retorno = controller_cargarDesdeText(archivoTextoVuelos,pLinkedListVuelos,archivoTextoPilotos,pLinkedListPilotos);
            if(retorno == 0){
                printf("Datos traidos correctamente.\n");
            }else if(retorno == 1){
                printf("Ya se trajeron los datos del archivo.\n ");
            }else{
                printf("No se pudo leer el archivo.\n");
            }
            break;
        case 2:
            retorno = controller_MostrarListaVuelos(pLinkedListVuelos,pLinkedListPilotos);
            if(retorno == 1){
                printf("Debe traer los datos del archivo.\n");
            }else if(retorno == -1){
                printf("No se puede mostrar los datos.\n");
            }else{
                printf("Total de vuelos:%d\n",ll_len(pLinkedListVuelos));
            }
            break;
        case 3:
            retorno = controller_contar(pLinkedListVuelos,3);
            if(retorno == -1){
                printf("No se pudo contar.\n");
            }else{
                printf("Cant de pasajeros:%d\n",retorno);
            }
            break;
        case 4:
            retorno = controller_contar(pLinkedListVuelos,4);
            if(retorno == -1){
                printf("No se pudo contar.\n");
            }else{
                printf("Cant de pasajeros a Irlanda:%d\n",retorno);
            }
            break;
        case 5:
            retorno = controller_filtrar(pLinkedListVuelos,pLinkedListVuelosCortos,pLinkedListPilotos,5);
            if(retorno == 1){
                printf("Lista filtrada.\n");
            }else{
                printf("Error.\n");
            }
            break;
        case 6:
            retorno = controller_filtrar(pLinkedListVuelos,pLinkedListVuelosPortugal,pLinkedListPilotos,6);
            if(retorno == 1){
                printf("Lista filtrada.\n");
            }else{
                printf("Error.\n");
            }
            break;
        case 7:
            retorno = controller_filtrar(pLinkedListVuelos,pLinkedListPorPilotoExcluido,pLinkedListPilotos,7);
            if(retorno == 1){
                printf("Lista filtrada.\n");
            }else{
                printf("Error.\n");
            }
            break;
        case 8:
           retorno = controller_filtrar(pLinkedListVuelos,pLinkedListPorPilotoExcluidoIngresado,pLinkedListPilotos,8);
           if(retorno == 1){
                printf("Lista filtrada.\n");
           }else{
                printf("Error.\n");
           }
            break;
        case 9:
            retorno = controller_filtrar(pLinkedListVuelos,pLinkedListPorPilotoIncluidoIngresado,pLinkedListPilotos,9);
            if(retorno == 1){
                printf("Lista filtrada.\n");
           }else{
                printf("Error.\n");
           }
            break;
            case 10:
            break;
        }
        cleanScreen();

    }while(opcion != 10);

    return 0;
}
