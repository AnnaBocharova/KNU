// Дана длина ребра куба a. Найти объем куба V = a3и площадь его по верхности S = 6·a2
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, V, S, b, c;
	b = 2;
	c = 3;
	cout << "Enter the length of the edge of the cube :";
	cin >> a;
	cout << "V=" << pow(a, c) << endl;
	S = 6 * pow(a, b);
	cout << "S=" << S << endl;
	cin.get();
	return 0;
	
}
