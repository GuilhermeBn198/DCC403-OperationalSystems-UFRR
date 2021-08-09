/**
Compile: gcc -pthread example01.c -o example01
**/

#include <pthread.h>
#include <stdio.h>

void *printHello(){
    printf("Hello thread :) \n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t mythread;
    printf("Estou no main \n");
    pthread_create(&mythread, NULL, printHello, NULL);
    pthread_join(mythread, NULL);
    printf("Voltei para o main \n");
    pthread_exit(NULL);
}