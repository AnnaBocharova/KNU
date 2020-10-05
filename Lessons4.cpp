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
	//Даны 5 чисел (тип int). Вывести вначале наименьшее, а затем наибольшее из данных чисел.
	int a1, b1, c1, d1, l1, min=0, max=0;
	cout << "Enter a1:";
	cin >> a1;
	cout << "Enter b1:";
	cin >> b1;
	cout << "Enter c1:";
	cin >> c1;
	cout << "Enter d1:";
	cin >> d1;
	cout << "Enter l1" << endl;
	cin >> l1;
	if (a1 < b1 && a1 < c1 && a1 < d1 ||  a1<l1)
		min = a1;
	else if (b1 < a1 && b1 < c1 && b1 < d1 && b1<l1)
		min = b1;
	else if (c1 < a1 && c1 < b1 && c1 < d1 && c<l1)
		min = c1;
	else if (d1 < a1 && d1 < c1 && d1 < b1 && d1<l1)
		min = d1;
	else if (l1 < a1 && l1 < c1 && l1 < b1 && l1<c1)

	cout << "Minimum:" << min;
	if (a1 > b1 && a1 > c1 && a1 > d1 || a1 > l1)
		max = a1;
	else if (b1 > a1 && b1 > c1 && b1 > d1 && b1 > l1)
		max = b1;
	else if (c1 > a1 && c1 > b1 && c1 > d1 && c > l1)
		max = c1;
	else if (d1 > a1 && d1 > c1 && d1 > b1 && d1 > l1)
		max = d1;
	else if (l1 > a1 && l1 > c1 && l1 > b1 && l1 > c1)

		cout << "Maximum:" << max;
	// Дано число месяца (тип int). Необходимо определить время года (зима, весна, лето, осень) и вывести на консоль.
	cout << "Enter number 1-12 ";
	int N;
	cin >> N;
	switch (N) {
	case 1: cout << "Winter"; break;
	case 2: cout << "Winter"; break;
	case 3: cout << "Winter"; break;
	case 4: cout << "Spring"; break;
	case 5: cout << "Spring"; break;
	case 6: cout << "Spring"; break;
	
	
	}

		

	cin.get();
	return 0;

}