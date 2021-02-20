#include "Input.h"

int getInt(char mensaje[],char mensajeError[],int desde,int hasta,int reintentos)
{
    int esValido;
    int nro;

    esValido=-1;

    do
    {
        printf("%s",mensaje);
        if(scanf("%d",&nro) != 1 || nro < desde || nro > hasta)
        {
            fflush(stdin);
            printf("%s",mensajeError);
        }
        else
        {
            esValido=1;
        }

        reintentos--;

    }while(reintentos > 0 && esValido != 1);

    if(esValido == -1){
        nro = -1;
    }

    return nro;
}


void getCadena(char mensaje[],char mensajeError[],char paramNombre[])
{
    char nombre[30];
    int validacion;
    char respuesta;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(nombre);

        validacion = validarCadena(nombre);

        if(validacion == 0)
        {
            printf("%s",mensajeError);
        }

        printf("Desea volver a ingresar el dato?(s/n)");
        fflush(stdin);
        scanf("%c",&respuesta);
    }
    while(respuesta != 'n');

    if(validacion != 0)
    {
        strcpy(paramNombre,nombre);
    }
    else
    {
        strcpy(paramNombre,"0");
    }

}

int validarCadena(char paramNombre[])
{
    int retorno;
    int i;

    retorno = 1;

    for(i=0; i < strlen(paramNombre); i++)
    {
        if(!((paramNombre[i] >= 65 && paramNombre[i] <= 90) || (paramNombre[i] >=97 && paramNombre[i] <= 122) || paramNombre[i] == ' '))
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

float getFloat(char mensaje[],char mensajeError[],int desde)
{
    float retorno;
    int esValido;

    do
    {
        printf("%s",mensaje);
        if(scanf("%f",&retorno) != 1 || retorno <= desde)
        {
            fflush(stdin);
            printf("%s",mensajeError);
            esValido=0;
        }
        else
        {
            esValido=1;
        }
    }
    while(esValido == 0);

    return retorno;
}


char getChar(char mensaje[]){
    char retorno;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&retorno);

    return retorno;
}


void showMenu(char mensaje[]){
    printf("%s",mensaje);
}

void cleanScreen(void){
    system("pause");
    system("cls");
}


long int getDni(char mensaje[],char mensajeError[],int desde,long int hasta){
    long int dni;
    int esValido;
    int retorno;
    char respuesta;

    do{
        printf("%s",mensaje);
        if(scanf("%ld",&dni) != 1 || dni < desde || dni > hasta)
        {
            fflush(stdin);
            printf("%s",mensajeError);
            esValido=0;
        }
        else
        {
            esValido=1;
        }

        respuesta = getChar("Desea volver a ingresar el DNI?(s/n)");
    }while(respuesta == 's');

    if(esValido == 0){
        retorno = 0;
    }else{
        retorno = dni;
    }

    return retorno;
}


void getCadenaLetrasYNumeros(char mensaje[],char cadena[]){
    char string[10];
    char respuesta;

    do{
        printf("%s",mensaje);
        fflush(stdin);
        gets(string);

        respuesta = getChar("Desea volver a ingresar el dato?(s/n)");
    }while(respuesta == 's');

    strcpy(cadena,string);
}

long int getTelefono(char mensaje[],char mensajeError[],int desde){
    long int telefono;
    int retorno;
    int esValido;
    char respuesta;

    do{
        printf("%s",mensaje);
        fflush(stdin);
        if(scanf("%ld",&telefono) != 1 || telefono < desde)
        {
            printf("%s",mensajeError);
            esValido=0;
        }
        else
        {
            esValido=1;
        }

        respuesta = getChar("Desea modificar el telefono?(s/n)");
    }while(respuesta == 's');

    if(esValido == 0){
        retorno = 0;
    }else{
        retorno = telefono;
    }

    return retorno;
}
