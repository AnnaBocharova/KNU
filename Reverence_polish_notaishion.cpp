#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Stack {
	char c;
	Stack* next;
}*top;
int Prior(char);
Stack* InS(Stack*, char);
Stack* OutS(Stack*, char&);
double Result(char*);
double arr[4];
int Prior(char a) {
	switch (a) {
	case'*':
	case'/': return 3;
	case'-':
	case'+':
		return 2;
	case '(': return 1;
	}
	return 0;
}
Stack* InS(Stack* p, char out) {
	Stack* t = new Stack;
	t->c = out;
	t->next = p;
	return t;
}
Stack* OutS(Stack* p, char& in) {
	Stack* t = p;
	in = p->c;
	p = p->next;
	delete t;
	return p;
}
void main() {
	setlocale(LC_ALL, "rus");
	Stack* t, * Op = NULL;
	char a, In[81], Out[81];
	int k = 0, l = 0; 
	cout << "Enter formuly:";
	cin >> In;
	while (In[k] != '\0') {
		if (In[k] >= 'a' && In[k] <= 'z')
			Out[l++] = In[k];
		if (In[k] == '(')
			Op = InS(Op, In[k]);
		if (In[k] == ')') {
			while ((Op->c) != '(') {
				Op = OutS(Op, a);
				if (!Op)
					a = '\a';
				Out[l++] = a;
			}
			t = Op;
			Op = Op->next;
			delete t;
		}
		if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/') {
			while (Op != NULL && Prior(Op->c) >= Prior(In[k])) {
				Op = OutS(Op, a);
				Out[l++] = a;
			}
			Op = InS(Op, In[k]);
		}
		k++;
	}
	while (Op != NULL) {
		Op = OutS(Op, a);
		Out[l++] = a;
	}
	Out[l] = '\0';
	cout << "\n Polish=" << Out << endl;
	cout << "Res=" << fixed << setprecision(2) << Result(Out) << endl;
}
double Result(char* str) {
	int i;
	char ss, ss1, ss2, ssR = 'z' + 1;
	double op1, op2, res = 0, mas[200];
	cout << "Input data" << endl;
	for (i = 0; str[i] != '\0'; ++i) {
		ss = str[i];
		if (ss >= 'a' && ss <= 'z') {
			cout << ss << "=";
			cin >> mas[int(ss)];
		}
	}
	for (i = 0; str[i] != '\0'; ++i) {
		ss = str[i];
		if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/'))
			top = InS(top, ss);
		else {
			top = OutS(top, ss2);
			top = OutS(top, ss1);
			op2 = mas[int(ss2)];
			op1 = mas[int(ss1)];
			switch (ss) {
			case'+':res = op1 + op2; break;
			case'-':res = op1 - op2; break; 
			case'*':res = op1 * op2; break;
			case'/':res = op1 / op2; break;

			}
			mas[int(ssR)] = res;
			top = InS(top, ssR);
			ssR++;
		}
	}
	return res;
}
