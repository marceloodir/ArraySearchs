/*
 * main.c
 *
 *  Created on: 25/02/2015
 *      Author: Marcelo Odir
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int binarySearch(int *array, int inicio, int fim, int valor) {
	int meio = (inicio+fim)/2;

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

int binarySearchSmart(int *array, int inicio, int fim, int valor) {
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

int defaultSearch(int *array, int len, int valor) {
	int i;
	for(i=0;i<len;i++){
		if(array[i]==valor)
			return i;
	}
	return -1;
}

int main(int argc, char **argv) {
	int len = 999999, valor;
	int array[len];
	int i,temp = 0;
	int saida01,saida02,saida03;
	double tempo01, tempo02, tempo03,ini;


	for(i=0;i<len;i++) {
		temp = temp + (rand() % 100);
		array[i] = temp;
		if(i==len-1) {
			valor = array[i];
			printf("valor buscado: %d\n",valor);
		}
	}

	ini = clock();
	saida02 = binarySearch(array,0,len-1,valor);
	tempo02 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;

	ini = clock();
	saida03 = binarySearch(array,0,len-1,valor);
	tempo03 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;

	ini = clock();
	saida01 = defaultSearch(array,len,valor);
	tempo01 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;


	printf("Busca Sequencial tempo de execução %lfms\n",tempo01);
	printf("Busca Binária tempo de execução %lfms\n",tempo02);
	printf("Busca Binária Smart tempo de execução %lfms\n",tempo03);

	return EXIT_SUCCESS;
}

