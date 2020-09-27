// Найти значение функции y = 4·(x–3)6 – 7·(x–3)3 + 2 при данном значе нии x.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int x, y, b=6, c=3;
	cout << "x=";
	cin >> x;
	y = 4 * pow((x - 3), b) - 7 * pow((x - 3), c) + 2;
	cout << "y=" << y;
	cin.get();
	return 0;
}