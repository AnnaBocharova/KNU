#include <iostream>
#include <conio.h>
using namespace std;
void rectangle() {
	setlocale(LC_ALL, "rus"); 
	int line, symbol;
	cout << "Количество строк:";
	cin >> line;
	cout << "Количество символов в одной сроке:";
	cin >> symbol;
	for (int i = 0; i <= line; i++) {
		if (i == 0 || i == line) {
			for(int l=0; l<=symbol; l++)
				cout << "*";
		}
		else {
			cout << "*";
			for (int k = 0; k <= symbol - 2; k++)
			{
				cout << " ";
			}
			cout << "*";
		}
		cout << endl;
	}


}
void rightTriangle() {
	setlocale(LC_ALL, "rus");
	int line;
	cout << "Количество строк и символов:";
	cin >> line;
	cout << "*" << endl;
	cout << "**" << endl;
	for (int i = 0; i <= line - 4; i++) {
		cout << "*";
		for (int k = 0; k <= i; k++) {
			cout << " ";
		}
		cout << "*";
		cout << "\n";
	}
	for (int s = 1; s <= line; s++) {
		cout << "*";
	}

}
void equilateralTriangle() {
	int line;
	cin >> line;
	
		for (int i = line; i > 0; i--) {
			for (int k = 0; k < i; k++)
				cout << " ";
			cout << "*";
			cout << "\n";

		}
		for (int i = line; i < 2 * line; i++) {
			if (i == 2 * line - 1) {
				for (int l = 0; l <= line - 3; l++)
					cout << "*";
			}
			else {

				for (int k = 0; k < i; k++)
					cout << " ";
				cout << "*";

			}
			cout << "\n";
		}
	

	
}
void empty(int x) {
	for (int i = 0; i < x; i++) 
		cout << " ";
	
}

void romb() {
		
	for (int i = 8; i > 0; i--) {
		empty(i);
		cout << "*";
		empty((8 - i) * 2);
		cout << "*" << endl;
	}
	for (int i = 0; i <=8; i++) {
		empty(i);
		cout << "*";
		empty((8- i) * 2);
		cout << "*" << endl;
	}

}
int menu();

int main() {
	setlocale(LC_ALL, "Russian");
	int answer = menu();
	switch (answer)
	{
	case 0: rectangle(); break;
	case 1: rightTriangle(); break;
	case 2: equilateralTriangle(); break;
	case 3: romb(); return 0;
	}
	
	return 0;
	
}
int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> прямоугольник" << endl;
		else  cout << "    прямоугольник" << endl;
		if (key == 1) cout << "-> прямоугольнный треугльник" << endl;
		else  cout << "   прямоугольный треугольник" << endl;
		if (key == 2) cout << "-> равносторонний треугольник" << endl;
		else  cout << "   равносторонний треугольник" << endl;
		if (key == 3) cout << "-> ромб" << endl;
		else  cout << "   ромб" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
