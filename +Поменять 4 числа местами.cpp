// Поменять местами содержимое переменных A B C D. Чтобы в=с, a=d, c=a, d=b.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int A, B, C, D;
	cout << "A=";
	cin >> A;
	cout << "B=";
	cin >> B;
	cout << "C=";
	cin >> C;
	cout << "D=";
	cin >> D;
	A = A + B + C + D;
	C = A - C - B - D;
	B = A - C - B - D;
	D = A - C - D - B;
	A = A - D - B - C;
	cout << "B=" << B << endl;
	cout << "A=" << A << endl;
	cout << "C=" << C << endl;
	cout << "D=" << D << endl;
	cin.get();
	return 0;
}