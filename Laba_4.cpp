#include<iostream>
#include "Laba_4.h"


using namespace std;
// Дано рядок. Дописати до нього мінімальну кількість символів так, щоб він став паліндромом.

	
int findMinSymbol(char str[], int l, int h)
{
   
    if (l == h) return 0;
    if (l == h - 1) return (str[l] == str[h]) ? 0 : 1;

    if (str[l] == str[h])
        return findMinSymbol(str, l + 1, h - 1);
    else
        return  (min(findMinSymbol(str, l, h - 1), findMinSymbol(str, l + 1, h)) + 1);
        
}
int main()
{
    char str[] = "edef";
    int n = strlen(str);
  // cout << findMinSymbol(str, 0, strlen(str) - 1);
    int l = n + findMinSymbol(str, 0, strlen(str) - 1);
    
    char newstr[100] = "";
    
    int f = l-1;
    int k = 0;
    for (int i = n - 1; i > 0; i--) {

        char tmp = str[i];
        newstr[k] = tmp;
        newstr[l - k - 1] = tmp;
        k++;
    }
    cout << newstr << endl;
    int counter = 0;
   bool Ispolindrom=true;
    for (int h = 0; h < n; h++) {
        for (int s = 0; s < l; s++) {
            if (str[h] == newstr[s]) {
                counter++;
            }
        }
            if (counter == 0) {
                Ispolindrom = false;

            }
            else
                counter = 0;
        
    }



    char newstr2[100] = "";
    for (int i = 0; i < n; i++) {

        char tmp = str[i];
        newstr2[f] = tmp;
        newstr2[i] = tmp;
        f--;

    }
    cout << newstr2 << endl;
    int counter2 = 0;
    bool Ispolindrom2=true;
    for (int h = 0; h < n; h++) {
        for (int s = 0; s < l; s++) {
            if (str[h] == newstr2[s]) {
                counter2++;
            }
        }
            if (counter2 == 0) {
                Ispolindrom2 = false;

            }
            else
                counter2 = 0;
        
    }
    if (Ispolindrom==false)
        cout << newstr2;
    else if(Ispolindrom2==false)
        cout << newstr;
     
    
    
    
  
    return 0;
}

