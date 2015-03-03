/*
 * main.c
 *
 *  Created on: 25/02/2015
 *      Author: Marcelo Odir
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int binarySearch(unsigned long int *array, int inicio, int fim, unsigned long int valor) {
	int meio = (inicio+fim)/2;

	if(array[meio] == valor) {
		return meio;
	}else{
		if((valor > array[meio]) && (inicio < fim)) {
			return binarySearch(array,meio+1,fim,valor);
		}else{
			if((valor < array[meio]) && (inicio < fim)) {
				return binarySearch(array,inicio,meio-1,valor);
			}else{
				return -1;
			}
		}
	}
}

int binarySearchSmart(int *array, int inicio, int fim, unsigned long int valor) {
	int meio,passo;

	passo = (array[inicio]+array[fim])/fim;
	if(valor%passo == 0) {
		meio = valor / passo;
	}else{
		meio = (valor / passo) + 1;
	}


	if(array[meio] == valor) {
		return meio;
	}else{
		if(valor > array[meio] && inicio < fim) {
			return binarySearch(array,meio+1,fim,valor);
		}else{
			if(valor < array[meio] && inicio < fim) {
				return binarySearch(array,inicio,meio-1,valor);
			}else{
				return -1;
			}
		}
	}
}

int defaultSearch(unsigned long int *array, int len, unsigned long int valor) {
	int i;
	for(i=0;i<len;i++){
		if(array[i]==valor)
			return i;
	}
	return -1;
}

unsigned long int array[699999999];

int main(int argc, char **argv) {
	unsigned long int len = 699999999, valor;
	unsigned long int i,temp = 0;
	unsigned long int saida01,saida02,saida03;
	double tempo01, tempo02, tempo03,ini;


	for(i=0;i<len;i++) {
		temp = temp + (rand() % 50);
		array[i] = temp;
	}

    for (i= 0 ; i <10 ; i++){
	  valor = rand()%array[len-1];
	  printf("\nvalor buscado: %d\n",valor);


	  ini = clock();
	  saida01 = defaultSearch(array,len,valor);
	  tempo01 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;

	  ini = clock();
	  saida03 = binarySearch(array,0,len-1,valor);
	  tempo03 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;

	  ini = clock();
	  saida02 = binarySearch(array,0,len-1,valor);
	  tempo02 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;


	  printf("Busca Sequencial tempo de execução %lfms (Indice=%ld)\n",tempo01, saida01);
	  printf("Busca Binária tempo de execução %lfms (Indice=%ld)\n",tempo02,saida02);
	  printf("Busca Binária Smart tempo de execução %lfms (Indice=%ld)\n",tempo03,saida03);
	  if (saida01>=0){
		  printf ("Array[%ld] = %ld\n",saida01,array[saida01]);
	  }
    }
	return EXIT_SUCCESS;
}

