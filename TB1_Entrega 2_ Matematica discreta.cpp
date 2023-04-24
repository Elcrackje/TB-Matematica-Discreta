#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

void menu(int* opcion);
void Conclusion();
void Credits();

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

	setlocale(LC_ALL, "spanish");
	srand(time(NULL));

	double** weather_matrix = new double* [4];
	double** aux_matrix = new double* [4];
	double** probability_matrix = new double* [4];
	double** aux_probability_matrix = new double* [4];

	for (int i = 0; i < 4; i++) {
		weather_matrix[i] = new double[4];
		aux_matrix[i] = new double[4];
	}
	for (int i = 0; i < 4; i++) {
		probability_matrix[i] = new double[1];
		aux_probability_matrix[i] = new double[1];
	}
	int* opcion = new int;
	int* day_number = new int;

	while (true) {
		menu(opcion);

		switch (*opcion) {
		case 1:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					weather_matrix[i][j] = 0;
					aux_matrix[i][j] = 0;
				}
			}
			RegisterNumber(day_number);
			WheatherProbabilityGenerator(weather_matrix);
			ProbabilityMatrix(probability_matrix);

			ShowMatrix(weather_matrix);
			ShowProbMatrix(probability_matrix);

			PowMatrix(weather_matrix, aux_matrix, day_number);
			MultiplyMatrix(weather_matrix, probability_matrix, aux_probability_matrix);

			ShowMatrix(weather_matrix);
			ShowProbMatrix(aux_probability_matrix);

			system("pause");
			break;
		case 2:
			Conclusion();
			break;
		case 3:
			Credits();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		delete[] weather_matrix[i];
		delete[] aux_matrix[i];
		delete[] probability_matrix[i];
		delete[]aux_probability_matrix[i];
	}
	delete[] weather_matrix, aux_matrix, probability_matrix, aux_probability_matrix;
	delete opcion, day_number;

	return 0;
}

void menu(int *opcion){
	do {
		system("cls");
		Console::ForegroundColor = ConsoleColor::White;

		cout << "\t|Proyecto 03 de Matematica Discreta|\n" << endl;

		cout << "1. Iniciar prediccion del clima" << endl;
		cout << "2. Reflexion" << endl;
		cout << "3. Creditos" << endl;
		cout << "4. Salir" << endl;

		cout << "\nIngrese la opcion deseada: "; cin >> *opcion;

		if (*opcion < 1 || *opcion > 4) {
			system("cls");
			cout << "Ingrese un numero valido entre 1 y 4" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (*opcion < 1 || *opcion > 4);
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
	} while (*number < 0 || *number > 90);
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
	int day_number = 0;
	//*number = 20;

	for (int k = 1; k < *number; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				aux[i][j] = 0;
				for (int p = 0; p < 4; p++) {
					aux[i][j] += matrix[i][p] * matrix[p][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j] = aux[i][j];
			}
		}
	}
}

void MultiplyMatrix(double** matrix, double** Pmatrix, double** auxPmatrix) {
	for (int i = 0; i < 4; i++) {
		auxPmatrix[i][0] = 0;
		for (int j = 0; j < 4; j++) {
			auxPmatrix[i][0] += matrix[i][j] * Pmatrix[j][0];
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
	cout << "----------------------------------------" << endl;
	cout << "La martriz de probabilidades es: " << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			cout << "[" << matrix[i][j] << "]\n";
		}
	}
	cout << "\n";
}

void Conclusion() {
	cout << "\t|Conclusiones|\n" << endl;
	Console::ForegroundColor = ConsoleColor::Blue;

	cout << "- Para completar este trabajo, se requiere conocimiento previo" << endl;
	cout << "  de Programación I y Algoritmos y Estructura de Datos.\n" << endl;

	cout << "- Es necesario crear un diagrama de flujo de alta calidad y" << endl;
	cout << "  coherente con el tema, y escribir todas las ecuaciones.\n" << endl;

	cout << "- Además, es importante tener una actitud autodidacta en los" << endl;
	cout << "  temas relacionados, ya que hemos investigado diversas variedades" << endl;
	cout << "  y algoritmos necesarios para implementar el código.\n" << endl;

	cout << "- El trabajo ha sido un poco difícil, pero ha sido muy útil para" << endl;
	cout << "  comprender conceptos avanzados de informática y matemáticas.\n" << endl;
	

	cout << "- La programación en equipo es beneficiosa, ya que el código" << endl;
	cout << "  permitirá la validación de los días solicitados por el usuario" << endl;
	cout << "  y la creación de una matriz para mostrar los resultados, utilizando" << endl;
	cout << "  técnicas de elevación de matrices.\n" << endl;

	system("pause");
}

void Credits() {
	cout << "\t|Integrantes|\n" << endl;
	Console::ForegroundColor = ConsoleColor::DarkYellow;

	cout << "Cachis Gonzales, Sebastian\t(U202210846)" << endl;
	cout << "Gutierrez Garcia, Jose Eduardo\t(U202221518)" << endl;
	cout << "Jaramillo Llave, Diego Jesus\t(U20221B787)" << endl;
	cout << "Oneglio De Paz, Beth Shantal\t(U202213423)" << endl;
	cout << "Orrego Cespedes, Matias Joaquin\t(U202210702)" << endl;

	Console::ForegroundColor = ConsoleColor::White;
	cout << "\n\t|Datos del curso|\n" << endl;

	Console::ForegroundColor = ConsoleColor::Red;
	cout << "Universidad Peruana de Ciencias Aplicadas" << endl;
	cout << "Ingeniería de Software y Ciencias de la Computación - Ciclo III" << endl;
	cout << "matemática Discreta - SS38" << endl;
	cout << "Antonio Marcos Medina Martinez" << endl;

	system("pause");
}
