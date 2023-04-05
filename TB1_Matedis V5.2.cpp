#include<iostream>
#include <cstdlib>
#include <ctime>

void RegisterNumber(int* number); // Beth
void WheatherProbabilityGenerator(double** matrix); // Sebas
void ProbabilityMatrix(double** matrix); // Jose
void ShowProbMatrix(double** matrix); // Jose
void ShowMatrix(double** matrix); // Diego

using namespace std;
using namespace System;

int main() { // Mathias

	srand(time(NULL));

	double** weather_matrix = new double* [4];
	double** probability_matrix = new double* [4];
	int* day_number = new int;

	for (int i = 0; i < 4; i++) {
		weather_matrix[i] = new double[4];
	}
	for (int i = 0; i < 4; i++) {
		probability_matrix[i] = new double[4];
	}

	RegisterNumber(day_number);
	WheatherProbabilityGenerator(weather_matrix);
	ProbabilityMatrix(probability_matrix);

	
	ShowMatrix(weather_matrix);
	ShowProbMatrix(probability_matrix);

	system("pause");

	delete day_number;

	for (int i = 0; i < 4; i++)
		delete[] weather_matrix[i];
	delete[] weather_matrix;

	for (int i = 0; i < 4; i++){
		delete[] probability_matrix[i];
	}
	return 0;
}

void RegisterNumber(int* number) {
	do {
		cout << "Registre el numero de dias: "; cin >> *number;
		system("cls");

		if (*number < 60 || *number > 90) {
			cout << "Registre un número >= 60 o <= 90" << endl;

			system("pause");
			system("cls");
		}
	} while (*number < 60 || *number > 90);
}

void WheatherProbabilityGenerator(double** matrix) {
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

void ProbabilityMatrix(double** matrix) {
	int num1, num2, num3, num4;

	for (int j = 0; j < 1; j++) {

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

void ShowProbMatrix(double** matrix) {
	int aux = 0;

	cout << "\n ----------------------------------------" << endl;
	cout << " La martriz de probabilidades es: " << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			aux = matrix[i][j];
			if (aux % 10 == 0) {
				cout << "[" << (double)matrix[i][j] / 100 << "0]\n";
			}
			else {
				cout << "[" << (double)matrix[i][j] / 100 << "]\n";
			}
		}
		
	}
}

void ShowMatrix(double** matrix) {
	int aux = 0;

	cout << "Nublado = Nu | Parcialmente Nublado = PN | Parcialmente Soleado = PS | Soleado = So" << endl;

	cout << "\n\tNu\tPN\tPS\tSo" << endl;

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

			aux = matrix[i][j];
			if (aux % 10 == 0) {
				cout << "[" << (double)matrix[i][j] / 100 << "0]\t";
			}
			else {
				cout << "[" << (double)matrix[i][j] / 100 << "]\t";
			}
		}
		cout << endl;
	}
}