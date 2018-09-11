#include"jishu.h"
#include <iostream>
using namespace std;

void radixsort(int data[], int n); //»ùÊıÅÅĞò

int main()
{
	int data[] = { 9,6,7,22,20,33,16,20 };
	cout << "Before sorted:" << endl;
	for (int i = 0; i <= 7; i++)
		cout << data[i] << " ";
	cout << endl;

	cout << "After sorted:" << endl;
	radixsort(data, 8);
	for (int i = 0; i <= 7; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}