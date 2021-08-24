// $ gcc -pthread count_race.c -o cr

#include <stdio.h>
#include <pthread.h>

long contador = 0;

void *inc(void *threadid){
    int i = 0;
    for(; i < 9000000; i++) { contador++; }
}

void *dec(void *threadid){
    int i = 0;
    for(; i < 9000000; i++) { contador--; }
}

int main (int argc, char *argv[]){
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, inc, NULL);
    pthread_create(&thread2, NULL, dec, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Valor final do contador: %ld\n", contador);
    pthread_exit(NULL);
}

