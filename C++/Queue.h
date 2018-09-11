template <typename T>
class Queue {
public:
	Queue() { 
		node_num = 0;
		front_node = nullptr;
		back_node = nullptr;
	}

	Queue(const Queue & another) {
		if (another.node_num == 0) {
			node_num = 0;
			front_node = back_node = nullptr;
		}
		else {
			node_num = another.node_num;
			Node * p1 = another.front_node;
			Node * p2 = front_node = new Node(p1->element);
			while (p1->next != nullptr) {
				p2->next = new Node(p1->next->element);
				p1 = p1->next;
				p2 = p2->next;
			}
			back_node = p2;
 		}
	}
	~Queue() {
		if (front_node != nullptr) {
			while (front_node != nullptr) {
				Node *p = front_node;
				front_node = p->next;
				delete p;
			}
		}
	}
	bool empty() { return node_num == 0; }
	int size() { return node_num; }
	T front() const { return front_node->element; }
	T back() const { return back_node->element; }
	void push(T element) {
		if (front_node == nullptr) {
			front_node = back_node = new Node(element);
		}
		else {
			Node *p = back_node;
			back_node = p->next = new Node(element);
		}
		node_num++;
	}
	void pop() {
		if (front_node == nullptr) return;
		if (front_node == back_node) {
			delete front_node;
			front_node = back_node = nullptr;
		}
		else {
			Node *p = front_node;
			front_node = front_node->next;
			delete p;
		}
		node_num--;
 	}
	void swap(Queue & queue) {
		Queue tmp1(*this);
		Queue tmp2(queue);
		int num = queue.node_num;
		for (int i = 0; i < num; ++i)
			queue.pop();
		num = tmp1.node_num;
		for (int i = 0; i < num; ++i) {
			queue.push(tmp1.front());
			tmp1.pop();
		}
		num = node_num;
		for (int i = 0; i < num; ++i) {
			pop();
		}
		num = tmp2.node_num;
		for (int i = 0; i < num; ++i) {
			push(tmp2.front());
			tmp2.pop();
		}
	}

private:
	struct Node {
		T element;
		Node* next;
		Node(T ele, Node* n = NULL) {
			element = ele;
			next = n;
		}
	};
	Node* front_node;
	Node* back_node;
	int node_num;
};
