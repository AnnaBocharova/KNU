#include<iostream>
#include "LibIf.h"
using namespace std;
int findMax(int x, int y) {
	if (x >= y)
		return x;
	else
		return y;
}
int findMin(int x, int y) {
	if (x <= y)
		return x;
	else
		return y;

}
int notEqual(int x, int y) {
	if (x != y)
		return x;
	else
		return y;
}
/*1.Дано целое число. Если оно является положительным, то прибавить к не-
му 1; если отрицательным, то вычесть из него 2; если нулевым, то заме-
нить его на 10. Вывести полученное число.
*/
void if3() {
	int i;
	cin >> i;
	if (i > 0)
		i++;
	if (i < 00)
		i -= 2;
	if (i == 0)
		i = 10;
	cout << "new number=" << i << endl;
}
/*2.Даны три целых числа. Найти количество положительных и количество от-
рицательных чисел в исходном наборе.
*/
void if5() {
	int a, b, c;
	int positive = 0, negative = 0;
	cin >> a >> b >> c;
	if (a > 0)
		positive++;
	if (a < 0)
		negative++;
	if (b > 0)
		positive++;
	if (b < 0)
		negative++;
	if (c > 0)
		positive++;
	if (c < 0)
		negative++;
	if (a == 0 && b == 0 && c == 0)
		cout << "zero numbers" << endl;
	cout << "count of positive=" << positive << endl;;
	cout << "count of negative=" << negative << endl;
}

/*3. Даны два числа. Вывести порядковый номер меньшего из них.
*/
void if7() {
	int a, b;
	cin >> a >> b;
	int array[] = { a, b };
	int min = a;
	if (a > b)
		min = b;
	for (int i = 0; i < 2; i++) {
		if (array[i] == min)
			cout << "index" << i;
	}

}
/*4.Даны две переменные вещественного типа: A, B. Перераспределить значе-
ния данных переменных так, чтобы в A оказалось меньшее из значений,
а в B — большее. Вывести новые значения переменных A и B.
*/
void if9() {
	float a, b;
	cin >> a >> b;
	if (a >= b) {
		a = a - b;
		b = a + b;
		a = b - a;
	}
	cout << "a=" << a << endl << "b=" << b << endl;
}

/*5.Даны две переменные целого типа: A и B. Если их значения не равны, то
присвоить каждой переменной сумму этих значений, а если равны, то при-
своить переменным нулевые значения. Вывести новые значения перемен-
ных A и B.
*/
void if10() {
	int a, b;
	cin >> a >> b;
	if (a != b)
		a = b = a + b;
	else
		a = b = 0;

	cout << a << endl << b << endl;
}
/* 6.Даны три числа. Найти среднее из них (то есть число, расположенное ме-
жду наименьшим и наибольшим).
*/
void if13() {
	int a, b, c;
	cin >> a >> b >> c;
	int min = findMin(c, findMin(a, b));
	int max = findMax(c, findMax(a, b));
	if (min < a && a < max)
		cout << "midle=" << a << endl;
	else if (min < b && b < max)
		cout << "midle=" << b << endl;
	else
		cout << "midle=" << c << endl;
}
/*7.Даны три числа. Найти сумму двух наибольших из них.
*/
void if15() {
	int a, b, c, sum;
	cin >> a >> b >> c;
	if (a >= b && c >= b)
		sum = a + c;
	else if (a >= c && b >= c)
		sum = a + b;
	else
		sum = b + c;
	cout << "sum=" << sum << endl;




}
/*8.Даны три переменные вещественного типа: A, B, C. Если их значения упо-
рядочены по возрастанию или убыванию, то удвоить их; в противном слу-
чае заменить значение каждой переменной на противоположное. Вывести
новые значения переменных A, B, C.
*/
void if17() {
	float a, b, c;
	cin >> a >> b >> c;
	if (a<b && b<c || a>b && b>c) {
		a *= 2;
		b *= 2;
		c *= 2;
	}
	else {
		a = -a;
		b = -b;
		c = -c;
	}
	cout << a << "," << b << "," << c << endl;

}
/*9.Даны четыре целых числа, одно из которых отлично от трех других, рав-
ных между собой. Определить порядковый номер числа, отличного от ос-
тальных.
*/
void if19() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b == c && c == d)
		cout << "number " << 1;
	if (c == a && c == d)
		cout << "number " << 2;
	if (b == a && a == d)
		cout << "number " << 3;
	if (b == c && c == a)
		cout << "number " << 4;

}
/* 10.Даны целочисленные координаты точки на плоскости. Если точка совпа-
дает с началом координат, то вывести 0. Если точка не совпадает с началом
координат, но лежит на оси OX или OY, то вывести соответственно 1 или 2.
Если точка не лежит на координатных осях, то вывести 3.
*/
void if21() {
	int x, y;
	cin >> x >> y;
	if (x == 0 && y == 0)
		cout << 0 << endl;
	else if (x == 0)
		cout << 1 << endl;
	else if (y == 0)
		cout << 2 << endl;
	else
		cout << 3 << endl;

}
/*11. Даны целочисленные координаты трех вершин прямоугольника, стороны
которого параллельны координатным осям. Найти координаты его четвер-
той вершины.
*/
void if23() {
	int x1, x2, x3, y1, y2, y3;
	cout << "Koordinati 1:";
	cin >> x1 >> y1;
	cout << "Koordinati 2:";
	cin >> x2 >> y2;
	cout << "Koordinati 3:";
	cin >> x3 >> y3;
	if (x1 == x2)
		cout << x3 << endl;
	else if (x1 == x3)
		cout << x2 << endl;
	else
		cout << x1 << endl;


	if (y1 == y2)
		cout << y3 << endl;
	else if (y1 == y3)
		cout << y2 << endl;
	else
		cout << y1 << endl;
}
/*12.Для данного вещественного x найти значение следующей функции f, при-
нимающей вещественные значения:
			 2·sin(x), если x > 0,
f(x) =
			6 – x, если x ≤ 0.
*/
void if24() {
	float x;
	cin >> x;
	if (x > 0)
		cout << "f(x)=" << 2 * sin(x) << endl;
	else
		cout << "f(x)=" << 6 - x << endl;



}
/*13.Для данного вещественного x найти значение следующей функции f,
принимающей значения целого типа:
			 0, если x < 0,
f(x) =
			  1, если x принадлежит [0, 1), [2, 3), ... ,
			   –1, если x принадлежит [1, 2), [3, 4), ... .
*/
void if27() {
	float x;
	cin >> x;
	if (x < 0)
		cout << 0 << endl;
	else if ((int)x % 2 == 0)
		cout << 1 << endl;
	else
		cout << -1 << endl;


}
/*14.Дан номер года (положительное целое число). Определить количество
дней в этом году, учитывая, что обычный год насчитывает 365 дней, а ви-
сокосный — 366 дней. Високосным считается год, делящийся на 4, за ис-
ключением тех годов, которые делятся на 100 и не делятся на 400 (напри-
мер, годы 300, 1300 и 1900 не являются високосными, а 1200 и 2000 — яв-
ляются).
*/
void if28() {
	int x;
	cin >> x;
	if (x == 1200 || x == 2000 || (x % 4 == 0 && x % 100 != 0 && x % 400 != 0))
		cout << "366 day of year" << endl;
	else
		cout << "365 day of year" << endl;

}
/*Дано целое число. Вывести его строку-описание вида «отрицательное чет-
ное число», «нулевое число», «положительное нечетное число» и т. д.
*/
void if29() {
	setlocale(LC_ALL, "Russian");
	int x;
	cin >> x;
	if (x == 0)
		cout << "нулевое число" << endl;
	else if (x < 0 && x % 2 == 0)
		cout << "отрицательное четное" << endl;
	else if (x < 0 && x % 2 != 0)
		cout << "отрицательное нечетное" << endl;
	else if (x > 0 && x % 2 == 0)
		cout << "положительное четное" << endl;
	else
		cout << "положительное нечетное" << endl;



}