#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int compare(char op1, char op2) {
	if (op1 == '#') {
		if (op2 == '#') return 3;
		else return 1;
	}
	if (op1 == '+' || op1 == '-') {
		if (op2 == '*' || op2 == '/' || op2 == '(') return 1;
		else return 2;
	}
	if (op1 == '*' || op1 == '/') {
		if (op2 == '(') return 1;
		else return 2;
	}
	if (op1 == '(') {
		if (op2 == ')') return 3;
		else return 1;
	}
	if (op1 == ')') return 2;
}

void operate(char op1, stack<int>& data, stack<char>& op) {
	if (compare(op.top(), op1) == 1) {
		op.push(op1);
	}
	else if (compare(op.top(), op1) == 3) {
		op.pop();
	}
	else {
		int b = data.top();
		data.pop();
		int a = data.top();
		data.pop();
		if (op.top() == '+') {
			op.pop();
			data.push(a + b);
			operate(op1, data, op);
		}
		else if (op.top() == '-') {
			op.pop();
			data.push(a - b);
			operate(op1, data, op);
		}
		else if (op.top() == '*') {
			op.pop();
			data.push(a * b);
			operate(op1, data, op);
		}
		else if (op.top() == '/') {
			op.pop();
			data.push(a / b);
			operate(op1, data, op);
		}
	}
}

int main() {
	queue<char> que;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		que.push(str[i]);
	}
	que.push('#');
	stack<int> data;
	stack<char> op;
	op.push('#');
	while (!que.empty()) {
		int num = 0;
		while (que.front() <= '9' && que.front() >= '0') {
			num *= 10;
			num += que.front() - '0';
			que.pop();
			if (que.front() > '9' || que.front() < '0') data.push(num);
		}
		operate(que.front(), data, op);
		que.pop();
	}
	cout << str << '=' << data.top() << endl;
	return 0;
}