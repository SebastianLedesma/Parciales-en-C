#include "utn.h"

int esNumerica(char* cadena,int longitud){
	int retorno=-1;
	int i;

	if(cadena != NULL && longitud > 0){
		retorno=1;
		for(i=0; i < longitud && cadena[i] != '\0';i++){
                /*
			if(i== 0 && (cadena[i]=='+' || cadena[i]=='-')){
				continue;
			}
			*/
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}


int esNombre(char* cadena,int longitud){
	int i;
	int retorno=1;
	int contadorSeparador=0;

	if(cadena != NULL && longitud > 0){
		for(i=0;cadena[i] != '\0' && i < longitud ;i++){

			if((cadena[i] < 'a' || cadena[i] > 'z') &&(cadena[i] < 'A' || cadena[i] > 'Z')){
				if((cadena[i]==' ' || cadena[i]=='-')&& contadorSeparador < 2){
                contadorSeparador++;
                }else{
                    retorno=0;
                    break;
                }

			}
		}
	}

	return retorno;
}


void cleanScreen(void){
    system("pause");
    system("cls");
}

int myGets(char* cadena,int longitud){
	char bufferString[4096];
	int retorno=-1;

	if(cadena != NULL && longitud > 0){
		fflush(stdin);

		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){//el sizeof pone un limite de carac a leer.Si ingresa mas,estos que exceden los ingnora.
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';//corrijo el \n
			}

			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strcpy(cadena,bufferString);
				retorno=0;
			}
		}

	}

	return retorno;
}


int getInt(int* pResultado){
	int retorno=-1;
	char bufferString[50];

	if(pResultado != NULL && myGets(bufferString,sizeof(bufferString))==0 && esNumerica(bufferString,sizeof(bufferString))){
		*pResultado=atoi(bufferString);
		retorno=0;
	}

	return retorno;

}


int utn_GetNumero(int *pResultado,char* cadena,char* cadenaError,int minimo,int maximo,int reintentos){
	int retorno=-1;
	int bufferInt;

	do{
		printf("%s",cadena);
		if(getInt(&bufferInt)==0 && bufferInt >= minimo && bufferInt <= maximo){
			*pResultado = bufferInt;
			retorno=0;
			break;
		}

		printf("%s",cadenaError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;

}


int esNombreArchivo(char* nombre,int longitud){
    int retorno=-1;
    int i=0;
    int contadorPuntos=0;

    while(nombre[i] != '\0' && contadorPuntos < 1){
        if(nombre[i] == '.'){
            contadorPuntos++;
        }
        i++;
    }

    if(contadorPuntos <= 1 && i <= longitud && nombre[longitud-1] != '.'){
        retorno=0;
    }

    return retorno;

}


int utn_getNombreArchivo(char* pResultado,int longitud,char* cadena,char* cadenaError,int reintentos){
    char bufferString[30];
	int retorno=-1;

	do{
		printf("%s",cadena);
		if(myGets(bufferString,longitud) == 0 && esNombreArchivo(bufferString,longitud) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud){
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
			break;
		}

		printf("%s",cadenaError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}

int getNombre(char* cadena,int longitud){
	int retorno=-1;
	char bufferString[4096];

	if(myGets(bufferString,sizeof(bufferString))==0 && esNombre(bufferString,sizeof(bufferString)) && strnlen(bufferString,sizeof(bufferString)) < longitud){
		strcpy(cadena,bufferString);
		retorno=0;
	}

	return retorno;

}


int utn_GetNombre(char* pResultado,int longitud,char* cadena,char* cadenaError,int reintentos){
	char bufferString[4096];
	int retorno=-1;

	do{
		printf("%s",cadena);
		if(getNombre(bufferString,sizeof(bufferString))== 0 && strnlen(bufferString,sizeof(bufferString)) < longitud){
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
			break;
		}

		printf("%s",cadenaError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}


int utn_GetRespuesta(char* respuesta,char* mensaje,char* mensajeError,int reintentos){
    int retorno=-1;
    char letra;

    do{
        printf("%s",mensaje);
        scanf("%c",&letra);
        if(esLetra(&letra)==0){
            *respuesta=letra;
            retorno=0;
            break;
        }

        reintentos--;
    }while(reintentos >= 0);

    return retorno;
}

int esLetra(char* letra){
    int retorno=-1;
    if((*letra >= 'a' && *letra <= 'z') || (*letra >= 'A' && *letra <= 'Z')){
        retorno=0;
    }
    return retorno;
}
