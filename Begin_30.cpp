// Дано значение угла α в радианах (0 < α < 2·π). Определить значение этого же угла в градусах, учитывая, что 180° = π радианов. В качестве зна чения π использовать 3.14.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int  a;
	const float π = 3.14;
	cout << "a=";
	cin >> a;
	if (a > 0 && a < 6.28) {
		cout << "a=" << a / (π / 180)<< endl;
	}
	else
		cout << "Wrong angle value! 0<a<6.28";
	cin.get();
	return 0;
}
