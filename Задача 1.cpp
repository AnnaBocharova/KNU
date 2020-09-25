

#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cout << "Enter the roots of the equation:";
	cin >> x;
	cin >> y;
	int b, c;
	b = -(x + y);
	cout << "Сoefficient1 of the equation: " << b << endl;
	c = x * y;
	cout << "Coefficient2 of the equation: " << c << endl;
	cin.get();
	return 0;

}

