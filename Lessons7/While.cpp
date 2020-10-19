#include<iostream>
#include<cmath>
#include "Task6.h"
#include "LibFor.h"
using namespace std;


void while6() {
	int n;
	cin >> n;
	float res = n;
	while (n > 1) {
		if (n >= 1) {
			n -= 2;
			res *= n;
		}
	}
	cout << res;
}
void while9() {
	int n;
	cin >> n;
	int k = 1;
	int numstep = 0, count = 0;

	while (numstep <= n) {
		numstep = pow(3, k);
		k++;
	}
	cout << k - 1;
}
void while13() {
	int a;
	cin >> a;
	int k = 0;
	float sum = 0;
	while (true) {
		k++;
		sum += (float)1 / k;
		if (sum > a) {
			cout << "Sum=" << sum << endl;
			cout << "k=" << k << endl;
			break;
		}

	}

}
void while19() {
	int n;
	cin >> n;
	int back = 0;
	while (n > 0) {
		int ostatok = n % 10;
		back = back * 10 + ostatok;
		n /= 10;
		cout << back << endl;
	}


}
void while23() {
	int a, b;
	cin >> a >> b;
	while (a != 0 && b != 0) {
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	cout << a + b;
}
void while24() {
	int n;
	cin >> n;
	int f1 = 1, f2 = 1, f = 0;
	while (f < n) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;

	}
	if (n == f)
		cout << "true" << endl;
	else
		cout << "false";
}
void while27() {
	int n;
	cin >> n;
	int f1 = 0, f2 = 1, f = 0, k = 2;
	while (f < n) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		k++;
	}
	if (n == f)
		cout << "count" << k << endl;
	else
		cout << "it`s not fibonachi" << endl;
}

