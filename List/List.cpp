#include<iostream>
using namespace std;
//добавление/удаление в начале, конце, по индексу
template<typename T>
class List

{
public:
	List();
	~List();
	int GetSize() {
		return Size;
	}
	T& operator[] (const int index);
	void push_back(T data);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();
	

private:
	template<typename T>
	class Node {
	public: 
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext=nullptr) {
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;
	Node<T> *head;

};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();
}


//добавление в конец списка
template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current=this->head; 
		while (current->pNext!=nullptr) {
			current = current->pNext;
		}
		current -> pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T & List<T>::operator[] (const int index) {
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}


//удаление элемента с начала списка
template<typename T>
void List<T>::pop_front() {
	Node<T> *temp = head;
	head = head->pNext;
	delete temp; 
	Size--; 
}

//удаление всех элементов списка
template<typename T>
void List<T>::clear() {
	while (Size) {
		pop_front();
	}
}

//добавление в начало списка
template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head); 
	Size++;
}



//вставка после указанного индекса
template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* prev = this->head;
		for (int i = 0; i < index - 1; i++) {
			prev = prev->pNext;
		}
		Node<T>* newNode = new Node<T>(data, prev->pNext);
		prev->pNext = newNode;
		Size++;
	}

}



//удаление по индексу
template<typename T>
void List<T>::removeAt( int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T> *prev = this->head;
		for (int i = 0; i < index - 1; i++) {
			prev = prev ->pNext;
		}
		Node<T>* temp = prev->pNext;
		prev->pNext = temp->pNext;
		delete temp;
		Size--;
	}
}



//удаление последнего элемента в списке
template<typename T>
void List<T>::pop_back() {
	removeAt(Size - 1);
}



int main() {
	List <int> lst;
	lst.push_back(27);
	lst.push_front(5);
	lst.push_back(100);
	lst.push_back(4);
	lst.insert(85, 1);
	
	
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << endl;
	lst.pop_back();
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i] << endl;
	}
	return 0;
}