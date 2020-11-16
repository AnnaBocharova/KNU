
/*Описать структуру с именем ZNAK, содержащую следующие ноля :
• фамилия, имя;
• знак Зодиака;
• день рождения(массив из трех чисел).
2. Написать программу, выполняющую следующие действия :
• ввод с клавиатуры данных в массив, состоящий из восьми элементов тина
ZNAK; записи должны быть упорядочены по датам дней рождения;
• вывод на экран информации о человеке, чья фамилия введена с клавиатуры;
• если такого нет, выдать на дисплей соответствующее сообщение.*/
//

#include<iostream>

using namespace std;
struct Znak {
   static const int z = 200;
    char Surname[z];
    char Name[z];
    char zodiak[z];
    int date[3];
} array[8];


void fillUser(Znak* array, const int n) {

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Enter surname: ";
            cin >> array[i].Surname;
            bool isValueWord = true;
            int j = 0;

            while (array[i].Surname[j] != '\0') {
                if (!isalpha(array[i].Surname[j])) {
                    isValueWord = false;
                    break;
                }

                j++;
            }
            if (isValueWord && strlen(array[i].Surname) > 2)
            {
                break;
            };
            if (!isValueWord || strlen(array[i].Surname) <= 2) {
                std::cout << "Surname has other characters or so short! Try again " << endl;;
            }
        }
        while (true) {
            cout << "Enter name: ";
            cin >> array[i].Name;
            bool isValueWord = true;
            int j = 0;

            while (array[i].Name[j] != '\0') {
                if (!isalpha(array[i].Name[j])) {
                    isValueWord = false;
                    break;
                }

                j++;
            }
            if (isValueWord && strlen(array[i].Name) > 2)
            {
                break;
            };
            if (!isValueWord || strlen(array[i].Name) <= 2) {
                std::cout << "Name has other characters or so short! Try again " << endl;;
            }
        }
        while (true) {
            cout << "Enter zodiak: ";
            cin >> array[i].zodiak;
            bool isValueWord = true;
            int j = 0;

            while (array[i].zodiak[j] != '\0') {
                if (!isalpha(array[i].zodiak[j])) {
                    isValueWord = false;
                    break;
                }

                j++;
            }
            if (isValueWord && strlen(array[i].zodiak) > 2)
            {
                break;
            };
            if (!isValueWord || strlen(array[i].zodiak) <= 2) {
                std::cout << "Zodiak has other characters or so short! Try again " << endl;;
            }
        }
        while (true) {
            cout << "Enter date of birth: ";
            for (int j = 0; j < 3; j++) {
                cin >> array[i].date[j];
            }
                                
                if ((array[i].date[0] > 0 && array[i].date[0] < 32)&& (array[i].date[1] > 0 && array[i].date[1] < 13)&& (array[i].date[2] > 0 && array[i].date[2] < 2021)) break;
                else
                    cout << "The date is in the wrong range, try again:";
            }
        }
           
    }
    void show(Znak * array, const int n) {
        for (int i = 0; i < n; i++) {
            cout << "Surname: " << array[i].Surname << endl;
            cout << "Name: " << array[i].Name << endl;
            cout << "Zodiak:" << array[i].zodiak << endl;
            cout << "Date of birth: ";
            for (int j = 0; j < 3; j++) {
                cout << array[i].date[j] << ".";
            }
            cout << endl;
        }
    }

    void sortbydate(Znak * array, const int n) {

        Znak tmp;
        bool isolder = true;
        for (int l = 0; l < n - 1; l++) {
            for (int i = 0, j; i < n - 1; i++) {
                isolder = false;
                j = i + 1;
                if (array[i].date[2] > array[j].date[2]) {
                    isolder = true;
                }
                else if (array[i].date[2] == array[j].date[2]) {
                    if (array[i].date[1] > array[j].date[1]) {
                        isolder = true;
                    }
                    else if (array[i].date[1] == array[j].date[1]) {
                        if (array[i].date[0] > array[j].date[0]) {
                            isolder = true;
                        }
                    }
                }
                if (isolder) {
                    tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }
            }

        }


    }
    void findInform(Znak * array, const int n) {
        char find[25];
        int mark = 0;

        cout << "Enter the last name of the person you are looking for: ";
        cin >> find;
        cout << "Information: " << endl;
        for (int i = 0; i < n; i++) {
            if (strcmp(array[i].Surname, find) == 0) {
                cout << "Surname: " << array[i].Surname << endl;
                cout << "Name: " << array[i].Name << endl;
                cout << "Zodiak:" << array[i].zodiak << endl;
                cout << "Date of birth: ";
                for (int j = 0; j < 3; j++) {
                    cout << array[i].date[j] << ".";
                }
                cout << endl;
                mark = 1;
            }
        }
        if (mark == 0)
            cout << "Error!User is not found" << endl;

    }



    int main() {
    const int n = 8;
    Znak object[n];
    fillUser(object, n);
    //show(object, n);
    sortbydate(object, n);
    show(object, n);
    findInform(object, n);
    return 0;  
    }