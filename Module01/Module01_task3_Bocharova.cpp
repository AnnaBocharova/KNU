#include<iostream>
#include<fstream>

const int SIZE=100;
const int MAX = 100;
const int N = 5;
using namespace std;

 template<typename T>
struct Node {
	T data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

template<typename T>
struct List {
	Node<T>* head = nullptr;
	Node<T>* top = nullptr;
	size_t size = 0;

	void push(T data) {
		if (!head) {
			head = new Node<T>{data};
			top = head;
		}
		else {
			top->next = new Node<T>	{ data };
			top->next->prev = top;
			top = top->next;
		}
		++size;
	}
	
	void print() {
		Node<T>* current = head;
		cout << "{ ";
		while (current) {
			cout << current->data<<", ";
			current = current->next;
		}
		cout << "}" << endl;
		cout << endl;
	}

	void clear() {
		if (!top) return;
		while (top->prev) {
			top = top->prev;
			delete top->next;
			top->next = nullptr;
		}
		delete top;
	 }
};





List<int>* randomList() {
	auto* lst = new List<int>;
	for (int i = 0; i < SIZE; i++) {
		lst->push(rand() % MAX + 1);
	}
	return lst;
}


int SumDigitModN(int digit) {
	int sum = 0;
	while (digit) {
		sum += digit % 10;
		digit /= 10;
	}
	int result = sum % N;
	return result;
}


List<List<int>*>* listOfList(List<int> &lst) {
	auto* data = new List<List<int>*> {};

	List<int>* value[N] = {};
	for (int i = 0; i < N; i++) {
		value[i] = new List<int> ();
		data->push(value[i]);
	}

	Node<int>* temp = lst.head;
	while (temp) {
		int result = SumDigitModN(temp->data);
		value[result]->push(temp->data);
		temp = temp->next;
	}
	
	return data;
}


template<typename T>
void printListofList(List<List<T>*>& lst) {
	Node<List<T>*>* temp = lst.head;
	if (!temp) return;
	while (temp) {
		temp->data->print();
		temp = temp->next;
	}
}

 
bool findvalue(List<List<int>*>* lstoflst, int value) {
	int result = SumDigitModN(value);

	auto* lst = lstoflst->head;
	for (int i = 0; i < result; i++) {
		lst = lst->next;
	}
	auto* nodelist = lst->data->head;
	while (nodelist) {
		if (nodelist->data == value) {
			return true;
		}
		nodelist = nodelist->next;
	}
	return false;
}

int main() {
	auto* lst = randomList();
	lst->print();
	cout << endl <<endl;
	List<List<int>*>* listoflist = listOfList(*lst);
	printListofList(*listoflist);
	cout << "Enter value: ";
	int value;
	cin >> value;
	if (findvalue(listoflist, value)) {
		cout << value << " is find" << endl;
	}
	else
		cout << value << " is not find" << endl;
	return 0;
}