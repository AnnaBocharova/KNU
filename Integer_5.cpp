//Даны целые положительные числа A и B (A > B). На отрезке длины A размещено максимально возможное количество отрезков длины B(без наkожений).
//Используя операцию взятия остатка от деления нацело, найти lлину незанятой части отрезка A.
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int A, B;
	cout << "Enter a segment A:";
	cin >> A;
	cout << "Enter a segment B:";
	cin >> B;
	if (A > B) {
		cout << "The length of the unoccuptied part of the line A: " << A % B << endl;
	}
	else
		cout << "Error! The segment A is more than B." << endl;
	cin.get();
	return 0;
}