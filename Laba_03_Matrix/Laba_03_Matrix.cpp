#include <iostream>
using namespace std;
const int mrank=5;


struct MatrixElement {
	int rows, column;
	int data;
	MatrixElement* pNext = nullptr;
	MatrixElement* prev = nullptr;
 };

struct List_Matrix {
	MatrixElement* head = nullptr;
	MatrixElement* end = nullptr;
	
	
	void push_next(int i, int j, int data){
		MatrixElement* matrix_element = new MatrixElement{ i, j, data };
		if (head == nullptr) {
			head = matrix_element;
			end = matrix_element;
		}
		else{
			matrix_element->pNext = head;
			head->prev = matrix_element;
			head = matrix_element;
		}
		
	}
	
};

void fillNewMatrix(const char* namefile) {
	FILE* fp;
	if (fopen_s(&fp, namefile, "wb"))
		perror("Error!");
	else {
		for (int i = 0; i < pow(mrank, 2); i++) {
			int element = rand() % 2;
			fwrite(&element, sizeof(int), 1, fp);
		}

	}
	fclose(fp);
 }



void createMatrix(const char* namefile, List_Matrix (&rows_matrix)[mrank], List_Matrix (&column_matrix)[mrank]){
	FILE* fp;
	if (fopen_s(&fp, namefile, "rb"))
	perror("Error!");
	else {
		for (int rows = 0; rows < mrank; rows++) {
			for (int column = 0; column < mrank; column++) {
				int element;
				fread(&element, sizeof(int), 1, fp);
				if (element != 0) {
					rows_matrix[rows].push_next(rows, column, element);
					column_matrix[column].push_next(rows, column, element);
				}
			}
		}
		
	}
	fclose(fp);
}

void printMatrix(List_Matrix(&rows_matrix)[mrank]) {
	
	for (int i = 0; i < mrank; i++) {
		MatrixElement* element = rows_matrix[i].end;
		if (element == nullptr) {
			for(int k=0; k<mrank; k++){
				cout << "0 ";
			}
		}
		int chek_column = -1;
		while (element != nullptr) {

			if (chek_column == -1 && element->column != 0) {
				for (int j = 0; j < element->column; j++) {
					cout << "0 ";
				}
			}
			else {
				for (int j = chek_column + 1; j < element->column; j++) {
					cout << "0 ";
				}
			}

			cout << element->data << ' ';
			chek_column = element->column;
			if (element->prev == nullptr) {
				for (int i = chek_column+1; i < mrank; i++) {
					cout << "0 ";
				}
			}
			element = element->prev;
		}
		cout << endl;
	}
	
}
void push_sum(MatrixElement* matrix_rows, List_Matrix(&rows_sum)[mrank], int i) {
	while (matrix_rows != nullptr) {
		rows_sum[i].push_next(matrix_rows->rows, matrix_rows->column, matrix_rows->data);
		matrix_rows = matrix_rows->prev;
	}
}
void sum_matrix(List_Matrix(&rows_A)[mrank], List_Matrix(&rows_B)[mrank], List_Matrix (&rows_sum)[mrank]) {
	for (int i = 0; i < mrank; i++) {

		MatrixElement* matrix_rows_A = rows_A[i].end;
		MatrixElement* matrix_rows_B = rows_B[i].end;
		if (matrix_rows_A == nullptr && matrix_rows_B != nullptr) {
			push_sum(matrix_rows_B, rows_sum, i);
		}
		else {
			if (matrix_rows_A != nullptr && matrix_rows_B == nullptr) {
				push_sum(matrix_rows_A, rows_sum, i);
			}
			else {
				bool check_A = true;
				bool check_B = true;
				while (matrix_rows_A != nullptr && matrix_rows_B != nullptr) {
					if ((matrix_rows_A->column == matrix_rows_B->column) && (matrix_rows_A->data + matrix_rows_B->data) != 0) {
						rows_sum[i].push_next(matrix_rows_A->rows, matrix_rows_A->column, (matrix_rows_A->data + matrix_rows_B->data));
					}
					if (matrix_rows_A->column < matrix_rows_B->column) {
						rows_sum[i].push_next(matrix_rows_A->rows, matrix_rows_A->column, matrix_rows_A->data);
					}
					if (matrix_rows_A->column > matrix_rows_B->column) {
						rows_sum[i].push_next(matrix_rows_B->rows, matrix_rows_B->column, matrix_rows_B->data);
					}
					matrix_rows_A = matrix_rows_A->prev;
					matrix_rows_B = matrix_rows_B->prev;
					if (matrix_rows_A == nullptr) check_A = false;
					if (matrix_rows_B == nullptr) check_B = false;
				}
				if (check_A == false) {
					push_sum(matrix_rows_B, rows_sum, i);
				
				}
				if(check_B==false){
					push_sum(matrix_rows_A, rows_sum, i);
				}
			}
		}
	}
	printMatrix(rows_sum);
}
void multiplication(List_Matrix(&rows_A)[mrank], List_Matrix(&column_B)[mrank], List_Matrix(&rows_multi)[mrank]) {
	for (int i = 0; i < mrank; i++) {
		for (int j = 0; j < mrank; j++) {
			MatrixElement* matrix_rows_A = rows_A[i].end;
			int counter = 0;
			while (matrix_rows_A != nullptr) {
				MatrixElement* matrix_column_B = column_B[j].end;
				while (matrix_column_B != nullptr) {
					if (matrix_column_B->rows == matrix_rows_A->column) {
						counter += matrix_column_B->data * matrix_rows_A->data;
					}
					matrix_column_B = matrix_column_B->prev;
				}
				matrix_rows_A = matrix_rows_A->prev;
			}
			if (counter != 0) {
				rows_multi[i].push_next(i, j, counter);
			}
		}
		
	}
	printMatrix(rows_multi);
}
	


int main(){
	fillNewMatrix("matrixA.dat");
	fillNewMatrix("matrixB.dat");

	List_Matrix rows_A[mrank], column_A[mrank];
	
	createMatrix("matrixA.dat", rows_A, column_A);

	cout << "Matrix_A" << endl << endl;
	printMatrix(rows_A);
	cout << endl;

	List_Matrix rows_B[mrank], column_B[mrank];

	createMatrix("matrixB.dat", rows_B, column_B);

	cout << "Matrix_B" << endl << endl;
	printMatrix(rows_B);
	cout << endl;

	List_Matrix sum_matr[mrank];

	cout << "Sum A + B" << endl << endl;
	sum_matrix(rows_A, rows_B, sum_matr);
	cout << endl;

	cout << "Multiplication A*B" << endl << endl;
	List_Matrix multy_rows[mrank];
	multiplication(rows_A, column_B, multy_rows);
	cout << endl;

	return 0;
}