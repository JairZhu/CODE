#include "ArrayList.hpp"

ArrayList::ArrayList()
{
	storage = new E[DEFAULT_MAX_SIZE];
	_size = 0;
	_maxsize = DEFAULT_MAX_SIZE;
}

ArrayList::~ArrayList()
{
	delete [] storage;
}

void ArrayList::add(E e)
{
	if (_size < _maxsize) {
		storage[_size++] = e;
	}
	else {
		extend();
		storage[_size++] = e;
	}
}

void ArrayList::remove(E e)
{
	for (int i = 0; i < _size; ++i) {
		if (storage[i] != e) continue;
		else {
			for (int j = i; j < _size - 1; ++j) {
				storage[j] = storage[j + 1];
			}
			_size--;
		}
	}
}

void ArrayList::clear()
{
	delete[] storage;
	storage = new E[_maxsize];
	_size = 0;
}

bool ArrayList::contain(E e)
{
	for (int i = 0; i < _size; ++i) {
		if (storage[i] == e) return true;
	}
	return false;
}

bool ArrayList::isEmpty()
{
	return _size == 0;
}

E & ArrayList::operator[](int index)
{
	return storage[index];
	// TODO: 在此处插入 return 语句
}

E & ArrayList::get(int index)
{
	return storage[index];
	// TODO: 在此处插入 return 语句
}

int ArrayList::indexOf(E element)
{
	for (int i = 0; i < _size; ++i) {
		if (storage[i] == element) return i;
	}
	return -1;
}

int ArrayList::size()
{
	return _size;
}

void ArrayList::extend()
{
	E *p = storage;
	_maxsize *= extend_factor;
	storage = new E[_maxsize];
	for (int i = 0; i < _size; ++i) {
		storage[i] = p[i];
	}
	delete[] p;
}
