#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//Para inicializar una variable de condicion
//pthread_cond_t cu = PTHREAD_COND_INITIALIZER
//Usar usleep
//hacer dos variables condicion y un mutex

void *productor(void *estructura);
void *consumidor(void *estructura);

typedef struct mi_estructuraTDA{
	int cola;
	pthread_mutex_t lock;
}estructura;

void *productor(void *estructura){
	estructura *datos = (estructura *) estructura;
	int cola = i->cola;
	

	while(1){
		
	}
	return (void *)0;
}

void *consumidor(void *estructura){

	return (void *)0;
}

int main(int argc, char *argv[]){

	if(argc!=7){
		printf("Cantidad de argumentos incorrecta");
		return -1;
	}
	int num_hilos_p = atoi(argv[1]);
	int tiempo_pro = atoi(argv[2]);
	int tiempo_con = atoi(argv[4]);
	int num_hilos_c = atoi(argv[3]);
	int tam_cola = atoi(argv[5]);
	int total = atoi(argv[6]);
	int cola = 0;
	
	if (pthread_mutex_init(&lock, NULL) != 0){
	    printf("\n mutex init failed\n");
		return 1;
	}


	return 0;
}
