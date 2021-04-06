#include<iostream>
#include <stdio.h>
#include <windows.h>
#include <direct.h>

using namespace std;

#define DICTIONARY "dictionary"
#define COPY "dictionary_copy"
const int SIZE_ARRAY = 30;

struct dictionary {
	char ukr[SIZE_ARRAY];
	char engl[SIZE_ARRAY];
	int counter;
};
struct Node_tree {
	dictionary data;
	Node_tree* right;
	Node_tree* left;
};


void Fill_file() {
	dictionary word;
	cout << "Enter the English word:";
	cin.ignore();
	cin.getline(word.engl, SIZE_ARRAY, '\n');
	cout << "Enter its translation into Ukrainian";
	cin.getline(word.ukr, SIZE_ARRAY, '\n');
	cout << "Enter the number of requests: ";
	cin >> word.counter;

	FILE* vocablurary;
	if (fopen_s(&vocablurary, DICTIONARY, "rb")) {
		perror("File isn`t open");
	}
	else {
		while (!feof(vocablurary)) {
			dictionary check;
			if (feof(vocablurary))
				break;
			fread(&check, sizeof(check), 1, vocablurary);
			if (strcmp(check.engl, word.engl)) {
				cout << "This word has already been written into the dictionary" << endl;
				return;
			}
		}

	}
	fclose(vocablurary);
	fopen_s(&vocablurary, DICTIONARY, "a+b");
	fwrite(&word, sizeof(word), 1, vocablurary);
	fclose(vocablurary);
}

int Check_alfa(char* word1,char*  word2, size_t size) {
	for (int i = 0; i < size; i++) {
		if (word1[i] != word2[i]) {
			return i;
		}
	}
	
}

void Add_Data (Node_tree*& tree, dictionary word ) {
	int check = 0;
	if (tree && tree->data.engl[0] == word.engl[0]) {
		 check = Check_alfa(tree->data.engl, word.engl, size(word.engl));
	}
	if (!tree) {
		tree = new Node_tree;
		tree->data = word;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else {
		if (word.engl[check] < tree->data.engl[check]) {
			Add_Data(tree->left, word);
		}
		else {
			Add_Data(tree->right, word);
		}
	}
}

void Build_Tree(Node_tree*& tree) {
	FILE* vocablurary;
	if (fopen_s(&vocablurary, DICTIONARY, "rb")) {
		perror("File isn`t open");
	}
	else {
		while (!feof(vocablurary)) {
			dictionary word;
			if (feof(vocablurary))
				break;
			fread(&word, sizeof(word), 1, vocablurary);
			Add_Data(tree, word);
		}
	}
}


void New_counter(dictionary word) {
	FILE* fp;
	FILE* copy_fp;

	if (fopen_s(&fp, DICTIONARY, "rb") || fopen_s(&copy_fp, COPY, "wb")) {
		perror("Error");
	}
	else {
		while (!feof(fp)) {
			dictionary check;
			fread(&check, sizeof(check), 1, fp);
			if (feof(fp))
				break;
			fwrite(&check, sizeof(check), 1, copy_fp);
		}
		fclose(fp);
		fclose(copy_fp);
	}
	if (fopen_s(&fp, "dictionary.dat", "wb") || fopen_s(&copy_fp, "dictionary_copy.dat", "rb")) {
		perror("Error");
	}
	else {
		while (!feof(copy_fp)) {
			dictionary check;
			fread(&check, sizeof(check), 1, copy_fp);
			if (feof(copy_fp))
				break;
			if (strcmp(word.engl, check.engl)) {
				word.counter++;
			}
			fwrite(&check, sizeof(check), 1, fp);
		}
		fclose(fp);
		fclose(copy_fp);
	}
	remove(COPY);
}

void Find_Max_Counter(Node_tree*& tree, dictionary &word, int &max ) {
	if (tree) {
		Find_Max_Counter(tree->left, word, max);
		if (tree->data.counter >= max) {
			max = tree->data.counter;
			word = tree->data;
		}
		Find_Max_Counter(tree->right, word, max);
	}
}

void Delete_Max(Node_tree*& tree, dictionary word) {
	if (tree) {
		Delete_Max(tree->left, word);
		if (strcmp(tree->data.engl, word.engl)) {
			for (int i = 0; i < size(tree->data.engl); i++)
				tree->data.engl[i] = NULL;
			for (int i = 0; i < size(tree->data.ukr); i++)
				tree->data.ukr[i] = NULL;
			tree->data.counter = INT_MIN;
		
		}
		Delete_Max(tree->right, word);
	}
}

void Add_By_Counter(Node_tree*& tree, dictionary word) {
	if (!tree) {
		tree = new Node_tree;
		tree->data = word;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else {
		if (word.counter<= tree->data.counter) {
			Add_By_Counter(tree->left, word);
		}
		
		else {
			Add_By_Counter(tree->right, word);
		}
	}
}
bool Isnotempty (Node_tree* tree)
{
	if (tree)
	{
		Isnotempty(tree->left);
		if (tree->data.counter != INT_MIN)
			return true;
		else Isnotempty(tree->right);
	}
	return false;
}

void Delete_tree(Node_tree*& tree) {
	if (!tree) {
		return;
	}
	Delete_tree(tree->left);
	delete tree;
	Delete_tree(tree->right);
	return;
}
void Build_new_tree(Node_tree*& old_tree, Node_tree*&new_tree) {
	dictionary new_word;
	int max;
	Find_Max_Counter(old_tree, new_word, max);
	Delete_Max(old_tree, new_word);
	Add_By_Counter(new_tree, new_word);
	if (Isnotempty(old_tree)) {
		Build_new_tree(old_tree, new_tree);
	}
	Delete_tree(old_tree);
}

void Print_tree(Node_tree* tree, int level)
{
	if (tree)
	{
		Print_tree(tree->left, level + 1);
		for (int i = 0; i < level; i++)
			cout << "	";
		cout << tree->data.engl << " " << tree->data.counter << endl;
		Print_tree(tree->right, level + 1);
	}
}

void Find_ukr_version(Node_tree*& tree, dictionary& word) {
	if (tree) {
		Find_ukr_version(tree->left, word);
		if (strcmp(word.engl, tree->data.engl)) {
			word = tree->data;
			tree->data.counter++;
		}
		Find_ukr_version(tree->right, word);
	}
}


void Find_Translation(Node_tree*& tree) {
	dictionary word;
	cout << "Enter the word you want to translate: ";
	cin.ignore();
	cin.getline(word.engl, size(word.engl), '\n');
	Find_ukr_version(tree, word);
	cout << "Translation: " << word.ukr << endl;
	New_counter(word);

}

void menu(Node_tree*& Tree_By_Alphabet,Node_tree*& Tree_By_Counter, bool &check_old_tree, bool &check_new_tree) {
	cout << "What do you want to do?" << endl
		<< "---------1. Add a new word" << endl
		<< "---------2. Build tree alphabetically" << endl
		<< "---------3. Find the translation of a word" << endl
		<< "---------4. Build a tree based on the number of queries for a word" << endl
		<< "_______________________________________________________________________" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case(1): {
		Fill_file();
		break;
	}
	case(2): {
		if (check_old_tree)
			Delete_tree(Tree_By_Alphabet);
		Build_Tree(Tree_By_Alphabet);
		Print_tree(Tree_By_Alphabet, 0);
		check_old_tree = true;
		cout << endl << endl;
		break;
	}
	case(3): {
		if (!check_old_tree) 
			Build_Tree(Tree_By_Alphabet);
		Find_Translation(Tree_By_Alphabet);
		break;
	}
	case(4): {
		if (check_new_tree) {
			Delete_tree(Tree_By_Counter);
			Tree_By_Counter = NULL;
		}
		if (!Tree_By_Alphabet || Tree_By_Alphabet->data.counter == INT_MIN)
			Build_Tree(Tree_By_Alphabet);
		Build_new_tree(Tree_By_Alphabet, Tree_By_Counter);
		Print_tree(Tree_By_Counter, 0);
		cout << endl;
		break;
		   }
	}


}

int main() {
	setlocale(LC_ALL, " ");
	Node_tree* Tree_By_Alphabet = NULL;
	Node_tree* Tree_By_Counter = NULL;
	bool check_alphabet = false;
	bool check_counter = false;
	bool notshutdown = true;
	int choise = 0;
	while (notshutdown)
	{
		cout << "What do you want to do?" << endl
			<< "1 - Continue" << endl << "2 - Finish" << endl << "_______" << endl;
		int choice;
		cin >> choise;
		switch (choise)
		{
		case 1:
			menu(Tree_By_Alphabet, Tree_By_Counter, check_alphabet, check_counter);
			break;
		case 2:
			cout << "The work has been completed" << endl;
			notshutdown = false;
		default:
			break;
		}
	}
	return 0;
}