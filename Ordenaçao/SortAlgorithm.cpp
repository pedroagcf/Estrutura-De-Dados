#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//C
void bubleSort(int vet[], int size){

  int i, j, aux = 0;

  for(i = 0; i < size; i++){
    for(int j = i+1; j < size; j++){
      if(vet[j] < vet[i]){

        aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
      }
    }
  }
}

//C
void insertionSort(int vetor[], int size){

  int i, j, value;

  for (int i = 1; i < size; i++){
    
    value = vet[i];
    j = i - 1;

    while((j >= 0) && (value < vetor[j]))
      vet[j+1] = vet[j--];

    vet[j+1] = value;
  }
}

//funçao auxiliar utilizada no quickSort C++
void swap(vector<int>& vec, int a, int b){
  
  int aux = vec[a];
  
  vec[a] = vec[b]; 
  vec[b] = aux;

}

//quicksort C++ com usando vector
void quickSort(vector<int> vec, int inicio, int final){

  int esq = inicio, dir = final, meio, pivo;
  meio = inicio + (final - inicio)/2;
  pivo = vec[meio];

  while(esq < final || dir > inicio){
    
    while(vec[esq] < pivo)
      esq++;

    while(vec[dir] > pivo)
      dir--;

    if (esq <= dir){  
      swap(vec, esq, dir);
      esq++;
      dir--;

    }else{

      if(esq < final)
        quickSort(vec, esq, final);

      if(dir > inicio)
        quickSort(vec, inicio, dir);

      return
    }
  }
}

void merge(int* vet, int inicio, int meio, int fim){
  
  int init = inicio;
  int init2 = meio+1;
  int aux = 0;
  int tam = fim - inicio + 1;
  int * vetAux;

  vetAux = (int*) malloc(tam*sizeof(int));

  while(init <= meio && init2 <= fim){

    if (vet[init] < vet[init2])
      vetAux[aux++] = vet[init++];

    else
      vetAux[aux++] = vet[init2++];
  }

  while(init <= meio)
    vetAux[aux++] = vet[init++];

  while(init2 <= fim)
    vetAux[aux++] = vet[init2++];    

  for(aux = inicio; aux <= fim; aux++)
    vet[aux] = vetAux[aux - inicio];
}



void mergeSort(int vet[], int inicio, int fim){

  if (inicio < fim){

    int meio = (inicio + fim)/2;
    
    mergeSort(vet, inicio, meio);
    mergeSort(vet, meio+1, fim);
    merge(vet, inicio, meio, fim);
  }

}

//gera numeros aleatorios para o vetor
void RandomVet(int array[], int size){
  
  srand(time(NULL));

  for (int i = 0; i < size; i++){
    
    array[i] = 1 + (rand() % 100);
    printf(" [%d] |", array[i]);
  }
  
  printf("\n");
}

int main(){

  int size = 0;
  long int inicio, fim;

  inicio = clock();

  printf("Digite o tamanho para o vetor:\n");
  scanf("%d", &size);
  
  int array[size];

  RandomVet(array, size); // funçao resposavel por embaralhar o vetor com numeros aleatorios!
  
  printf("\n=============================================\n\n");

  mergeSort(array, 0, size - 1); //algoritmo de ordenaçao!
  insertionSort(array, size); // algoritmo de ordenaçao! 
  quickSort(array, 0, size-1) //algoritmo de ordenaçao!

  for (int i = 0; i < size; i++)
    printf(" [%d] |", array[i]);
  
  printf("\n"); 

  fim = clock();

  printf("\nTempo de execuçao dado em segundos do algoritmo: %lf \n", (double) (fim - inicio)/1000000);

  return 0;
}