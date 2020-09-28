// Дано двузначное число. Найти сумму и произведение его цифр.
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int ab;
	cout << "Enter two-digit number:";
	cin >> ab;
	cout << "Sum of digit: " << (ab / 10)+(ab%10) << endl;
	cout << "Product of numbers:" << (ab/10)*(ab % 10) << endl;
	cin.get();
	return 0;

}
