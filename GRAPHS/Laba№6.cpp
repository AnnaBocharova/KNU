#include<iostream>
using namespace std;
#define EDGE  5

struct ElementMatrix {
	bool data;
	int j;
	ElementMatrix* next = nullptr;
	ElementMatrix* prev = nullptr;
};

struct Matrix {
	ElementMatrix* head = nullptr;
	ElementMatrix* end = nullptr;

	void add(int j) {
		ElementMatrix* new_element = new ElementMatrix;
		new_element->data = true;
		new_element->j = j;
		if (!head) {
			head=new_element;
			end=new_element;
		}
		else {
			head->next = new_element;
			new_element->prev =head;
			head = new_element;
		}
	}

	void insert(int j) {
		ElementMatrix* temp = end;
		while (temp!=NULL && temp->j < j) {
			temp = temp->next;
		}
		
		if (head->j<j) {
			add(j);
		}
		else if ( temp==end) {
			ElementMatrix* new_element = new ElementMatrix;
		    new_element->data = true;
			new_element->j = j;
			new_element->next = end;
			end->prev = new_element;
			end = new_element;
		}
		else {
			ElementMatrix* new_element = new ElementMatrix;
			new_element->data = true;
			new_element->j = j;
			new_element->prev = temp;
			new_element->next = temp->next;
			temp->next->prev = new_element;
			temp->next = new_element;
		}
	}

	void remove(ElementMatrix*& rows_delete) {
		ElementMatrix*& temp = rows_delete;
		if (temp->next) {
			if (temp == end) {
				end = temp->next;
				end->prev = nullptr;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			
		}
		else {
			temp->prev->next = nullptr;
		}
		delete rows_delete;
	}

	void merger_column(int a, int b) {
		ElementMatrix* current1 = end;
		ElementMatrix* current2 = end;
		while (current1 != NULL && current1->j != a - 1) {
			current1 = current1->next;
		}

		while (current2 != NULL && current2->j != b - 1) {
			current2 = current2->next;
		}
		if (current1 == NULL && current2 != NULL) {
			insert(current2->j);
		}
		if (current2 != NULL) {
			remove(current2);
		}
	}

	void vertical_delete(int b) {
		ElementMatrix* temp = end;
		while (temp != NULL) {
			if (temp->j >= b - 1)
				temp->j--;
			temp = temp->next;
		}

	}
	
};


void merger_rows(Matrix& rows1, Matrix& rows2) {
	ElementMatrix* current1 = rows1.end;
	ElementMatrix* current2 = rows2.head;
	while (current2 != NULL) {
		while (current1!=NULL && current1->j < current2->j) {
			current1 = current1->next;
		}
		if (current1!=NULL && current1->j != current2->j) {
			rows1.insert(current2->j);
		}
		else if (rows1.head->j < current2->j) {
			rows1.insert(current2->j);
		}
		current2 = current2->prev;
		current1 = rows1.end;
		if (current2 != NULL) {
			rows2.remove(current2->next);
		}

	}

}

void create_matrix(Matrix*& rows) {
	FILE* graph;
	int value;
	if (fopen_s(&graph, "graph.dat", "rb")) {
		perror("File isn`t open!");
	}
	else {
		for (int i = 0; i < EDGE; i++) {
			for (int j = 0; j < EDGE; j++) {
				fread(&value, sizeof(int), 1, graph);
				if (!value)
					rows[i].add(j);
			}
		}
		fclose(graph);
	}
}
void print_matrix(Matrix* rows, int size) {
	for (int i = 0; i < size; i++) {
		ElementMatrix* element = rows[i].end;
		if (element == nullptr) {
			for (int k = 0; k < size; k++) {
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
			if (element->next == nullptr) {
				for (int i = chek_column + 1; i < size; i++) {
					cout << "0 ";
				}
			}
			element = element->next;
		}
		cout << endl;
	}

}
int main() {
	FILE* graph;
	if (fopen_s(&graph, "graph.dat", "wb")) 
		perror("File isn`t open!");
	
	else {
		for (int i = 0; i < pow(EDGE, 2); i++) {
			int value = rand() % 2;
			fwrite(&value, sizeof(int), 1, graph);
		}
		fclose(graph);
	}

	Matrix* graph_matrix = new Matrix[EDGE];
	create_matrix(graph_matrix);
	print_matrix(graph_matrix, EDGE);

	cout << "Vertices you want to connect" << endl;;
	int vertex1=0, vertex2=0;
	cin >> vertex1;
	cin>>vertex2;

	merger_rows(graph_matrix[vertex1 - 1], graph_matrix[vertex2 - 1]);

	for (int i = 0; i < EDGE; i++) {
		graph_matrix[i].merger_column(vertex1, vertex2);
	}
	for (int i = 0; i < EDGE; i++) {
		graph_matrix[i].vertical_delete(vertex2);
	}

	Matrix* new_graph=new Matrix[EDGE - 1];
	for (int i = 0; i < vertex2 - 1; i++)
		new_graph[i] = graph_matrix[i];
	for (int i = vertex2; i < EDGE; i++)
		new_graph[i-1] = graph_matrix[i];
	print_matrix(new_graph, EDGE - 1);
	delete[] graph_matrix;
	delete[] new_graph;
	return 0;
}