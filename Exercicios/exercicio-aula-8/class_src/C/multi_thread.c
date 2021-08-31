#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
  long tid;
  tid = (long)threadid;
  printf("Thread #%ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

  // Conjunto de threads
  pthread_t threads[NUM_THREADS];

  // Retorno da criação das threads
  int rc;
  // Contador para as threads
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("No main: criando thread %ld\n", t);

    // &threads[t]: Endereço onde será armazenado o id único para a thread
    // NULL: Opção para a execução da thread, exemplo, prioridade
    // PrintHello: a rotina/procedimento/segmento que será executado
    // (void *)t: argumento para a rotina PrintHello
	
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
  	pthread_join(threads[t], NULL);

    if (rc) {
      printf("ERRO = %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
