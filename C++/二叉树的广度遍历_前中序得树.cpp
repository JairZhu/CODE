#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Tree
{
	char word;
	Tree *lchil;
	Tree *rchil;
	Tree(char chr) : word(chr), lchil(NULL), rchil(NULL) {}
};

Tree *buildtree(string str1, string str2) {
	if (str2.length() == 0) return NULL;
	Tree *node = new Tree(str1.front());
	int p = str2.find(str1.front());
	str1.erase(str1.begin());
	if (str1.length() == 0) return node;
	string tmp1 = str2.substr(0, p);
	string tmp2 = str2.substr(p + 1, str2.length() - p - 1);
	string tmp3 = str1.substr(0, tmp1.length());
	string tmp4 = str1.substr(tmp1.length(), str1.length() - tmp1.length());
	node->lchil = buildtree(tmp3, tmp1);
	node->rchil = buildtree(tmp4, tmp2);
	return node;
}

void BFS(Tree *head) {
	cout << head->word;
	queue<Tree*> que;
	if (head->lchil != NULL) {
		que.push(head->lchil);
		cout << head->lchil->word;
	}
	if (head->rchil != NULL) {
		que.push(head->rchil);
		cout << head->rchil->word;
	}
	while (!que.empty()) {
		Tree *p = que.front();
		que.pop();
		if (p->lchil != NULL) {
			que.push(p->lchil);
			cout << p->lchil->word;
		}
		if (p->rchil != NULL) {
			que.push(p->rchil);
			cout << p->rchil->word;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		string str1, str2;
		cin >> str1 >> str2;
		Tree *head = buildtree(str1, str2);
		BFS(head);
		cout << endl;
	}
	return 0;
}