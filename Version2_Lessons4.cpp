#include <iostream>
#include"LibSwitchIf.h"
#include "Version2_Lessons4.h"
using namespace std;
int menu()
{
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "1. Даны 4 числа типа int. Сравнить их и вывести наименьшее на консоль. " << endl;
	cout << "2. Вывести на консоль количество максимальных чисел среди этих четырех." << endl;
	cout << "3.Даны 5 чисел (тип int). Вывести вначале наименьшее, а затем наибольшее из данных чисел." << endl;
	cout << "4.Дано число месяца (тип int). Необходимо определить время года (зима, весна, лето, осень) и вывести на консоль через if." << endl;
	cout << "5. Дано число месяца (тип int). Необходимо определить время года (зима, весна, лето, осень) и вывести на консоль через case:" << endl;
	int choise = 0;
	cin >> choise;
	return choise;
}
int main() {
	menu();
	int choise = menu();
	switch (choise) {
	case 1:
		findMinMax4();
		break;
	case 2:
		countOfMax();
		break;
	case 3:
		findMaxMin5();
		break;
	case 4:
		findSeasonIf();
		break;
	case 5:
		findSeasonCase();
		break;
	default:"Error"; break;
	}

	cin.get();
	return 0;

}

