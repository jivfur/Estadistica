/*
author: jivfu
date: 2016-05-11
descripcion:
v0: Media Aritmética
v1: Moda
v2: Mediana
v3: Varianza  y Desviación Estándar
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 11

int vector[N];
int vector_frecuencias[N][2];
int num_diferentes = 0;

void inicializa_vector_frencuencias() {
	for (int i = 0; i < N; i++) {
		vector_frecuencias[i][0] = 0;
		vector_frecuencias[i][1] = 0;
	}
}

void calculo_frecuencias() {
	int existe = false;
	int j;
	inicializa_vector_frencuencias();
	for (int i = 0; i < N; i++) {
		for (j = 0; j < num_diferentes; j++) {
			if (vector_frecuencias[j][0] == vector[i]) {
				existe = true;
				break;
			}
		}
		if (existe) {
			vector_frecuencias[j][1]++;
			existe = false;
		}
		else {
			vector_frecuencias[j][0] = vector[i];
			vector_frecuencias[j][1]++;
			num_diferentes++;
		}
	}
}

int frecuencia_modal() {
	int fModal = INT_MIN;
	for (int i = 0; i < num_diferentes; i++) {
		if (vector_frecuencias[i][1] > fModal) {
			fModal = vector_frecuencias[i][1];
		}
	}
	return fModal;
}

void moda() {
	calculo_frecuencias();
	int fModal = frecuencia_modal();
	printf("Modas:\n");
	for (int i = 0; i < num_diferentes; i++) {
		if (vector_frecuencias[i][1] == fModal) {
			printf("%d \t %d\n", vector_frecuencias[i][0], vector_frecuencias[i][1]);
		}
	}
}

void imprime_frecuencias() {
	printf("Frecuencias\n");
	for (int i = 0; i < num_diferentes; i++) {
		printf("%d \t %d\n", vector_frecuencias[i][0], vector_frecuencias[i][1]);
	}
}

void llenar_vector() {
	for (int i = 0; i < N; i++) {
		vector[i] = rand() % 10;
	}
}

void imprime_vector() {
	for (int i = 0; i < N; i++) {
		printf("%d - %d \n",i+1, vector[i]);
	}
}

float media_aritmetica() {
	float suma = 0;
	for (int i = 0; i < N; i++) {
		suma += vector[i];
		//suma = suma+vector[i];
	}
	return suma / N;
}

void burbuja() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (vector[i] > vector[j]) {
				int aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}
}

//0 1 2 3 4 5 6 7 8 9 
//mediana = (vector[4]+vector[5])/2
// División entera: 1/2 = 0
float mediana() {
	int pos = N / 2;
	float m = 0.0;
	if (N % 2 == 0) {
		m = (float)(vector[pos - 1] + vector[pos]) / 2.0;
	}
	else {
		m = vector[pos - 1];
	}
	return m;
}

float varianza() {
	float media = media_aritmetica();
	float var = 0;
	for (int i = 0; i < N; i++) {
		var += pow(vector[i] - media, 2);
	}
	var /= N;
	return var;
}

float desviacionEstandar() {
	return sqrt(varianza());
}

int main() {
	llenar_vector();
	imprime_vector();
	printf("\n El valor de la varianza es: %f\n ", varianza());
	printf("\n El valor de la DS es: %f\n ", desviacionEstandar());
	system("pause");
	return 0;
}