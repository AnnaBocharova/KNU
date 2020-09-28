// Дан размер файла в байтах. Используя операцию деления нацело,найти количество полных килобайтов, которые занимает данный файл (1 килобайт = 1024 байта).
#include<iostream>
using std::endl;
using std::cin;
using std::cout;
int main() {
	int byte, klb;
	cout << "Enter the file size in bytes:";
	cin >> byte;
	klb = byte / 1024;
	cout << "Size in kilobytes:" << klb << endl;
	cin.get();
	return 0;

}