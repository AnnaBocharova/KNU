#include <iostream>
#include<cmath>

using namespace std;
void enter(float& x1, float& y1, float& x2, float& y2, float& x3, float& y3)
{
	cout << "Enter the coordinates of the vertices1 of the triangle x1 and y1:" << endl;
	cin >> x1 >> y1;
	cout << "Enter the coordinates of the vertices2 of the triangle x2 and y2:" << endl;
	cin >> x2 >> y2;
	cout << "Enter the coordinates of the vertices3 of the triangle x3 and y3:" << endl;
	cin >> x3 >> y3;
}



float check(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y) {
	float sign1 = ((x - x1) * (y2 - y1)) - ((y - y1) * (x2 - x1));
	float sign2 = ((x3 - x1) * (y2 - y1)) - ((y3 - y1) * (x2 - x1));
	float lenght1 = sqrt((pow(x1 - x, 2)) + (pow(y1 - y, 2)));
	float lenght2 = sqrt((pow(x2 - x, 2)) + (pow(y2 - y, 2)));
	float lenght3 = sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2)));
	float distance = lenght1 + lenght2;

	if (sign1 * sign2 > 0)
		return 0;
	else if (sign2 == 0)
		cout << "Error! There is no triangle! The points lie on one line." << endl;
	else if (sign1 == 0 && distance <= lenght3)
		return 1;
	else
		return 2;
}

int main() {
	/*Задаються три пари чисел, які задають трикутник на площині.Крім
		того, задається ще одна -1
		пара чисел, яка задає точку на площині.Визначити, чи
		лежить точка усередині трикутника, чи на одному з його ребер, чи зовні.*/

	float x1, y1, x2, y2, x3, y3, x, y;
	enter(x1, y1, x2, y2, x3, y3);
	cout << "Enter the coordinates of the point x and y" << endl;
	cin >> x >> y;


	int check1, check2, check3;
	check1 = check(x1, y1, x2, y2, x3, y3, x, y);
	check2 = check(x1, y1, x3, y3, x2, y2, x, y);
	check3 = check(x2, y2, x3, y3, x1, y1, x, y);
	check(x1, y1, x2, y2, x3, y3, x, y);
	if (check1 == 0 && check2 == 0 && check3 == 0)
		cout << "The point lies inside the triangle" << endl;
	else if ( check1==1 || check2 == 1 || check3 == 1)
		cout << "The point lies on the edge of the triangle." << endl;

	else
		cout << "The point lies outside the triangle" << endl;

	return 0;
}

