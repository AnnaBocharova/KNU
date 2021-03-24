#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* prev = nullptr;
	Node* pNext = nullptr;
};

struct List {
	Node* head = nullptr;
	int size = 0;
	void push_back(int data) {
		if (head == nullptr) {
			head = new Node{ data };
			size++;
		}
		else {
			Node* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new Node{ data };
			current->pNext->prev = current;
			size++;
		}
	}

	void new_list(List& lst) {
		Node* current = lst.head;
		while (current->pNext) {
			current = current->pNext;
		}

		while (current->prev) {
			if (current->data == current->prev->data) {
				Node* temp = current;
				current = current->prev;
				current->pNext = temp->pNext;
				delete temp;
				lst.size--;

			}
			else {
				current = current->prev;
			}
		}


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
		
};



int main() {
	List lst;
	lst.push_back(1);
	lst.push_back(1);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(1);
	lst.push_back(7);
	lst.push_back(7);
	lst.push_back(1);
	for (int i = 0; i < lst.size; i++) {
		cout << lst[i].data;
	}
	cout << endl;
	lst.new_list(lst);
	for (int i = 0; i < lst.size; i++) {
		cout << lst[i].data;
	}
	cout << endl;
	cout << endl;
	

	return 0;
}