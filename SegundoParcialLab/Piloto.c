#include "Piloto.h"

ePiloto* piloto_new(){
    return (ePiloto*) malloc(sizeof(ePiloto));
}

ePiloto* piloto_newParametros(char* nombreCompleto,int id){
    ePiloto* pPiloto;
    ePiloto* pRetorno = NULL;

    pPiloto = piloto_new();

    if(pPiloto != NULL && piloto_setId(pPiloto,id) == 0 && piloto_setNombre(pPiloto,nombreCompleto) == 0){

        pRetorno = pPiloto;
    }

    return pRetorno;
}

ePiloto* piloto_newParametrosCaracter(char* nombre,char* id){
    ePiloto* pPiloto;
    ePiloto* pRetorno = NULL;

    pPiloto = piloto_new();

    if(pPiloto != NULL && piloto_setIdText(pPiloto,id) == 0 && piloto_setNombre(pPiloto,nombre) == 0){

        pRetorno = pPiloto;
    }

    return pRetorno;
}

int piloto_AltaDePiloto(LinkedList* pLinkedListPilotos,char* nombre,int* idPiloto){
    int retorno=-1;

    if(pLinkedListPilotos != NULL &&
                                    utn_GetNombre(nombre,30,"Ingrese nombre del piloto:","No es un nombre.\n",2) == 0 &&
                                    piloto_buscarProximoIdPiloto(pLinkedListPilotos,idPiloto) == 0){

        retorno = 0;

    }

    return retorno;
}

int piloto_getId(ePiloto* pPiloto,int* id){
    int retorno = -1;

    if(pPiloto != NULL){
        *id = pPiloto->id;
        retorno = 0;
    }

    return retorno;
}

int piloto_getNombre(ePiloto* pPiloto,char* nombreCompleto){
    int retorno=-1;

    if(pPiloto!= NULL){
        strcpy(nombreCompleto,pPiloto->nombreCompleto);
        retorno = 0;
    }

    return retorno;
}

int piloto_setId(ePiloto* pPiloto,int id){
    int retorno = -1;

    if(pPiloto != NULL){
        pPiloto->id = id;
        retorno = 0;
    }

    return retorno;
}

int piloto_setNombre(ePiloto* pPiloto,char* nombreCompleto){
    int retorno = -1;

    if(pPiloto != NULL && nombreCompleto != NULL){
        strcpy(pPiloto->nombreCompleto,nombreCompleto);
        retorno =0;
    }

    return retorno;
}

int piloto_setIdText(ePiloto* pPiloto,char* id){
    int retorno=-1;

    if(pPiloto != NULL && id != NULL){
        pPiloto->id = atoi(id);
        retorno = 0;
    }

    return retorno;
}


int piloto_buscarProximoIdPiloto(LinkedList* pLinkedListPilotos,int* maxId){
    int retorno=-1;
    int longitud;
    int i;
    ePiloto* auxPiloto;
    int id;

    if(pLinkedListPilotos != NULL){
        retorno = 0;

        if(ll_isEmpty(pLinkedListPilotos) == 1){
            *(maxId) = 1;
        }else{
            longitud = ll_len(pLinkedListPilotos);

            for(i=0; i < longitud;i++){
                auxPiloto = ll_get(pLinkedListPilotos,i);

                if(auxPiloto != NULL && piloto_getId(auxPiloto,&id) == 0){
                    if(id > *maxId || i == 0){
                        *maxId = id;
                    }
                }
            }
            (*(maxId))++;
        }
    }

    return retorno;
}


int piloto_mostrarUnPiloto(ePiloto* pPiloto){
    int retorno = -1;
    int id;
    char nombre[30];

    if(pPiloto != NULL && piloto_getId(pPiloto,&id) == 0 && piloto_getNombre(pPiloto,nombre) == 0){
        printf("%d %10s\n",id,nombre);
        retorno = 0;
    }

    return retorno;
}

int piloto_guardarListaPilotos(char* nombreArch,LinkedList* pLinkedListPilotos){
    int retorno = -1;
    FILE* pFile;
    int longitud;
    int i;
    int id;
    char nombre[30];
    ePiloto* auxPiloto;

    pFile = fopen(nombreArch,"w");

    if(pFile != NULL){
        longitud = ll_len(pLinkedListPilotos);
        fprintf(pFile,"ID,Nombre\n");

        for(i=0; i< longitud ; i++){
            auxPiloto = (ePiloto*) ll_get(pLinkedListPilotos,i);
            if(auxPiloto != NULL && piloto_getId(auxPiloto,&id) == 0 && piloto_getNombre(auxPiloto,nombre) == 0){
                fprintf(pFile,"%d,%s\n",id,nombre);
            }
        }

        retorno = 0;
    }

    return retorno;
}

int piloto_buscarPilotoPorId(LinkedList* pLinkedListPilotos,int idBuscado,char* nombre){
    int retorno=-1;
    int i;
    int longitud;
    ePiloto* auxPiloto;
    int idPiloto;
    char nombreBuscado[30];

    if(pLinkedListPilotos != NULL){
        longitud = ll_len(pLinkedListPilotos);

        for(i=0; i < longitud; i++){
            auxPiloto = ll_get(pLinkedListPilotos,i);
            if(auxPiloto != NULL && piloto_getId(auxPiloto,&idPiloto) == 0 && idPiloto == idBuscado){
                piloto_getNombre(auxPiloto,nombreBuscado);
                strcpy(nombre,nombreBuscado);

            retorno = 0;
            }
        }
    }

    return retorno;
}


int piloto_buscarIdPilotoPorNombre(LinkedList* pListaPilotos,char* nombreBuscado){
    int retorno = 0;
    int i;
    int longitud;
    ePiloto* pPiloto;
    char nombre[30];
    int idPiloto;


    if(pListaPilotos != NULL && nombreBuscado != NULL){
        longitud = ll_len(pListaPilotos);

        for(i=0; i < longitud;i++){
            pPiloto = (ePiloto*) ll_get(pListaPilotos,i);
            if(pPiloto != NULL && piloto_getNombre(pPiloto,nombre) == 0 && strcmp(nombre,nombreBuscado) == 0){
                piloto_getId(pPiloto,&idPiloto);
                retorno = idPiloto;
                break;
            }
        }
    }

    return retorno;
}
