#include <stdio.h> //IO
#include <pthread.h> //Funções de thread incluindo mutex, e demais coisas
int sb;
int turn = 0;
#define MAX_BUFFER 1000;
pthread_mutex_t lock;

void put(int i){
    sb = i;
}

int get(){
    return sb;
}

void *producer(){
    int i = 0;
    while(1){
        while(turn == 1);
        pthread_mutex_lock(&lock);
        printf(">> Producer \n");
        printf("\t - Turn Producer \n");
        put(i);
        turn = 1;
        if (i<1000)
            i = i + 1;
        pthread_mutex_unlock(&lock);
    }    
}


void *consumer(){
    int i,v;
    while(1){
        while(turn == 0);
        pthread_mutex_lock(&lock);
        printf(">> Consumer \n");
        printf("\t - Turn Consumer \n");
        v = get();
        turn = 0;
        printf("\t - Peguei o valor: %d\n", v);
        pthread_mutex_unlock(&lock);
    }
}

void *printarNumeromaluco(int i){
    int num=i;
    printf("%d",num);
}

int main(){
    pthread_t producer_t; 
    pthread_t consumer_t;

    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);


    return 0;
}