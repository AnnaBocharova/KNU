// Begin13. Даны два круга с общим центром и радиусами R1 и R2 (R1 > R2). Найти площади этих кругов S1 и S2, 
//а также площадь S3 кольца, внешний радиус которого равен R1, а внутренний радиус равен R2:  S1 = π·(R1)2, S2 = π·(R2)2, S3 = S1 – S2.В качестве значения π использовать 3.14.
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int R1, R2, b=2;
	float S1, S2, S3;
	const float π = 3.14;
	cout << "Enter a larger radius:";
	cin >> R1;
	cout << "Enter a smaller radius:";
	cin >> R2;
	S1 = π * pow(R1, b);
	S2 = π * pow(R2, b);
	S3 = S1 - S2;
	cout << "S1=" << S1 << endl;
	cout << "S2=" << S2 << endl;
	cout << "S3=" << S3 << endl;
	cin.get();
	return 0;


}