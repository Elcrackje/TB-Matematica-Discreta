#include<iostream>
#include <cstdlib>
#include <ctime>

/*
void GenderedWheatherProbability(float** matrix);
void ShowMatrix(float** matrix);
int  genNumber();
void printNums(int n);
*/


using namespace std;
using namespace System;

// funcion para obtener un numero aleatorio entre 60 y 90
int genNumber()
{
	srand(time(NULL));
	int n = rand() % 31 + 60;
	return n;
}
// funcion para imprimir los numeros
void printNums(int n)
{
	for (int i = 0; i < 4; ++i) {
		cout << n + i << " ";
	}
	cout << endl;
}

// funci�n para elevar una matriz a un n�mero n
void elevar_matriz(float** matriz, int n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matriz[i][j] = pow(matriz[i][j], n);
		}
	}
}

void GenderedWheatherProbability(float** matrix) {
	int num1, num2, num3, num4;

	for (int j = 0; j < 4; j++) {

		num1 = 1 + rand() % 50;
		num2 = 1 + rand() % (60 - num1);
		num3 = 1 + rand() % (70 - num1 - num2);
		num4 = 100 - num1 - num2 - num3;

		matrix[0][j] = num1;
		matrix[1][j] = num2;
		matrix[2][j] = num3;
		matrix[3][j] = num4;
	}
}

void ShowMatrix(float** matrix) {
	int aux = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			aux = matrix[i][j];
			if (aux % 10 == 0) {
				cout << "[" << (float)matrix[i][j] / 100 << "0]";
			}
			else {
				cout << "[" << (float)matrix[i][j] / 100 << "]";
			}
		}
		cout << endl;
	}
}

int main() {

	srand(time(NULL));

	float** weather_matrix = new float* [4];

	for (int i = 0; i < 4; ++i) {
		weather_matrix[i] = new float[4];
	}

	GenderedWheatherProbability(weather_matrix);
	ShowMatrix(weather_matrix);

	int n;
	cout << "Ingrese el numero al que desea elevar la matriz: ";
	cin >> n;

	elevar_matriz(weather_matrix, n);
	ShowMatrix(weather_matrix);

	system("pause");

	for (int i = 0; i < 4; ++i){
		delete[] weather_matrix[i];
	}
	delete[] weather_matrix;
	
	return 0;
}
