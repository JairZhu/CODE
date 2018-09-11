#include <iostream>
#include <string>
using namespace std;

void split(string str, char che) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == che) cout << endl;
		if (str[i] != che) cout << str[i];
	}
}

int main() {
	string str;
	char che;
	cin >> str >> che;
	split(str, che);
	return 0;
}