#include<iostream>
#include <functional>
using std::function;
using namespace std;
const int VERTIX = 5;
const int SIZE = 25;


struct ElementMatrix {
	int data;
	int i, j;
	ElementMatrix* next = nullptr;
	ElementMatrix* prev = nullptr;
};

struct Vertix {
	int x=0, y=0;
	int vertix;
	int counter_edges = 0;
	int sum_lenght = 0;
};
struct Edges {
	int start, x1 = 0, y1 = 0;
	int end, x2 = 0, y2 = 0;
	int lenght = 0;
	double x_middle;
	double y_middle;
};
struct Cycle {
	int vertix1, edge1,
		vertix2, edge2,
		vertix3, edge3;
};
struct Matrix {
	ElementMatrix* head = nullptr;
	ElementMatrix* end = nullptr;

	void add(int i, int j,int data) {
		ElementMatrix* new_element = new ElementMatrix;
		new_element->data = data;
		new_element->i = i;
		new_element->j = j;
		
		if (!head) {
			head = new_element;
			end = new_element;
		}
		else {
			new_element->next = head;
			head->prev = new_element;
			head = new_element;
			
		}
	}

	void edges_number(int &counter) {
		ElementMatrix* temp = head;
		while (temp) {
			if (temp->data) {
				counter++;
			}
			temp = temp->next;
		}
		
	}

	void sum_lenght_edges(int& lenght) {
		ElementMatrix* temp = head;
		while (temp) {
			lenght += temp->data;
			temp = temp->next;
		}
		
	}

	int lenght_edges(int j) {
		ElementMatrix* temp = head;
		while (temp) {
			if (temp->j == j) {
				return temp->data;
			}
			temp = temp->next;
		}
		return INT_MAX;
	}
};

//сортировка вставкой
void insertion_sort(Vertix(&edges)[VERTIX]) {
	for (int i = 1; i < VERTIX; i++) {
		Vertix temp = edges[i];
		for (int j = i - 1; j >= 0 && edges[j].counter_edges > temp.counter_edges; j--) {
			edges[j + 1] = edges[j];
			edges[j] = temp;
		}
	}
}

//сортировка пузырьком
void bubble_sort(Vertix(&edges) [VERTIX]) {
	for (int i = 0; i < VERTIX; i++) {
		bool flag = false;
		for (int j = VERTIX - 1; j > 0; j--) {
			if (edges[j].sum_lenght < edges[j - 1].sum_lenght) {
				swap(edges[j], edges[j - 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

bool function_of_coordinates(Vertix vertix1, Vertix vertix2) {
	if (sqrt(pow(vertix1.x,2)+pow(vertix1.y,2))< sqrt(pow(vertix2.x, 2) + pow(vertix2.y, 2)))	
		return true;
	return false;
}

//сортировка перемешиванием 
void shaker_sort(Vertix(&edges)[VERTIX]) {
	int left = 1;
	int right=VERTIX - 1;
	while (left <= right) {
		
		for (int i = right; i >= left; i--) {
			if (function_of_coordinates(edges[i], edges[i - 1])) {
				swap(edges[i], edges[i - 1]);
				
			}
		}
		left++;
		for (int i = left; i <= right; i++) {
			if (function_of_coordinates(edges[i], edges[i-1])) {
				swap(edges[i], edges[i-1]);
			}
		}
		right--;
	}
}

void quick_sort(Edges(&edges) [SIZE], int first, int last) {
	int frst = first, lst = last;
	int middle = edges[(frst + lst) / 2].lenght;

	while (frst < lst) {
		while (edges[frst].lenght < middle) {
			frst++;
		}
		while (edges[lst].lenght>  middle) {
			lst--;
		}
		if (frst <= lst) {
			swap(edges[frst], edges[lst]);
			frst ++;
			lst--;
		}
	}
	if (first < lst) {
		quick_sort(edges, first, lst);
	}
	if (frst < last) {
		quick_sort(edges, frst, last);
	}
}




//слиянием 
void merge(Edges arr[], int l, int m, int r)
{
	function<bool(Edges, Edges)> funct;
	int n1 = m - l + 1;
	int n2 = r - m;

	
	Edges* L = new Edges[n1];
	Edges* R = new Edges[n2];
	
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (funct(L[i], R[j])) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete L, delete R;
}

void merge_sort(Edges(&edges)[SIZE], int l, int r) {
	if (l < r) {
		int m = (l +r)/ 2;
		merge_sort(edges, l, m);
		merge_sort(edges, m + 1, r);
		merge(edges, l, m, r);
	}
}


double area(const int&a, const int&b, const int &c) {
	double p = (a + b + c) / 2;
	if (p * (p - a) * (p - b) * (p - c) < 0)
		return 0;
	else
		return sqrt(p * (p - a) * (p - b) * (p - c));
}
void shell_sort(Cycle array[], int size)
{
	int d = size / 2;
	while (d > 0)
	{
		for (int i = 0; i < size - d; i++)
		{
			int j = i;
			while (j >= 0 && area(array[j].edge1, array[j].edge2, array[j].edge2)< area(array[j+d].edge1, array[j+d].edge2, array[j+d].edge2))
			{
				swap(array[j], array[j + d]);
				j--;
			}
		}
		d = d / 2;
	}
	
}

void create_matrix(Matrix (&matrix)[VERTIX]) {
	FILE* graph;
	int value;
	if (fopen_s(&graph, "graph.dat", "rb")) {
		perror("File isn`t open!");
	}
	else {
		for (int i = 0; i < VERTIX; i++) {
			for (int j = 0; j < VERTIX; j++) {
				fread(&value, sizeof(int), 1, graph);
				if (value!=0) {
					matrix[i].add(i, j, value);
				}
			}
		}
		fclose(graph);
	}
}

void print_matrix(Matrix(&rows_matrix)[VERTIX]) {

	for (int i = 0; i < VERTIX; i++) {
		ElementMatrix* element = rows_matrix[i].end;
		if (element == nullptr) {
			for (int k = 0; k < VERTIX; k++) {
				cout << "0 ";
			}
		}
		int chek_column = -1;
		while (element != nullptr) {

			if (chek_column == -1 && element->j != 0) {
				for (int j = 0; j < element->j; j++) {
					cout << "0 ";
				}
			}
			else {
				for (int j = chek_column + 1; j < element->j; j++) {
					cout << "0 ";
				}
			}

			cout << element->data << ' ';
			chek_column = element->j;
			if (element->prev == nullptr) {
				for (int j = chek_column + 1; j < VERTIX; j++) {
					cout << "0 ";
				}
			}
			element = element->prev;
		}
		cout << endl;
	}

}

void print_array(Vertix array[VERTIX], int check) {
	if (check == 1) {
		for (int i = 0; i < VERTIX; i++) {
			cout << array[i].vertix+1;
			if (i != VERTIX - 1) {
				cout << "->";
			}
		}
		cout << endl;
	}
	else if (check == 2) {
		for (int i = VERTIX - 1; i >= 0; i--) {
			cout << array[i].vertix+1;
			if (i != 0) {
				cout << "->";
			}
		}
		cout << endl;
	}	
	else {
		cout << "Incorrect input!" << endl;
	}
}

void print_array_edges(Edges array[SIZE], int check) {
	if (check == 1) {
		for (int i = 0; i < SIZE && array[i].lenght!=INT_MAX; i++) {
			cout << array[i].start + 1 << "-" << array[i].end+1 << endl;
		}
	}
	else if (check == 2) {
		for (int i = SIZE - 1; i >= 0 && array[i].lenght!=INT_MAX; i--) {
			cout << array[i].start + 1 << "-" << array[i].end+1 << endl;
		}
	}
	else {
		cout << "Incorrect input!";
	}
	cout << endl;
}
void print_edges(Edges array[SIZE], int check) {
	if (check == 1) {
		for (int i = 0; i < SIZE && array[i].lenght != INT_MAX && array[i].start!=array[i].end; i++) {
			cout << array[i].start + 1 << "-" << array[i].end + 1 << endl;
		}
	}
	else if (check == 2) {
		for (int i = SIZE - 1; i >= 0 && array[i].lenght != INT_MAX && array[i].start != array[i].end; i--) {
			cout << array[i].start + 1 << "-" << array[i].end + 1 << endl;
		}
	}
	else {
		cout << "Incorrect input!";
	}
	cout << endl;
}

void create_cycle(Matrix matrix_graph[], Cycle(&result)[SIZE], int &counter) {
	int mygraph[VERTIX][VERTIX];
	for (int i = 0; i < VERTIX; i++) {
		for (int j = 0; j < VERTIX; j++) {
			mygraph[i][j] = matrix_graph[i].lenght_edges(j);
		}
	}

	for (int i = 0; i < VERTIX; i++) {
		for (int j = i + 1; j < VERTIX; j++) {
			if (mygraph[i][j] != INT_MAX) {
				for (int k = j + 1; k < VERTIX; k++) {
					if (mygraph[j][k] != INT_MAX && mygraph[k][i] != INT_MAX) {
						result[counter].vertix1 = i;
						result[counter].vertix2 = j;
						result[counter].vertix3 = k;
						result[counter].edge1 = mygraph[i][j];
						result[counter].edge2 = mygraph[j][k];
						result[counter].edge3 = mygraph[k][i];
						counter++;
					}
				}
			}
		}
	}
}

void crete_array_edge(Vertix number_edges[], Matrix matrix_graph[], Edges(&alledges)[SIZE]) {
	int vertix = 0,  counter1 = 0, i = 0;
	for (int j = 0; j < SIZE; j++) {
		vertix = 0;
		alledges[j].start = i;
		alledges[j].end = vertix + counter1;
		alledges[j].x1 = number_edges[i].x;
		alledges[j].y1 = number_edges[i].y;
		alledges[j].x2 = number_edges[vertix + counter1].x;
		alledges[j].y2 = number_edges[vertix + counter1].y;
		alledges[j].x_middle = (alledges[j].x1 + alledges[j].x2) / 2;
		alledges[j].y_middle = (alledges[j].y1 + alledges[j].y2) / 2;
		alledges[j].lenght = matrix_graph[i].lenght_edges(vertix + counter1);
		counter1++;

		if (j % 5 == 4) {
			i += 1;
			counter1 = 0;
		}
	}

}

int main() {
	FILE* graph;
	if (fopen_s(&graph, "graph.dat", "wb")) {
		perror("File isn`t open!");
	}
	else {
		for (int i = 0; i < pow(VERTIX, 2); i++) {
			int value = rand() % 4;
			fwrite(&value, sizeof(int), 1, graph);
		}
		fclose(graph);
	}

	Matrix matrix_graph[VERTIX];
	create_matrix(matrix_graph);
	int x = 0, y = 0;
	Vertix number_edges[VERTIX];

	for (int i = 0; i < VERTIX; i++) {
		number_edges[i].vertix = i;
		x = -10 + rand() % 20;
		y = -10 + rand() % 20;
		number_edges[i].x = x;
		number_edges[i].y = y;
		matrix_graph[i].edges_number(number_edges[i].counter_edges);
		matrix_graph[i].sum_lenght_edges(number_edges[i].sum_lenght);
	}

	
	
	print_matrix(matrix_graph);
	for (int i = 0; i < VERTIX; i++) {
		cout << number_edges[i].vertix + 1 << "  ("
			<< number_edges[i].x << ", "
			<< number_edges[i].y << ")" << endl;
	}
	Edges alledges[SIZE];
	crete_array_edge(number_edges, matrix_graph, alledges);
	
	
	Cycle result[SIZE];
	int counter = 0;
	create_cycle(matrix_graph, result, counter);
	bool check = true;
	while (check) {
		int sort, sort_check;
		
			cout<< "1 - insertion sort" << endl 
			<< "2 - bubble sort" << endl 
			<< "3 - shaker sort" << endl 
			<< "4 - quick sort " << endl 
			<< "5 - merge sort" << endl 
			<< "6 - shell sort" << endl 
			<< "_____________________________" << endl;
		cin >> sort;
		cout << "1 - from low to high" << endl
			<< "2 - from high to low" << endl;

		cin >> sort_check;
		cout << endl;

		switch (sort)
		{
		case 1:
			insertion_sort(number_edges);
			print_array(number_edges, sort_check);
			break;
		case 2:
			bubble_sort(number_edges);
			print_array(number_edges, sort_check);
			break;
		case 3:
			for (int i = 0; i < VERTIX; i++) {
				cout << number_edges[i].vertix+1 << "  ("
					<< number_edges[i].x << ", "
					<< number_edges[i].y << ")" << endl;
			}
			shaker_sort(number_edges);
			print_array(number_edges, sort_check);
			break;
		case 4:
			quick_sort(alledges, 0,SIZE - 1);
			print_array_edges(alledges, sort_check);
			break;
		case 5:
			merge_sort(alledges,0, SIZE-1);
			print_edges(alledges, sort_check);
			break;
		case 6:
			shell_sort(result, counter);
			for (int i = 0; i < counter; i++) {
				cout << result[i].vertix1+1 << "->" << result[i].vertix2+1 << "->" << result[i].vertix3+1 << endl;
			}
			break;
		default:
			cout << "Function number entered incorrectly!";
			break;
		}
		
		cout << endl << "Would you like to continue work?" << endl;
		cout << "1 - YES" << endl << "0 - NO"<< endl;
		cin >> check;
		if (check == 0)
			break;
	}
	
	}




