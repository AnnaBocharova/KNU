//Дано трехзначное число. Используя одну операцию деления нацело,вывести первую цифру данного числа(сотни).
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int abc;
	cout << "Enter three-digit number:";
	cin >> abc;
	cout << "The number of hunders:" << abc / 100 << endl;
	cin.get();
	return 0;
}

