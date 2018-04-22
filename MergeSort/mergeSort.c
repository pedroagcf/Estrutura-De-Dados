#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int vetor[], int inicio, int meio, int fim){

   int init = inicio;
   int init2 = meio + 1;
   int aux = 0;
   int tam = fim - inicio + 1;
   int * vetAux;

   vetAux = (int*) malloc(tam*sizeof(int));

   while(init <= meio && init2 <= fim){

       if (vetor[init] < vetor[init2]){

           vetAux[aux] = vetor[init];
           init++;

       }else{

           vetAux[aux] = vetor[init2];
           init2++;

       }

       aux++;
   }

   while(init <= meio){

       vetAux[aux] = vetor[init];
       aux++;
       init++;
   }

   while(init2 <= fim){
       vetAux[aux] = vetor[init2];
       aux++;
       init2++;
   }

   for (aux = inicio; aux <= fim; aux++)
       vetor[aux] = vetAux[aux - inicio];
}

void mergeSort(int vetor[], int inicio, int fim){

	if(inicio < fim){

		int meio = (inicio + fim)/2;

		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);
		merge(vetor, inicio, meio, fim);
	}

}

int main(){

	int size = 0;
	long int inicio, fim;

	inicio = clock();

	printf("Digite o tamanho para o vetor:\n");
	scanf("%d", &size);

	int array[size];


	srand(time(NULL));

	for (int i = 0; i < size; i++){
		
		array[i] = 1 + (rand() % 100);
		printf("vetor original: %d\n", array[i]);
	}

	printf("=============================================\n");

	mergeSort(array, 0, size - 1);

	for (int i = 0; i < size; i++){
		
		printf("vetor ordenado: %d\n", array[i]);
	}

	fim = clock();

	printf("Tempo de execuçao dado em segundos do algoritmo: %lf \n", (double) (fim - inicio)/1000000);


	return 0;
}











