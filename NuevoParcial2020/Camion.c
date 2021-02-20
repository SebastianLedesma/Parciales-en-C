#include "Camion.h"

#define OCUPADO 1
#define LIBRE 0
#define BORRADO -1

void inicializarEstadoCamiones(eCamion listaCamiones[],int cantidadCamiones){
    int i;

    for(i=0; i < cantidadCamiones;i++){
        listaCamiones[i].estado = LIBRE;
    }
}

void hardcodearListsCamiones(eCamion listaCamiones[],int cantidadCamiones)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][10]= {{"FDG123"},{"RER309"},{"FRR123"},{"GTR332"},{"HHO434"},{"FOT490"},{"FRT342"},{"TTT453"},{"OPE654"},{"GTA111"}};
    char marca[][15]= {{"Ford"},{"Ford"},{"Fiat"},{"Fiat"},{"VW"},{"Ford"},{"Ford"},{"Ford"},{"Ford"},{"Ford"}};
    int anio[]= {2000,2000,2005,2006,2010,2005,2015,2017,2017,2016};
    float peso[]= {1.10,2,1.50,1.35,1.6,2,1.4,1.35,2,2.1};
    int cantidadRuedas[]= {6,8,6,8,6,8,6,8,6,8};
    char tipo[][20]= {{"cortaDistancia"},{"largaDistancia"},{"cortaDistancia"},{"largaDistancia"},{"cortaDistancia"},{"largaDistancia"},{"cortaDistancia"},{"largaDistancia"},{"cortaDistancia"},{"largaDistancia"}};
    int idChofer[]= {1,1,2,2,3,4,4,5,5,5};
    int estado[]= {1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i = 0; i<10; i++)
    {
        listaCamiones[i].id= id[i];
        strcpy(listaCamiones[i].patente,patente[i]);
        strcpy(listaCamiones[i].marca,marca[i]);
        //listaCamiones[i].idMarca = idMarca[i];
        listaCamiones[i].anio=anio[i];
        listaCamiones[i].peso=peso[i];
        listaCamiones[i].cantidadRuedas=cantidadRuedas[i];
        strcpy(listaCamiones[i].tipo,tipo[i]);
        listaCamiones[i].idChofer=idChofer[i];
        listaCamiones[i].estado=estado[i];
    }
}


void mostrarUnCamion(eCamion camion,eChofer listaChoferes[],int cantidadChoferes)
{
    int idChofer;

    idChofer = buscarUnChoferPorId(listaChoferes,cantidadChoferes,camion.idChofer);
    printf("ID  PATENTE    MARCA\tANIO\tPESO\tTIPO\t\tIDCHOFER   CHOFER\n");
    printf("%d %8s %8s %8d %8.2f  %10s %5d %15s\n",camion.id,
                                                camion.patente,
                                                camion.marca,
                                                camion.anio,
                                                camion.peso,
                                                camion.tipo,
                                                camion.idChofer,
                                                listaChoferes[idChofer].nombre);
}


void mostrarTodosLosCamiones(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChoferes[],int cantidadChofer)
{
    int i;

    printf("ID  PATENTE    MARCA\tANIO\tPESO\tTIPO\t\tIDCHOFER   CHOFER\n");
    for(i=0; i< cantidadCamiones; i++)
    {
        if(listaCamiones[i].estado == OCUPADO)
        {
            mostrarUnCamion(listaCamiones[i],listaChoferes,cantidadChofer);
        }
    }
}


int buscarIndiceLibreCamion(eCamion listaCamiones[],int cantidadCamiones)
{
    int i;
    int retorno;

    retorno = -1;

    for(i=0; i < cantidadCamiones; i++)
    {
        if(listaCamiones[i].estado != OCUPADO)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int cargarListaCamiones(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChoferes[],int cantidadChoferes)
{
    int indiceLibre;
    int idAsignado;
    int retorno;
    char respuesta;
    eCamion auxCamion;

    retorno = -1;

    indiceLibre = buscarIndiceLibreCamion(listaCamiones,cantidadCamiones);

    if(indiceLibre != -1)
    {
        idAsignado = asignarIDCamion(listaCamiones,cantidadCamiones,indiceLibre);
        auxCamion = cargarUnCamion(listaChoferes,cantidadChoferes,idAsignado);

        if(auxCamion.id == 0){
            retorno = 0;
        }else{
            printf("ID  PATENTE    MARCA\tANIO\tPESO\tTIPO\t\tIDCHOFER   CHOFER\n");
            mostrarUnCamion(auxCamion,listaChoferes,cantidadChoferes);

            respuesta = getChar("Desea dar de alta este camion?(s/n)");

            if(respuesta == 's')
            {
                retorno = 1;
                listaCamiones[indiceLibre] = auxCamion;
            }
            else
            {
                retorno = 0;
            }
        }

    }

    return retorno;
}


int validarCamposCamion(char tipo[],int idChofer){
    int retorno;

    retorno = 1;
    if(strcmp(tipo,"0")==0 || idChofer == -1){
        retorno=0;
    }

    return retorno;
}


eCamion cargarUnCamion(eChofer listaChoferes[],int cantidadChofer,int idCamion)
{
    eCamion auxCamion;
    int validacion;

    auxCamion.id = idCamion;
    auxCamion.anio = getInt("Ingrese el anio del camion:","Valor invalido.\n",1950,2020,3);
    auxCamion.peso = getFloat("Ingrese el peso del camion en toneladas:","Valor invalido.\n",0);
    auxCamion.cantidadRuedas = getInt("Ingrese cantidad de ruedas del camion:","Valor incorrecto.\n",6,8,3);
    getCadenaLetrasYNumeros("Ingrese la patente del camion:",auxCamion.patente);
    getCadena("Ingrese marca del camion:","Opcion invalida.\n",auxCamion.marca);
    getCadena("Ingrese el tipo de camion:","Opcion invalida.\n",auxCamion.tipo);
    auxCamion.idChofer = seleccionarUnChofer(listaChoferes,cantidadChofer);
    auxCamion.estado = OCUPADO;

    validacion = validarCamposCamion(auxCamion.tipo,auxCamion.idChofer);

    if(validacion == 0){
        auxCamion.id = 0;
    }

    return auxCamion;
}

int asignarIDCamion(eCamion listaCamiones[],int cantidadCamiones,int indice)
{
    int idRetorno;

    if(listaCamiones[indice].estado == LIBRE)
    {
        idRetorno = buscarMaxIdCamion(listaCamiones,cantidadCamiones);
        idRetorno++;
    }
    else
    {
        idRetorno = listaCamiones[indice].id;
    }

    return idRetorno;
}

int buscarMaxIdCamion(eCamion listaCamiones[],int cantidadCamiones)
{
    int i;
    int max;

    for(i=0; i< cantidadCamiones; i++)
    {
        if((listaCamiones[i].id > max || i == 0) && listaCamiones[i].estado == OCUPADO)
        {
            max = listaCamiones[i].id;
        }
    }

    return max;
}


int eliminarUnCamion(eCamion listaCamiones[],int cantidadCamion,eChofer listaChofer[],int cantidadChofer)
{
    int retorno;
    int idBuscado;
    int idEncontrado;
    char respuesta;
    int maxId;

    retorno = -1;
    maxId = buscarMaxIdCamion(listaCamiones,cantidadCamion);
    idBuscado = getInt("Ingrese ID a buscar:","Opcion incorrecta.\n",1,maxId,3);

    if(idBuscado != -1){
        idEncontrado = buscarCamionPorID(listaCamiones,cantidadCamion,idBuscado);

        if(idEncontrado != -1)
        {
            mostrarUnCamion(listaCamiones[idEncontrado],listaChofer,cantidadChofer);
            respuesta = getChar("Desea eliminar este camion?(s/n)");

            if(respuesta == 's')
            {
                listaCamiones[idEncontrado].estado = BORRADO;
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


int buscarCamionPorID(eCamion listaCamiones[],int cantidadCamion,int id)
{
    int i;
    int retorno;

    retorno = -1;

    for(i=0; i < cantidadCamion; i++)
    {
        if(listaCamiones[i].id == id && listaCamiones[i].estado == OCUPADO)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int modificarUnCamion(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChoferes[],int cantidadChoferes)
{
    int retorno;
    int idBuscado;
    int indiceBuscado;
    eCamion auxCamion;
    char respuesta;
    int maxId;

    retorno = -1;
    maxId = buscarMaxIdCamion(listaCamiones,cantidadCamiones);
    idBuscado = getInt("Ingrese ID del camion:","Opcion invalida.\n",1,maxId,3);

    if(idBuscado != -1){
        indiceBuscado = buscarCamionPorID(listaCamiones,cantidadCamiones,idBuscado);

        if(indiceBuscado != -1)
        {
            mostrarUnCamion(listaCamiones[indiceBuscado],listaChoferes,cantidadChoferes);
            auxCamion = modificarCamposCamion(listaCamiones[indiceBuscado],listaChoferes,cantidadChoferes);
            mostrarUnCamion(auxCamion,listaChoferes,cantidadChoferes);
            respuesta = getChar("Confirma los cambios?(s/n)");

            if(respuesta == 's'){
                listaCamiones[indiceBuscado] = auxCamion;
                retorno = 1;
            }else{
                retorno = 0;
            }
        }
    }

    return retorno;
}


eCamion modificarCamposCamion(eCamion camion,eChofer listaChoferes[],int cantidadChoferes)
{
    eCamion auxCamion;
    char tipo[20];
    int opcion;
    char respuesta;

    auxCamion = camion;

    do
    {
        showMenu("1.MODIFICAR TIPO\n"
                 "2.MODIFICAR CHOFER\n"
                 "3.MODIFICAR LA MARCA\n"
                 "4.SALIR\n");
        opcion = getInt("Elija una opcion:","Opcion incorrecta.\n",1,4,3);

        switch(opcion)
        {
        case 1:
            getCadena("Ingrese tipo(larga-corta distancia):","Formato invalido.\n",tipo);
            strcpy(auxCamion.tipo,tipo);
            break;
        case 2:
            auxCamion.idChofer = seleccionarUnChofer(listaChoferes,cantidadChoferes);
            break;
        case 3:
            //auxCamion.idMarca = seleccionarMarca(listaMarcas,cantidadMarcas);
            getCadena("Ingrese la marca del camion:","Dato invalido.\n",auxCamion.marca);
            break;
        case -1:
            printf("Se agotaron los intentos.\n");
            break;
        case 4:
            break;
        }

        respuesta = getChar("Desea continuar modificando los datos del camion?(s/n)");
    }
    while(respuesta == 's');

    return auxCamion;
}


void mostrarCamionPorMarca(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChoferes[],int cantidadChoferes){
    char marca[15];
    int i;
    char banderaMarca;
    //int idMarcaBuscado;

    banderaMarca = 'n';

    getCadena("Ingrese la marca de camion a buscar:","Valor invalido.\n",marca);
    //idMarcaBuscado=buscarIdMarcaPorNombre(listaMarcas,cantidadMarcas,marca);

    printf("CAMIONES DE LA MARCA %s:\n",marca);
    for(i=0;i< cantidadCamiones;i++){
        if(strcmp(listaCamiones[i].marca,marca)== 0 && listaCamiones[i].estado == OCUPADO){
            banderaMarca='s';
            mostrarUnCamion(listaCamiones[i],listaChoferes,cantidadChoferes);
        }
    }

    if(banderaMarca == 'n'){
        printf("No hay camiones con esa marca.\n");
    }
}


void ordenarCamionesPorTipo(eCamion listaCamiones[],int cantidadCamiones){
    int i;
    int j;
    eCamion auxCamion;

    for(i=0 ; i < cantidadCamiones -1;i++){
        for(j = i+1;j < cantidadCamiones;j++){
            if(strcmp(listaCamiones[i].tipo,listaCamiones[j].tipo) < 0 && listaCamiones[i].estado == OCUPADO && listaCamiones[j].estado == OCUPADO){
                auxCamion = listaCamiones[i];
                listaCamiones[i]=listaCamiones[j];
                listaCamiones[j] = auxCamion;
            }
        }
    }
}


void mostrarCamionesConMasDe10Anios(eCamion listaCamiones[],int cantidadCamiones,eChofer listaChofer[],int cantidadChofer){
    int i;
    int anio;
    int contadorCamiones;

    contadorCamiones = 0;

    anio = 2020;

    printf("ID  PATENTE    MARCA\tANIO\tPESO\tTIPO\t\tIDCHOFER\tCHOFER\n");
    for(i=0; i < cantidadCamiones;i++){
        if(listaCamiones[i].estado == OCUPADO && (anio -listaCamiones[i].anio) > 10){
            mostrarUnCamion(listaCamiones[i],listaChofer,cantidadChofer);
            contadorCamiones++;
        }
    }

    if(contadorCamiones == 0){
        printf("No hay camiones con mas de 10 anios de antiguedad.\n");
    }else{
        printf("Camiones con mas de 10 anios: %d\n",contadorCamiones);
    }
}


int acumuladorAniosCamion(eCamion listaCamiones[],int cantidadCamiones){
    int i;
    int anio;
    int acumuladorAnios;

    anio = 2020;
    acumuladorAnios = 0;

    for(i=0; i < cantidadCamiones;i++){
        if(listaCamiones[i].estado == OCUPADO){
            acumuladorAnios= acumuladorAnios + (anio - listaCamiones[i].anio);
        }
    }

    return acumuladorAnios;
}

int contadorCamiones(eCamion listaCamiones[],int cantidadCamiones){
    int i;
    int contador;

    contador = 0;
    for(i= 0 ; i< cantidadCamiones;i++){
        if(listaCamiones[i].estado == OCUPADO){
            contador++;
        }
    }

    return contador;
}


float calcularPromedioAntiguedadCamiones(eCamion listaCamiones[],int cantidadCamiones){
    int contador;
    int acumulador;
    float promedio;

    contador = contadorCamiones(listaCamiones,cantidadCamiones);
    acumulador = acumuladorAniosCamion(listaCamiones,cantidadCamiones);

    if(contador != 0){
        promedio = (float) acumulador / contador;
    }

    return promedio;
}


void mostrarPromedioFlotaCamiones(eCamion listaCamiones[],int cantidadCamiones){
    float promedio;

    promedio = calcularPromedioAntiguedadCamiones(listaCamiones,cantidadCamiones);

    if(promedio != 0){
        printf("Promedio de edad de la flota de camiones: %.2f\n",promedio);
    }else{
        printf("No se pudo calcular el promedio.\n");
    }
}

/*
int buscarCamionPorMarca(eMarca listaMarcas[],int cantidadMarcas,char marca[]){
    int i;
    int retorno;

    for(i=0; i < cantidadMarcas;i++){
        if(listaMarcas[i].estado == OCUPADO && strcmp(listaMarcas[i].nombre,marca) == 0){
            //listaMarcas[i].nombre
        }
    }

    return retorno;
}
*/


int contadorCamionesPorIdChofer(eCamion listaCamiones[],int cantidadCamiones,int idChofer){
    int i;
    int contadorCamiones;

    contadorCamiones=0;

    for(i=0; i < cantidadCamiones; i++)
    {
        if(listaCamiones[i].idChofer == idChofer && listaCamiones[i].estado == OCUPADO)
        {
            contadorCamiones++;
        }
    }

    return contadorCamiones;
}
