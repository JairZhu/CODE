#include <iostream> 
using namespace std;

int main() {
	int num;
	cin >> num;
	int joy;
	int * price = new int[1000000];
	double * hfm = new double [1000000];
	int data[3];
	double sum = 0;
	for (int i = 0; i < num; ++i) {
		cin >> joy >> price[i];
		hfm[i] = (joy * 1.0) / (price[i] * 1.0);
	}
	for (int j = 0; j < 3; ++j) {
		double tmp = -1;
		int index = -1;
		for (int i = 0; i < num; ++i) {
			if (tmp < hfm[i]) {
				tmp = hfm[i];
				index = i;
			}
			else if (tmp == hfm[i] && index < i) {
				index = i;
			}
		}
		sum += price[index];
		hfm[index] = -2;
		data[j] = index;
	}
	cout << sum << endl;
	for (int i = 0; i < 3; ++i) {
		cout << data[i] + 1<< endl;
	}
	//system("pause");
}