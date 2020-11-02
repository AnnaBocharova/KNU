#include<iostream>
#include<cmath>
using namespace std;


int main() {

	int n = 1000;
	int* denum = new int[n];
	int* num = new int[n];
	int* factor = new int[n];
	cout << "Enter the numenator:";
	cin >> num[0];
	cout << "Enter the denumenator:";
	cin >> denum[0];
	cout << "[";
	factor[0] = 1;
	if (denum[0] * num[0] > 0) {
		for (int i = 0; i < n; i++) {
			if (denum[i] == 0) {
				cout << "]";
				break;
			}
			else {
				factor[i] = num[i] / denum[i];
				cout << factor[i] << ", ";
				denum[i + 1] = num[i] - denum[i] * factor[i];
				num[i + 1] = denum[i];

			}

		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (denum[i] == 0) {
				cout << "]";
				break;
			}
			else {
				if (num[i] < 0 || denum[i] < 0) {
					factor[i] = (num[i] / denum[i]) - 1;
				}
				else {
					factor[i] = (num[i] / denum[i]);
				}
				cout << factor[i] << ", ";
				denum[i + 1] =abs( (abs(factor[i]) * abs(denum[i])) - abs(num[i]));
				num[i + 1] = abs(denum[i]);

			}
		}

		delete[] num;
		delete[] denum;
		delete[] factor;

		return 0;
	}
}