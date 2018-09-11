#include <iostream>
#include <string>
using namespace std;

int main() {
	string substr, mainstr;
	cin >> substr >> mainstr;
	int count = 0;
	int position = mainstr.find(substr, 0);
	while (position != string::npos) {
		count++;
		position++;
		position = mainstr.find(substr, position);
	}
	cout << count;
	return 0;
}