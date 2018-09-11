#include <iostream>
#include <string>
using namespace std;

void next(string p, int *next)
{
	int pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

void nextval(string p, int *next)
{
	int pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			//next[j] = k;
			if (p[j] != p[k])
				next[j] = k;
			else
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}

/*通过计算返回子串T的next数组*/
void get_next(string T, int *next) {
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T.length()) {
		if (j == 0 || T[i] == T[j]) {		//T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];					//若字符不相同，则j值回溯
	}
}

/*求模式串T的next函数修正值并存入数组nextval*/
void get_nextval(string T, int *nextval) {
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T.length()) {
		if (j == 0 || T[i] == T[j]) {		//T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
			++i;
			++j;
			if (T[i] != T[j])				//若当前字符与前缀字符不同，则当前的j为nextval在i位置的值
				nextval[i] = j;			
			else
				nextval[i] = nextval[j];	//如果与前缀字符相同，则将前缀字符的nextval值赋值给nextval在i位置的值
		}
		else
			j = nextval[j];					//若字符不相同，则j值回溯
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		int pnext[10000];
		nextval(str, pnext);
		for (int i = 0; i < str.length(); ++i) {
			cout << pnext[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}