#include <iostream>
using namespace std;
int findmin(int x, int y) {
	if (x <= y)
		return x;
	else
		return y;
}
int findmax(int x, int y) {
	if (x >= y)
		return x;
	else
		return y;

}
int main() {
	//1. Даны 4 числа типа int. Сравнить их и вывести наименьшее на консоль. 
	int a, b, c, d;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	cout << "Enter d:";
	cin >> d;
	int min = a;
	int max = b;
	min = findmin(d, findmin(c, findmin(a, b)));
	max = findmax(d, findmax(c, findmax(a, b)));
	cout << "Minimum:" << min << endl;
	//2. Вывести на консоль количество максимальных чисел среди этих четырех.
	int n = 0;
	if (a == max)
		n++;
	if (b == max)
		n++;
	if (c == max)
		n++;
	if (d == max)
		n++;
	cout << "Number max:" << n << endl;
	//Даны 5 чисел (тип int). Вывести вначале наименьшее, а затем наибольшее из данных чисел.
	int a1, b1, c1, d1, f1;
	cout << "Enter a1:";
	cin >> a1;
	cout << "Enter b1:";
	cin >> b1;
	cout << "Enter c1:";
	cin >> c1;
	cout << "Enter d1:";
	cin >> d1;
	cout << "Enter f1:";
	cin >> f1;
	min = findmin(f1, findmin(d1, findmin(c1, findmin(a1, b1))));
	max = findmax(f1, findmax(d1, findmax(c1, findmax(a1, b1)))); \
		cout << "Min=" << min << endl;
	cout << "Max=" << max << endl;
	//Дано число месяца (тип int). Необходимо определить время года (зима, весна, лето, осень) и вывести на консоль.
//через case:
	cout << "Enter month 1-12 ";
	int N;
	cin >> N;
	switch (N) {
	case 12: cout << "Winter"; break;
	case 1: cout << "Winter"; break;
	case 2: cout << "Winter"; break;
	case 3: cout << "Spring"; break;
	case 4: cout << "Spring"; break;
	case 5: cout << "Spring"; break;
	case 6: cout << "Summer"; break;
	case 7: cout << "Summer"; break;
	case 8: cout << "Summer"; break;
	case 9: cout << "Autumn"; break;
	case 10: cout << "Autumn"; break;
	case 11: cout << "Autumn"; break;
	}
// через if
		int N1;
        cout << "Enter month 1-12 ";
		cin >> N1;
		if ((N1<3) || N1==12)
			cout << "Winter" << endl;
		 else if (N1<6)
			cout << "Spring" << endl;
		else if (N1<9)
			cout << "Summer" << endl;
		else if (N1<12)
			cout << "Autumn" << endl;
		cin.get();
		return 0;

	}
