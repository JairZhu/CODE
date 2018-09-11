#include <iostream>
#include <cstring>
using namespace std;

void reversion(char * arr) {
	int n = strlen(arr);
	for (int i = 0; i < n / 2; ++i) {
		char tmp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = tmp;
	}
}

int main() {
	int n;
	cin >> n;
	cin.get();
	char str[n][1000000];
	for (int i = 0; i < n; ++i) {
		str[i][0] = '\0';
		char tmp = cin.get();
		while (tmp != '\n') {
			if (tmp != '_') {
				int count = 0;
				char arr[1000000];
				while (tmp != '_' && tmp != '\n') {
					arr[count++] = tmp;
					tmp = cin.get();
				}
				arr[count] = '\0';
				reversion(arr);
				strcat(str[i], arr);
			}
			if (tmp == '_') {
				strcat(str[i], "_");
				tmp = cin.get();
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << str[i] << endl;
	}
	//system("pause");
}