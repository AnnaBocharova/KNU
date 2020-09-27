// Даны два ненулевых числа. Найти сумму, разность, произведение и частное их квадратов.  
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, b, c=2;
	float quot;
	cout << "Enter a number1: ";
	cin >> a;
	cout << "Enter a number2: ";
	cin >> b;
	if (a != 0 && b != 0) {
		cout << "Sum=" << pow(a, c) + pow(b, c) << endl;
		cout << "Difference=" << pow(a, c) - pow(b, c) << endl;
		cout << "Product=" << pow(a, c) * pow(b, c) << endl;
		quot = pow(a, c) / pow(b, c);
		cout << "Quotient=" << quot<< endl;
	}
	else
		cout << "Don`t enter zero numbers!" << endl;
	cin.get();
	return 0;

}
