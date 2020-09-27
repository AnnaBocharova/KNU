// Найти корни квадратного уравнения A·x2 + B·x + C = 0, заданного своими коэффициентами A, B, C (коэффициент A не равен 0), если извест но, что дискриминант уравнения положителен. Вывести вначале меньший,  а затем больший из найденных корней. Корни квадратного уравнения на ходятся по формуле x1,2 = ( )/ − ± B D (2·A), где D — дискриминант, рав ный B2 – 4·A·C.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, b, c, D;
	float x1, x2;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	D =pow(b,2)- 4*a*c;
	x1 = (-b + sqrt(D)) / (2*a);
	x2 = (-b - sqrt(D)) / (2*a);
		if (x1 > x2) {
			cout << "x2=" << x2;
			cout << "x1=" << x1;
				}
		else {
			cout << "x1=" << x1<<endl;
			cout << "x2=" << x2<<endl;
		}
		cin.get();
		return 0;

}
