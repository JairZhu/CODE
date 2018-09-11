#include<iostream>
using namespace std;

void Heapfy(int arr[], int idx, int max)
{
	while (idx * 2 + 2< max) {
		int j = idx * 2 + 1;
		if (arr[j] < arr[j + 1]) j++;
		if (arr[idx] > arr[j]) break;
		int tmp = arr[idx];
		arr[idx] = arr[j];
		arr[j] = tmp;
		idx = j;
	}
}