//Даны целые положительные числа A и B (A > B). На отрезке длины A размещено максимально возможное количество отрезков длины B(без наложений).
//Используя операцию деления нацело, найти количество отрезков B, размещенных на отрезке A.

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
		cout << "Number of segments B in A:" << A / B << endl;
	}
	else
		cout << "Error! The segment A is more than B." << endl;
	cin.get();
	return 0;
}