// Найти расстояние между двумя точками с заданными координатами (x1, y1) и (x2, y2) на плоскости.
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int x1, y1, x2, y2, b = 2;
	float d;
	cout << "Enter the coordinates of the vertex1:";
	cout << "x1=";
	cin >> x1;
	cout << "y1=";
	cin >> y1;
	cout << "Enter the coordinates of the vertex2:";
	cout << "x2=";
	cin >> x2;
	cout << "y2=";
	cin >> y2;
	d = sqrt(pow((x2 - x1), b) + pow((y2 - y1), b));
	cout << "Distance=" << d << endl;
	cin.get();
	return 0;
}
