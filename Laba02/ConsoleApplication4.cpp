#include<iostream>
using namespace std;
//Дано n точок на площині.Побудувати їх опуклу лінійну оболонку

//перевіряємо орієнтацію точок
int orientashion(int px, int py, int qx, int qy, int rx, int ry) {
	int val = ((qy - py) * (rx - qx)) - ((qx - px) * (ry - qy));
	if (val == 0)
		return 0; // якщо колінеарні
	return(val > 0) ? 1 : 2; // за та проти годинникової стрілки
}
void convexShell(int points[], int n) {
	if (n < 3) return;
	int* returnArray = new int[2*n];
	int lx = 0;
	//шукаєсо крайню ліву точку(з найменшим значення х) 
	for (int i = 2; i < 2 * n; i += 2) {
		if (points[i] < points[lx])
			lx = i;
	}
	int px = lx, qx, py, qy, k=1, j=0;
	
	do {
		for ( j; j < j + 1; ) {
			returnArray[j] =points[px];
			break;
		}
		for ( k; k < k + 1; ) {
			returnArray[k] = points[px + 1];
			break;
		}
		
			qx = (px + 2) % (2*n);
			//шукаємо точку яка найбільше відхилена від даної проти годинникової стрілки
		for (int i = 0; i < 2*n; i+=2)
		{
			if (orientashion(points[px], points[px + 1], points[i], points[i + 1], points[qx], points[qx + 1]) == 2) {
				qx = i;
				/*break;*/
			}
		}
		px = qx;
		j += 2;
		k += 2;
	} while (px != lx); //поки не повернемося до початкової точки
	//вивід точок
	for (int i = 0; i <2*n; i+=2)
		//(sizeof(returnArray) / sizeof(returnArray[0]) - ділимо вказівник 
		cout << "(" <<returnArray[i] << "," << returnArray[i+1] << ")" << endl;
	delete[] returnArray;
}

int main() {
	
	int n, coord;
	cin >> n;
	int* points = new int[2*n];
	for (int i = 0; i < 2*n; i++) {
		cin >> coord;
		points[i] = coord;
	}
	for (int i = 0; i < 2*n - 1; i += 2) {
		cout << "(" << points[i] <<","<< points[i + 1] << ")" << endl;;
	}
	cout << endl;


	convexShell(points, n);
	delete[] points;
	return 0;


}
