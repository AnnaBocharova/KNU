#include<iostream>
#include<cmath>
#include "Task6.h"
#include "LibFor.h"
using namespace std;
void for3() {
	int a, b;
	cin >> a >> b;
	for (int i = b - 1; i >= a; i--) {
		cout << i << ",";
	}
	cout << "Count of number: " << b - a << endl;
}
void for9() {
	int a, b, sum = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		sum += pow(i, 2);

	}
	cout << "Summ of number^2=" << sum;
}
void for10() {
	int n;
	double sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += (double)1 / i;

	}
	cout << "Sum=" << sum << endl;
}
void for14() {
	setlocale(LC_ALL, "rus");
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= (2 * n - 1); i += 2) {
		sum += i;
		cout << sum << endl;
	}
}
void for18() {
	float a, n, sum = 0;
	cout << "Enter A:";
	cin >> a;
	cout << "Enter N:";
	cin >> n;
	for (int i = 0; i <= n; i++) {
		sum += pow(-1, i) * pow(a, i);
	}
	cout << sum << endl;

}
void for24() {
	float x;
	cout << "Enter X:";
	cin >> x;
	int n;
	cout << "Enter N:";
	cin >> n;
	int znak = -1;
	float factorial = 1, sum = 1;
	for (int i = 0; i <= n; i++) {
		factorial *= (i + 1);
		if (i % 2 == 0) {
			znak = (-znak);
			sum += (znak * pow(x, 2 * i)) / factorial;
		}
	}
	cout << sum;
}
void for38() {
	int n;
	float sum = 0;
	int z = 0;
	cin >> n;
	for (int i = n; i >= 1; i--) {
		z++;
		for (z; z <= n;) {
			sum += (float)pow(z, i);
			break;
		}
	}
	cout << sum;


}
