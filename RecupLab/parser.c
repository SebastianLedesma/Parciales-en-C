#include "parser.h"

int parser_loadFromText(FILE* pFile,LinkedList* pLista){
    int retorno = 0;
    char fecha[11];
    char hora[6];
    char nombreServicio[65];
    char gravedad [2];
    char mensaje[65];
    LogEntry* logAux;

    //fscanf(pFile,"%[^;],%[^;],%[^;],%[^;],%[^\n]\n",fecha,hora,nombreServicio,gravedad,mensaje);

    if(pFile != NULL){
        while(!feof((pFile))){
            if(feof(pFile)){
                break;
            }

            fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",fecha,hora,nombreServicio,gravedad,mensaje);
            logAux = log_newParametros(fecha,hora,nombreServicio,gravedad,mensaje);
            if(logAux != NULL){
                ll_add(pLista,logAux);
            }
        }
        fclose(pFile);
        retorno = 1;
    }

    return retorno;
}
