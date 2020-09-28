//Дано расстояние L в сантиметрах. Используя операцию деления нацело, найти количество полных метров в нем(1 метр = 100 см).
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int L, m;
	cout << "Enter distance(cm): ";
	cin >> L;
	m = L / 100;
	cout << "Distance in maters:" << m << endl;
	cin.get();
	return 0;

}