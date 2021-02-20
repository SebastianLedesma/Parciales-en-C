#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"

typedef struct{
    int id;
    char nombreCompleto[30];
}ePiloto;

ePiloto* piloto_new();

ePiloto* piloto_newParametros(char*,int);

ePiloto* piloto_newParametrosCaracter(char*,char*);

int piloto_getId(ePiloto*,int*);

int piloto_getNombre(ePiloto*,char*);

int piloto_setId(ePiloto*,int);

int piloto_setNombre(ePiloto*,char*);

int piloto_buscarProximoIdPiloto(LinkedList*,int*);

int piloto_AltaDePiloto(LinkedList*,char*,int*);

int piloto_mostrarUnPiloto(ePiloto*);

int piloto_guardarListaPilotos(char*,LinkedList*);

int piloto_setIdText(ePiloto*,char*);

int piloto_buscarPilotoPorId(LinkedList*,int,char*);

int piloto_buscarIdPilotoPorNombre(LinkedList*,char*);
