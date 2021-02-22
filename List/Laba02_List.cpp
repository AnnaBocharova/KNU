#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

struct Node {
	int num=1;
	int den=1;
	Node* pNext = nullptr;
};
int NOD(int a, int b) {
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	while (a > 0 && b > 0) {

		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}

	}
	return a + b;
}

int NOK(int a, int b) {
	int nok = a * b / NOD(a, b);
	return nok;
}


int* georgeCantor(int n) {
	int num = 1, den = 1, counter = 1;
	while (counter < n) {
		den++; counter++;
		if (counter == n) {
			break;
		}
		while (den > 1 && counter < n) {
			den--, num++, counter++;
		}
		if (counter == n) {
			break;
		}
		num++, counter++;
		if (counter == n) {
			break;
		}
		while (num > 1 && counter < n) {
			num--, den++, counter++;
		}
	}
	int* array = new int[2];
	array[0] = num, array[1] = den;
	return array;

}

struct List {
	Node* head=nullptr;
	int Size = 0;
	int check = 0;
	void push_back(int num, int den) {
		if (head == nullptr) {
			head = new Node{ num, den };
		}
		else {
			Node* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new Node{ num, den };
		}
		Size++;
		check++;
	}

	Node operator[] (const int index) {
		int counter = 0;
		Node* current = this->head;
		while (current != nullptr) {
			if (counter == index) {
				return *current;
			}
			current = current->pNext;
			counter++;
		}

	}
	void pop_front() {
		Node* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	void removeAt(int index) {
		if (index == 0) {
			pop_front();
		}
		else {
			Node* current = head;
			for (int i = 0; i < index - 1; i++) {
				current = current->pNext;
			}
			Node* temp = current->pNext;
			current->pNext = temp->pNext;
			delete temp;
			Size--;
		}


	}
	void sum() {
		Node* current =this->head;
		Node* temp = current->pNext;
		while (temp != nullptr) {
			int del = NOK(current->den, temp->den);
			int value1 = (del / current->den) * current->num;
			int value2 = (del / temp->den) * temp->num;
			int num = value1 + value2;
			current = new Node{ num, del };
			temp = temp->pNext;
		}
		cout << current->num << '/' << current->den<<endl;


	}
	void delbynumb(List lst, Node nd) {
		for (int i = 0; i < Size; i++) {
			if (lst[i].num == nd.num && lst[i].den == nd.den) {
				removeAt(i);
			}
		}
	}
	void push_next(List lst) {
		int* array = georgeCantor(++check);
		int num = array[0];
		int den = array[1];
		lst.push_back(num, den);
		Size++;
		check++;
	}
	void clear() {
		for (int i = 0; i < Size; i++) {
			pop_front();
		}
	}
};
int main() {
	List  lst;
	int n = 0;
	cout << "Enter the number of numbers that we will write in the list after the diagonal Cantor method" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int* array = georgeCantor(i);
		int num = array[0];
		int den = array[1];
		lst.push_back(num, den);

	}
	cout << "What you want?" << endl
		<< "1:print all numbers" << endl
		<< "2: find number by index" << endl
		<< "3:remove the number by index from the list" << endl
		<< "4:remove the specified number from the list" << endl
		<< "5:the sum of all elements in the list" << endl
		<< "6:adding the next number according to the diagonal Cantor method" << endl
		<< "7:log out" << endl;
	int choice=1;
	while (choice != 7) {
		cin >> choice;

		switch (choice) {
		case 1: {
			for (int i = 0; i < lst.Size; i++) {
				cout << lst[i].num << '/' << lst[i].den << endl;
			}
			break;
		}
		case 2: {
			cout << "Enter index" << endl;
			int index = 0;
			cin >> index;
			if (index > 0 && index < lst.Size) {
				cout << lst[--index].num << '/' << lst[index].den << endl;
			}
			break;
		}
		case 3: {
			cout << "Enter index" << endl;
			int index = 0;
			cin >> index;
			if (index > 0 && index < lst.Size) {
				lst.removeAt(--index);
			}
			break;
		}
		case 4: {
			int num = 0, den = 0;
			char str[1024];
			cout << "Enter a rational fraction" << endl;
			cin >> str;
			char sep[2] = "/";
			char* istr;
			istr = strtok(str, sep);
			num = atoi(istr);
			istr = strtok(NULL, sep);
			den = atoi(istr);
			Node nd = { num, den };
			lst.delbynumb(lst, nd);
			break;
		}
		case 5: {
			cout << "The sum of all elements: " << endl;
			lst.sum();
			break;
		}
		case 6: {
			cout << "Adding the following element after Cantor's Diagonal method" << endl;
			lst.push_next(lst);
			break;
		}
		case 7:
		{
			cout << "Log out" << endl;
			lst.clear();
			break;
		}
		default: {
			cout << "Wrong input! Try again!" << endl;
			break;
		}
		}
	}
	
	return 0;
}