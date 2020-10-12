#include<iostream>
#include "LibSwitch.h"
using namespace std;


//���� ����� ����� K. ������� ������-�������� ������, ��������������� ����� K(1 � ������, 2 � ��������������������, 3 � ���������� - ��������, 4 � �������, 5 � ��������).���� K �� ����� � ��������� 1�5, �� ������� ������ �������.
void  case2() {
    setlocale(LC_ALL, "Russian");
    int k;
    cin >> k;
    if (k >= 1 && k <= 5) {
        switch (k) {
        case 1: cout << "�����" << endl;
        case 2: cout << "�������������������" << endl;
        case 3: cout << "�����������������" << endl;
        case 4: cout << "������" << endl;
        case 5: cout << "�������" << endl;
        }
    }
    else
        cout << "������" << endl;
}
// ��� ����� ������ � ����� ����� � ��������� 1�12 (1 � ������, 2 ������� � �.�.).���������� ���������� ���� � ���� ������ ��� ������������� ����.
void case4() {
    int month;
    cout << "Number month:";
    cin >> month;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: cout << "31 day" << endl; break;
    case 4:
    case 6:
    case 9:
    case 11: cout << "30 days" << endl; break;
    case 2:cout << "28 days" << endl; break;
    default: cout << "error";




    }
}
//�������������� �������� ��� ������� ������������� ����������������: 1 � ��������, 2 � ���������, 3 � ���������, 4 � �������.��� ����� �������� N(����� ����� � ��������� 1�4) � ������������ ����� A � B(� �� ����� 0).��������� ��� ������� ��������� �������� � ������� ���������.
void case5() {
    float a, b;
    cout << "Enter number";
    cin >> a >> b;
    int n;
    cout << "Enter number of operation";
    cin >> n;
    switch (n) {
    case 1: cout << a + b; break;
    case 2: cout << a - b; break;
    case 3: cout << a * b; break;
    case 4: cout << a / b; break;
    default: cout << "error";


    }


}
//������� ����� ������������� ��������� �������: 1 � ���������,2 � ����������, 3 � �����, 4 � �����, 5 � �������.��� ����� ������� �����(����� ����� � ��������� 1�5) � ����� ���� � ���� ��������(����c������� �����).����� ����� ���� � �����������.
void case7() {
    int massa;
    cout << "Enter massa";
    cin >> massa;
    int n;
    cout << "Enter number of operation ";
    cin >> n;
    switch (n) {
    case 1: cout << massa << "kg"; break;
    case 2: cout << massa / 100000 << "kg"; break;
    case 3: cout << massa / 1000 << "kg"; break;
    case 4: cout << massa * 1000 << "kg"; break;
    case 5: cout << massa * 100 << "kg"; break;
    default: cout << "error" << endl;
    }

}
//���� ��� ����� �����: D (����) � M (�����), ������������ ���������� ���� ������������� ����.������� �������� D � M ��� ����, ��������� �� ���������.
void case9() {
    int day, month;
    cin >> day >> month;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:if (day == 31) { day = 0; month++; } break;
    case 12: if (day == 31) { day = 0; month = 1; } break;
    case 4:
    case 6:
    case 9:
    case 11: if (day == 30) { day = 0; month++; }; break;
    case 2: if (day == 28) { day = 0; month++; } break;
    }
    day++;
    cout << "Next day:" << day << endl;
    cout << "Month" << month;



}
//���� ����� ����� � ��������� 100�999. ������� ������-������� ������� �����, ��������: 256 � ������� ��������� ������, 814 � ���������� �������������.
void case18() {
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    switch (n / 100)
    {
    case 1:cout << "���"; break;
    case 2:cout << "������"; break;
    case 3:cout << "������"; break;
    case 4:cout << "���������"; break;
    case 5:cout << "���m���"; break;
    case 6:cout << "��������"; break;
    case 7:cout << "�������"; break;
    case 8:cout << "���������"; break;
    case 9:cout << "���������"; break;
    }
    switch (n / 10 % 10)
    {
    case 1:cout << " ������"; break;
    case 2:cout << " ��������"; break;
    case 3:cout << " ��������"; break;
    case 4:cout << " �����"; break;
    case 5:cout << " ���������"; break;
    case 6:cout << " ����������"; break;
    case 7:cout << " ���������"; break;
    case 8:cout << " �����������"; break;
    case 9:cout << " ���������"; break;
    }
    switch (n % 100)
    {
    case 11:cout << " ����������"; break;
    case 12:cout << " ���������� "; break;
    case 13:cout << " ����������"; break;
    case 14:cout << " ������������"; break;
    case 15:cout << " ���������� "; break;
    case 16:cout << " ����������� "; break;
    case 17:cout << " ���������� "; break;
    case 18:cout << " ������������"; break;
    case 19:cout << " ������������"; break;
    }
    switch (n % 10) {
    case 1:cout << " ���� "; break;
    case 2:cout << " ��� "; break;
    case 3:cout << " ��� "; break;
    case 4:cout << " ������ "; break;
    case 5:cout << " ���� "; break;
    case 6:cout << " ����� "; break;
    case 7:cout << " ���� "; break;
    case 8:cout << " ������ "; break;
    case 9:cout << " ������ "; break;


    }
}
//� ��������� ��������� ������ 60-������ ����, ��������� �� 12-������ ���������, ������������ ���������� ����� : �������, �������, ������, ����� � ������.� ������ �������� ���� ����� �������� �������� : �����, ������, �����, �����, �������, ����, ������, ����, ��������, ������, ������ � ������.�� ������ ���� ���������� ��� ��������, ���� 1984 ��� � ������ ����� : ���� ������� ������.
void case19() {
    setlocale(LC_ALL, "Russian");
    int year;
    cin >> year;
    cout << "��� ";
    switch (year % 10) {
    case 0:
    case 1: cout << "���"; break;
    case 2:
    case 3: cout << "����"; break;
    case 4:
    case 5: cout << "�����"; break;
    case 6:
    case 7: cout << "�����"; break;
    case 8:
    case 9: cout << "����"; break;

    }
    switch (year % 12) {
    case 0: cout << "�� ��������"; break;
    case 1: cout << "�� ������"; break;
    case 2: cout << "�� ������"; break;
    case 3: cout << "�� ������"; break;
    case 4: cout << "�� �����"; break;
    case 5: cout << "�� ������"; break;
    case 6: cout << "��� �����"; break;
    case 7: cout << "��� �����"; break;
    case 8: cout << "��� �������"; break;
    case 9: cout << "�� ����"; break;
    case 10: cout << "�� ������"; break;
    case 11: cout << "�� ����"; break;


    }

}
//���� ��� ����� �����: D (����) � M (�����), ������������ ���������� ����.������� ���� �������, ��������������� ���� ���� : �������� (20.1�18.2), ������(19.2�20.3), �����(21.3�19.4), �������(20.4�20.5),����������(21.5�21.6), ����(22.6�22.7), ����(23.7�22.8), ����� (23.8�22.9), ������(23.9�22.10), ���������(23.10�22.11), ��������� (23.11�21.12), ��������(22.12�19.1).
void case20() {
    setlocale(LC_ALL, "Russian");
    int day, month;
    cout << "Enter day:";
    cin >> day;
    cout << "Enter month:";
    cin >> month;

    switch (month) {
    case 1:
        if (day > 19) cout << "�������";
        else cout << "�������";
        break;
    case 2:
        if (day > 18) cout << "����";
        else cout << "�������";
        break;
    case 3:
        if (day > 20) cout << "����";
        else cout << "����";
        break;
    case 4:
        if (day > 19) cout << "�����";
        else cout << "����";
        break;
    case 5:
        if (day > 20) cout << "��������";
        else cout << "�����";
        break;
    case 6:
        if (day > 21) cout << "���";
        else cout << "��������";
        break;
    case 7:
        if (day > 22) cout << "���";
        else cout << "���";
        break;
    case 8:
        if (day > 22) cout << "����";
        else cout << "���";
        break;
    case 9:
        if (day > 22) cout << "����";
        else cout << "����";
        break;
    case 10:
        if (day > 22) cout << "��������";
        else cout << "����";
        break;
    case 11:
        if (day > 22) cout << "�������";
        else cout << "��������";
        break;
    case 12:
        if (day > 21) cout << "�������";
        else cout << "�������";
        break;
    }

}


