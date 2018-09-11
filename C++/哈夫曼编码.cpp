#include <iostream>
#include <string>
using namespace std;

struct Tree
{
	Tree *lchil;
	Tree *rchil;
	int num;
	char word;
	int flag;
	Tree():lchil(NULL), rchil(NULL), num(0), word(0), flag(0){}
};

void dfs(Tree *head, int depth, int de[]) {
	if (head->flag != 0) de[head->word] = depth;
	else {
		if (head->lchil != NULL) dfs(head->lchil, depth + 1, de);
		if (head->rchil != NULL) dfs(head->rchil, depth + 1, de);
	}
}

int main() {
	int data[128] = { 0 };
	string str;
	cin >> str;
	for (char i : str) {
		data[i]++;
	}
	Tree tree[128];
	for (char i = 'a'; i <= 'z'; ++i) {
		tree[i].num = data[i];
		tree[i].word = i;
		if (data[i] != 0) tree[i].flag = 1;
	}
	int j = 0;
	while (true) {
		int min = 10000;
		int target1, target2;
		for (int i = 0; i < 128; ++i) {
			if (data[i] < min && data[i] != 0) {
				min = data[i];
				target1 = i;
			}
		}
		data[target1] = 0;
		min = 10000;
		for (int i = 0; i < 128; ++i) {
			if (data[i] < min && data[i] != 0) {
				min = data[i];
				target2 = i;
			}
		}
		data[target2] = 0;
		data[j] = tree[target1].num + tree[target2].num;
		tree[j].num = tree[target1].num + tree[target2].num;
		tree[j].lchil = &tree[target1];
		tree[j].rchil = &tree[target2];
		if (tree[j++].num == str.length()) break;
	}
	int depth[128] = { 0 };
	dfs(&tree[j - 1], 0, depth);
	int sum = 0;
	for (char i = 'a'; i <= 'z'; ++i) {
		sum += depth[i] * tree[i].num;
	}
	cout << sum;
	return 0;
}