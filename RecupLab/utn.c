#include "utn.h"

int esNumerica(char* cadena,int longitud){
	int retorno=-1;
	int i;

	if(cadena != NULL && longitud > 0){
		retorno=1;
		for(i=0; i < longitud && cadena[i] != '\0';i++){
			if(i== 0 && (cadena[i]=='+' || cadena[i]=='-')){
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno=0;
				break;
			}
		}
	}

	return retorno;
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


void cleanScreen(void){
    system("pause");
    system("cls");
}
