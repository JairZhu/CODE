#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	bool hasmin = false;
	char source[100000];
	char target[100000];
	cin >> source >> target;
	int table[255] = { 0 };
	for (int i = 0; i < strlen(target); ++i)
		table[target[i]] = 1;
	int min = 10000;
	int minfront, minrear, front, rear;
	minfront = minrear = front = rear = 0;
	int count = 0;
	int inc[255] = { 0 };
	while (source[rear] != '\0') {
		if (table[source[rear]]) {
			if (inc[source[rear]] == 0) {
				count++;
				inc[source[rear]]++;
				if (count == strlen(target)) {
					while (true) {
						if (table[source[front]]) {
							inc[source[front]]--;
							if (inc[source[front]] == 0) {
								if ((rear - front + 1) < min) {
									min = rear - front + 1;
									minfront = front;
									minrear = rear;
									hasmin = true;
								}
								count--;
								front++;
								break;
							}
							else front++;
						}
						else front++;
					}
				}
			}
			else inc[source[rear]]++;
		}
		rear++;
	}
	if (hasmin)
		for (int i = minfront; i <= minrear; ++i)
			cout << source[i];
	else cout << "No";
	return 0;
}