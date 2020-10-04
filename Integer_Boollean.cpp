#include<iostream>
using namespace std;
void sign() {
	cout << "=============================================================" << endl;
}
void num_11() {
	//Дано трехзначное число. Найти сумму и произведение его цифр
	cout << "Integer11" << endl;
		int a;
		cout << "Enter a number:";
		cin >> a;

	cout << "Sum="<< a / 100 + a / 10 % 10 + a % 10 << endl;
	cout << "Product=" << (a / 100) * (a / 10 % 10) * (a % 10) << endl;

}
void num_12() {
	//Дано трехзначное число. Вывести число, полученное при прочтении исходного числа справа налево.
	cout << "Integer12" << endl;
	int a;
	cout << "Enter a number:";
	cin >> a;
	cout << "Reverse number:" << ((a % 10) * 100) + ((a/10 % 10) * 10) + (a / 100);
}
void num_13() {
	// Дано трехзначное число. В нем зачеркнули первую слева цифру и приписали ее справа. Вывести полученное число.
	cout << "Integer13" << endl;
	int a;
	cout << "Enter a number:";
	cin >> a;
	cout << "Reverse number:" << ((a / 10 % 10) * 100) + a / 100 * 10 + a % 10 << endl;
}
void num_16() {
	//Дано трехзначное число. Вывести число, полученное при перестановке цифр десятков и единиц исходного числа(например, 123 перейдет в 132).
	cout << "Integer16" << endl;
	int a;
	cout << "Enter a number:";
	cin >> a;
	cout << "Reverse number:" << (a/100*100)+(a%10*10)+a/10%10 << endl;

}
void num_17() {
	//Дано целое число, большее 999. Используя одну операцию деления нацело и одну операцию взятия остатка от деления, найти цифру, соответствующую разряду сотен в записи этого числа.
	cout << "Integer17" << endl;
	int a;
	cout << "Enter a number over 999:";
	cin >> a;
	cout << "Number of hunders:" << a / 100 % 10;
}
void num_20(){
	// С начала суток прошло N секунд (N — целое). Найти количество полных часов, прошедших с начала суток.
	cout << "Integer20" << endl;
	int N;
cout << "Enter seconds:";
cin >> N;
cout << "Full hours:" << N / 60 / 60;


}
void num_22() {
	//С начала суток прошло N секунд (N — целое). Найти количество секунд, прошедших с начала последнего часа.
	cout << "Integer22" << endl;
	int N;
	cout << "Enter seconds: ";
	cin >> N;
	cout << "Seconds since the last hour:" << N % (60 * 60);

}
void num_24() {
	//Дни недели пронумерованы следующим образом: 0 — воскресенье,	1 — понедельник, 2 — вторник, ..., 6 — суббота.Дано целое число K, ле -жащее в диапазоне 1–365.Определить номер дня недели для K - го дня года,если известно, что в этом году 1 января было понедельником.
	cout << "Integer24" << endl;
	int K;
	cout << "Enter the daae (1-365)";
	cin >> K;
	cout << "Day of week" << K % 7;
}
void num_27() {
	//Дни недели пронумерованы следующим образом: 1 — понедельник,	2 — вторник, ..., 6 — суббота, 7 — воскресенье.Дано целое число K, лежащее в диапазоне 1–365.Определить номер дня недели для K - го дня года,если известно, что в этом году 1 января было субботой.
	cout << "Integer27" << endl;
	int K;
	cout << "Enter the daae (1-365)";
	cin >> K;
	cout << "Day of week" << (K+4)%7+1;
}
void num_28() {
	//Дни недели пронумерованы следующим образом: 1 — понедельник,	2 — вторник, ..., 6 — суббота, 7 — воскресенье.Дано целое число K, лежащее в диапазоне 1–365, и целое число N, лежащее в диапазоне 1–7.Оп -ределить номер дня недели для K - го дня года, если известно, что в этомгоду 1 января было днем недели с номером N.
	cout << "Integer28" << endl;
	int K, N;
	cout << "Enter the daae (1-365)";
	cin >> K;
	cout << "Day of week (1 january):";
	cin >> N;
	cout << "Day of week" << (K + N -2) % 7 + 1<<endl;

}
void num_29(){
	//Даны целые положительные числа A, B, C. На прямоугольнике раз	мера A × B размещено максимально возможное количество квадратов со стороной C(без наложений).Найти количество квадратов, размещенных на прямоугольнике, а также площадь незанятой части прямоугольника.
	cout << "Integer29";
	int A, B, C, N;
	cout << "Enter side1 of the rectangle:";
	cin >> A;
	cout << "Enter side2 of the rectangle:";
	cin >> B;
	cout << "Enter side of the square:";
	cin >> C;
	N = (A / C) * (B / C);
	cout << "Number of squares in a rectangle:" << N<<endl;
	cout << "Unoccupied area of the rectangle:" << (A * B) - (N * pow(C, 2))<<endl;
	}
void num_30() {
	//Дан номер некоторого года (целое положительное число). Определить соответствующий ему номер столетия, учитывая, что, к примеру, на -чалом 20 столетия был 1901 год.
	cout << "Integer30" << endl;
	int year;
	cout << "Enter year:";
	cin >> year;
	cout << "Century:" << (year / 100) + 1 << endl;

}
void bool_1() {
	//Дано целое число A. Проверить истинность высказывания: «Число A является положительным».
	cout << "Boolean1" << endl;
	int A;
	cout << "Enter number:";
	cin >> A;
	bool iscorrect = A>0;
	cout << "The number is positive " << iscorrect<< endl;
	}
void bool_2() {
	//Дано целое число A. Проверить истинность высказывания: «Число A является нечетным».
	cout << "Boolean2" << endl;
	int A;
	cout << "Enter number";
	cin >> A;
	bool istrue = A % 2 != 0;
	cout << "Odd number? " << istrue << endl;
}
void bool_5() {
	//Даны два целых числа: A, B. Проверить истинность высказывания:«Справедливы неравенства A ≥ 0 или B < –2».
	cout << "Boolean_5" << endl;
	int A, B;
	cout << "Enter number1:";
	cin >> A;
	cout << "Enter number2:";
	cin >> B;
	bool istrue = A >= 0 || B < -2;
	cout << istrue;

}
void bool_7() {
	//Даны три целых числа: A, B, C. Проверить истинность высказывания: «Число B находится между числами A и C».
	cout << "Boolean7" << endl;
	int a, b, c;
	cout << "Enter number1:";
	cin >> a;
	cout << "Enter number2:";
	cin >> b;
	cout << "Enter number3:";
	cin >> c;
	bool istrue =( a < b && b < c )|| (c < b  && b< a);
	cout << istrue << endl;

}
void bool_9() {
	//Даны два целых числа: A, B. Проверить истинность высказывания:«Хотя бы одно из чисел A и B нечетное».
	cout << "Boolean9" << endl;
	int a, b;
	cout << "Enter number1:";
	cin >> a;
	cout << "Enter number2:";
	cin >> b;
	bool istrue = (a%2!=0 || b%2!=0);
	cout <<"At least on of the numbers is odd:"<< istrue << endl;
}
void bool_10() {
	//Даны два целых числа: A, B. Проверить истинность высказывания:«Ровно одно из чисел A и B нечетное».
	cout << "Boolean10" << endl;
	int a, b;
	cout << "Enter number1:";
	cin >> a;
	cout << "Enter number2:";
	cin >> b;
	bool istrue = (( b%2==0 && a % 2 != 0)||(b%2!=0 && a%2==0 ));
	cout << "Exactly on of the numbers is odd:" << istrue << endl;
}
void bool_12() {
	//Даны три целых числа: A, B, C. Проверить истинность высказывания: «Каждое из чисел A, B, C положительное».
	cout << "Boolean12" << endl;
	int a, b, c;
	cout << "Enter number1:";
	cin >> a;
	cout << "Enter number2:";
	cin >> b;
	cout << "Enter number3:";
	cin >> c;
	bool istrue = a>0 && b>0 && c>0;
	cout <<"All numbers are positive:"<< istrue << endl;

}
void bool_13() {
	//Даны три целых числа: A, B, C. Проверить истинность высказывания: «Хотя бы одно из чисел A, B, C положительное».
	cout << "Boolean13" << endl;
	int a, b, c;
	cout << "Enter number1:";
	cin >> a;
	cout << "Enter number2:";
	cin >> b;
	cout << "Enter number3:";
	cin >> c;
	bool istrue = a > 0 || b > 0 || c > 0;
	cout << "At least one number is positive:" << istrue << endl;
}
void bool_16() {
	//Дано целое положительное число. Проверить истинность высказывания: «Данное число является четным двузначным».
	cout << "Boolean16" << endl;
	int A;
	cout << "Enter number";
	cin >> A;
	bool istrue = A / 10 != 0 && A / 100 == 0 && A % 2 == 0;
	cout << "Two-digit multiple number" << istrue << endl;


}
void bool_19() {
	//Проверить истинность высказывания: «Среди трех данных целых чисел есть хотя бы одна пара взаимно противоположных».
	cout << "Boolean119" << endl;
	int a, b, c;
	cout << "Enter number1:";
	cin >> a;
	cout << "Enter number2:";
	cin >> b;
	cout << "Enter number3:";
	cin >> c;
	bool istrue = a == (-1) * b || b == (-1) * c || a == (-1) * c;
	cout << "At least one pair of mutually opposite:" << istrue << endl;

}
void bool_20() {
	//Дано трехзначное число. Проверить истинность высказывания:«Все цифры данного числа различны».
	cout << "Bollean20" << endl;
	cout << "Enter number:";
	int a;
	cin >> a;
	bool istrue = (a / 100) != ((a / 10) % 10) && (a / 100) != (a % 10) && ((a / 10) % 10) != (a % 10);
	cout << "All digits of this number are different:" << istrue << endl;
}
void bool_22() {
	//Дано трехзначное число. Проверить истинность высказывания:«Цифры данного числа образуют возрастающую или убывающую после -довательность».
	cout << "Boolean22" << endl;
	cout << "Enter number:";
	int a;
	cin >> a;
	bool istrue = (a / 100 > a / 10 % 10 && a / 10 % 10 > a % 10) || (a / 100 < a / 10 % 10 && a / 10 % 10 < a % 10);
		cout << "The digits of a given number form an increasing or decreasing sequence: " << istrue << endl;
}
void bool_23() {
	//Дано четырехзначное число. Проверить истинность высказывания:«Дано четырехзначное число. Проверить истинность высказывания:«Данное число читается одинаково слева направо и справа налево».».
	cout << "Boolean23" << endl;
	cout << "Enter number:";
	int a;
	cin >> a;
	bool istrue = a / 1000 == a % 10 && a /100 % 10 == a % 100 / 10;
	cout << "This number is read equally from left to right and from right to left:" << istrue << endl;
}
void bool_26() {
	//Даны числа x, y. Проверить истинность высказывания: «Точка с координатами(x, y) лежит в четвертой координатной четверти».
	cout << "Boolean26" << endl;
	int x, y;
	cout << "Enter x:";
	cin >> x;
	cout << "Enter y";
	cin >> y;
	bool istrue = x > 0 && y < 0;
	cout << "The point with coordinates (x, y) lies in the fourth coordinate quarter: " << istrue << endl;
}
void bool_28() {
	//Даны числа x, y. Проверить истинность высказывания: «Точка с координатами(x, y) лежит в первой или третьей координатной четверти».
	cout << "Boolean28" << endl;
	int x, y;
	cout << "Enter x:";
	cin >> x;
	cout << "Enter y";
	cin >> y;
	bool istrue = (x>0 && y>0)|| (x<0 && y<0);
	cout << "Point with coordinates (x, y) lies in the first or third coordinate quarter:" << istrue << endl;
}
void bool_29() {
	//Даны числа x, y, x1, y1, x2, y2. Проверить истинность высказывания:«Точка с координатами(x, y) лежит внутри прямоугольника, левая верхняявершина которого имеет координаты(x1, y1), правая нижняя —(x2, y2),а стороны параллельны координатным осям».
	cout << "Boolean29" << endl;
	int x, y, x1, y1, x2, y2;
	cout << "Enter x:";
	cin >> x;
	cout << "Enter y:";
	cin >> y;
	cout << "Enter x1:";
	cin >> x1;
	cout << "Enter x2:";
	cin >> x2;
	cout << "Enter y1:";
	cin >> y1;
	cout << "Enter y2:";
	cin >> y2;
	bool istrue = (x1 < x&& x < x2) && (y2 < y&& y < y1);
	cout << "Point with coordinates (x, y) lies inside the rectangle: " << istrue << endl;


}
void bool_32() {
	//Даны целые числа a, b, c, являющиеся сторонами некоторого тре-угольника.Проверить истинность высказывания : «Треугольник со сторо -нами a, b, c является прямоугольным».
	cout << "Bollean32" <<endl;
	int a, b, c;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	bool istrue = pow(a, 2)== pow(b, 2) + pow(c, 2) || pow(b, 2) == pow(a, 2) + pow(c, 2) || pow(c, 2) == pow(b, 2) + pow(a, 2);
	cout << "Rectangular triangle:" << istrue << endl;
}
void bool_33() {
	//Даны целые числа a, b, c. Проверить истинность высказывания:«Существует треугольник со сторонами a, b, c».
	cout << "Bollean33" << endl;
	int a, b, c;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	bool istrue = a + b > c && b + c > a && c + a > b;
	cout << "There is a triangle with sides a, b, c: " << istrue << endl;
}
void bool_35() {
	//Даны координаты двух различных полей шахматной доски x1, y1,x2, y2(целые числа, лежащие в диапазоне 1–8).Проверить истинность вы -сказывания: «Данные поля имеют одинаковый цвет».
	cout << "Boolean_35" << endl;
	int x1, y1, x2, y2;
	cout << "Enter x1:";
	cin >> x1;
	cout << "Enter x2:";
	cin >> x2;
	cout << "Enter y1:";
	cin >> y1;
	cout << "Enter y2:";
	cin >> y2;
	bool istrue = ((y1 % 2 == 0 && x1 % 2 != 0) && (y2 % 2 == 0 && x2 % 2 != 0)) || ((y1 % 2 == 0 && x1 % 2 != 0) && (y2 % 2 != 0 && x2 % 2 == 0)) || ((y1 % 2 != 0 && x1 % 2 == 0) && (y2 % 2 == 0 && x2 % 2 != 0)) || ((y1 % 2 != 0 && x1 % 2 == 0) && (y2 % 2 != 0 && x2 % 2 == 0));
	cout << "These fields have the same color:" << istrue << endl;


}
int main() {
	
	num_11();
	sign();
	num_12();
	sign();
	num_13();
	sign();
	num_16();
	sign();
	num_17();
	sign();
	num_20();
	sign();
	num_22();
	sign();
	num_24();
	sign();
	num_27();
	sign();
	num_28();
	sign();
	num_29();
	sign();
	num_30();
	sign();
	bool_1();
	sign();
	bool_2();
	sign();
	bool_5();
	sign();
	bool_7();
	sign();
	bool_9();
	sign();
	bool_10();
	sign();
	bool_12();
	sign();
	bool_13();
	sign();
	bool_16();
	sign();
	bool_19();
	sign();
	bool_20();
	sign();
	bool_22();
	sign();
	bool_23();
	sign();
	bool_26();
	sign();
	bool_28();
	sign();
	bool_29();
	sign();
	bool_32();
	sign();
	bool_33();
	sign();
	bool_35();
	sign();


	cin.get();
	return 0;
}