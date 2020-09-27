// Скорость первого автомобиля V1 км/ч, второго — V2 км/ч, расстояние между ними S км. Определить расстояние между 
//ними через T часов, если автомобили удаляются друг от друга. Данное расстояние равно сумме на чального расстояния и 
//общего пути, проделанного автомобилями; общий путь = время · суммарная скорость.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int V1, V2, S, T;
	cout << "Speed1=";
	cin>>V1;
	cout << "Speed2=";
	cin>>V2;
	cout << "Initial distance=";
	cin>>S;
	cout << "Time=";
	cin >> T;
	cout << "Distance=" << (V1 + V2) * T + S << endl;
	cin.get();
	return 0;
}
