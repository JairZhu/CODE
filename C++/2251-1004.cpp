#include <iostream>
#include <string>
using namespace std;

string arr;
string str[1000];
int fuck_num;

void fuck_static_check() {
	while (arr.length()) {
		int maxlenth = 1;
		int index2 = -1;
		for (int i = 0; i < fuck_num; ++i) {
			if (arr.find(str[i]) == string::npos) continue;
			else if (arr.find(str[i]) == 0) {
				if (index2 == -1) {
					index2 = i;
					maxlenth = str[i].length();
				}
				else if (index2 != i) {
					if (str[i].length() < str[index2].length())
						maxlenth = str[i - 1].length();
					else 
						maxlenth = str[i].length();
					index2 = str[i].length() < str[index2].length() ? index2 : i;
				}
			}
		}
		if (index2 != -1) {
			cout << str[index2];
		}
		else cout << arr[0];
		arr = arr.erase(0, maxlenth);
		if (arr.length() != 0) cout << ' ';
	}
}

int main() {	
	cin >> fuck_num;
	for (int i = 0; i < fuck_num; ++i)
		cin >> str[i];
	cin >> arr;
	fuck_static_check();
	cout << endl;
	//system("pause");
}