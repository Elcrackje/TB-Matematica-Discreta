#include<iostream>
#include <cstdlib>
#include <ctime>

void GenderedWheatherProbability(float** matrix);
void ShowMatrix(float** matrix);

using namespace std;
using namespace System;

int main() {

	srand(time(NULL));

	float** weather_matrix = new float* [4];

	for (int i = 0; i < 4; i++) {
		weather_matrix[i] = new float[4];
	}

	GenderedWheatherProbability(weather_matrix);
	ShowMatrix(weather_matrix);

	system("pause");

	for (int i = 0; i < 4; i++)
		delete[] weather_matrix[i];
	delete[] weather_matrix;

	return 0;
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