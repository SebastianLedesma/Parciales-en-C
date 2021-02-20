#include <stdio.h>
#include <stdlib.h>
#include "Chofer_Camion.h"

#define OCUPADO 1
#define LIBRE 0
#define BORRADO -1

void mostrarListadoChoferesConCamiones(eChofer listaChoferes[],int cantidadChofer,eCamion listaCamion[],int cantidadCamion)
{
    int i;
    int j;
    char banderaTieneCamion;

    for(i=0; i< cantidadChofer; i++)
    {
        banderaTieneCamion = 'n';
        if(listaChoferes[i].estado == OCUPADO)
        {
            printf("ID  NOMBRE\tAPELLIDO\n");
            printf("%d %8s %10s\n\n",listaChoferes[i].id,listaChoferes[i].nombre,listaChoferes[i].apellido);

            for(j=0; j < cantidadCamion; j++)
            {
                if(listaChoferes[i].id == listaCamion[j].idChofer && listaCamion[j].estado == OCUPADO)
                {
                    mostrarUnCamion(listaCamion[j],listaChoferes,cantidadChofer);
                    banderaTieneCamion='s';
                }
            }

            if(banderaTieneCamion == 'n')
            {
                printf("No tiene chofer.\n");
            }

            printf("/////////////////////////////////////\n");
        }
    }
}


int eliminarUnChofer(eChofer listaChoferes[],int cantidadChoferes,eCamion listaCamiones[],int cantidadCamiones)
{
    int retorno;
    int idChofer;
    int indiceChofer;
    char respuesta;

    retorno = -1;
    idChofer = getInt("Ingrese el ID del chofer a eliminar:","Valor invalido.\n",1,cantidadChoferes,3);

    if(idChofer != -1){
        indiceChofer = buscarUnChoferPorId(listaChoferes,cantidadChoferes,idChofer);

        if(indiceChofer != -1)
        {
            printf("ID  NOMBRE   APELLIDO\t DNI\t LEGAJO\t NACIONALIDAD\t TELEFONO    EDAD  SEXO\n");
            mostrarUnChofer(listaChoferes[indiceChofer]);
            respuesta = getChar("Desea eliminar este chofer y los camiones que conduce?(s/n)");

            if(respuesta == 's')
            {
                eliminarChoferConSusCamiones(listaCamiones,cantidadCamiones,idChofer);
                listaChoferes[indiceChofer].estado = BORRADO;
                retorno = 1;
            }
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}


void eliminarChoferConSusCamiones(eCamion listaCamiones[],int cantidadCamiones,int idChofer)
{
    int i;

    for(i=0; i< cantidadCamiones; i++)
    {
        if(listaCamiones[i].idChofer == idChofer && listaCamiones[i].estado == OCUPADO)
        {
            listaCamiones[i].estado=BORRADO;
        }
    }
}


void mostrarChoferesConMasUnCamion(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChofer[],int cantidadChofer)
{
    int i;
    //int j;
    int arrayParalelo[cantidadChofer];
    //int contadorCamiones;

    for(i=0; i < cantidadChofer; i++)
    {
        //contadorCamiones = 0;
        if(listaChofer[i].estado == OCUPADO)
        {
            arrayParalelo[i]=contadorCamionesPorIdChofer(listaCamiones,cantidadCamiones,listaChofer[i].id);
        }

    }

    printf("ID  NOMBRE\tAPELLIDO   CAMIONES\n");
    for(i=0; i< cantidadChofer; i++)
    {
        if(arrayParalelo[i] > 1 && listaChofer[i].estado == OCUPADO)
        {
            mostrarUnChoferConCantidadCamiones(listaChofer[i],arrayParalelo[i]);
        }
    }
}


void mostrarChoferesOrdenadosPorCantidad(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChofer[],int cantidadChofer)
{
    int i;
    int j;
    int arrayParalelo[cantidadChofer];
    //int contadorCamiones;
    int auxInt;
    eChofer auxChofer;

    for(i=0; i < cantidadChofer; i++)
    {
        //contadorCamiones = 0;
        if(listaChofer[i].estado == OCUPADO)
        {
            arrayParalelo[i]=contadorCamionesPorIdChofer(listaCamiones,cantidadCamiones,listaChofer[i].id);
        }
    }


    for(i=0; i < cantidadChofer - 1; i++)
    {
        for(j= i+1; j < cantidadChofer; j++)
        {
            if(arrayParalelo[i] < arrayParalelo[j])
            {
                auxInt = arrayParalelo[i];
                arrayParalelo[i] = arrayParalelo[j];
                arrayParalelo[j]= auxInt;

                auxChofer = listaChofer[i];
                listaChofer[i] = listaChofer[j];
                listaChofer[j] = auxChofer;
            }
        }
    }

    printf("ID  NOMBRE\tAPELLIDO   CAMIONES\n");
    for(i=0; i< cantidadChofer; i++)
    {
        if(listaChofer[i].estado == OCUPADO)
        {
            mostrarUnChoferConCantidadCamiones(listaChofer[i],arrayParalelo[i]);
        }
    }
}


void mostrarChoferesOrdenadosPorCantidadYNombre(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChofer[],int cantidadChofer)
{
    int i;
    int j;
    int arrayParalelo[cantidadChofer];
    //int contadorCamiones;
    int auxInt;
    eChofer auxChofer;


    for(i=0; i < cantidadChofer; i++)
    {
        //contadorCamiones = 0;
        if(listaChofer[i].estado == OCUPADO)
        {
            arrayParalelo[i]=contadorCamionesPorIdChofer(listaCamiones,cantidadCamiones,listaChofer[i].id);
        }
    }


    for(i=0; i < cantidadChofer - 1; i++)
    {
        for(j= i+1; j < cantidadChofer; j++)
        {
            if(arrayParalelo[i] < arrayParalelo[j])
            {
                auxInt = arrayParalelo[i];
                arrayParalelo[i] = arrayParalelo[j];
                arrayParalelo[j]= auxInt;

                auxChofer = listaChofer[i];
                listaChofer[i] = listaChofer[j];
                listaChofer[j] = auxChofer;

            }
            else if(arrayParalelo[i] == arrayParalelo[j] && strcmp(listaChofer[i].nombre,listaChofer[j].nombre) < 0)
            {
                auxInt = arrayParalelo[i];
                arrayParalelo[i] = arrayParalelo[j];
                arrayParalelo[j]= auxInt;

                auxChofer = listaChofer[i];
                listaChofer[i] = listaChofer[j];
                listaChofer[j] = auxChofer;
            }
        }
    }

    printf("ID  NOMBRE\tAPELLIDO   CAMIONES\n");
    for(i=0; i< cantidadChofer; i++)
    {
        if(listaChofer[i].estado == OCUPADO)
        {
            mostrarUnChoferConCantidadCamiones(listaChofer[i],arrayParalelo[i]);
        }
    }

}
