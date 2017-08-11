#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//Para inicializar una variable de condicion
//pthread_cond_t cu = PTHREAD_COND_INITIALIZER
//Usar usleep
//hacer dos variables condicion y un mutex

pthread_cond_t prod = PTHREAD_COND_INITIALIZER;
pthread_cond_t cons = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock;
int total;
int tam_cola;
int cola;
float tiempo_pro;
float tiempo_con;
int contadorpro = 0;
int contadorcon = 0;

void *productor(void *estructura);
void *consumidor(void *estructura);

typedef struct mi_estructuraTDA{
	int id;	
}estructura;

void *productor(void *arg){
	estructura *datos = (estructura *) arg;
	int id = datos->id;
	while(1){
		pthread_mutex_lock(&lock);
		while(cola>=tam_cola){
			pthread_cond_wait(&prod,&lock);
		}
		usleep(tiempo_pro*1000000);
		pthread_mutex_unlock(&lock);
		pthread_mutex_lock(&lock);
		if(contadorpro>=total){
			pthread_mutex_unlock(&lock);
			pthread_cond_broadcast(&prod);
			break;
		}
		cola++;
		contadorpro++;
		printf("Productor %i ha producido 1 item, tamaño de cola = %i\n",id,cola);
		pthread_mutex_unlock(&lock);
		pthread_cond_broadcast(&cons);
	}
	//printf("Productor %i ha terminado.\n",id);
	return (void *)0;
}

void *consumidor(void *arg){
	estructura *datos = (estructura *) arg;
	int id = datos->id;
	while(1){
		pthread_mutex_lock(&lock);
		while((cola<=0)){
			pthread_cond_wait(&cons,&lock);
		}
		usleep(tiempo_con*1000000);
		cola--;
		contadorcon++;
		printf("Consumidor %i ha consumido 1 item, tamaño de cola = %i\n",id,cola);
		pthread_mutex_unlock(&lock);
		pthread_mutex_lock(&lock);
		if(contadorcon>=total){
			pthread_mutex_unlock(&lock);
			pthread_cond_broadcast(&cons);
			break;
		}
		pthread_mutex_unlock(&lock);
		pthread_cond_broadcast(&prod);
	}
	//printf("Consumidor %i ha terminado.\n",id);
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
	tiempo_pro = atof(argv[2]);
	tiempo_con = atof(argv[4]);
	int num_hilos_c = atoi(argv[3]);
	tam_cola = atoi(argv[5]);
	total = atoi(argv[6]);

	printf("Número de productores: %i\n", num_hilos_p);
	printf("Número de consumidores: %i\n", num_hilos_c);
	printf("Tamaño de cola: %i\n", tam_cola);
	printf("Tiempo de consumo: %f\n", tiempo_con);
	printf("Tiempo de producción: %f\n", tiempo_pro);
	printf("Total de ítems a producir: %i\n\n", total);

	cola = 0;

	pthread_t *productores;
	pthread_t *consumidores;
	productores = (pthread_t*)malloc(num_hilos_p*sizeof(pthread_t));
	consumidores = (pthread_t*)malloc(num_hilos_c*sizeof(pthread_t));

	int i;
	for(i=0;i<num_hilos_p;i++){
		estructura *estruc = (estructura *)malloc(sizeof(estructura *));
		estruc->id = i+1;
		pthread_create(&productores[i], NULL, productor,(void *)estruc);
	}
	
	for(i=0;i<num_hilos_c;i++){
		estructura *estruc = (estructura *)malloc(sizeof(estructura *));
		estruc->id = i+1;
		pthread_create(&consumidores[i], NULL, consumidor,(void *)estruc);
	}

	while(1){
		if(contadorcon>=total) break;
	}

	printf("\n Programa terminado \n");
	return 0;
}
