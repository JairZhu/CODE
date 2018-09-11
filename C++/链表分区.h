#ifndef ListNode_h
#define ListNode_h
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() {
		val = 0;
		next = NULL;
	}
	ListNode(int x) : val(x), next(NULL) {}
	~ListNode() {}
};

#endif

#include <queue>
using namespace std;
ListNode* partList(ListNode* head, int x) {
	queue<int> arr1;
	while (head != nullptr) {
		arr1.push(head->val);
		head = head->next;
	}
	ListNode *here = new ListNode(0);
	ListNode *p = here;
	queue<int> arr2;
	while (!arr1.empty()) {
		if (arr1.front() < x) {
			p->next = new ListNode(arr1.front());
			arr1.pop();
			p = p->next;
		}
		else {
			arr2.push(arr1.front());
			arr1.pop();
		}
	}
	while (!arr2.empty()) {
		p->next = new ListNode(arr2.front());
		arr2.pop();
		p = p->next;
	}
	return here->next;
}