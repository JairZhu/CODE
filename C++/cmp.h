#include <cstring>
using namespace std;

template <typename T>
bool cmp(T a, T b) {
	return a == b;
}

template <> bool cmp<char*>(char * a, char * b) {
	if (strcmp(a, b) == 0) return true;
	else return false;
}


template <> bool cmp<int*>(int *a, int *b) {
	return *a == *b;
}

template <> bool cmp<double*>(double *a, double *b) {
	return *a == *b;
}