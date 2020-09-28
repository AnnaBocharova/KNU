//Дана масса M в килограммах.Используя операцию деления нацело,найти количество полных тонн в ней(1 тонна = 1000 кг).
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int M, ton;
	cout << "Enter weight(kg): ";
	cin >> M;
	ton = M / 1000;
	cout << "Weight in tons:" << ton << endl;
	cin.get();
	return 0;

}