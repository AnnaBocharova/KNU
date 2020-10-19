#include<iostream>
#include<cmath>
#include "Task6.h"
#include "LibFor.h"
#include "LibWhile.h"
#include"Series.h"
#include "Array.h"
using namespace std;
void array6() {
	int a[1000] = {};
	int b, n;
	cin >> b >> n;
	for (int i = 2; i < n; ++i) {
		a[i] = 0;
		int i2;
		for (i2 = 0; i2 < i; ++i2) a[i] += a[i2];
	}
	for (int i = 0; i < n; ++i)
		cout << a[i];
}