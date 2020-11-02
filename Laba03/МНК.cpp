#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int function(float x) {
    float function = 2 *pow( x,2) - 4;
    return function;
}
int main() {
    srand(time(NULL));
    int k;
    cout << "If you want to approximate the given function enter 1 , if you want to enter points enter 2:";
    cin >> k;
    int n;
    float x, y;

    cout << "How many points do you want to enter?";
    cin >> n;
    float* arrayX = new float[n];
    float* arrayY = new float[n];
    if (k == 1) {
      
        for (int i = 0; i < n; i++) {
            x = rand() % 120;
            arrayX[i] = x;
            arrayY[i] = function(x);
            cout << "{" << arrayX[i] << "," << arrayY[i] << "}" << ", ";
         }
        cout<<endl;
    }
   
    if (k == 2) {
        for (int i = 0; i < n; i++) {
            cin >> x;
            arrayX[i] = x;
            cin >> y;
            arrayY[i] = y;

        }
    }
    float sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;
    for (int i = 0; i < n; i++) {
        sumx += arrayX[i];
        sumy += arrayY[i];
        sumx2 += pow(arrayX[i],2);
        sumxy += arrayX[i]*arrayY[i];
    }
    float a = (n * sumxy - (sumx * sumy)) / (n * sumx2 - (pow(sumx,2)));
    float b = (sumy - a * sumx) / n;
    if (b > 0)
        cout << "y=" << a << "x" << "+" << b << endl;
    else
        cout << "y=" << a << "x" << b << endl;

    delete [] arrayX;
    delete[] arrayY;
    return 0;
}




