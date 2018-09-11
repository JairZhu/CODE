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

//#include"ListNode.h"
#include <queue>
using namespace std;
ListNode* resetList(ListNode* head) {
	queue<int> que1;
	queue<int> que2;
	while (head != nullptr) {
		que1.push(head->val);
		head = head->next;
		if (head != nullptr) {
			que2.push(head->val);
			head = head->next;
		}
		else break;
	}
	ListNode *here = new ListNode(0);
	ListNode *p = here;
	while (!que1.empty()) {
		p->next = new ListNode(que1.front());
		que1.pop();
		p = p->next;
	}
	while (!que2.empty()) {
		p->next = new ListNode(que2.front());
		que2.pop();
		p = p->next;
	}
	return here->next;
}