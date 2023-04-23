#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

void RegisterNumber(int* number);
void WheatherProbabilityGenerator(double** matrix);
void ProbabilityMatrix(double** matrix);
void PowMatrix(double** matrix, double** aux, int* number);

void MultiplyMatrix(double** matrix, double** aux, double** Pmatrix);

void ShowProbMatrix(double** matrix);
void ShowMatrix(double** matrix);

using namespace std;
using namespace System;

int main() {

	srand(time(NULL));

	double** weather_matrix = new double* [4];
	double** aux_matrix = new double* [4];
	double** probability_matrix = new double* [4]; // tiene que ser arreglo 4 elementos y crear aux para el vector de probabilidad
	int* day_number = new int;

	for (int i = 0; i < 4; i++) {
		weather_matrix[i] = new double[4];
		aux_matrix[i] = new double[4];
	}
	for (int i = 0; i < 4; i++) {
		probability_matrix[i] = new double[1];
	}

	RegisterNumber(day_number);
	WheatherProbabilityGenerator(weather_matrix);
	ProbabilityMatrix(probability_matrix);

	ShowMatrix(weather_matrix);
	ShowProbMatrix(probability_matrix);

	PowMatrix(weather_matrix, aux_matrix, day_number);
	//MultiplyMatrix(weather_matrix, aux_matrix, probability_matrix);

	ShowMatrix(weather_matrix);
	ShowProbMatrix(probability_matrix);

	system("pause");

	for (int i = 0; i < 4; i++) {
		delete[] weather_matrix[i];
		delete[] aux_matrix[i];
		delete[] probability_matrix[i];
	}
	delete[] weather_matrix, probability_matrix;
	delete day_number;

	return 0;
}

void RegisterNumber(int* number) {
	do {
		cout << "Registre el numero de dias: "; cin >> *number;
		system("cls");

		if (*number < 60 || *number > 90) {
			cout << "Registre un numero >= 60 o <= 90" << endl;

			system("pause");
			system("cls");
		}
	} while (*number < 60 || *number > 90);
}

void WheatherProbabilityGenerator(double** matrix) {
	int num1, num2, num3, num4;

	for (int j = 0; j < 4; j++) {

		num1 = rand() % 50;
		num2 = rand() % (60 - num1);
		num3 = rand() % (70 - num1 - num2);
		num4 = 100 - num1 - num2 - num3;

		matrix[0][j] = (double)num1 / 100.00;
		matrix[1][j] = (double)num2 / 100.00;
		matrix[2][j] = (double)num3 / 100.00;
		matrix[3][j] = (double)num4 / 100.00;
	}
}

void ProbabilityMatrix(double** matrix) {
	int num1, num2, num3, num4;

	for (int j = 0; j < 1; j++) {

		num1 = rand() % 50;
		num2 = rand() % (60 - num1);
		num3 = rand() % (70 - num1 - num2);
		num4 = 100 - num1 - num2 - num3;

		matrix[0][j] = (double)num1 / 100.00;
		matrix[1][j] = (double)num2 / 100.00;
		matrix[2][j] = (double)num3 / 100.00;
		matrix[3][j] = (double)num4 / 100.00;
	}
}

void PowMatrix(double** matrix, double** aux, int* number) {
	int day_number = 1;

	do {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				aux[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					aux[i][j] += matrix[i][k] * matrix[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j] = aux[i][j];
			}
		}
		day_number++;
	} while (day_number <= *number - 3);
}

void MultiplyMatrix(double** matrix, double** aux, double** Pmatrix) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 1; ++j) {
			for (int k = 0; k < 4; ++k) {
				aux[i][j] += matrix[i][k] * Pmatrix[k][1];
			}
		}
	}
}

void ShowMatrix(double** matrix) {
	int aux = 0;

	cout << "Nublado = Nu | Parcialmente Nublado = PN | Parcialmente Soleado = PS | Soleado = So" << endl;

	cout << "\tNu\tPN\tPS\tSo" << endl;

	for (int i = 0; i < 4; i++) {

		switch (i) {
		case 0:
			cout << "Nu\t";
			break;
		case 1:
			cout << "PN\t";
			break;
		case 2:
			cout << "PS\t";
			break;
		case 3:
			cout << "So\t";
			break;
		}
		for (int j = 0; j < 4; j++) {
			cout << "[" << matrix[i][j] << "]\t";
		}
		cout << endl;
	}
}

void ShowProbMatrix(double** matrix) {
	int aux = 0;

	cout << "----------------------------------------" << endl;
	cout << "La martriz de probabilidades es: " << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			cout << "[" << matrix[i][j] << "]\n";
		}
	}
	cout << "\n";
}