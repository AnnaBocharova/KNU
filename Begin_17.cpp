//Даны три точки A, B, C на числовой оси.Найти длины отрезков AC  и BC и их сумму.
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
	cin >>C;
	AC = abs(C - A);
	BC = abs(C - B);
	cout << "AC=" << AC<<endl;
	cout << "BC=" << BC<<endl;
	cout << "AC+BC=" << AC + BC<<endl;
	cin.get();
	return 0;
}
