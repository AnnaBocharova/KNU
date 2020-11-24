#include<iostream>
#include <cmath>
#include "лаба4.h"
using namespace std;
int triangle(int a, int b, int c) {
	double angle0 = acos((b * b + c * c - a * a) / (2 * b * c));
	double angle1 = acos((c * c + a * a - b * b) / (2 * a * c));
	double angle2 = acos((a * a + b * b - c * c) / (2 * a * b));
	double maxAngle = angle0 > angle1 ? (angle0 > angle2 ? angle0 : angle2) : (angle1 > angle2 ? angle1 : angle2);
	if (maxAngle < 3.15 / 2)
		return 0;
	else
		return 1;
	
}

void sortarray(int size, int  array1[9], int& counter, int  array[10], int& k, int newsize, int& counter2)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array1[i] == array1[j]) {
				counter++;
			}
		}
		if (counter <= 3) {
			int value = array1[i];
			array[k] = value;
			k++;
			counter = -1;

		}
		else {
			for (int l = 0; l < newsize; l++) {
				if (array1[i] == array[l]) {
					counter2++;
				}
			}
			if (counter2 < 3) {
				array[k] = array1[i];
				counter2 = 0;
				k++;
				counter = -1;
			}
			else {
				counter2 = 0;
				counter = -1;
			}
		}

	}
}

int main() {
	//Дано масив натуральних чисел. Вивести на екран без повторень всі трійки чисел
	//з масиву, які є сторонами гострокутного трикутника
	int array1[] = {1,1,1,6,6,3,1,1,1};
	int array[10];
	int counter = -1,counter2=0, k=0;
	int size = (sizeof(array1) / sizeof(array1[0]));
	int newsize = (sizeof(array) / sizeof(array[0]));
	sortarray(size, array1, counter, array, k, newsize, counter2);
	int l = 0;
	int tmp = k;
	int newarray[100];
	for (int i = 0; i < tmp; i++) {
		for (int j = 0; j < tmp; j++) {
			if (j+i+1 >= tmp)break;
			int k = triangle(array[i], array[i+1], array[j+i+2]);
			if (k == 0) {
				newarray[l] = array[i];
				newarray[l + 1] = array[i+1];
				newarray[l + 2] = array[j+i+2];
				l += 3;
			}

		}
	}
	for (int i = 0; i < l; i+=3) {
		cout << "{";
		cout << newarray[i] << ",";
		cout << newarray[i + 1] << ",";
		cout<< newarray[i + 2];
		cout << "}";
	}
	return 0;
}