// Дана сторона квадрата a. Найти его площадь S = a2
#include <iostream>
int main() {
	int a, b, S;
	b = 2;
	std::cout << "Enter the side of the square: ";
	std::cin >> a;
	std::cout << "S = " << pow(a, b) << std::endl;
	std:: cin.get();
	return 0;

}
// S=a*a;