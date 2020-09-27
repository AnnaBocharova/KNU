// Даны два ненулевых числа. Найти сумму, разность, произведение и частное их модулей.  

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, b;
	double quot;
	cout << "Enter a number1: ";
	cin >> a;
	cout << "Enter a number2: ";
	cin >> b;
	if (a != 0 && b != 0) {
		cout << "Sum=" << abs(a) + abs(b) << endl;
		cout << "Difference=" << abs(a) - abs(b) << endl;
		cout << "Product=" << abs(a) * abs(b) << endl;
		quot = abs(a) / abs(b);
		cout << "Quotient=" << quot<< endl;
	}
	else
		cout << "Don`t enter zero numbers!" << endl;
	cin.get();
	return 0;

}