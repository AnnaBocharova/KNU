//Даны переменные A, B, C. Изменить их значения, переместив содер жимое A в B, B — в C, C — в A, и вывести новые значения переменных A,  B, C.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int A, B, C;
	//через "пустую" переменную;
	//int emp;
	cout << "A=";
	cin >> A;
	cout << "B=";
	cin >> B;
	cout << "C=";
	cin >> C;
	//emp = B;
	//B = A;
	//A = C;
	//C = emp;
	A = A + B + C;
	B = A - B - C;
	C = A - B - C;
	A = A - B - C;
	cout << "B="<<B<<endl;
	cout << "C=" << C<<endl;
	cout << "A="<< A<<endl;

	cin.get();
	return 0;
}

