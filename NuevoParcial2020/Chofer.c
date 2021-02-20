#include "Chofer.h"
#define OCUPADO 1
#define LIBRE 0

void inicializarEstadoChoferes(eChofer listaChoferes[],int cantidadChoferes){
    int i;

    for(i=0; i < cantidadChoferes;i++){
        listaChoferes[i].estado = LIBRE;
    }
}

void hadcodearListaChoferes(eChofer listaChoferes[],int cantidadChoferes)
{
    int id[]= {1,2,3,4,5,6};
    char nombre[][30]= {{"Lucrecia"},{"Jorge"},{"Natalia"},{"Matias"},{"Geremias"},{"Tomas"}};
    char apellido[][30]= {{"Gomez"},{"Perez"},{"Frias"},{"Sosa"},{"Flores"},{"Pereyra"}};
    long int dni[]= {32434565,41435622,30435465,34545665,20434533,33000555};
    char legajo[][10]= {{"a234323"},{"a543423"},{"a432343"},{"b120001"},{"b101032"},{"a54342"}};
    char nacionalidad[][20]= {{"Argentina"},{"Bolivia"},{"Peru"},{"Argentina"},{"Bolivia"},{"Peru"}};
    long int telefono[]= {1543233223,1543233212,1543299883,1576990656,1577665900,1589450033};
    int edad[]= {23,31,54,34,44,33};
    char sexo[]= {'f','m','f','m','m','m'};
    int estado[]= {1,1,1,1,1,1};
    int i;

    for(i=0; i< 6; i++)
    {
        listaChoferes[i].id=id[i];
        strcpy(listaChoferes[i].nombre,nombre[i]);
        strcpy(listaChoferes[i].apellido,apellido[i]);
        listaChoferes[i].dni=dni[i];
        strcpy(listaChoferes[i].legajo,legajo[i]);
        strcpy(listaChoferes[i].nacionalidad,nacionalidad[i]);
        listaChoferes[i].telefono=telefono[i];
        listaChoferes[i].edad=edad[i];
        listaChoferes[i].sexo=sexo[i];
        listaChoferes[i].estado=estado[i];
    }
}


void mostrarUnChofer(eChofer chofer)
{
    printf("%d %8s %8s %10ld %8s %10s %15ld %5d %5c\n",chofer.id,
                                                    chofer.nombre,
                                                    chofer.apellido,
                                                    chofer.dni,
                                                    chofer.legajo,
                                                    chofer.nacionalidad,
                                                    chofer.telefono,
                                                    chofer.edad,
                                                    chofer.sexo);
}


void mostrarTodosLosChoferes(eChofer listaChoferes[],int cantidadChoferes)
{
    int i;

    printf("ID  NOMBRE   APELLIDO\t DNI\t LEGAJO\t NACIONALIDAD\t TELEFONO    EDAD  SEXO\n");
    for(i=0; i < cantidadChoferes; i++)
    {
        if(listaChoferes[i].estado == OCUPADO)
        {
            mostrarUnChofer(listaChoferes[i]);
        }
    }
}

int buscarUnChoferPorId(eChofer listaChoferes[],int cantidadChofer,int id)
{
    int i;
    int retorno;

    retorno = -1;
    for(i=0; i <cantidadChofer; i++)
    {
        if(listaChoferes[i].id == id && listaChoferes[i].estado == OCUPADO)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int seleccionarUnChofer(eChofer listaChoferes[],int cantidadChofer)
{
    int i;
    int opcion;
    int indiceBuscado;
    int maxId;

    do
    {
        for(i=0; i < cantidadChofer; i++)
        {
            if(listaChoferes[i].estado == OCUPADO)
            {
                printf("%d %10s %10s\n",listaChoferes[i].id,listaChoferes[i].nombre,listaChoferes[i].apellido);
            }
        }

        maxId=buscarMaxIdChofer(listaChoferes,cantidadChofer);
        opcion = getInt("Elija un chofer:","Opcion incorrecta.\n",1,maxId,3);

        if(opcion != -1){
            indiceBuscado = buscarUnChoferPorId(listaChoferes,cantidadChofer,opcion);
            if(indiceBuscado != -1){
                break;
            }
        }
    }
    while(opcion < 1 || opcion > maxId);

    return opcion;

}



int asignarIDChofer(eChofer listaChoferes[],int cantidadChofer,int indice)
{
    int idRetorno;

    if(listaChoferes[indice].estado == LIBRE)
    {
        idRetorno = buscarMaxIdChofer(listaChoferes,cantidadChofer);
        idRetorno++;
    }
    else
    {
        idRetorno = listaChoferes[indice].id;
    }

    return idRetorno;
}

int buscarMaxIdChofer(eChofer listaChoferes[],int cantidadChofer)
{
    int i;
    int max;

    for(i=0; i< cantidadChofer; i++)
    {
        if((listaChoferes[i].id > max || i == 0) && listaChoferes[i].estado == OCUPADO)
        {
            max = listaChoferes[i].id;
        }
    }

    return max;
}

int validarCamposChofer(char nombre[],char apellido[],long int dni,char nacionalidad[],long int telefono,int edad){
    int retorno;

    retorno = 1;

    if(strcmp(nombre,"0")==0 || strcmp(apellido,"0")==0 || dni == 0 || strcmp(nacionalidad,"0")==0 || telefono == 0 || edad == -1){
        retorno =0;
    }


    return retorno;
}



eChofer cargarUnChofer(int idChofer)
{
    eChofer auxChofer;
    int validacion;

    getCadena("Ingrese el nombre del chofer:","Valor incorrecto.\n",auxChofer.nombre);
    getCadena("Ingrese el apellido del chofer:","Valor incorrecto.\n",auxChofer.apellido);
    auxChofer.dni = getDni("Ingrese nro de dni:","Valor incorrecto.\n",1,99999999);
    getCadenaLetrasYNumeros("Ingrese el legajo:",auxChofer.legajo);
    getCadena("Ingrese nacionalidad:","Valor incorrecto.\n",auxChofer.nacionalidad);
    auxChofer.telefono = getTelefono("Ingrese nro de telefono:","Valor invalido.\n",1);
    auxChofer.edad = getInt("Ingrese la edad del chofer:","Valor invalido.\n",18,90,3);
    auxChofer.sexo = getChar("Ingrese sexo del chofer(f,m)");
    auxChofer.estado = OCUPADO;

    validacion = validarCamposChofer(auxChofer.nombre,auxChofer.apellido,auxChofer.dni,auxChofer.nacionalidad,auxChofer.telefono,auxChofer.edad);
    auxChofer.id = idChofer;

    if(validacion != 1){
        auxChofer.id = 0;
    }

    return auxChofer;

}

int buscarIndiceLibreChofer(eChofer listaChoferes[],int cantidadChofer)
{
    int i;
    int retorno;

    retorno = -1;

    for(i=0; i< cantidadChofer; i++)
    {
        if(listaChoferes[i].estado != OCUPADO)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int cargarListaChoferes(eChofer listaChoferes[],int cantidadChoferes)
{
    int retorno;
    int indiceLibre;
    int idAsginado;
    char respuesta;
    eChofer auxChofer;

    retorno = -1;
    indiceLibre = buscarIndiceLibreChofer(listaChoferes,cantidadChoferes);

    if(indiceLibre != -1)
    {
        idAsginado = asignarIDChofer(listaChoferes,cantidadChoferes,indiceLibre);
        auxChofer = cargarUnChofer(idAsginado);

        if(auxChofer.id == 0){
            retorno = 0;
        }else{
            printf("ID  NOMBRE   APELLIDO\t DNI\t LEGAJO\t NACIONALIDAD\t TELEFONO    EDAD  SEXO\n");
            mostrarUnChofer(auxChofer);
            respuesta = getChar("Desea dar de alta este chofer?(s/n)");

            if(respuesta == 's')
            {
                listaChoferes[indiceLibre] = auxChofer;
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


int modificarUnChofer(eChofer listaChoferes[],int cantidadChoferes)
{
    int retorno;
    int idBuscado;
    int indiceChofer;
    char respuesta;
    int maxId;
    eChofer auxChofer;

    retorno = -1;
    maxId = buscarMaxIdChofer(listaChoferes,cantidadChoferes);
    idBuscado = getInt("Ingrese el ID del chofer a modficar:","Valor incorrecto.\n",1,maxId,3);

    if(idBuscado != -1){
        indiceChofer = buscarUnChoferPorId(listaChoferes,cantidadChoferes,idBuscado);

        if(indiceChofer != -1)
        {
            printf("ID  NOMBRE   APELLIDO\t DNI\t LEGAJO\t NACIONALIDAD\t TELEFONO    EDAD  SEXO\n");
            mostrarUnChofer(listaChoferes[indiceChofer]);
            auxChofer = modificarCampoChofer(listaChoferes[indiceChofer]);
            printf("ID  NOMBRE   APELLIDO\t DNI\t LEGAJO\t NACIONALIDAD\t TELEFONO    EDAD  SEXO\n");
            mostrarUnChofer(auxChofer);

            respuesta = getChar("Confirma los cambios?(s/n)");

            if(respuesta == 's')
            {
                listaChoferes[indiceChofer] = auxChofer;
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


eChofer modificarCampoChofer(eChofer chofer)
{
    eChofer auxChofer;
    int opcion;
    char respuesta;
    char nombre[30];
    char apellido[30];
    long int dni;
    char legajo[10];
    char nacionalidad[20];
    long int telefono;
    int edad;
    char sexo;

    auxChofer = chofer;

    do
    {
        showMenu("1.MODIFICAR NOMBRE\n"
                 "2.MODIFICAR APELLIDO\n"
                 "3.MODIFICAR DNI\n"
                 "4.MODIFICAR LEGAJO\n"
                 "5.MODIFCAR NACIONALIDAD\n"
                 "6.MODIFCAR TELEFONO\n"
                 "7.MODIFICAR EDAD\n"
                 "8.MODIFICAR SEXO\n"
                 "9.SALIR\n");
        opcion = getInt("Elija una opcion:","Opcion incorrecta.\n",1,9,3);

        switch(opcion)
        {
        case 1:
            getCadena("Ingrese el nuevo nombre:","Valor incorrecto.\n",nombre);
            strcpy(auxChofer.nombre,nombre);
            break;
        case 2:
            getCadena("Ingrese el nuevo apellido:","Valor incorrecto.\n",apellido);
            strcpy(auxChofer.apellido,apellido);
            break;
        case 3:
            dni = getDni("Ingrese nuevo nro de dni:","Valor invalido.\n",1,99999999);
            auxChofer.dni=dni;
            break;
        case 4:
            getCadenaLetrasYNumeros("Ingrese el nuevo legajo:",legajo);
            strcpy(auxChofer.legajo,legajo);
            break;
        case 5:
            getCadena("Ingrese la nueva nacionalidad:","Valor incorrecto.\n",nacionalidad);
            strcpy(auxChofer.nacionalidad,nacionalidad);
            break;
        case 6:
            telefono = getTelefono("Ingrese nuevo telefono:","Valor invalido.\n",1);
            auxChofer.telefono = telefono;
            break;
        case 7:
            edad = getInt("Ingrese la nueva edad:","Valor invalido.\n",18,65,3);
            auxChofer.edad = edad;
            break;
        case 8:
            sexo = getChar("Ingrese nuevo sexo del chofer:");
            auxChofer.sexo = sexo;
            break;
        case -1:
            printf("Se agotaron los intentos.\n");
            break;
        case 9:
            break;
        }

        respuesta = getChar("Desea continuar modificando los datos del chofer?(s/n)");
    }
    while(respuesta == 's');

    return auxChofer;
}


int contadorChoferesActivos(eChofer listaChoferes[],int cantidadChoferes)
{
    int i;
    int contador;

    contador=0;

    for(i=0; i< cantidadChoferes; i++)
    {
        if(listaChoferes[i].estado == OCUPADO)
        {
            contador++;
        }
    }

    return contador;
}

int acumuladorEdadChoferes(eChofer listaChoferes[],int cantidadChoferes)
{
    int i;
    int acumuladorEdades;

    acumuladorEdades=0;

    for(i=0; i < cantidadChoferes; i++)
    {
        if(listaChoferes[i].estado == OCUPADO)
        {
            acumuladorEdades+=listaChoferes[i].edad;
        }
    }

    return acumuladorEdades;
}


float calcularPromedioEdadesChoferes(eChofer listaChoferes[],int cantidadChoferes)
{
    int contadorEdad;
    int acumuladorEdad;
    float promedioEdad;

    promedioEdad=0;
    contadorEdad = contadorChoferesActivos(listaChoferes,cantidadChoferes);
    acumuladorEdad = acumuladorEdadChoferes(listaChoferes,cantidadChoferes);

    if(contadorEdad != 0)
    {
        promedioEdad = (float) acumuladorEdad / contadorEdad;
    }

    return promedioEdad;
}


void mostrarPromedioEdadChoferes(eChofer listaChoferes[],int cantidadChoferes){
    float promedio;

    promedio = calcularPromedioEdadesChoferes(listaChoferes,cantidadChoferes);

    if(promedio == 0){
        printf("No se pudo calcular el promedio.\n");
    }else{
        printf("El promedio de edad entre choferes es %.2f\n",promedio);
    }
}

void mostrarUnChoferConCantidadCamiones(eChofer chofer,int cantidadCamiones){
    printf("%d %10s %10s %10d\n",chofer.id,chofer.nombre,chofer.apellido,cantidadCamiones);
}


int contadorChoferesPorSexo(eChofer listaChoferes[],int cantidadChoferes,char sexo){
    int i;
    int contador;

    contador=0;

    for(i=0; i< cantidadChoferes;i++){
        if(listaChoferes[i].estado == OCUPADO && listaChoferes[i].sexo == sexo){
            contador++;
        }
    }
    return contador;
}



void mostrarPromedioChoferesMasculinos(eChofer listaChoferes[],int cantidadChofer){
    float promedioHombres;
    float promedioMujeres;
    int contadorChoferes;
    int contadorHombres;
    int contadorMujeres;

    promedioHombres = 0;
    promedioMujeres=0;
    contadorChoferes = contadorChoferesActivos(listaChoferes,cantidadChofer);
    contadorHombres = contadorChoferesPorSexo(listaChoferes,contadorChoferes,'m');
    contadorMujeres = contadorChoferesPorSexo(listaChoferes,contadorChoferes,'f');

    if(contadorHombres > 0){
        promedioHombres = (float)(contadorHombres * 100) / contadorChoferes;
    }


    if(contadorMujeres > 0){
        promedioMujeres = (float) contadorChoferes / contadorMujeres;
    }

    printf("Promedio de hombres:%.1f\n",promedioHombres);

    printf("Promedio de mujeres:%.1f\n",promedioMujeres);
}
