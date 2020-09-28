//Дано двузначное число. Вывести вначале его левую цифру (десятки),а затем — его правую цифру(единицы).Для нахождения десятков использовать операцию деления
//нацело, для нахождения единиц — операцию взятия остатка от деления.
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int ab;
	cout << "Enter two-digit number:";
	cin >> ab;
	cout << "Figure tens: " << ab / 10 << endl;
	cout << "Digit units:" << ab % 10 << endl;
	cin.get();
	return 0;

}