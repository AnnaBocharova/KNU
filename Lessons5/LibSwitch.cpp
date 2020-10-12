#include<iostream>
#include "LibSwitch.h"
using namespace std;


//Дано целое число K. Вывести строку-описание оценки, соответствующей числу K(1 — «плохо», 2 — «неудовлетворительно», 3 — «удовлетво - рительно», 4 — «хорошо», 5 — «отлично»).Если K не лежит в диапазоне 1–5, то вывести строку «ошибка».
void  case2() {
    setlocale(LC_ALL, "Russian");
    int k;
    cin >> k;
    if (k >= 1 && k <= 5) {
        switch (k) {
        case 1: cout << "плохо" << endl;
        case 2: cout << "неудовлетворительно" << endl;
        case 3: cout << "удовлитворительно" << endl;
        case 4: cout << "хорошо" << endl;
        case 5: cout << "отлично" << endl;
        }
    }
    else
        cout << "ошибка" << endl;
}
// Дан номер месяца — целое число в диапазоне 1–12 (1 — январь, 2 февраль и т.д.).Определить количество дней в этом месяце для невисокосного года.
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
//Арифметические действия над числами пронумерованы следующимобразом: 1 — сложение, 2 — вычитание, 3 — умножение, 4 — деление.Дан номер действия N(целое число в диапазоне 1–4) и вещественные числа A и B(В не равно 0).Выполнить над числами указанное действие и вывести результат.
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
//Единицы массы пронумерованы следующим образом: 1 — килограмм,2 — миллиграмм, 3 — грамм, 4 — тонна, 5 — центнер.Дан номер единицы массы(целое число в диапазоне 1–5) и масса тела в этих единицах(вещеcтвенное число).Найти массу тела в килограммах.
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
//Даны два целых числа: D (день) и M (месяц), определяющие правильную дату невисокосного года.Вывести значения D и M для даты, следующей за указанной.
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
//Дано целое число в диапазоне 100–999. Вывести строку-описани данного числа, например: 256 — «двести пятьдесят шесть», 814 — «восемьсот четырнадцать».
void case18() {
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    switch (n / 100)
    {
    case 1:cout << "сто"; break;
    case 2:cout << "двести"; break;
    case 3:cout << "триста"; break;
    case 4:cout << "четыреста"; break;
    case 5:cout << "пятmсот"; break;
    case 6:cout << "шестьсот"; break;
    case 7:cout << "семьсот"; break;
    case 8:cout << "восемьсот"; break;
    case 9:cout << "девятьсот"; break;
    }
    switch (n / 10 % 10)
    {
    case 1:cout << " десять"; break;
    case 2:cout << " двадцать"; break;
    case 3:cout << " тридцать"; break;
    case 4:cout << " сорок"; break;
    case 5:cout << " пятьдесят"; break;
    case 6:cout << " шестьдесят"; break;
    case 7:cout << " семьдесят"; break;
    case 8:cout << " восемьдесят"; break;
    case 9:cout << " девяносто"; break;
    }
    switch (n % 100)
    {
    case 11:cout << " одинадцать"; break;
    case 12:cout << " двенадцать "; break;
    case 13:cout << " тринадцать"; break;
    case 14:cout << " четырнадцать"; break;
    case 15:cout << " пятнадцать "; break;
    case 16:cout << " шестнадцать "; break;
    case 17:cout << " семнадцать "; break;
    case 18:cout << " восемнадцать"; break;
    case 19:cout << " девятнадцать"; break;
    }
    switch (n % 10) {
    case 1:cout << " один "; break;
    case 2:cout << " два "; break;
    case 3:cout << " три "; break;
    case 4:cout << " четыре "; break;
    case 5:cout << " пять "; break;
    case 6:cout << " шесть "; break;
    case 7:cout << " семь "; break;
    case 8:cout << " восемь "; break;
    case 9:cout << " девять "; break;


    }
}
//В восточном календаре принят 60-летний цикл, состоящий из 12-летних подциклов, обозначаемых названиями цвета : зеленый, красный, желтый, белый и черный.В каждом подцикле годы носят названия животных : крысы, коровы, тигра, зайца, дракона, змеи, лошади, овцы, обезьяны, курицы, собаки и свиньи.По номеру года определить его название, если 1984 год — начало цикла : «год зеленой крысы».
void case19() {
    setlocale(LC_ALL, "Russian");
    int year;
    cin >> year;
    cout << "год ";
    switch (year % 10) {
    case 0:
    case 1: cout << "бел"; break;
    case 2:
    case 3: cout << "черн"; break;
    case 4:
    case 5: cout << "зелон"; break;
    case 6:
    case 7: cout << "красн"; break;
    case 8:
    case 9: cout << "желт"; break;

    }
    switch (year % 12) {
    case 0: cout << "ой обезьяны"; break;
    case 1: cout << "ой курицы"; break;
    case 2: cout << "ой собаки"; break;
    case 3: cout << "ой свиньи"; break;
    case 4: cout << "ой крысы"; break;
    case 5: cout << "ой коровы"; break;
    case 6: cout << "ого тигра"; break;
    case 7: cout << "ого зайца"; break;
    case 8: cout << "ого дракона"; break;
    case 9: cout << "ой змеи"; break;
    case 10: cout << "ой лошади"; break;
    case 11: cout << "ой овцы"; break;


    }

}
//Даны два целых числа: D (день) и M (месяц), определяющие правильную дату.Вывести знак Зодиака, соответствующий этой дате : «Водолей» (20.1–18.2), «Рыбы»(19.2–20.3), «Овен»(21.3–19.4), «Телец»(20.4–20.5),«Близнецы»(21.5–21.6), «Рак»(22.6–22.7), «Лев»(23.7–22.8), «Дева» (23.8–22.9), «Весы»(23.9–22.10), «Скорпион»(23.10–22.11), «Стрелец» (23.11–21.12), «Козерог»(22.12–19.1).
void case20() {
    setlocale(LC_ALL, "Russian");
    int day, month;
    cout << "Enter day:";
    cin >> day;
    cout << "Enter month:";
    cin >> month;

    switch (month) {
    case 1:
        if (day > 19) cout << "Водолей";
        else cout << "Козерог";
        break;
    case 2:
        if (day > 18) cout << "Рыбы";
        else cout << "Водолей";
        break;
    case 3:
        if (day > 20) cout << "Овен";
        else cout << "Рыбы";
        break;
    case 4:
        if (day > 19) cout << "Телец";
        else cout << "Овен";
        break;
    case 5:
        if (day > 20) cout << "Близнецы";
        else cout << "Телец";
        break;
    case 6:
        if (day > 21) cout << "Рак";
        else cout << "Близнецы";
        break;
    case 7:
        if (day > 22) cout << "Лев";
        else cout << "Рак";
        break;
    case 8:
        if (day > 22) cout << "Дева";
        else cout << "Лев";
        break;
    case 9:
        if (day > 22) cout << "Весы";
        else cout << "Дева";
        break;
    case 10:
        if (day > 22) cout << "Скорпион";
        else cout << "Весы";
        break;
    case 11:
        if (day > 22) cout << "Стрелец";
        else cout << "Скорпион";
        break;
    case 12:
        if (day > 21) cout << "Козерог";
        else cout << "Стрелец";
        break;
    }

}


