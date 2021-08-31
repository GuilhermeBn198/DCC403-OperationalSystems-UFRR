#include <stdio.h>
#include <pthread.h>
#define N 5

void *isEven()
{
	int a[N], i, even = 0, odd = 0;
	printf("Digite %d numeros inteiros\n", N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n\nOs numeros pares dos %d numeros digitados sao...\n", N);
	for (i = 0; i < N; i++)
	{
		if (a[i] % 2 == 0)
		{
			printf("%d\t", a[i]);
			even++;
		}
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t mythread;
	pthread_create(&mythread, NULL, isEven, NULL);
	pthread_join(mythread, NULL);
	pthread_exit(NULL);
	return 0;
}