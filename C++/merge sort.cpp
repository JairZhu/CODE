struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = nullptr;
		ListNode *p1 = sortList(head);
		ListNode *p2 = sortList(fast);
		return merge(p1, p2);
	}
	ListNode *merge(ListNode *p1, ListNode *p2) {
		if (p1 == nullptr) return p2;
		if (p2 == nullptr) return p1;
		ListNode tmp = ListNode(0);
		ListNode *p = &tmp;
		while (p1 && p2) {
			if (p1->val > p2->val) {
				p->next = p2;
				p2 = p2->next;
			}
			else {
				p->next = p1;
				p1 = p1->next;
			}
			p = p->next;
		}
		if (p1 == nullptr) p->next = p2;
		else if (p2 == nullptr) p->next = p1;
		return tmp.next;
	}
};