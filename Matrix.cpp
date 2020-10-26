/*Двумерные массивы  

1. Вывести все положительные елементы; Статична матриця
2. Вывести количество строк, не содержащих ни одного нулевого элемента; Динамічна матриця*/
#include<iostream>
#include "Matrix.h"
using namespace std;
void dinamicMatrix(int rows, int** arr, int cols, int& k, int& counter, int& counter2)
{
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> k;
			arr[i][j] = k;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++) {
		counter = 0;
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] != 0)
				counter++;
		}
		counter2 += counter / cols;
	}
	cout << "The number of lines that do not contain any zero elements" << counter2 << endl;
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
}
int main() {
	int rows, cols, k, counter, counter2=0, k1;
	cout << "Enter colums:";
	cin >> cols;
	cout << "Enter rows:";
	cin >> rows;
	int** arr =new int*[rows];
	//dinamicMatrix(rows, arr, cols, k, counter, counter2);
	delete[] arr;
	const int ROWS = 5;
	const int COLS = 4;
	int array[ROWS][COLS]{};
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cin >> k1;
			array[i][j] = k1;
		}
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if(array[i][j]>0)
			cout<<array[i][j]<<"\t";
		}
		cout<< endl;
	}

	return 0;
}