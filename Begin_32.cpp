// Дано значение температуры T в градусах Цельсия. Определить значе ние этой же температуры в градусах Фаренгейта. Температура по Цельсию TC и температура по Фаренгейту TF связаны следующим соотношением:  TC = (TF – 32)·5/9.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	float Tc, Tf;
	cout << "Enter the temperature in degrees Celsius:";
	cin >> Tc;
	Tf = (9 * Tc / 5) + 33;
	cout << "Temperature in degrees Fahrenheit=" << Tf << endl;
	cin.get();
	return 0;

}