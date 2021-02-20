#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

int main()
{
    LinkedList* pLista;
    LinkedList* pListaSinClasificar;
    LinkedList* pListaWarnings;
    LinkedList* pListaErrors;
    LinkedList* pListaMenor;

    int opcion;
    int retorno;
    char archivoLog[]={"log.txt"};

    pLista = ll_newLinkedList();

    do
    {
        utn_GetNumero(&opcion,"MENU\n"
                      "1.Leer Log.\n"
                      "2.Procesar informacion.\n"
                      "3.Mostrar estadisticas.\n"
                      "4.Imprimir lista Log.\n"
                      "5.Salir\n"
                      "Elija una opcion:",
                      "Opcion invalida.\n",1,5,2);

        switch(opcion){
            case 1:
                retorno = controller_loadFromText(archivoLog,pLista);
                if(retorno == 0){
                    printf("Ya se trajeron los datos del archivo.\n");
                }else if(retorno == -1){
                    printf("No se pudo leer el archivo.\n");
                }else{
                    printf("Archivo leido.\n");
                }
                break;
            case 2:
                retorno = controller_procesarInformacion(pLista,&pListaSinClasificar,&pListaWarnings,&pListaErrors,&pListaMenor);
                if(retorno == 0){
                    printf("No se pudo procesar la informacion.\n");
                }else{
                    printf("Info procesada.\n");
                }
                break;
            case 3:
                retorno = controller_mostrarEstadisticas(pLista,&pListaSinClasificar,&pListaWarnings,&pListaErrors,&pListaMenor);
                if(retorno == 0){
                    printf("Error al procesar estadisticas.\n");
                }else{
                    printf("Estas son todas las estadisticas.\n");
                }
                break;
            case 4:
                retorno = controller_mostrarListaLogs(pLista);
                if(retorno){
                    printf("Registros:%d\n",ll_len(pLista));
                }else{
                    printf("No se puede mostrar los registros.\n");
                }
                break;
            case 5:
                if(ll_deleteLinkedList(pLista) == 0){
                    printf("Se borro la lista.\n");
                }else{
                    printf("No se pudo borrar la lista.\n");
                }
                break;
        }
        cleanScreen();
    }
    while(opcion != 5);

    return 0;
}
