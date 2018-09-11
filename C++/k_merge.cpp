#include"ListNode.h"
#include<vector>
#include<algorithm>
using namespace std;

/*ListNode* mergeKLists(vector<ListNode*>& lists) {
	int index, min = 100000;
	for (int i = 0; i < lists.size(); ++i) {
		if (lists[i]->val < min) {
			min = lists[i]->val;
			index = i;
		}
	}
	ListNode *head = new ListNode(lists[index]->val);
	ListNode *tmp = lists[index];
	lists[index] = lists[index]->next;
	delete tmp;
	if (lists[index] == nullptr) lists.erase(lists.begin() + index);
	ListNode *p = head;
	while (!lists.empty()) {
		min = 100000;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i]->val < min) {
				min = lists[i]->val;
				index = i;
			}
		}
		p->next = new ListNode(lists[index]->val);
		tmp = lists[index];
		lists[index] = lists[index]->next;
		delete tmp;
		if (lists[index] == nullptr) lists.erase(lists.begin() + index);
		p = p->next;
	}
	return head;
}*/

ListNode *mergeKLists(vector<ListNode*>& lists) {
	int data[10000];
	int index = 0;
	bool flag = 0;
	for (int i = 0; i < lists.size(); ++i) {
		while (lists[i] != nullptr) {
			data[index++] = lists[i]->val;
			lists[i] = lists[i]->next;
			flag = 1;
		}
	}
	if (flag == 0) return nullptr;
	sort(data, data + index);
	ListNode *head = new ListNode(data[0]);
	ListNode *p = head;
	for (int i = 1; i < index; ++i) {
		p->next = new ListNode(data[i]);
		p = p->next;
	}
	return head; 
}