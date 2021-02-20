#include "parser.h"

int parser_VuelosDesdeText(FILE* pFile, LinkedList* pLinkedListVuelos){
    int retorno = -1;
    char idVuelo[3];
    char idAvion[3];
    char idPiloto[3];
    char fecha[11];
    char destino[14];
    char pasajeros[5];
    char despegue[3];
    char llegada[3];
    eVuelo* pVuelo;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,pasajeros,despegue,llegada);
    if(pFile != NULL){
        while(!feof(pFile)){
            if(feof(pFile)){
                break;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,pasajeros,despegue,llegada);
            pVuelo = vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,pasajeros,despegue,llegada);
                if(pVuelo != NULL){
                    ll_add(pLinkedListVuelos,pVuelo);
                }

        }

        retorno = 0;
    }

    return retorno;
}

int parser_PilotosDesdeText(FILE* pFile,LinkedList* pLinkedListPilotos){
    int retorno=-1;
    char id[2];
    char nombre[30];
    ePiloto* auxPiloto;

    if(pLinkedListPilotos != NULL && pFile != NULL){
        fscanf(pFile,"%[^,],%[^\n]\n",id,nombre);
        while(!feof(pFile)){
            if(feof(pFile)){
                break;
            }

            fscanf(pFile,"%[^,],%[^\n]\n",id,nombre);
            auxPiloto = piloto_newParametrosCaracter(nombre,id);
            if(auxPiloto != NULL){
                ll_add(pLinkedListPilotos,auxPiloto);
            }
        }

        retorno = 0;
    }

    return retorno;
}
