#include<iostream>
using namespace std;
int main() {
	int a, b, c, d, min=0, max1=0, max2=0, max3=0, max4=0;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	cout << "Enter d:";
	cin >> d;
	if (a < b && a < c && a < d)
		min = a;
	else if (b < a && b < c && b < d)
		min = b;
	else if (c < a && c < b && c < d)
		min = c;
	else if (d < a && d < c && d < b)
		min = d;
	cout << "Minimum:" << min;
	//Вывести на консоль количество максимальных чисел среди этих четырех.
	if (a > b && a >c  && a > d)
		max1 = a;
	else if (b > a && b > c && b > d)
		max2 = b;
	else if (c > a && c > b && c > d)
		max3 = c;
	else if (d > a && d > c && d > b)
		max4 = d;
	if (max1 == max2 || max1 == max3 || max1 == max4 || max2 == max3 || max2 == max4 || max3 == max4)
		cout << "N max 2" << endl;
	else if (max1 == max2 == max3 || max1 == max2 == max4 || max1 == max3 == max4 || max2 == max3 == max4)
		cout << "N max 3" << endl;
	else if (max1 == max2 == max3 == max4)
		cout << "N max 4" << endl;
		

	cin.get();
	return 0;

}