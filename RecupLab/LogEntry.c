#include "LogEntry.h"

LogEntry* log_new(){
    return (LogEntry*) malloc(sizeof(LogEntry));
}

LogEntry* log_newParametros(char* date,char* time,char* service,char* gravedad,char* msg){
    LogEntry* logAux = NULL;
    LogEntry* pLog;

    logAux = log_new();

    if(logAux != NULL &&
                        log_setDate(logAux,date) &&
                        log_setTime(logAux,time) &&
                        log_setServiceName(logAux,service) &&
                        log_setGravedad(logAux,gravedad) &&
                        log_setMsg(logAux,msg)){

        pLog = logAux;
    }

    return pLog;
}

int log_setDate(LogEntry* pLog,char* date){
    int retorno = 0;

    if(pLog != NULL && date != NULL){
        strcpy(pLog->date,date);
        retorno = 1;
    }

    return retorno;
}

int log_getDate(LogEntry* pLog,char* date){
    int retorno = 0;

    if(pLog != NULL){
        strcpy(date,pLog->date);
        retorno = 1;
    }

    return retorno;
}

int log_setTime(LogEntry* pLog,char* time){
    int retorno = 0;

    if(pLog != NULL && time != NULL){
        strcpy(pLog->time,time);
        retorno = 1;
    }

    return retorno;
}

int log_getTime(LogEntry* pLog,char* time){
    int retorno=0;

    if(pLog != NULL){
        strcpy(time,pLog->time);
        retorno = 1;
    }
    return retorno;
}

int log_setServiceName(LogEntry* pLog,char* service){
    int retorno = 0;

    if(pLog != NULL && service != NULL){
        strcpy(pLog->serviceName,service);
        retorno = 1;
    }

    return retorno;
}

int log_getServiceName(LogEntry* pLog,char* service){
    int retorno=0;

    if(pLog != NULL){
        strcpy(service,pLog->serviceName);
        retorno = 1;
    }

    return retorno;
}

int log_setGravedad(LogEntry* pLog,char* gravedad){
    int retorno = 0;

    if(pLog != NULL && gravedad != NULL){
        pLog->gravedad = atoi(gravedad);
        retorno = 1;
    }
    return retorno;
}

int log_getGravedad(LogEntry* pLog,int* gravedad){
    int retorno=0;

    if(pLog != NULL){
        *gravedad = pLog->gravedad;
        retorno = 1;
    }

    return retorno;
}

int log_setMsg(LogEntry* pLog,char* msg){
    int retorno = 0;

    if(pLog != NULL && msg != NULL){
        strcpy(pLog->msg,msg);
        retorno = 1;
    }
    return retorno;
}

int log_getMsg(LogEntry* pLog,char* msg){
    int retorno = 0;

    if(pLog != NULL){
        strcpy(msg,pLog->msg);
        retorno = 1;
    }

    return retorno;
}


int log_mostrarUnLog(LogEntry* pLog){
    int retorno = 0;
    char fecha[11];
    char hora[6];
    char nombreServicio[65];
    int gravedad;
    char mensaje[65];

    if(pLog != NULL &&
                    log_getDate(pLog,fecha) &&
                    log_getTime(pLog,hora) &&
                    log_getServiceName(pLog,nombreServicio) &&
                    log_getGravedad(pLog,&gravedad) &&
                    log_getMsg(pLog,mensaje)){

        printf("%s %10s %30s %10d %20s\n",fecha,hora,nombreServicio,gravedad,mensaje);
        retorno = 1;
    }

    return retorno;
}


int log_mostrarUnLogFiltrado(LogEntry* pLog){
    int retorno = 0;
    char fecha[11];
    char hora[6];
    char nombreServicio[65];
    int gravedad;
    char mensaje[65];

    if(pLog != NULL &&
                    log_getDate(pLog,fecha) &&
                    log_getTime(pLog,hora) &&
                    log_getServiceName(pLog,nombreServicio) &&
                    log_getGravedad(pLog,&gravedad) &&
                    log_getMsg(pLog,mensaje)){

        printf("%s %10s %30s %20s %10d\n",fecha,hora,nombreServicio,mensaje,gravedad);
        retorno = 1;
    }

    return retorno;
}


int log_guardarListaEnArchivo(char* rutaArch,LinkedList* pLista){
    int retorno = 0;
    char fecha[11];
    char hora[6];
    char nombreServicio[65];
    int gravedad;
    char mensaje[65];
    int longitud;
    int i;
    LogEntry* logAux;
    FILE* pFile;

    if(pLista != NULL){
        pFile = fopen(rutaArch,"w");
        longitud = ll_len(pLista);
        if(pFile != NULL){
            for(i = 0; i < longitud; i++){
                logAux =(LogEntry*) ll_get(pLista,i);
                //log_mostrarUnLog(logAux);
                if(logAux != NULL &&
                                    log_getDate(logAux,fecha) &&
                                    log_getTime(logAux,hora) &&
                                    log_getServiceName(logAux,nombreServicio) &&
                                    log_getGravedad(logAux,&gravedad) &&
                                    log_getMsg(logAux,mensaje)){
                    fprintf(pFile,"%s;%s;%s;%s;%d\n",fecha,hora,nombreServicio,mensaje,gravedad);
                }
            }
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}


int log_buscarGravedadTres(LogEntry* pLog){
    int retorno = 0;
    int gravedad;

    if(pLog != NULL && log_getGravedad(pLog,&gravedad) && gravedad == 3){
        retorno = 1;
    }
    return retorno;
}

int log_buscarGravedadIntermedio(LogEntry* pLog){
    int retorno=0;
    int gravedad;

    if(pLog != NULL && log_getGravedad(pLog,&gravedad) && gravedad >= 4 && gravedad <= 7){
        retorno = 1;
    }
    return retorno;
}


int log_buscarGravedadSuperior(LogEntry* pLog){
    int retorno = 0;
    int gravedad;

    if(pLog != NULL && log_getGravedad(pLog,&gravedad) && gravedad > 7){
        retorno = 1;
    }

    return retorno;
}

int log_buscarGravedadMenor(LogEntry* pLog){
    int retorno=0;
    int gravedad;

    if(pLog != NULL && log_getGravedad(pLog,&gravedad) && gravedad < 3){
        retorno = 1;
    }
    return retorno;
}


int log_mostrarEstadistica(char* mensaje,LinkedList* pLista){
    int retorno = 0;
    int registros;
    if(pLista != NULL){
        registros = ll_len(pLista);
        printf("%s %d\n",mensaje,registros);
        retorno=1;
    }
    return retorno;
}
