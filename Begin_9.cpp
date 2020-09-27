// Даны два неотрицательных числа a и b. Найти их среднее геометриче ское, то есть квадратный корень из их произведения
#include <iostream>;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, b;
	float geom;
	cout << "Enter a positive number1: ";
		cin >> a;
		cout << "Enter a positive number2:";
		cin >> b;
		if (a > 0 && b > 0) {
			geom = sqrt(a * b);
			cout << "Geometric mean of numbers= " << geom << endl;
		}
		else
			cout << "Error";
		
		cin.get();
		return 0;

}