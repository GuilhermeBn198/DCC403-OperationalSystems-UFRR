#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUM 2

pthread_mutex_t mutexBuffer;

int buffer[10];
int count = 0;

void* producer(void* args){
	while (1) {		
		//produce
		int x = rand() % 100;

		//add to the buffer 
		pthread_mutex_lock(&mutexBuffer);
		if (count < 10) {
			sleep(1);
			buffer[count] = x;
			count++;
		} else {
			printf("Skipped %d\n", x);
		}
			pthread_mutex_unlock(&mutexBuffer);
	}
}

void* consumer(void* args){
	while (1) {
		int y = -1;

		//remove from the buffer
		pthread_mutex_lock(&mutexBuffer);
		if (count > 0){
			y = buffer[count-1];
			count--;
		}
		pthread_mutex_unlock(&mutexBuffer);
	
		//consume
		printf("Got %d\n", y);
	}
}

int main(int argc, char** argv[]){
	srand(time(NULL));
	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexBuffer, NULL);
	int i;
	for (i = 0; i < THREAD_NUM; i++) {
		if (i % 2 == 0) {
			if (pthread_create(&th[i], NULL, &producer, NULL) != 0) {
				perror ("failed to create thread");
			}
		} else {
			if (pthread_create(&th[i], NULL, &consumer, NULL) != 0){
				perror ("failed to create thread");
			}
		}
	}
	for (i = 0; i < THREAD_NUM; i++){
		if (pthread_join(th[i], NULL)!= 0){
		perror ("failed to join thread");
		}
	}
	pthread_mutex_destroy(&mutexBuffer);
	return 0;
}