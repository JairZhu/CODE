#include <iostream>
using namespace std;

int main() {
	int number;
	int data[100000] = { 0 };
	cin >> number;
	for (int i = 0; i < number; ++i)
		cin >> data[i];
	int max = data[0];               //当前最大子数组的和
	int cur = 0;					 //以data[i]结尾的子数组
	for (int i = 0; i < number; ++i) {
		cur = data[i] > (cur + data[i]) ? data[i] : (cur + data[i]);//求以data[i]结尾的和最大的子数组
		max = cur > max ? cur : max;								//当前和最大子数组要么是以data[i]结尾，要么和data[i]无关
	}
	cout << max;
	return 0;
}