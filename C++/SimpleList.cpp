#include "SimpleList.hpp"
#include <sstream>

list::list()
{
	head = NULL;
	_size = 0;
}

list::list(const list & p)
{
	if (p.head == NULL) {
		head = NULL;
		_size = p._size;
	}
	else {
		_size = p._size;
		head = new node;
		head->data = p.head->data;
		if (p.head->next == NULL) {
			head->next = NULL;
		}
		else {
			head->next = new node;
			node * tmp1 = p.head->next;
			node * tmp2 = head->next;
			tmp2->data = tmp1->data;
			while (tmp1 != NULL) {
				tmp1 = tmp1->next;
				if (tmp1 == NULL) {
					tmp2->next = NULL;
				}
				else{
					tmp2->next = new node;
					tmp2 = tmp2->next;
					tmp2->data = tmp1->data;
				}
			}
		}
	}
}

list & list::operator=(const list & p)
{
	if (this->head != NULL) {
		node* p = this->head;
		while (p != NULL) {
			node* temp = p;
			p = p->next;
			delete temp;
		}
		this->head = NULL;
	}
	if (p.head == NULL) {
		head = NULL;
		_size = p._size;
	}
	else {
		_size = p._size;
		head = new node;
		head->data = p.head->data;
		if (p.head->next == NULL) {
			head->next = NULL;
		}
		else {
			head->next = new node;
			node * tmp1 = p.head->next;
			node * tmp2 = head->next;
			tmp2->data = tmp1->data;
			while (tmp1 != NULL) {
				tmp1 = tmp1->next;
				if (tmp1 == NULL) {
					tmp2->next = NULL;
				}
				else {
					tmp2->next = new node;
					tmp2 = tmp2->next;
					tmp2->data = tmp1->data;
				}
			}
		}
	}
	return *this;
}

list::~list()
{
	this->clear();
	delete head;
}

bool list::empty(void) const
{
	return head == NULL; 
}

int list::size(void) const
{
	return _size;
}

std::string list::toString(void) const
{
	using namespace std;
	stringstream str;
	node * tmp = head;
	while (head != NULL) {
		str << tmp->data << "->";
		if (tmp->next == NULL) break;
		tmp = tmp->next;
	}
	str << "NULL";
	string str1;
	str >> str1;
	return str1;
}

void list::insert(int position, const int & data1)
{
	if (position > _size) return;
	node * tmp = new node;
	tmp->data = data1;
	if (position == 0) {
		tmp->next = head;
		head = tmp;
		++_size;
	}
	else if (position < _size) {
		int i = 1;
		node * p1 = head;
		node * p2 = head->next;
		while (i++ != position) {
			p1 = p2;
			p2 = p2->next;
		}
		p1->next = tmp;
		tmp->next = p2;
		++_size;
	}
	else {
		node * p1 = head;
		node * p2 = head->next;
		for (int i = 1; i < _size; ++i) {
			p1 = p1->next;
		}
		p1->next = tmp;
		tmp->next = NULL;
		++_size;
	}
}

void list::erase(int position)
{
	if (head == NULL || position > _size) return;
 	if (position == 0) {
		node *tmp1 = head;
		head = head->next;
		delete tmp1;
		_size--;
		return;
	}
	int i = 1; 
	node * p2 = head->next;
	node * p1 = head;
 	while (i++ != position) {
		p1 = p2;
		p2 = p2->next;
	}
	p1->next = p2->next;
	delete p2;
	_size--;
}

list & list::sort(void)
{
	node * p1 = head;
	node * p2 = p1->next;
	for (int i = 0; i < _size - 1; ++i) {
		for (int j = i + 1; j < _size; ++j) {
			if (p1->data > p2->data) {
				int tmp = p1->data;
				p1->data = p2->data;
				p2->data = tmp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = p1->next;
	}
	return *this;
}