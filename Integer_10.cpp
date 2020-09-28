//Дано трехзначное число. Вывести вначале его последнюю цифру (единицы), а затем — его среднюю цифру(десятки).
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int abc;
	cout << "Enter three-digit number:";
	cin >> abc;
	cout << "Digit units:" << abc %10 << endl;
	cout << "Figure tens:" << abc / 10 % 10 << endl;
	cin.get();
	return 0;
}