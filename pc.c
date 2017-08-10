#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t lock;

void *funcion_hilo(void *estruc);


typedef struct mi_estructuraTDA{
	int linea_inicio;
	int linea_final;
	int *tam_lineas;
	char *ruta;
}estructura;


void * funcion_hilo(void *estruc){


	return (void *)0;
}

int main(int argc, char *argv[]){

	if(argc<7){
		printf("Cantidad de argumentos incorrecta");
		return -1;
	}
	else{
		int cont=0;	
		if (pthread_mutex_init(&lock, NULL) != 0){
		    	printf("\n mutex init failed\n");
		    	return 1;
			}

	}

	return 0;
}
