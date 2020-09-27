// Дано число A. Вычислить A15, используя две вспомогательные пере менные и пять операций умножения. Для этого последовательно находить A2, A3, A5, A10, A15. Вывести все найденные степени числа A.  
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int var1, var2, A;
	cout << "A=";
	cin >> A;
	var1 = A * A;
	cout << "A^2=" << var1 << endl;
	var2 = var1 * A;
	cout << "A^3=" << var2 << endl;
	var1 = var1 * var2;
	cout << "A^5=" << var1<<endl;
	var1 = var1 * var1;
	cout << "A^10=" << var1<<endl;
	var2 = var2 * var1;
	cout << "A^15=" << var2 << endl;
	cin.get();
	return 0;

}
