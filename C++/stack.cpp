#include "stack.hpp"
stack::~stack() {
    delete [] storage;
}

void stack::push(E ele) {
    if (size == max_size) return;
    else {
        storage[size] = ele;
        size++;
    }
}

void stack::pop() {
    if (size == 0) return;
    else {
        storage[--size] = 0;
    }
}

E stack::top() {
    if (size != 0) return storage[size - 1];
    else return 0;
}

bool stack::isEmpty() {
    if (size == 0) return true;
    else return false;
}

bool stack::isFull() {
    if (size == max_size) return true;
    else return false;
}

void stack::clear() {
    delete [] storage;
	storage = new E[MAX_SIZE];
    size = 0;
}