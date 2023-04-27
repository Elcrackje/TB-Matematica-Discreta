#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

void menu(int* opcion);
void Conclusion();
void Credits();

void RegisterNumber(int* number);
void RegisterProbabilityMatrix(double** matrix);
void WheatherProbabilityGenerator(double** matrix, int* number);

void PowMatrix(double** matrix, double** aux, double** m1, double** m2, double** m3, double** m4);
void MultiplyMatrix(double** m1, double** m2, double** m3, double** m4, double** Pmatrix, double** auxPmatrix, double** pw1, double** pw2, double** pw3, double** pw4);

void FinalMessage(int* number, double** pw1, double** pw2, double** pw3, double** pw4);

void ShowProbMatrix(double** matrix);
void ShowMatrix(double** matrix);

using namespace std;
using namespace System;

int main() {

	setlocale(LC_ALL, "spanish");
	srand(time(NULL));

	int* opcion = new int;
	int* day_number = new int;

	double** weather_matrix = new double* [4];
	double** aux_matrix = new double* [4];
	
	double** weather1 = new double* [4];
	double** weather2 = new double* [4];
	double** weather3 = new double* [4];
	double** weather4 = new double* [4];

	
	double** probability_matrix = new double* [4];
	double** aux_probability_matrix = new double* [4];

	double** PW1 = new double* [4];
	double** PW2 = new double* [4];
	double** PW3 = new double* [4];
	double** PW4 = new double* [4];

	for (int i = 0; i < 4; i++) {
		weather_matrix[i] = new double[4];
		aux_matrix[i] = new double[4];

		weather1[i] = new double[4];
		weather2[i] = new double[4];
		weather3[i] = new double[4];
		weather4[i] = new double[4];
	}
	for (int i = 0; i < 4; i++) {
		probability_matrix[i] = new double[1];
		aux_probability_matrix[i] = new double[1];
		PW1[i] = new double[1];
		PW2[i] = new double[1];
		PW3[i] = new double[1];
		PW4[i] = new double[1];
	}

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
			RegisterProbabilityMatrix(probability_matrix);
			WheatherProbabilityGenerator(weather_matrix, day_number);

			ShowMatrix(weather_matrix);
			ShowProbMatrix(probability_matrix);

			PowMatrix(weather_matrix, aux_matrix, weather1, weather2, weather3, weather4);
			MultiplyMatrix(weather1, weather2, weather3, weather4, probability_matrix, aux_probability_matrix, PW1, PW2, PW3, PW4);


			ShowProbMatrix(PW1);
			ShowProbMatrix(PW2);
			ShowProbMatrix(PW3);
			ShowProbMatrix(PW4);
			cout << endl;

			FinalMessage(day_number, PW1, PW2, PW3, PW4);

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
		delete[] aux_probability_matrix[i];
		delete[] weather1[i];
		delete[] weather2[i];
		delete[] weather3[i];
		delete[] weather4[i];
	}
	delete[] weather_matrix, aux_matrix, probability_matrix, aux_probability_matrix, weather1, weather2, weather3, weather4;
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
		cout << "Registre el número de dias: "; cin >> *number;
		system("cls");

		if (*number < 60 || *number > 90) {
			cout << "Registre un número >= 60 o <= 90" << endl;

			system("pause");
			system("cls");
		}
	} while (*number < 60 || *number > 90);
}

void RegisterProbabilityMatrix(double** matrix) {
	int num;

	do {
		cout << "\t|Climas|" << endl;
		cout << "1 -> Nublado\n2 -> Parcialmente nublado\n3 -> Parcialmente soleado\n4 -> Soleado\n" << endl;
		
		cout << "Ingrese el número que representa el clima actual: "; cin >> num;
		system("cls");

		if (num < 1 || num > 4) {
			cout << "Registre un número >= 1 o <= 4" << endl;

			system("pause");
			system("cls");
		}
	} while (num < 1 || num > 4);

	switch (num) {
	case 1:
		matrix[0][0] = 1;
		matrix[1][0] = 0;
		matrix[2][0] = 0;
		matrix[3][0] = 0;
		break;
	case 2:
		matrix[0][0] = 0;
		matrix[1][0] = 1;
		matrix[2][0] = 0;
		matrix[3][0] = 0;
		break;
	case 3:
		matrix[0][0] = 0;
		matrix[1][0] = 0;
		matrix[2][0] = 1;
		matrix[3][0] = 0;
		break;
	case 4:
		matrix[0][0] = 0;
		matrix[1][0] = 0;
		matrix[2][0] = 0;
		matrix[3][0] = 1;
		break;
	}
}

void WheatherProbabilityGenerator(double** matrix, int* number) {
	int num1, num2, num3, num4;

	if (*number >= 60 && *number <= 69) {
		for (int j = 0; j < 4; j++) {

			num4 = 60 + rand()% 25;//s
			num3 = rand() % (100 - num4);// ps
			num2 = rand() % (100 - num4 - num3);// pn
			num1 = 100 - num4 - num3 - num2;// n

			matrix[0][j] = (double)num1 / 100.00;
			matrix[1][j] = (double)num2 / 100.00;
			matrix[2][j] = (double)num3 / 100.00;
			matrix[3][j] = (double)num4 / 100.00;
		}
	}
	else if (*number >= 70 && *number <= 79) {
		for (int j = 0; j < 4; j++) {

			num4 = 40 + rand() % 25;//s
			num3 = rand() % (100 - num4);// ps
			num2 = rand() % (100 - num4 - num3);// pn
			num1 = 100 - num4 - num3 - num2;// n

			matrix[0][j] = (double)num1 / 100.00;
			matrix[1][j] = (double)num2 / 100.00;
			matrix[2][j] = (double)num3 / 100.00;
			matrix[3][j] = (double)num4 / 100.00;
		}
	}
	else if (*number >= 80 && *number <= 90) {
		for (int j = 0; j < 4; j++) {

			num4 = 25 + rand() % 25;//s
			num3 = rand() % (100 - num4);// ps
			num2 = rand() % (100 - num4 - num3);// pn
			num1 = 100 - num4 - num3 - num2;// n

			matrix[0][j] = (double)num1 / 100.00;
			matrix[1][j] = (double)num2 / 100.00;
			matrix[2][j] = (double)num3 / 100.00;
			matrix[3][j] = (double)num4 / 100.00;
		}
	}
}

void PowMatrix(double** matrix, double** aux, double** m1, double** m2, double** m3, double** m4) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1[i][j] = matrix[i][j];
			m2[i][j] = matrix[i][j];
			m3[i][j] = matrix[i][j];
			m4[i][j] = matrix[i][j];
		}
	}
	//m2
	for (int k = 1; k < 2; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				aux[i][j] = 0;
				for (int p = 0; p < 4; p++) {
					aux[i][j] += m2[i][p] * m2[p][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m2[i][j] = aux[i][j];
			}
		}
	}
	//m3
	for (int k = 1; k < 3; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				aux[i][j] = 0;
				for (int p = 0; p < 4; p++) {
					aux[i][j] += m3[i][p] * m3[p][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m3[i][j] = aux[i][j];
			}
		}
	}
	//m3
	for (int k = 1; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				aux[i][j] = 0;
				for (int p = 0; p < 4; p++) {
					aux[i][j] += m4[i][p] * m4[p][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m4[i][j] = aux[i][j];
			}
		}
	}
}

void MultiplyMatrix(double** m1, double** m2, double** m3, double** m4, double** Pmatrix, double** auxPmatrix, double** pw1, double** pw2, double** pw3, double** pw4) {
	for (int i = 0; i < 4; i++) {
		pw1[i][0] = Pmatrix[i][0];
		pw2[i][0] = Pmatrix[i][0];
		pw3[i][0] = Pmatrix[i][0];
		pw4[i][0] = Pmatrix[i][0];
	}

	//m1
	for (int i = 0; i < 4; i++) {
		pw1[i][0] = 0;
		for (int j = 0; j < 4; j++) {
			pw1[i][0] += m1[i][j] * Pmatrix[j][0];
		}
	}
	//m2
	for (int i = 0; i < 4; i++) {
		pw2[i][0] = 0;
		for (int j = 0; j < 4; j++) {
			pw2[i][0] += m2[i][j] * Pmatrix[j][0];
		}
	}
	//m3
	for (int i = 0; i < 4; i++) {
		pw3[i][0] = 0;
		for (int j = 0; j < 4; j++) {
			pw3[i][0] += m3[i][j] * Pmatrix[j][0];
		}
	}
	//m4
	for (int i = 0; i < 4; i++) {
		pw4[i][0] = 0;
		for (int j = 0; j < 4; j++) {
			pw4[i][0] += m4[i][j] * Pmatrix[j][0];
		}
	}
}

void FinalMessage(int* number, double** pw1, double** pw2, double** pw3, double** pw4) {
	//m1
	if (pw1[0][0] > pw1[1][0] && pw1[0][0] > pw1[2][0] && pw1[0][0] > pw1[3][0]) {
		cout << "Para el día " << *number + 1 << " el clima es NUBLADO" << endl;
	}
	else if (pw1[1][0] > pw1[0][0] && pw1[1][0] > pw1[2][0] && pw1[1][0] > pw1[3][0]) {
		cout << "Para el día " << *number + 1 << " el clima es PARCIALMENTE NUBLADO" << endl;
	}
	else if (pw1[2][0] > pw1[0][0] && pw1[2][0] > pw1[1][0] && pw1[2][0] > pw1[3][0]) {
		cout << "Para el día " << *number + 1 << " el clima es PARCIALMENTE SOLEADO" << endl;
	}
	else if (pw1[3][0] > pw1[0][0] && pw1[3][0] > pw1[1][0] && pw1[3][0] > pw1[2][0]) {
		cout << "Para el día " << *number + 1 << " el clima es SOLEADO" << endl;
	}
	//m2
	if (pw2[0][0] > pw2[1][0] && pw2[0][0] > pw2[2][0] && pw2[0][0] > pw2[3][0]) {
		cout << "Para el día " << *number + 2 << " el clima es NUBLADO" << endl;
	}
	else if (pw2[1][0] > pw2[0][0] && pw2[1][0] > pw2[2][0] && pw2[1][0] > pw2[3][0]) {
		cout << "Para el día " << *number + 2 << " el clima es PARCIALMENTE NUBLADO" << endl;
	}
	else if (pw2[2][0] > pw2[0][0] && pw2[2][0] > pw2[1][0] && pw2[2][0] > pw2[3][0]) {
		cout << "Para el día " << *number + 2 << " el clima es PARCIALMENTE SOLEADO" << endl;
	}
	else if (pw2[3][0] > pw2[0][0] && pw2[3][0] > pw2[1][0] && pw2[3][0] > pw2[2][0]) {
		cout << "Para el día " << *number + 2 << " el clima es SOLEADO" << endl;
	}
	//m3
	if (pw3[0][0] > pw3[1][0] && pw3[0][0] > pw3[2][0] && pw3[0][0] > pw3[3][0]) {
		cout << "Para el día " << *number + 3 << " el clima es NUBLADO" << endl;
	}
	else if (pw3[1][0] > pw3[0][0] && pw3[1][0] > pw3[2][0] && pw3[1][0] > pw3[3][0]) {
		cout << "Para el día " << *number + 3 << " el clima es PARCIALMENTE NUBLADO" << endl;
	}
	else if (pw3[2][0] > pw3[0][0] && pw3[2][0] > pw3[1][0] && pw3[2][0] > pw3[3][0]) {
		cout << "Para el día " << *number + 3 << " el clima es PARCIALMENTE SOLEADO" << endl;
	}
	else if (pw3[3][0] > pw3[0][0] && pw3[3][0] > pw3[1][0] && pw3[3][0] > pw3[2][0]) {
		cout << "Para el día " << *number + 3 << " el clima es SOLEADO" << endl;
	}
	//m4
	if (pw4[0][0] > pw4[1][0] && pw4[0][0] > pw4[2][0] && pw4[0][0] > pw4[3][0]) {
		cout << "Para el día " << *number + 4 << " el clima es NUBLADO" << endl;
	}
	else if (pw4[1][0] > pw4[0][0] && pw4[1][0] > pw4[2][0] && pw4[1][0] > pw4[3][0]) {
		cout << "Para el día " << *number + 4 << " el clima es PARCIALMENTE NUBLADO" << endl;
	}
	else if (pw4[2][0] > pw4[0][0] && pw4[2][0] > pw4[1][0] && pw4[2][0] > pw4[3][0]) {
		cout << "Para el día " << *number + 4 << " el clima es PARCIALMENTE SOLEADO" << endl;
	}
	else if (pw4[3][0] > pw4[0][0] && pw4[3][0] > pw4[1][0] && pw4[3][0] > pw4[2][0]) {
		cout << "Para el día " << *number + 4 << " el clima es SOLEADO" << endl;
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
	cout << "Ingeniería de Software e Ingeniería de Ciencias de la Computación - Ciclo III" << endl;
	cout << "matemática Discreta - SS38" << endl;
	cout << "Antonio Marcos Medina Martinez" << endl;

	system("pause");
}
