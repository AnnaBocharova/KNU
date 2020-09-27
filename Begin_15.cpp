//Дана площадь S круга. Найти его диаметр D и длину L окружности,  ограничивающей этот круг, учитывая, что L = π·D, S = π·D2/4. В качестве значения π использовать 3.14.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	const float π = 3.14;
	int S;
	float D, L;
	cout << "Enter the area of the circle:";
	cin >> S;
	D = sqrt(4 * S / π);
	L = π * D;
	cout << "D=" << D << endl;
	cout << "L=" << L << endl;
	cin.get();
	return 0;
}