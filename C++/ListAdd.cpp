#include "ListAdd.hpp"
#include <sstream>
#include <string>
using namespace std;

List::List()
{
	head = nullptr;
	_size = 0;
}

List::List(const List & other)
{
	_size = other._size;
	node *p1 = other.head;
	head = new node(other.head->val);
	node *p2 = head;
	while (p1->next != NULL) {
		p2->next = new node(p1->next->val);
		p2 = p2->next;
		p1 = p1->next;
	}
}

List::List(const string & num)
{
	head = new node(num[0] - '0');
	_size = 1;
	node * p = head;
	for (int i = 1; i < num.length(); ++i) {
		p->next = new node(num[i] - '0');
		p = p->next;
		++_size;
	}
}

void List::clear()
{
	if (head != nullptr) {
		node *p = head;
		while (p != nullptr) {
			node * tmp = p;
			p = p->next;
			delete tmp;
		}
		head = nullptr;
	}
	_size = 0;
}

void List::push_front(int val)
{
	node * p = head;
	head = new node(val, p);
	_size++;
}

List List::operator+(const List & other)
{
	List tmp1(*this);
	List tmp2(other);
	int n1 = tmp1._size;
	int n2 = tmp2._size;
	if (n1 > n2) {
		for (int i = 0; i < n1 - n2; ++i) {
			tmp2.push_front(0);
		}
	}
	else {
		for (int i = 0; i < n2 - n1; ++i) {
			tmp1.push_front(0);
		}
	}
	List tmp;
	int count = tmp1._size;
	int jw[10000] = {0};
	while (count != 0) {
		node * p1 = tmp1.head;
		node * p2 = tmp2.head;
		for (int i = 0; i < count - 1; ++i) {
			p1 = p1->next;
			p2 = p2->next;
		}
		if (p1->val + p2->val + jw[count] > 9) jw[count - 1] = 1;
		tmp.push_front((p1->val + p2->val + jw[count]) % 10);
		--count;
	}
	if (jw[count] != 0) tmp.push_front(jw[count]);
	return tmp;
}


List & List::operator=(const List & other)
{
	clear();
	_size = other._size;
	if (other.head == nullptr) return *this;
	head = new node(other.head->val);
	node *p1 = other.head;
	node *p2 = head;
	while (p1->next != NULL) {
		p2->next = new node(p1->next->val);
		p2 = p2->next;
		p1 = p1->next;
	}
	return *this;
	// TODO: 在此处插入 return 语句
}

int List::size() const
{
	return _size;
}

List::~List()
{
	clear();
}

ostream & operator<<(ostream & os, const List & out)
{
	stringstream str;
	List::node * p = out.head;
	while (p != nullptr) {
		str << p->val;
		p = p->next;
	}
	string tmp;
	str >> tmp;
	os << tmp;
	return os;
}
