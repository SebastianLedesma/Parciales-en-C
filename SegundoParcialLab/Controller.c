#include "Controller.h"

int controller_cargarDesdeText(char* nombreArch,LinkedList* pLinkedListPrimario,char* nombreArchSecundario,LinkedList* pLinkedListSeundario){
    int retorno=-1;

    if(ll_isEmpty(pLinkedListPrimario) == 0 && ll_isEmpty(pLinkedListSeundario) == 0){
        retorno = 1;
    }else if(controller_leerUnArchivo(nombreArch,pLinkedListPrimario,parser_VuelosDesdeText) == 0 &&
             controller_leerUnArchivo(nombreArchSecundario,pLinkedListSeundario,parser_PilotosDesdeText) == 0){
        retorno = 0;
    }else{
        ll_clear(pLinkedListPrimario);
        ll_clear(pLinkedListSeundario);
    }

    return retorno;
}

int controller_leerUnArchivo(char* nombreArch,LinkedList* pLinkedList,int (*pFunc)(void*,void*)){
    int retorno= -1;
    char nombre[30];
    FILE* pFile;

    if(pLinkedList != NULL &&
                                    nombreArch != NULL &&
                                    utn_getNombreArchivo(nombre,30,"Ingrese nombre de archivo(incluya extension):","Nombre invalido.\n",2) == 0 &&
                                    strcmp(nombre,nombreArch) == 0){
        pFile = fopen(nombreArch,"r");

        if(pFile != NULL && pFunc(pFile,pLinkedList) == 0){
            retorno = 0;
        }
    }

    return retorno;
}

int controller_cargarArchivoPilotos(char* nombreArch,LinkedList* pLinkedListPilotos){
    int retorno= -1;
    char nombre[30];
    FILE* pFile;

    if(pLinkedListPilotos != NULL &&
                                    nombreArch != NULL &&
                                    utn_getNombreArchivo(nombre,30,"Ingrese nombre de archivo(incluya extension):","Nombre invalido.\n",2) == 0 &&
                                    strcmp(nombre,nombreArch) == 0){
        pFile = fopen(nombreArch,"r");

        if(pFile != NULL && parser_PilotosDesdeText(pFile,pLinkedListPilotos) == 0){
            retorno = 0;
        }
    }

    return retorno;
}

int controller_MostrarListaVuelos(LinkedList* pLinkedListVuelos,LinkedList* pLinkedListPilotos){
    int retorno = -1;
    int longitud;
    int i;
    eVuelo* pVuelo;
    int idPiloto;
    char nombre[30];

    if(pLinkedListVuelos != NULL && ll_isEmpty(pLinkedListVuelos) == 1){
        retorno = 1;
    }else{
        longitud = ll_len(pLinkedListVuelos);

        printf("VUELO  AVION    PILOTO             FECHA         DESTINO      PASAJEROS     SALIDA    LLEGADA\n");
        for(i=0; i < longitud; i++){
            pVuelo =(eVuelo*) ll_get(pLinkedListVuelos,i);
            if(pVuelo != NULL && vuelo_getIdPiloto(pVuelo,&idPiloto) == 0){
                piloto_buscarPilotoPorId(pLinkedListPilotos,idPiloto,nombre);
                vuelo_imprimirVuelo(pVuelo,nombre);
            }
        }

            retorno = 0;
    }

    return retorno;
}


int controller_agregarNuevoPiloto(LinkedList* pLinkedListPilotos){
    int retorno = -1;
    char nombre[30];
    int idPiloto;
    ePiloto* auxPiloto;
    char respuesta;

    if(pLinkedListPilotos != NULL && piloto_AltaDePiloto(pLinkedListPilotos,nombre,&idPiloto) == 0){
        auxPiloto = piloto_newParametros(nombre,idPiloto);

        if(auxPiloto != NULL){
            piloto_mostrarUnPiloto(auxPiloto);
            if(utn_GetRespuesta(&respuesta,"Desea dar de alta este piloto?(s/n)","Incorrecto.\n",2) == 0 && (respuesta == 's' || respuesta=='S')){
                ll_add(pLinkedListPilotos,auxPiloto);
                retorno=0;
            }
        }
    }

    return retorno;
}

int controller_mostrarListaPilotos(LinkedList* pLinkedListPilotos){
    int retorno = -1;
    int longitud;
    int i;
    ePiloto* auxPiloto;

    if(pLinkedListPilotos != NULL && ll_isEmpty(pLinkedListPilotos) == 1){
        retorno = 1;
    }else{
        longitud = ll_len(pLinkedListPilotos);

        printf("ID  Nombre\n");
        for(i=0; i < longitud;i++){
            auxPiloto = ll_get(pLinkedListPilotos,i);
            if(auxPiloto != NULL){
                piloto_mostrarUnPiloto(auxPiloto);
            }
        }

        printf("Total pilotos:%d\n",ll_len(pLinkedListPilotos));

        retorno = 0;
    }

    return retorno;
}


int controller_contar(LinkedList* pLinkedList,int opcion){
    int retorno = -1;

    if(pLinkedList != NULL){
        retorno=0;
        switch(opcion){
            case 3:
                retorno = ll_count(pLinkedList,vuelo_obtenerPasajeros);
                break;
            case 4:
                retorno = ll_count(pLinkedList,vuelo_obtenerPasajerosAIrlanda);
                break;
        }
    }

    return retorno;
}


int controller_filtrar(LinkedList* pLinkedListOriginal,LinkedList* pListaFiltrada,LinkedList* pLinkedListSecundaria,int opcion){
    int retorno =-1;

    if(pLinkedListOriginal != NULL && ll_isEmpty(pLinkedListOriginal) == 0 && ll_isEmpty(pListaFiltrada) == 1){
        switch(opcion){
        case 5:
            pListaFiltrada = ll_filter(pLinkedListOriginal,vuelo_obtenerVueloCorto);
            controller_MostrarListaVuelos(pListaFiltrada,pLinkedListSecundaria);
            vuelo_guardarListaVuelos("VuelosCortos.csv",pListaFiltrada);
            retorno = 1;
            break;
        case 6:
            pListaFiltrada = ll_filterPorCadenaCaracter(pLinkedListOriginal,vuelo_incluirVueloPorDestino,"Portugal");
            controller_MostrarListaVuelos(pListaFiltrada,pLinkedListSecundaria);
            retorno = 1;
            break;
        case 7:
            pListaFiltrada = vuelo_buscarVueloPorNombre(pLinkedListOriginal,pLinkedListSecundaria,"Alex Lifeson");
            controller_MostrarListaVuelos(pListaFiltrada,pLinkedListSecundaria);
            retorno = 1;
            break;
        case 8:
            pListaFiltrada = vuelo_buscarVueloPorPilotoIngresado(pLinkedListOriginal,pLinkedListSecundaria,vuelo_excluirVueloPorIdPiloto);
            controller_MostrarListaVuelos(pListaFiltrada,pLinkedListSecundaria);
            retorno = 1;
            break;
        case 9:
            pListaFiltrada = vuelo_buscarVueloPorPilotoIngresado(pLinkedListOriginal,pLinkedListSecundaria,vuelo_incluirVueloPorIdPiloto);
            controller_MostrarListaVuelos(pListaFiltrada,pLinkedListSecundaria);
            retorno=1;
            break;
        }
    }

    return retorno;
}

int controller_mostrarListaVuelosConPrecio(LinkedList* pLinkedListVuelos,LinkedList* pLinkedListPilotos){
    int retorno = -1;
    int longitud;
    int i;
    eVuelo* pVuelo;
    int idPiloto;
    char nombre[30];
    int precioTotal;

    if(pLinkedListVuelos != NULL && ll_isEmpty(pLinkedListVuelos) == 1){
        retorno = 1;
    }else{
        longitud = ll_len(pLinkedListVuelos);

        printf("VUELO  AVION    PILOTO          FECHA            DESTINO      PASAJEROS   SALIDA   LLEGADA  PRECIO\n");
        for(i=0; i < longitud; i++){
            pVuelo =(eVuelo*) ll_get(pLinkedListVuelos,i);
            if(pVuelo != NULL && vuelo_getIdPiloto(pVuelo,&idPiloto) == 0){
                piloto_buscarPilotoPorId(pLinkedListPilotos,idPiloto,nombre);
                precioTotal = vuelo_calcularPrecioVuelo(pVuelo);
                vuelo_mostrarUnVueloConPrecio(pVuelo,nombre,precioTotal);
            }
        }

            retorno = 0;
    }

    return retorno;
}
