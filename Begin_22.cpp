// Поменять местами содержимое переменных A и B и вывести новые значения A и B.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int A, B;
	cout << "A=";
	cin >> A;
	cout << "B=";
	cin >> B;
	A = A + B;
	B = A - B;
	A = A - B;
	cout << "B=" << B << endl;
	cout << "A=" << A << endl;
	cin.get();
	return 0;
}
