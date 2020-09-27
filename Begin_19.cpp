//Begin19.Даны координаты двух противоположных вершин прямоугольника : (x1, y1), (x2, y2).Стороны прямоугольника параллельны осям координат.Найти периметр и площадь данного прямоугольника
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int x1, y1, x2, y2;
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
	int side1 = abs(x2 - x1);
	int side2 = abs(y1 - y2);
	cout << "Perimetr=" << 2 * (side1 + side2) << endl;
	cout << "Area=" << side1 * side2;
	cin.get();
	return 0;

}