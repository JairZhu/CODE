#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int find_same_string(string str1, string str2) {
	if (str1.length() == 0 || str2.length() == 0) return 0;
	if (str1.front() == str2.front()) {
		str1.erase(str1.begin());
		str2.erase(str2.begin());
		return 1 + find_same_string(str1, str2);
	}
	else {
		string tmp1 = str1;
		string tmp2 = str2;
		str1.erase(str1.begin());
		str2.erase(str2.begin());
		return max(find_same_string(tmp1, str2), find_same_string(str1, tmp2));
	}
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	cout << find_same_string(str1, str2) << endl;
	return 0;
}