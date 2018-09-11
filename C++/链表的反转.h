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
#include <stack>
using namespace std;
ListNode* reverseList(ListNode* head) {
	stack<int> data;
	while (head != nullptr) {
		data.push(head->val);
		head = head->next;
	}
	ListNode *here = new ListNode(data.top());
	ListNode *p = here;
	data.pop();
	while (!data.empty()) {
		p->next = new ListNode(data.top());
		data.pop();
		p = p->next;
	}
	return here;
}