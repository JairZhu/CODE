#ifndef _LISTNODE_
#define _LISTNODE_
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
};
#endif // !_LISTNODE_

