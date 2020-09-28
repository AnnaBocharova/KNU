//Дано двузначное число. Вывести число, полученное при перестановке цифр исходного числа.
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int ab;
	cout << "Enter two-digit number:";
	cin >> ab;
	cout << (ab % 10) * 10 + (ab / 10) << endl;
	cin.get();
	return 0;
}