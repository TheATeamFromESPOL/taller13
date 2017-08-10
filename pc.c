#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//Para inicializar una variable de condicion
//pthread_cond_t cu = PTHREAD_COND_INITIALIZER
//Usar usleep
//hacer dos variables condicion y un mutex

pthread_cond_t prod;
pthread_cond_t cons;
pthread_mutex_t lock;
int total;
int tam_cola;

void *productor(void *estructura);
void *consumidor(void *estructura);

typedef struct mi_estructuraTDA{
	int cola;
	float tiempo;
}estructura;

void *productor(void *estructura){
	estructura *datos = (estructura *) estructura;
	int cola = i->cola;
	
	while(cola>=){

	}
	return (void *)0;
}

void *consumidor(void *estructura){

	return (void *)0;
}

int main(int argc, char *argv[]){

	if(argc!=7){
		printf("\n	Cantidad de argumentos incorrecta\n");
		return -1;
	}

	if (pthread_mutex_init(&lock, NULL) != 0){
        printf("\n	Iniciación de mutex fallida\n");
        return -1;
    }

	int num_hilos_p = atoi(argv[1]);
	float tiempo_pro = atoi(argv[2]);
	float tiempo_con = atoi(argv[4]);
	int num_hilos_c = atoi(argv[3]);
	int tam_cola = atoi(argv[5]);
	total = atoi(argv[6]);
	prod = PTHREAD_COND_INITIALIZER;
	cons = PTHREAD_COND_INITIALIZER;

	int cola = 0;

	pthread_t *productores;
	pthread_t *consumidores;
	productores = (pthread_t*)malloc(num_hilos_p*sizeof(pthread_t));
	consumidores = (pthread_t*)malloc(num_hilos_c*sizeof(pthread_t));

	int i;
	for(i=0;i<num_hilos_p;i++){
	
	}

	return 0;
}
