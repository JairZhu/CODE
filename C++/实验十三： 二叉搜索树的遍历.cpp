#include <iostream>
using namespace std;

struct node
{
	int value;
	node *lchild;
	node *rchild;
	node(int n) : value(n), lchild(NULL), rchild(NULL) {}
};

node *put(node *head, int value) {
	if (head == NULL) return new node(value);
	if (value < head->value) head->lchild = put(head->lchild, value);
	else head->rchild = put(head->rchild, value);
	return head;
}

node *buildtree(int number) {
	node *head = NULL;
	for (int i = 0; i < number; ++i) {
		int tmp;
		cin >> tmp;
		head = put(head, tmp);
	}
	return head;
}

void ZXBL(node *head) {
	if (head->lchild != NULL) ZXBL(head->lchild);
	cout << head->value << ' ';
	if (head->rchild != NULL) ZXBL(head->rchild);
}

void QXBL(node *head) {
	if (head != NULL) cout << head->value << ' ';
	if (head->lchild != NULL) QXBL(head->lchild);
	if (head->rchild != NULL) QXBL(head->rchild);
}

int main() {
	while (true) {
		int number;
		cin >> number;
		if (number == 0) return 0;
		node *head = buildtree(number);
		ZXBL(head);
		cout << endl;
		QXBL(head);
		cout << endl;
	}
}