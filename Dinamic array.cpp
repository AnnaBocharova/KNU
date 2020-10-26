#include<iostream>
#include<cmath>
using namespace std;
void array5() {
	int n;
	cout << "Enter counter of Fibonachi:";
	cin >> n;
	int* arr =new int[n];
	arr[0]=1;
	arr[1]= 1;
	for (int i = 2; i < n; i++)
		arr[i] = arr[i - 2] + arr[i - 1];
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	delete[] arr;

}
void array14() {
	int N, k;
	cout << "Enter N:";
	cin >> N;
	int *arr =new int[N];
	for (int i = 1; i < N; i++) {
		cin >> k;
		arr[i] = k;
	}
	for (int i = 0; i < N; i += 2)
		cout << arr[i] << endl;
	for (int i = 0; i < N; i += 2)
		cout << arr[i] << endl;

	delete [] arr;

}
void array23() {
	int k, l, n, value;
	float sum = 0;
	cout << "Enter size of aray: ";
	cin >> n;
	cin >> k >> l;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> value;
		arr[i] = value;
	}
	for (int i = 0; i < k-1; i++) {
		sum += arr[i];
	}
	for (int i = l; i < n; i++) {
		sum += arr[i];
	}

	cout <<"Sum= "<< sum / (float)(n-l+k-1);
	delete[] arr;
}
void array35() {
	int n, k, l;
	cout << "Enter size of aray: ";
	cin >> n;
	int* arr = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> k;
		arr[i] = k;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
			l = arr[i];
			for (int j = i; j == i;)
				arr2[j] = k;
		}

	}
	int min = arr2[0];
	for (int i = 0; i < k; i++) {
		if (arr2[i] <= min)
			min = arr2[i];
	}
	cout << "Min=" << min;
	delete[] arr;
	delete[] arr2;
}
void array45() {
	int n, k;
	cout << "Enter size of aray: ";
	cin >> n;
	int* arr = new int[n];
	

	for (int i = 0; i < n; i++) {
		cin >> k;
		arr[i] = k;
	}
	int i2, k1 = 0, k2 = 1;
	for (int i = 0; i < n - 1; ++i) {
		for (i2 = i + 1; i2 < n; ++i2) {
			if (abs(arr[i] - arr[i2]) < abs(arr[k1] - arr[k2])) {
				k1 = i;
				k2 = i2;
			}
		}
	}
	cout << k1 + 1 << "  " << k2 + 1;
	delete[] arr;
}
void array58() {
	int n, k;
	cout << "Enter size of aray";
	cin >> n;
	int* array1 = new int[n];
	int* array2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> k;
		array1[i] = k;
	}
	for (int j = 0; j < n; j++) {
		array2[j] = 0;
		for (int i = 0; i <= j; i++)
			array2[j] += array1[i];
	}
	for (int i = 0; i < n; i++)
		cout << array2[i]<<endl;

	delete[] array1;
	delete[] array2;
}
void array61() {
	int n, k;
	cout << "Enter n:" << endl;
	cin >> n;
	float* array = new float[n];
	float* array2 = new float[n];
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	for (int i = 0; i < n; i++) {
		array2[i] = 0;
		for (int j = 0; j < n; j++)
			array2[j] += array[j];
		array2[i] = array2[i] /(float) (n - i);
	}
	for (int i = 0; i < n; i++)
		cout << array2[i] << endl;

	delete[] array;
	delete[] array2;


}
void array69() {
	int n, k;
	cout << "Enter n:" << endl;
	cin >> n;
	int* array = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	for (int j = 1; j < n; j+=2) {
		array[j] += array[j- 1];
		array[j - 1] = array[j] - array[j - 1];
		array[j] -= array[j - 1];

	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}

	delete[] array;
}
void array76() {
	int n, k, i;
	cout << "Enter n:" << endl;
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	if (array[0] > array[1]) {
		i = 2;
		array[0] = 0;
	}
	else i = 1;

	for (; i < n - 1; i++) {
		if ((array[i - 1] < array[i]) && (array[i] > array[i + 1])) {
			array[i] = 0;
			i++;
		}
	}

	if ((i == n - 1) && (array[n - 2] < array[n - 1])) 
		array[n - 1] = 0;

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}
	

	delete[] array;
}
void array80() {
	int n, k;
	cout << "Enter n:" << endl;
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	for (int i = 0; i < n - 1; i++) {
		array[i] = array[i + 1];
	}
	array[n - 1] = 0;
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}
	delete[] array;
}
void array98() {
	int n, k, counter=1;
	cout << "Enter n:" << endl;
	cin >> n;
	int* array = new int[n];
	

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (array[i] == array[j])
				counter++;
		}
		if (counter < 3)
			array[i]=0 ;
		counter = 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}
	cout << "Size=" <<  sizeof(array) / sizeof(int) << endl;


	delete[] array;


}
void array110() {
	int n, k, counter = 1;
	cout << "Enter n:" << endl;
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (array[i] % 2 == 0) {
			n++;
			for (int j = n - 1; j > i; j--) 
				array[j] = array[j - 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}

	delete[] array;


}
void array113() {
	int n, k;
	cout << "Enter n:" << endl;
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		array[i] = k;
	}
	int max;
	for (int i = n - 1; i > 0; --i) {
		max = array[0];
		for (int j = 0; j <= i; j++) {
			if (array[j] > array[max]) {
				max = j;
			}
		}
		if (i != max) {
			array[i] += array[max];
			array[max] = array[i] - array[max];
			array[i] -= array[max];
		}
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << endl;
		}
		delete[] array;
	}
}
void array133() {
	int rows, x, y;
	cout << "Enter rows:" << endl;
	cin >> rows;
	
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++) {
		cout << "Enter coordainates x:";
		cin >> x;
		array[i][0] = x;
		cout << "Enter coordainates y:";
		cin >> y;
		array[i][1] = y;
	}

	int min = 0;
	float r, rmin;
	for (int i = 0; i < rows; ++i) {
		if ((array[i][0] > 0 && array[i][1] > 0) || (array[i][0] < 0 && array[i][1] < 0)) {
			r = sqrt(pow(array[i][0], 2) + pow(array[i][1], 2));
			if (r < rmin || i == 0) {
				rmin = r;
				min = i;
			}
		}
	}
	cout << array[min][0] << "," <<array[min][1] << endl;
	for (int i = 0; i < 2; i++)
		delete[] array[i];
	delete[] array;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "1.Дано целое число N (> 2). Сформировать и вывести целочисленный массив размера N, содержащий N первых элементов последовательности  чисел Фибоначчи FK :F1 = 1, F2 = 1, FK = FK–2 + FK–1, K = 3, 4, ..." << endl;
	cout << "2.Дан массив A размера N. Вывести вначале его элементы с четными номерами(в порядке возрастания номеров), а затем — элементы с нечетными номерами(также в порядке возрастания номеров) :	A2, A4, A6, ..., A1, A3, A5, ... .Условный оператор не использовать." << endl;
	cout << "3.Дан массив размера N и целые числа K и L (1 < K ≤ L ≤ N). Найти среднее арифметическое всех элементов массива, кроме элементов с номерами от K до L включительно." << endl;
	cout << "4.Дан массив размера N. Найти минимальный из его локальных максимумов(определение локального максимума дано в задании Array33)." << endl;
	cout << "5.Дан массив размера N. Найти номера двух ближайших элементов из этого массива(то есть элементов с наименьшим модулем разности) и вывести эти номера в порядке возрастания." << endl;
	cout << "6.Дан массив A размера N. Сформировать новый массив B того же размера по следующему правилу : элемент BK равен сумме элементов массива A с номерами от 1 до K." << endl;
	cout << "7. Дан массив A размера N. Сформировать новый массив B того же размера по следующему правилу : элемент BK равен среднему арифметическому элементов массива A с номерами от K до N." << endl;
	cout << "8.Дан массив размера N (N — четное число). Поменять местами его первый элемент со вторым, третий — с четвертым и т.д." << endl;
	cout << "9.Дан массив размера N. Обнулить все его локальные максимумы (то есть числа, большие своих соседей)." << endl;
	cout << "10.Дан массив размера N. Осуществить сдвиг элементов массива влево на одну позицию(при этом AN перейдет в AN–1, AN–1 — в AN–2, ..., A2 — в A1,a исходное значение первого элемента будет потеряно).Последний элемент полученного массива положить равным 0." << endl;
	cout << "11.Дан целочисленный массив размера N. Удалить из массива все элементы, встречающиеся менее трех раз, и вывести размер полученного массива и его содержимое." << endl;
	cout << "12.Дан целочисленный массив размера N. Продублировать в нем всe четные числа." << endl;
	cout << "13.Дан массив A размера N (≤ 6). Упорядочить его по возрастанию методом сортировки простым выбором : найти максимальный элемент массива и поменять его местами с последним(N - м) элементом; выполнить описанные действия N – 1 раз, каждый раз уменьшая на 1 количество анализируемых элементов и выводя содержимое массива." << endl;
	cout << "14.Дано множество A из N точек (точки заданы своими координатами x, y).Среди всех точек этого множества, лежащих в первой или третьей 	четверти, найти точку, наиболее близкую к началу координат.Если таких точек нет, то вывести точку с нулевыми координатами."<<endl;
		int n;
	cout << "Enter number of task: " << endl;
	cin >> n;
	switch (n) {
	case 1: array5(); break;
	case 2: array14(); break;
	case 3: array23(); break;
	case 4: array35(); break;
	case 5: array45(); break;
	case 6: array58(); break;
	case 7: array61(); break;
	case 8: array69(); break;
	case 9: array76(); break;
	case 10: array80(); break;
	case 11: array98(); break;
	case 12: array110(); break;
	case 13: array113(); break;
	case 14: array133(); break;
	}

	return 0;
}