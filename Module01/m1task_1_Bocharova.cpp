#include<iostream>
using namespace std;
const int SIZE = 100;
struct Stack {
	int data[SIZE];
	int size=0;
};

void Push(Stack &stack, int digit) {
	if (stack.size == SIZE) {
		cout << "Stack is full" << endl;;
		return;
	}
	stack.data[stack.size] = digit;
	stack.size++;
}

int Pop(Stack &stack) {
	if (stack.size == 0) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	stack.size--;
	return stack.data[stack.size];
}

int main() {
	FILE* fp;
	if (fopen_s(&fp, "task1.txt", "r"))
		perror("Error!");

	char str[100];
	fgets(str, sizeof(str), fp);

	cout << str<<endl;
	int digit;
	bool isnotoperation = false;
	Stack S;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i])) {
			digit = str[i] - '0';
			Push(S, digit);
		}
		else {
			int digit1 = Pop(S);
			int digit2 = Pop(S);
			int result=0;
			switch (str[i]) {
			case '+': {
				result = digit1 + digit2;
				break;
			}
			case '-': {
				result = digit1 - digit2;
				break;
			}
			case '*':
			{
				result = digit1 * digit2;
				break;
			}
			default: {
				cout << "This symbol is not a sign of an operation" << endl;
				isnotoperation = true;
				break;
			}
			}
			if(!isnotoperation)
			Push(S, result);
		}
		if (isnotoperation) {
			break;
			
		}
	}
	if(!isnotoperation)
	cout << "Result: " << Pop(S)<<endl;


	return 0;
}