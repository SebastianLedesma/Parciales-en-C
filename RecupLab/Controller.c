#include "Controller.h"

int controller_loadFromText(char* rutaArch,LinkedList* pLista){
    int retorno = -1;
    FILE* pFile;

    if(pLista != NULL){
       if(ll_isEmpty(pLista)){
            pFile = fopen(rutaArch,"r");
            if(pFile != NULL){
                parser_loadFromText(pFile,pLista);
                retorno = 1;
            }
       }else{
            retorno = 0;
       }
    }

    return retorno;
}


int controller_mostrarListaLogs(LinkedList*pLista){
    int retorno = 0;
    int i;
    int longitud;
    LogEntry* logAux;

    if(pLista != NULL){
        longitud = ll_len(pLista);

        printf("  FECHA         HORA           NOMBRE FALLO DE SERV        GRAVEDAD   MENS DE ERROR\n");
        for(i=0; i < longitud ; i++){
            logAux = ll_get(pLista,i);
            if(logAux != NULL){
                log_mostrarUnLog(logAux);
            }
        }
        retorno =1;
    }

    return retorno;
}


int controller_mostrarListaLogsFiltrada(LinkedList* pLista){
    int retorno = 0;
    int i;
    int longitud;
    LogEntry* logAux;

    if(pLista != NULL){
        longitud = ll_len(pLista);

        printf("  FECHA         HORA           NOMBRE FALLO DE SERV        MENS DE ERROR     GRAVEDAD\n");
        for(i=0; i < longitud ; i++){
            logAux = ll_get(pLista,i);
            if(logAux != NULL){
                log_mostrarUnLogFiltrado(logAux);
            }
        }
        retorno =1;
    }

    return retorno;
}


int controller_procesarInformacion(LinkedList* pLista,LinkedList** pListaSinClasificar,LinkedList** pListaWarning,LinkedList** pListaError,LinkedList** pListaMenor){
    int retorno = 0;
    char archivoWarning[]={"warnings.txt"};
    char archivoErrors[]={"errors.txt"};

    if(pLista != NULL){
        *pListaWarning = ll_filter(pLista,log_buscarGravedadTres);
        if(pListaWarning != NULL){
            log_guardarListaEnArchivo(archivoWarning,*pListaWarning);
        }


        *pListaSinClasificar = ll_filter(pLista,log_buscarGravedadIntermedio);
        if(pListaSinClasificar != NULL){
            controller_mostrarListaLogsFiltrada(*pListaSinClasificar);
        }

        *pListaError = ll_filter(pLista,log_buscarGravedadSuperior);
        if(pListaError != NULL){
            log_guardarListaEnArchivo(archivoErrors,*pListaError);
        }

        *pListaMenor = ll_filter(pLista,log_buscarGravedadMenor);
        retorno = 1;
    }

    return retorno;
}


int controller_mostrarEstadisticas(LinkedList* pLista,LinkedList** pListaSinClasificar,LinkedList** pListaWarning,LinkedList** pListaError,LinkedList** pListaMenor){
    int retorno = 0;

    if(pLista != NULL && pListaSinClasificar != NULL && pListaError != NULL && pListaWarning != NULL && pListaMenor != NULL){
        log_mostrarEstadistica("Gravedad menor a 3:",*pListaMenor);
        log_mostrarEstadistica("Gravedad nivel 3:",*pListaWarning);
        log_mostrarEstadistica("Gravedad entre 4 y 7:",*pListaSinClasificar);
        log_mostrarEstadistica("Gravedad mayor a 7:",*pListaError);

        retorno=1;
    }

    return retorno;
}
