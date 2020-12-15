
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct disp_res {
	int x;
	int y;
};
struct size_params {
	float hei;
	float wid;
	float len;
};

struct notebook {
	int x;
	int y;
	float hei;
	float wid;
	float len;
	disp_res dr;
	size_params sp;
	int f;
	float d;
	float weight;
	int price;
	int frec;
	int mb;
	int vid;
	float hdd;
	char model[21];
};
int main() {
	FILE *notetxt, *outputf;
	
	
	if ((notetxt = fopen("notebook.txt", "r")) == NULL) {
		cout << "Error: Could not open file!" << endl;
		return 1;
	}
	if ((outputf = fopen("binfile.bin", "ab+")) == NULL) {
		cout << "Error: Could not open file!" << endl;
		return 1;
	}
	
	int count = 0; //кількість записів
	const int lenght = 100;
	char fstring[lenght];
	const int len = 150;
	notebook str[len] = {};
	while (fgets(fstring, lenght, notetxt)) {
		for (int i = 0; i < lenght; i++) {
			strncpy(str[i].model, fstring, 20);
			str[i].model[20] = '\0';
			str[i].price = atoi(&fstring[21]);
			str[i].weight = atoi(&fstring[26]);
			str[i].hei = atoi(&fstring[30]);
			str[i].f = atoi(&fstring[44]);
			str[i].mb = atoi(&fstring[49]);
			str[i].d = atoi(&fstring[52]);
			str[i].vid = atoi(&fstring[57]);
			str[i].x = atoi(&fstring[59]);
			str[i].y = atoi(&fstring[64]);
			str[i].frec = atoi(&fstring[69]);
			str[i].hdd = atoi(&fstring[72]);
			fwrite(&str, sizeof str, 1, outputf);
			count++;

		}
	}
	fclose(notetxt);
	for (int i = 0; i < count; i++) {
		fseek(outputf, (sizeof str) * i, SEEK_SET);
		fread(&str, sizeof str, 1, outputf);
		cout << str[i].model << " " << str[i].price << " " << str[i].weight << " " << str[i].hei << " " << str[i].f << " " << str[i].mb << " " << str[i].d << " " << str[i].vid << " " << str[i].x << " " << str[i].y << " " << str[i].frec << " " << str[i].hdd;
	}
	fclose(outputf);
	FILE* newfile;
	char c;
	if ((newfile = fopen("newfile.txt", "w+b")) == NULL) {
		cout << "Error: Could not open file!" << endl;
		return 1;
	}
	char array[100];
	int counter2 = 0;
	for (int i = 0; i < count; i++) {
		if (str[i].weight < 7) {
			for (int j = 0; j < count; j++) {
				array[j] = i;
				counter2++;
			}
			
		}
	}
	
	
	int k = array[0];
	float min = str[k].price;
	for (int i = 0; i < counter2; i++) {
		int k = array[i];
		if (str[k].price < str[k++].price) {
			notebook temp = str[k];
			str[k] = str[k++];
			str[k++] = temp;
		}

	}
	fwrite(&str, sizeof(notebook), 1, newfile);
	fclose(newfile);

	return 0;
	
}
