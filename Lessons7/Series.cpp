#include<iostream>
#include<cmath>
#include "Task6.h"
#include "LibFor.h"
#include "LibWhile.h"
#include"Series.h"
using namespace std;

void series6() {
	int n;
	cin >> n;
	float prod = 1, numfloat;

	for (int i = 1; i <= n; i++)
	{
		cin >> numfloat;
		cout << numfloat - (float)(int)numfloat;
		prod *= numfloat - (float)(int)numfloat;

	}
	cout << "Prod=" << prod << endl;

}
void series15() {
	int k, num = 0;
	cin >> k;
	int numInt = 1;
	while (numInt != 0) {
		cin >> numInt;
		if (numInt > k && num == 0) {
			num = numInt;

		}
	}
	cout << num;

}
void series22() {
	int n;
	cin >> n;
	int i, rez = 0;
	float r = 1, r1;
	r1 = r;
	for (i = 1; i <= n; ++i, r1 = r) {
		cin >> r;
		if ((r1 < r) && (i != 1) && (rez == 0)) rez = i;
	}
	cin >> rez;

}