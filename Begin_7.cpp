// Найти длину окружности L и площадь круга S заданного радиуса R:  L = 2·π·R, S = π·R2.  В качестве значения π использовать 3.14.
#include <iostream>;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int R, b=2;
	const float π = 3.14;
	float L, S;
	cout << "Enter the radius of the circle:";
	cin >> R;
	L = 2 * π * R;
	cout << "L=" << L << endl;
	S = π * pow(R, b);
	cout << "S=" << S << endl;
	cin.get();
	return 0;
}