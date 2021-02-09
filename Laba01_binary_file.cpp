
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string>
#include<algorithm>
#include<iterator>
#define QUESTIONS "questions.txt"
#define ANSWERS "answers.txt"
#define PERSONANSWER "personanswers.dat"
#define USER  "logpass.dat"
#define NEWFILE "newfile.dat"
#define NEWANSWER "newanswer.dat"
using namespace std;

typedef struct PersonKey {
	long long id;
	char login[64];
	long long password;
	bool isnotdelete;
	long offset;

} PersonKey;

FILE* openfile(const char* namefile) {
	
	FILE* file = fopen(namefile, "ab");
	if (!file) {
		return nullptr;
	}
	return file;
}


int equalusers(const char* namefile, const PersonKey& new_user) {
	FILE* fp = fopen(namefile, "rb");
	PersonKey user;
	int counter = 0;
	while (fread(&user, sizeof(PersonKey), 1, fp)) {
		if (strcmp(user.login, new_user.login) == 0) {
			counter++;
		}
	}
	return counter;
 }


long long hesh(char *array) {
	const int k = 31, mod = 1e9 + 7;
	long long h = 0, m = 1;
	long size = (sizeof(array)) / sizeof(array[0]);

	for (int i = 0; i < size; i++ ) {
		int x = (int)(array[i] - 'a' + 1);
		h = (h + m * x) % mod;
		m = (m * k) % mod;
	}
	return h;
}


bool isNotNewPerson(const char* namefile, const PersonKey&  new_user,  int counter)
{
	FILE* file = fopen(namefile, "rb");

	if (!file)
	{
		cout<<"Error openning file!";
		return false;
	}
	fseek(file, 0, SEEK_SET);
	PersonKey user;
	for (int i = 0; i < counter; i++) {
		if (fread(&user, sizeof(struct PersonKey), 1, file) != 1)
		{
			cout<<"Error!";
			fclose(file);
			return false;
		}
		
		if (strcmp(user.login, new_user.login)==0) {
			return true;
		}

	}
	
	fclose(file);

	return false;
}


bool isLogPerson(const char* namefile, const PersonKey&  new_user, int counter){
	FILE* file = fopen(namefile, "rb");
	fseek(file, 0, SEEK_SET);
		PersonKey user;
		for (int i = 0; i < counter; i++) {
			if (fread(&user, sizeof(struct PersonKey), 1, file) != 1)
			{
				cout<<"Error!";
				fclose(file);
				return false;
			}

			if ((strcmp(user.login, new_user.login)==0)&&(user.password== new_user.password)) {
				return true;
			}

		}
	
	fclose(file);
	return false;
}


int countLine(const char* namefile) {
	int lines = 0;
	char eofornot;
	FILE* file = fopen(namefile, "r");
	if (file == NULL) {
		cout<<"Error opening file with questions";
		return -1;
	}
	do {
		eofornot = fgetc(file);
		if (eofornot == '\n') {
			++lines;
		}

	} while (eofornot != EOF);

	fclose(file);
	return lines;
}


void createOnePerson(FILE* keys, FILE* peranswer, const char* namefile, int counter) {
	PersonKey person;
	person.id = counter;
	cout << "Enter login:";
	char clogin[64];
	cin >> person.login;
	cout << "Enter password:";
	char chpassword[64];
	cin >> chpassword;
	long long i = hesh(chpassword);
	person.password = i;
	fseek(peranswer, 0, SEEK_END);
	person.offset = ftell(peranswer);
	fclose(peranswer);
	person.isnotdelete = true;
	bool isNotPerson = isNotNewPerson(namefile, person, counter);
	if (isNotPerson == true) {
		cout << "There is already a user with this login. Try again!";

	}
	else {
		fwrite(&person, sizeof(person), 1, keys);


		cout << "Take the survey\n";
		char quest[1024];
		char answer[512];
		int qcounter = countLine(QUESTIONS);
		int ancounter = countLine(ANSWERS);
		FILE* questions = fopen(QUESTIONS, "r");
		FILE* answers = fopen(ANSWERS, "r");
		FILE* personanswer = fopen(PERSONANSWER, "ab");
		if (questions == NULL || answers == NULL) {
			cout << "Error opening file!";
		}

		for (int i = 0; i < qcounter; i++) {
			fgets(quest, 1023, questions);
			cout << quest;
			for (int j = 0; j < 3; j++) {
				fgets(answer, 511, answers);
				cout << answer;
			}
			char buffer[2];
			do {
				cout << "Enter your answer: [a/b/c]\n";
				cin >> buffer;
				if (*buffer == 'a' || *buffer == 'b' || *buffer == 'c')
					fwrite(buffer, sizeof(buffer), 1, personanswer);
			} while (*buffer != 'a' && *buffer != 'b' && *buffer != 'c');
		}

	}
}


void read() {
	FILE* user = fopen(USER, "rb");
	PersonKey readuser;
	while (!feof(user))
	{
		if (fread(&readuser, sizeof(PersonKey), 1, user))
		{
			if (readuser.isnotdelete == true && equalusers(USER, readuser)==1) {
				cout << "ID: " << readuser.id << "    Login: " << readuser.login << "    Password: " << readuser.password << endl;
			}
		}
	}
	fclose(user);
}


void readinfouser(int index) {
	long useroffset=0;
	FILE* user = fopen(USER, "rb");
	PersonKey readuser;
	while (!feof(user))
	{
		fread(&readuser, sizeof(PersonKey), 1, user);
		if (readuser.id == index && equalusers(USER, readuser) == 1) {
			useroffset = readuser.offset;
			fclose(user);
			char answer;
			FILE* useranswer = fopen(PERSONANSWER, "rb");
			fseek(useranswer, useroffset, SEEK_SET);
			int counteranswer = countLine(QUESTIONS);
			cout << "User`s answer: ";
			for (int i = 0; i < counteranswer * 2; i++) {
				fread(&answer, sizeof(answer), 1, useranswer);
				cout << answer;
			}
			cout << endl;
			fclose(useranswer);
			break;
		}
	}
	
	
}


void deluser(int index) {
	FILE* users = fopen(USER, "a+b");
	fseek(users, 0, SEEK_SET);
	PersonKey readuser;
	fseek(users, 0, SEEK_SET);
	int colum = 0;
while (!feof(users)) {
	if (fread(&readuser, sizeof(readuser), 1, users) && readuser.isnotdelete && readuser.id == index) {
		readuser.isnotdelete = false;
		fpos_t cur_pos;
		fgetpos(users, &cur_pos);
		long  i = cur_pos - sizeof(PersonKey);
		fseek(users, i, SEEK_SET);
		fwrite(&readuser, sizeof(PersonKey), 1, users);
		cout << readuser.login << " deleted successfully\n";
		break;
	}


}

fclose(users);
}


void create() {
	cout << "Create new questions:\n";
	const int SIZE = 100;
	char str[SIZE];
	FILE* file = fopen(QUESTIONS, "a+");
	cin.ignore();
	cin.getline(str, SIZE);
	fwrite(&str, sizeof(str), 1, file);
	char ch = '\n';
	fwrite(&ch, sizeof(ch), 1, file);

	fclose(file);

	FILE* fileanswer = fopen(ANSWERS, "a+");
	for (int i = 0; i < 3; i++) {
		char inputanswer[100];
		cin.getline(inputanswer, 100);
		fwrite(&inputanswer, sizeof(inputanswer), 1, fileanswer);
		char ch = '\n';
		fwrite(&ch, sizeof(ch), 1, fileanswer);
	}
	fclose(fileanswer);
	cout << "New question recorded\n";

}


void updatefile(const char* namefile, FILE* quest, FILE* new_file, FILE* answer, FILE* new_answer) {
	PersonKey user;
	int counteranswer = countLine(QUESTIONS);
	int newid = 0;
	while (!feof(quest)) {
		if (fread(&user, sizeof(user), 1, quest) && equalusers(namefile, user) == 1) {
			user.id = newid;
			fwrite(&user, sizeof(user), 1, new_file);
			long useroffset = 0;
			useroffset = user.offset;
			fseek(answer, useroffset, SEEK_SET);
			char useranswer;
			for (int i = 0; i < counteranswer * 2; i++) {
				fread(&useranswer, sizeof(useranswer), 1, answer);
				fwrite(&useranswer, sizeof(useranswer), 1, new_answer);
			}
			newid++;

		}


	}
	fclose(quest);
	fclose(new_file);
	fclose(answer);
	fclose(new_answer);
}


void update() {
	FILE* quest = fopen(USER, "rb");
	FILE* new_file = fopen(NEWFILE, "wb");
	FILE* answer = fopen(PERSONANSWER, "rb");
	FILE* new_answer = fopen(NEWANSWER, "wb");
	updatefile(USER, quest, new_file, answer, new_answer);
	/*rename(NEWFILE, USER);
	rename(USER, NEWFILE);
	rename(NEWANSWER, PERSONANSWER);
	rename(PERSONANSWER, NEWANSWER);*/
	FILE* fquest = fopen(USER, "wb");
	FILE* fnew_file = fopen(NEWFILE, "rb");
	FILE* fanswer = fopen(PERSONANSWER, "wb");
	FILE* fnew_answer = fopen(NEWANSWER, "rb");
	updatefile(NEWFILE, fnew_file, fquest, fnew_answer, fanswer);

}


void deluserlogin(char* array) {
	FILE* users = fopen(USER, "a+b");
	fseek(users, 0, SEEK_SET);
	PersonKey readuser;
	fseek(users, 0, SEEK_SET);
	int colum = 0;
	while (!feof(users)) {
		if (fread(&readuser, sizeof(readuser), 1, users) && readuser.isnotdelete && memcmp(readuser.login, array, sizeof(readuser.login))==0) {
			readuser.isnotdelete = false;
				fpos_t cur_pos;
				fgetpos(users, &cur_pos);
				long  i = cur_pos - sizeof(PersonKey);
				fseek(users, i, SEEK_SET);
				fwrite(&readuser, sizeof(PersonKey), 1, users);
				cout << readuser.login << " deleted successfully\n";
				break;
		}
	}
}


void sql(char str[]) {
	char** words = NULL, * pntr = NULL;
	int counter = 0;
	for (pntr = strtok(str, " "); pntr != NULL; pntr = strtok(NULL, " ")) {
		if ((words = (char**)realloc(words, sizeof(char*) * (counter + 1))) == NULL) {
			cout << "Error!" << endl;
			exit(5);
		}
		if ((words[counter] = _strdup(pntr)) == NULL) {
			cout << "Error!";
			exit(5);
		}
		++counter;
	}

	if (strcmp(words[0], "SELECT") == 0 && strcmp(words[1], "from") == 0) {
		if (strcmp(words[counter - 3], "users") == 0) {
			if (strcmp(words[counter - 2], "id") == 0) {
				int index = stoi(words[counter - 1]);
				readinfouser(index);
			}
		}
	}
	else if (strcmp(words[0], "DELETE") == 0 && strcmp(words[1], "from") == 0) {
		if (strcmp(words[counter - 3], "users") == 0) {
			if ((strcmp(words[counter - 2], "id") == 0)) {
				int index = stoi(words[counter - 1]);
				deluser(index);
			}
			else if ((strcmp(words[counter - 2], "login") == 0)) {
				deluserlogin(words[counter - 1]);
			}
		}
		
	}
	
	for (int i = 0; i < counter; i++) {
		if (words[i] != NULL) {
			free(words[i]);
			words[i] = NULL;
		}
	}
	free(words);
	words = NULL;
}



void adminmenu() {
	cout << "Choose what you want:" << endl<<
	"1 - show information about all users"<<endl<<
		"2 - show answers of a specific user, "<<endl<<
		"3 - delete a user by index, "<< endl<<
		"4 - delete a user by login,"<<endl<<
		" 5 - create a new question,"<<endl<<
		"6 - update the system, "<<endl<<
		"7 - SQL requests" << endl <<
		"8 - log out account"<<endl;
	
	int choise=0;
	int index;
	char str[254];
	while (choise != 8) {
		cout << "Enter your choise: ";
		cin >> choise;
		switch (choise) {
		case 1: 
			read();
			break;
		case 2:
			cout << "Enter id: ";
			cin >> index;
			readinfouser(index);
			break;

		case 3: 
			cout << "Enter index to delete: ";
			cin >> index;
			deluser(index);
			break;
		
		case 4: 
			cout << "Enter login to delete: ";
			cin.getline(str, 253);
			deluserlogin(str);
			break;
		
		case 5: 
			create();
			break;
		
		case 6: 
			update();
			break;
		case 7:
			cin.ignore();
			cin.getline(str, 253);
			sql(str);
			break;
		case 8:
			cout << "You are signed out" << endl;
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
		
	}
	
}


int main() {
	PersonKey logPerson;
	FILE* keys = NULL;

	keys = openfile("logpass.dat");
	if (keys == 0) {
		cout<<"Error opening file";
	}
	FILE* personanswer = fopen(PERSONANSWER, "rb");

	int counter = 0;
	fseek(keys, 0, SEEK_END);
	long pos = ftell(keys);
	fseek(keys, 0, SEEK_SET);
	counter = pos / sizeof(PersonKey);

	cout<<"If you want to login please enter 'l',  if you want to register enter 'r'! [l/r]\n";
	char command[2];
    cin>> command;

	if (*command == 'r') {
		createOnePerson(keys,personanswer, "logpass.dat", counter);
	}

	else if (*command == 'l') {

		cout<<"Enter login:";
		cin>>logPerson.login;
		cout<<"Enter password:";
		char chpassword[64];
		cin >> chpassword;
		long long i = hesh(chpassword);
		logPerson.password = i;
		bool IsLoPerson = isLogPerson("logpass.dat", logPerson, counter);

		if (IsLoPerson) {
			bool IsAdmin = isLogPerson("logpass.dat", logPerson, 1);
			cout<< logPerson.login;
			if (IsAdmin) {
				cout<<" , hello administrator!\n";
				adminmenu();

				
			}
			else {
				cout<<" we are logged into your account";
			}
		}
		else {
			cout<<"Wrong input!";
		}
	}

	else {
		cout<<"Wrong input!";
	}


 return 0;
}
