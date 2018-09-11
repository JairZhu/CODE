#include <iostream>
#include"heap.h"
using namespace std;

void Heapfy(int A[], int idx, int max);//建立最大堆

void buildHeap(int A[], int len)
{
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		Heapfy(A, i, len);     //建立最大堆，将堆中最大的值交换到根节点
	}

	for (int i = len - 1; i >= 1; --i)
	{
		int temp = A[0];   //将当前堆的根节点交换到堆尾的指定位置
		A[0] = A[i];
		A[i] = temp;

		Heapfy(A, 0, i);  //建立下一次的最大堆
	}
}


int main() {
	int data[] = { 9,6,7,22,20,33,16,20 };
	cout << "Before sorted:" << endl;
	for (int i = 0; i <= 7; i++)
		cout << data[i] << " ";
	cout << endl;

	cout << "After sorted:" << endl;
	buildHeap(data, sizeof(data) / sizeof(data[0]));
	for (int i = 0; i <= 7; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
