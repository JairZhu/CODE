#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
	Stack() {
		node_num = 0;
		top_node = NULL;
	}

	Stack(const Stack &stack) {
		if (stack.top_node == NULL) top_node = NULL;
		else {
			Node * p1 = stack.top_node;
			Node * p2 = new Node(p1->element);
			top_node = p2;
			while (p1->next != NULL) {
				p1 = p1->next;
				p2->next = new Node(p1->element);
				p2 = p2->next;
			}
		}
		node_num = stack.node_num;
	}

	~Stack() {
		if (top_node != NULL) {
			Node *p = top_node->next;
			delete top_node;
			while (p != NULL) {
				top_node = p;
				p = p->next;
				delete top_node;
			}
		}
	}

	bool empty() { return node_num == 0; }

	size_t size() const { return node_num; }

	T top() const { return top_node->element; }

	void push(T element) {
		Node *p = top_node;
		top_node = new Node(element, p);
		node_num++;
	}

	void pop() {
		if (top_node == NULL) return;
		Node *p = top_node;
		top_node = top_node->next;
		delete p;
		node_num--;
	}

	void swap(Stack& stack) {
		Stack tmp1(stack);
		Stack tmp2(*this);
		size_t num1 = tmp1.node_num;
		size_t num2 = tmp2.node_num;
		stack.clear();
		for (int i = 0; i < num2; ++i) {
			stack.push(tmp2.top());
			tmp2.pop();
		}
		stack.reverse();
		clear();
		for (int i = 0; i < num1; ++i) {
			push(tmp1.top());
			tmp1.pop();
		}
		reverse();
	}

	void reverse() {
		if (top_node == NULL) return;
		size_t num = node_num;
		Stack tmp(*this);
		clear();
		for (int i = 0; i < num; ++i) {
			push(tmp.top());
			tmp.pop();
		}
	}
		/*reverse the elements' order in the stack*/

	void clear() {
		if (top_node != NULL) {
			Node *p = top_node->next;
			delete top_node;
			while (p != NULL) {
				top_node = p;
				p = p->next;
				delete top_node;
			}
		}
		top_node = NULL;
		node_num = 0;
	}

private:
	struct Node {
		T element;
		Node* next;
		Node(T ele, Node *n = NULL) {
			element = ele;
			next = n;
		}
	};
	Node *top_node;
	size_t node_num;
};