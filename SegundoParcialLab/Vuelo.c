#include "Vuelo.h"

#define DESTINO_LEN 10

//**********************CONSTRUCTORES***********************
eVuelo* vuelo_new(){
    return (eVuelo*) malloc(sizeof(eVuelo));
}


eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* pasajeros,char* despegue,char* llegada){
    eVuelo* vueloAux;

    vueloAux = vuelo_new();

    if(vueloAux != NULL && vuelo_setIdVueloText(vueloAux,idVuelo) == 0 &&
                        vuelo_setIdAvionText(vueloAux,idAvion) == 0 &&
                        vuelo_setIdPilotoText(vueloAux,idPiloto) == 0 &&
                        vuelo_setFecha(vueloAux,fecha) == 0 &&
                        vuelo_setDestino(vueloAux,destino) == 0 &&
                        vuelo_setCantPasajerosText(vueloAux,pasajeros) == 0 &&
                        vuelo_setHoraDespegueText(vueloAux,despegue) == 0 &&
                        vuelo_setHoraLlegadaText(vueloAux,llegada) == 0){
        return vueloAux;
    }else{
        return NULL;
    }

}

//*********************GETTERS****************************

int vuelo_getIdVuelo(eVuelo* pVuelo,int* idVuelo){
    int retorno=-1;

    if(pVuelo != NULL){
        *idVuelo = pVuelo->idVuelo;
        retorno =0;
    }

    return retorno;
}

int vuelo_getIdAvion(eVuelo* pVuelo,int* idAvion){
    int retorno=-1;

    if(pVuelo != NULL){
        *idAvion = pVuelo->idAvion;
        retorno = 0;
    }

    return retorno;
}

int vuelo_getIdPiloto(eVuelo* pVuelo,int* idPiloto){
    int retorno=-1;

    if(pVuelo != NULL){
        *idPiloto = pVuelo->idPiloto;
        retorno=0;
    }

    return retorno;
}

int vuelo_getFecha(eVuelo* pVuelo,char* fecha){
    int retorno=-1;

    if(pVuelo != NULL && fecha != NULL){
        strcpy(fecha,pVuelo->fecha);
        retorno = 0;
    }

    return retorno;
}

int vuelo_getDestino(eVuelo* pVuelo,char* destino){
    int retorno=-1;

    if(pVuelo !=  NULL && destino != NULL){
        strcpy(destino,pVuelo->destino);
        retorno = 0;
    }

    return retorno;
}

int vuelo_getCantPasajeros(eVuelo* pVuelo,int* cantPasajeros){
    int retorno=-1;

    if(pVuelo != NULL){
        *cantPasajeros = pVuelo->cantPasajeros;
        retorno = 0;
    }

    return retorno;
}

int vuelo_getHoraDesepegue(eVuelo* pVuelo,int* despegue){
    int retorno=-1;

    if(pVuelo != NULL){
        *despegue = pVuelo->horaDespegue;
        retorno = 0;
    }

    return retorno;
}

int vuelo_getHoraLlegada(eVuelo* pVuelo,int* llegada){
    int retorno=-1;

    if(pVuelo != NULL){
        *llegada = pVuelo->horaLlegada;
        retorno = 0;
    }

    return retorno;
}

//*******************SETTERS***************************

int vuelo_setIdVueloText(eVuelo* pVuelo,char* idVuelo){
    int retorno=-1;

    if(pVuelo != NULL && idVuelo != NULL){
        /*
        if(esNumerica(idVuelo,10)==1){
            pVuelo->idVuelo = atoi(idVuelo);
            retorno = 0;
        }
        */
         pVuelo->idVuelo = atoi(idVuelo);
        retorno = 0;
    }

    return retorno;
}

int vuelo_setIdAvionText(eVuelo* pVuelo,char* idAvion){
    int retorno=-1;

    if(pVuelo != NULL && idAvion != NULL){
        //if(esNumerica(idAvion,10) == 1){
            pVuelo->idAvion = atoi(idAvion);
            retorno = 0;
        //}
    }

    return retorno;
}

int vuelo_setIdPilotoText(eVuelo* pVuelo,char* idPiloto){
    int retorno = -1;

    if(pVuelo != NULL && idPiloto != NULL){
        pVuelo->idPiloto = atoi(idPiloto);
        retorno = 0;
    }

    return retorno;
}

int vuelo_setFecha(eVuelo* pVuelo,char* fecha){
    int retorno = -1;

    if(pVuelo != NULL && fecha != NULL){
        strcpy(pVuelo->fecha,fecha);
        retorno = 0;
    }

    return retorno;
}

int vuelo_setDestino(eVuelo* pVuelo,char* destino){
    int retorno = -1;

    if(pVuelo != NULL && destino != NULL){
        if(esNombre(destino,DESTINO_LEN) == 1){
            strcpy(pVuelo->destino,destino);
            retorno = 0;
        }
    }

    return retorno;
}

int vuelo_setCantPasajerosText(eVuelo* pVuelo,char* pasajeros){
    int retorno=-1;

    if(pVuelo != NULL && pasajeros != NULL){
        //if(esNumerica(pasajeros,10)==1){
            pVuelo->cantPasajeros= atoi(pasajeros);
            retorno = 0;
        //}
    }

    return retorno;
}

int vuelo_setHoraDespegueText(eVuelo* pVuelo,char* despegue){
    int retorno=-1;

    if(pVuelo != NULL && despegue != NULL){
        //if(esNumerica(despegue,10) == 1){
            pVuelo->horaDespegue = atoi(despegue);
            retorno = 0;
        //}
    }

    return retorno;
}

int vuelo_setHoraLlegadaText(eVuelo* pVuelo,char* llegada){
    int retorno=-1;

    if(pVuelo != NULL && llegada != NULL){
        //if(esNumerica(llegada,2) == 1){
            pVuelo->horaLlegada = atoi(llegada);
            retorno = 0;
        //}
    }

    return retorno;
}

int vuelo_imprimirVuelo(eVuelo* pVuelo,char* nombre){
    int retorno=-1;
    int idVuelo;
    int idAvion;
    //int idPiloto;
    char fecha[14];
    char destino[14];
    int pasajeros;
    int despegue;
    int llegada;

    if(pVuelo != NULL &&
                        vuelo_getIdVuelo(pVuelo,&idVuelo) == 0 &&
                        vuelo_getIdAvion(pVuelo,&idAvion) == 0 &&
                        vuelo_getFecha(pVuelo,fecha) == 0 &&
                        vuelo_getDestino(pVuelo,destino) ==0 &&
                        vuelo_getCantPasajeros(pVuelo,&pasajeros) == 0 &&
                        vuelo_getHoraDesepegue(pVuelo,&despegue) == 0 &&
                        vuelo_getHoraLlegada(pVuelo,&llegada) == 0){

        printf("%d  %5d  %15s  %15s  %15s  %5d  %10d  %10d\n",idVuelo,idAvion,nombre,fecha,destino,pasajeros,despegue,llegada);
        retorno =0;
    }

    return retorno;
}


int vuelo_obtenerPasajeros(eVuelo* pVuelo){
    int pasajeros = -1;

    if(pVuelo != NULL){
        vuelo_getCantPasajeros(pVuelo,&pasajeros);
    }

    return pasajeros;
}

int vuelo_obtenerPasajerosAIrlanda(eVuelo* pVuelo){
    int pasajeros = 0;
    char destino[10];

    if(pVuelo != NULL && vuelo_getDestino(pVuelo,destino) == 0 && strcmp(destino,"Irlanda") == 0){
        vuelo_getCantPasajeros(pVuelo,&pasajeros);
    }

    return pasajeros;
}

int vuelo_obtenerVueloCorto(eVuelo* pVuelo){
    int retorno = -1;
    int despegue;
    int llegada;
    int tiempo;
    if(pVuelo != NULL && vuelo_getHoraDesepegue(pVuelo,&despegue) == 0 && vuelo_getHoraLlegada(pVuelo,&llegada) == 0){
        tiempo = llegada - despegue;
        if(tiempo < 3){
            retorno = 0;
        }
    }

    return retorno;
}

int vuelo_guardarListaVuelos(char* nombreArch,LinkedList* pLinkedList){
    int retorno=-1;
    FILE* pFile;
    int longitud;
    int i;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[11];
    char destino[14];
    int pasajeros;
    int despegue;
    int llegada;
    eVuelo* auxVuelo;

    pFile = fopen(nombreArch,"w");

    if(pFile != NULL){
        longitud = ll_len(pLinkedList);
        fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

        for(i=0; i< longitud ; i++){
            auxVuelo = (eVuelo*) ll_get(pLinkedList,i);
            if(auxVuelo != NULL && vuelo_getIdVuelo(auxVuelo,&idVuelo) == 0 &&
                                    vuelo_getIdAvion(auxVuelo,&idAvion) == 0 &&
                                    vuelo_getIdPiloto(auxVuelo,&idPiloto) == 0 &&
                                    vuelo_getFecha(auxVuelo,fecha) == 0 &&
                                    vuelo_getDestino(auxVuelo,destino) == 0 &&
                                    vuelo_getCantPasajeros(auxVuelo,&pasajeros) == 0 &&
                                    vuelo_getHoraDesepegue(auxVuelo,&despegue) == 0 &&
                                    vuelo_getHoraLlegada(auxVuelo,&llegada) == 0){

                fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,pasajeros,despegue,llegada);
            }
        }

        retorno = 0;
    }

    return retorno;
}

int vuelo_incluirVueloPorDestino(eVuelo* pVuelo,char* nombre){
    char nombreDestino[30];
    int retorno = 0;
    if(pVuelo != NULL && vuelo_getDestino(pVuelo,nombreDestino) == 0 && strcmp(nombreDestino,nombre) == 0){
        retorno = 1;
    }

    return retorno;
}


int vuelo_filtrarPorExcluirPiloto(LinkedList* pLinkedList,eVuelo* pVuelo,char* nombrePiloto){
    int retorno=-1;
    int idPiloto;
    char nombreEncontrado[30];

    if(pVuelo != NULL && vuelo_getIdPiloto(pVuelo,&idPiloto)==0
                        && piloto_buscarPilotoPorId(pLinkedList,idPiloto,nombreEncontrado) == 0 &&
                        strcmp(nombrePiloto,nombreEncontrado) != 0){
        retorno = 0;
    }

    return retorno;
}

int vuelo_esVueloADestino(eVuelo* pVuelo){
    int retorno= -1;
    char destino[14];

    if(pVuelo != NULL){
        if(vuelo_getDestino(pVuelo,destino) == 0 && strcmp(destino,"Portugal") == 0){
            vuelo_setPrecio(pVuelo,1500);
        }else{
            vuelo_setPrecio(pVuelo,1000);
        }
        retorno = 0;
    }

    return retorno;
}


int vuelo_setPrecio(eVuelo* pVuelo,int precio){
    int retorno=-1;

    if(pVuelo != NULL && precio > 0){
        pVuelo->precio = precio;
        retorno = 0;
    }

    return retorno;
}

int vuelo_getPrecio(eVuelo* pVuelo,int* precio){
    int retorno=-1;

    if(pVuelo != NULL && precio != NULL){
        *precio = pVuelo->precio;
        retorno = 0;
    }

    return retorno;
}

int vuelo_mostrarUnVueloConPrecio(eVuelo* pVuelo,char* nombre,int precioTotal){
    int retorno=-1;
    int idVuelo;
    int idAvion;
    char fecha[14];
    char destino[14];
    int pasajeros;
    int despegue;
    int llegada;

    if(pVuelo != NULL &&
                        vuelo_getIdVuelo(pVuelo,&idVuelo) == 0 &&
                        vuelo_getIdAvion(pVuelo,&idAvion) == 0 &&
                        vuelo_getFecha(pVuelo,fecha) == 0 &&
                        vuelo_getDestino(pVuelo,destino) ==0 &&
                        vuelo_getCantPasajeros(pVuelo,&pasajeros) == 0 &&
                        vuelo_getHoraDesepegue(pVuelo,&despegue) == 0 &&
                        vuelo_getHoraLlegada(pVuelo,&llegada) == 0){

        printf("%d  %5d  %15s  %15s  %15s  %5d  %8d  %8d  %8d\n",idVuelo,idAvion,nombre,fecha,destino,pasajeros,despegue,llegada,precioTotal);
        retorno =0;
    }

    return retorno;
}

int vuelo_calcularPrecioVuelo(eVuelo* pVuelo){
    int retorno = -1;
    int precio;
    int pasajeros;

    if(pVuelo != NULL && vuelo_getPrecio(pVuelo,&precio) == 0 && vuelo_getCantPasajeros(pVuelo,&pasajeros) == 0){
        retorno = pasajeros * precio;
    }

    return retorno;
}

int vuelo_guardarListaVuelosCoPrecio(char* nombreArch,LinkedList* pLinkedList){
    int retorno=-1;
    FILE* pFile;
    int longitud;
    int i;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[11];
    char destino[14];
    int pasajeros;
    int despegue;
    int llegada;
    int precioTotal;
    eVuelo* auxVuelo;

    pFile = fopen(nombreArch,"w");

    if(pFile != NULL){
        longitud = ll_len(pLinkedList);
        fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada,precioTotal\n");

        for(i=0; i< longitud ; i++){
            auxVuelo = (eVuelo*) ll_get(pLinkedList,i);
            precioTotal = vuelo_calcularPrecioVuelo(auxVuelo);
            if(auxVuelo != NULL && vuelo_getIdVuelo(auxVuelo,&idVuelo) == 0 &&
                                    vuelo_getIdAvion(auxVuelo,&idAvion) == 0 &&
                                    vuelo_getIdPiloto(auxVuelo,&idPiloto) == 0 &&
                                    vuelo_getFecha(auxVuelo,fecha) == 0 &&
                                    vuelo_getDestino(auxVuelo,destino) == 0 &&
                                    vuelo_getCantPasajeros(auxVuelo,&pasajeros) == 0 &&
                                    vuelo_getHoraDesepegue(auxVuelo,&despegue) == 0 &&
                                    vuelo_getHoraLlegada(auxVuelo,&llegada) == 0){

                fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,pasajeros,despegue,llegada,precioTotal);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}


int vuelo_buscarVueloPorIdPiloto(eVuelo* pVuelo,int idBuscado){
    int retorno = 0;
    int idPiloto;

    if(pVuelo != NULL && vuelo_getIdPiloto(pVuelo,&idPiloto) == 0 && idBuscado == idPiloto){
        retorno = 1;
    }

        return retorno;
}

LinkedList* vuelo_buscarVueloPorNombre(LinkedList* pListaVuelos,LinkedList* pListaPilotos,char* nombreBuscado){
    int idPiloto;
    LinkedList* pListaFiltrada;

    if(pListaVuelos != NULL && nombreBuscado != NULL){
        idPiloto = piloto_buscarIdPilotoPorNombre(pListaPilotos,nombreBuscado);

        if(idPiloto != 0){
            pListaFiltrada = ll_filterPorEntero(pListaVuelos,vuelo_excluirVueloPorIdPiloto,idPiloto);
        }
    }

    return pListaFiltrada;
}


int vuelo_incluirVueloPorIdPiloto(eVuelo* pVuelo,int idBuscado){
    int retorno = 0;
    int idPiloto;

    if(pVuelo != NULL && idBuscado > 0 && vuelo_getIdPiloto(pVuelo,&idPiloto) == 0 && idPiloto == idBuscado){
        retorno = 1;
    }

    return retorno;
}

int vuelo_excluirVueloPorIdPiloto(eVuelo* pVuelo,int idBuscado){
    int retorno = 0;
    int idPiloto;

    if(pVuelo != NULL && idBuscado > 0 && vuelo_getIdPiloto(pVuelo,&idPiloto) == 0 && idPiloto != idBuscado){
        retorno = 1;
    }

    return retorno;
}

LinkedList* vuelo_buscarVueloPorPilotoIngresado(LinkedList* pListaVuelos,LinkedList* pListaPilotos,int (*pFunc)(void*,int*)){
    char nombre[30];
    int idPiloto;
    LinkedList* pListaFiltrada= NULL;

    if(pListaPilotos != NULL && utn_GetNombre(nombre,30,"Ingrese el nombre de piloto:","Error.\n",2) == 0){
        idPiloto = piloto_buscarIdPilotoPorNombre(pListaPilotos,nombre);

        if(idPiloto != 0){
            pListaFiltrada = ll_filterPorEntero(pListaVuelos,pFunc,idPiloto);
        }
    }

    return pListaFiltrada;
}
