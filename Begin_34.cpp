//Известно, что X кг шоколадных конфет стоит A рублей, а Y кг ирисок стоит B рублей. Определить, сколько стоит 1 кг шоколадных конфет, 1 кг ирисок, а также во сколько раз шоколадные конфеты дороже ирисок.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	float x, a, y, b;
	cout << "Kilograms x of chocolates=";
	cin >>x;
	cout << "Price of chocolates:";
	cin >> a;
	cout << "Kilograms y of iricki:";
	cin >> y;
	cout << "Price b of iricki:";
	cin >> b;
	cout << "1 kilogram of chocolates=" << a / x << endl;
	cout << "1 kilogram of iricki=" << b / y << endl;
	cout << "Chocolates are so many times more expensive than iricki:" << (a / x) / (b/ y) << endl;
	cin.get();
	return 0;

		
}