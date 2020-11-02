#include<iostream>
using namespace std;
void matrix4() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	int set[n];
	for(int i=0; i<n; i++){
		cin >> set[i];
		 
    }
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = set[j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}



}
void matrix9() {
	const int m = 10;
	const int n = 4;
	int array[m][n]{};
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin>>array[i][j];
		}
	}
	for (int i = 1; i < m; i+=2) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}
void matrix10() {
	const int m = 6;
	const int n = 4;
	int array[m][n]{};

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j+=2) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}
void matrix12() {
	const int m = 3;
	const int n = 4;
	int array[m][n]{};

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			for (int j = 0; j < m; j++)
				cout << array[j][i] << " ";
		else
			for (int j = m-1; j >= 0; j--)
				cout << array[j][i] << ' ';
		cout << endl;
	}
	
}
void matrix14() {
	const int m = 4;
	const int n = 4;
	int array[m][n]{};

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}
	
	cout << endl << endl;
	int l = 1, value=m;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < value; j++) {
			cout << array[j][i] << " ";

		}
		cout << endl;
		for (int k = l; k < value - 1; k++)
			cout << array[value - 1][k] << " ";


		cout << endl;
		value--;
		l++;
	}
}
void matrix19() {
	const int m = 3;
	const int n = 4;
	int sum = 0, k=1;
	int array[m][n]{};

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	} 

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += array[i][j];
			}
		cout << "Sum" << k << "=" << sum<<endl;
		k++;
		sum = 0;
	}
}
void matrix23() {
	const int m = 3;
	const int n = 4;
	int array[m][n]{};
	int min = 0,k=1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		min = array[i][0];
		for (int j = 0; j < n; j++) {
			if (array[i][j] <= min)
				min = array[i][j];
		}
		cout << endl;
		cout << "Min" << k << "="<<min << endl;
		k++;
	}

}
void matrix28() {
	const int m = 3;
	const int n = 4;
	int array[m][n]{};
	int max, min=0, max1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < 1; i++) {
		max = array[0][i];
		for (int j = 0; j < m; j++) {
			if (array[j][i] >= max)
				max = array[j][i];

		}
	}
	for (int i = 0; i < n; i++) {
		max1 = array[1][i];
		for (int j = 0; j < m; j++) {
			if (array[j][i] >= max1)
				max1 = array[j][i];

		}
		int const k = max;
		if (max1 <= max) {
			min = max1;
		}
		cout << endl;

	}
	cout << "Min of max=" << min<< endl;

}
void matrix29() {
	const int m = 3;
	const int n = 4;
	int sum = 0, k=0;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += array[i][j];
		}
		sum = sum / n;
		for (int j = 0; j < n; j++) {
			if (array[i][j] < sum)
				k++;
		}
		cout << i << "-" << "quantity=" << k;
		k = 0;
		sum = 0;
		cout << endl;
	}

}
void matrix32() {
	const int m = 5;
	const int n = 4;
	int neg=0, pos=0, counter=0;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (array[i][j] > 0)
				pos++;
			if (array[i][j] < 0)
				neg++;
		}
		if (neg == pos) {
			cout << "line in which the same number of positive and negative elements " << i + 1;
			counter++;
		}
		neg = 0;
		pos = 0;
		cout << endl;
	}
	if (counter == 00)
		cout << 0;


}
void matrix35() {
	const int m = 5;
	const int n = 4;
	int counter = 0, odd = 0;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (array[i][j] % 2 != 0)
				odd++;
		}

			if (odd == n) {
				cout << "line in which the same number of odd elements " << i + 1;
				counter++;
				break;
			}
			odd = 0;
			cout << endl;
		}
		if (counter == 00)
			cout << 0;

	}
void matrix38() {
	const int m = 5;
	const int n = 4;
	int counter = 0, l=0;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int h = 0; h < n; h++) {
				if (array[i][h] == array[i][j]) {
					counter++;
					
				}
			}
		}
		

		if (counter-n==0) {
			l++;
		}
		counter = 0;
	}
	cout << "the number of its lines, all elements of which are different: " << l;

}
void matrix43() {
	const int m = 5;
	const int n = 4;
	int counter = 0,k=0;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j++) {
			if (array[j][i] > array[j+1][i])
				counter++;
		}
		if (counter == m - 1)
			k++;
		counter = 0;
	}
	cout << "The number of its columns, the elements of which are sorted in descending order: " << k;

}
void matrix45() {
	const int m = 5;
	const int n = 4;
	int counter = 0, k = 0;
	int max1, max2;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (array[j][i] > array[j + 1][i])
				counter++;
		}
		if (counter % (m - 1) == 0) {
			max1 = array[0][i];
			for (int j = 0; j < m - 1; j++) {
				if (array[j][i]>=max1)
					max1=array[j][i];
			}
		}
		counter = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (array[j][i] < array[j + 1][i])
				counter++;
		}
		if (counter % (m - 1) == 0) {
			max2 = array[0][i];
			for (int j = 0; j < m - 1; j++) {
				if (array[j][i] >= max2)
					max2 = array[j][i];
			}
		}
		counter = 0;
	}
	if (max1 > max2)
		cout << max1;
	else
		cout << max2;
	
}
void matrix48() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	int k1, k2, rows;
	cout << "Enter k1 and k2:";
	cin >> k1 >> k2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rows = array[i][k1-1];
			array[i][k1-1] = array[i][k2-1];
			array[i][k2-1] = rows;
		}
	}
	cout << endl << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

}
void matrix50() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	int max, min, rows, k1, k2;
	for (int i = 0; i < n; i++) {
		max = array[i][0];
		min= array[i][0];
		for (int j = 0; j < m; j++) {
			if (array[j][i] >= max) {
				max = array[j][i];
				k1 = j;
			}
			if (array[j][i] <= min) {
				min = array[j][i];
				k2 = j;
			}
		}
		array[k1][i] = min;
		array[k2][i] = max;
	}
	cout << endl << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}


}
void matrix54() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std:: cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	int counter = 0, k=-1, rows, l=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (array[j][i] < 0) {
				counter++;
				l = i;
			}
		}
		if (counter % m == 0) {
			k =l ;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
			rows = array[k][i];
			array[k][i] = array[n-1][i];
			array[n-1][i] = rows;
		
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	if (k == -1) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
void matrix59() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < m / 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int cows = array[i][j];
			array[i][j] = array[m - i - 1][j];
			array[m - i - 1][j] = cows;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}
void matrix56() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int rows = array[j][i];
			array[j][i] = array[j][n-(n/2)+i];
			array[j][n-(n/2)+i] = rows;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

}
void matrix64() {
	
	
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int cows = array[i][j];
			array[i][j] = array[n - i - 1][j];
			array[n - i - 1][j] = cows;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

}
void matrix67() {
	const int m = 5;
	const int n = 4;
	int array[m][n]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> array[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	int counter = 0;
	int arrayK[m]{};
	int k=-1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (array[j][i] < 0)
				counter++;
		}
		if (counter % m == 0) {
			k++;
			arrayK[k] = i;
		}
	} 
	if (k == -1) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
	}
	int z = k;
	if(k!=-1) {
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < m; l++) {
					array[k][l] = array[k + 1][l];
				}
			}
			k++;
		}
		z = n - z;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < z; j++) {
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
	
	}
	

}


int main() {
	setlocale(LC_ALL, "rus");
	
	cout << "1. Даны целые положительные числа M, N и набор из N чисел. Сформировать матрицу размера M × N, у которой в каждой строке содержатся все	числа из исходного набора(в том же порядке)." << endl;
	cout << "2.Дана матрица размера M × N. Вывести ее элементы, расположенные в строках с четными номерами(2, 4, ...).Вывод элементов производить по строкам, условный оператор не использовать." << endl;
	cout << "3.Дана матрица размера M × N. Вывести ее элементы, расположенные в столбцах с нечетными номерами(1, 3, ...).Вывод" << endl;
	cout << "4.Дана матрица размера M × N. Вывести ее элементы в следующем порядке: первый столбец сверху вниз, второй столбец снизу вверх, третий столбец сверху вниз, четвертый столбец снизу вверх и т.д." << endl;
	cout << "5.Дана квадратная матрица A порядка M. Начиная с элемента A1,1, вывести ее элементы следующим образом(«уголками») : все элементы первого столбца; элементы последней строки, кроме первого(уже выведенного) элемента; оставшиеся элементы второго столбца; оставшиеся элементы предпоследней строки и т.д.; последним выводится элемент A1, M." << endl;
	cout << "6.Дана матрица размера M × N. Для каждой строки матрицы найти сумму ее элементов." << endl;
	cout << "7.Дана матрица размера M × N. В каждой строке матрицы найти минимальный элемент." << endl;
	cout << "8. Дана матрица размера M × N. Найти минимальный среди максимальных элементов ее столбцов." << endl;
	cout << "9.Дана матрица размера M × N. В каждой ее строке найти количество элементов, меньших среднего арифметического всех элементов этой строки." << endl;
	cout << "10.Дана целочисленная матрица размера M × N. Найти номер первой из ее строк, содержащих равное количество положительных и отрицательных элементов(нулевые элементы матрицы не учитываются).Если таких строк 	нет, то вывести 0." << endl;
	cout << "11. Дана целочисленная матрица размера M × N. Найти номер первого из ее столбцов, содержащих только нечетные числа.Если таких столбцов нет, 	то вывести 0." << endl;
	cout << "12.Дана целочисленная матрица размера M × N. Найти количество ее	строк, все элементы которых различны." << endl;
	cout << "13.Дана матрица размера M × N. Найти количество ее столбцов, элементы которых упорядочены по убыванию." << endl;
	cout << "14.Дана матрица размера M × N. Найти максимальный среди элементов тех столбцов, которые упорядочены либо по возрастанию, либо по убыванию.Если упорядоченные столбцы в матрице отсутствуют, то вывести 0." << endl;
	cout << "15.Дана матрица размера M × N и целые числа K1 и K2 (1 ≤ K1 < K2 ≤ N). Поменять местами столбцы матрицы с номерами K1 и K2." << endl;
	cout << "16.Дана матрица размера M × N. Преобразовать матрицу, поменяв местами минимальный и максимальный элемент в каждом столбце." << endl;
	cout << "17.Дана матрица размера M × N. Поменять местами столбец с номером N 	и первый из столбцов, содержащих только отрицательные элементы.Если требуемых столбцов нет, то вывести матрицу без изменений." << endl;
	cout << "18.Дана матрица размера M × N. Зеркально отразить ее элементы относительно горизонтальной оси симметрии матрицы(при этом поменяются местами строки с номерами 1 и M, 2 и M – 1 и т.д.)." << endl;
	cout << "19.Дана матрица размера M × N (N — четное число). Поменять местами левую и правую половины матрицы." << endl;
	cout << "20.Дана матрица размера M × N. Зеркально отразить ее элементы относительно вертикальной оси симметрии матрицы(при этом поменяются местами столбцы с номерами 1 и N, 2 и N – 1 и т.д.)." << endl;
	cout << "21.Дана матрица размера M × N, содержащая как положительные, так и отрицательные элементы.Удалить все ее столбцы, содержащие только положительные элементы.Если требуемых столбцов нет, то вывести матрицу без изменений." << endl;
	cout << "22.Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). После	столбца матрицы с номером K вставить столбец из единиц." << endl;


	int n;
	cout << "Please enter number of task:";
	cin >> n;
	switch (n) {
	case 1: matrix4(); break;
	case 2: matrix9(); break;
	case 3: matrix10(); break;
	case 4: matrix12(); break;
	case 5: matrix14(); break;
	case 6: matrix19(); break;
	case 7: matrix23(); break;
	case 8: matrix28(); break;
	case 9: matrix29(); break;
	case 10: matrix32(); break;
	case 11: matrix35(); break;
	case 12: matrix38(); break;
	case 13: matrix43(); break;
	case 14: matrix45(); break;
	case 15: matrix48(); break;
	case 16: matrix50(); break;
	case 17: matrix54(); break;
	case 18: matrix59(); break;
	case 19: matrix56(); break;
	case 20: matrix64(); break;
	case 21: matrix67(); break;
		

	}

	return 0;

}
