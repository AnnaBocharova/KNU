//Даны три точки A, B, C на числовой оси.Точка C расположена между точками A и B.Найти произведение длин отрезков AC и BC.
#include <iostream>;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int A, B, C, AC, BC;
	cout << "Enter the coordinates op point A:";
	cin >> A;
	cout << "Enter the coordinates op point B:";
	cin >> B;
	cout << "Enter the coordinates op point C:";
	cin >> C;
	if ((A < C && C < B) ||( B<C && C<A)) {
		AC = abs(C - A);
		BC = abs(C - B);
		cout << "AC=" << AC << endl;
		cout << "BC=" << BC << endl;
		cout << "AC*BC=" << AC * BC << endl;
	}
	else
		cout << "Incorrectly entered coordinates. Poin C lies between A and B!" << endl;
	cin.get();
	return 0;
}