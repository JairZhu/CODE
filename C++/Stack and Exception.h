const int MAX_LEN = 5;

template<class T>

class Stack

{

public:

	explicit Stack() {
		stack_size = 0;
	}

	bool empty() const { return stack_size == 0; }

	int size() const { return stack_size; }

	T& top() {
		if (stack_size == 0) throw 1;
		else return data[stack_size - 1];
	}

	const T& top() const {
		if (stack_size == 0) throw 1;
		else return data[stack_size - 1];
	}

	void push(const T& x) {
		if (stack_size == MAX_LEN) {
			if (x > data[stack_size - 1]) data[stack_size - 1] = x;
		}
		else {
			data[stack_size++] = x;
		}
	}

	void pop() {
		if (stack_size == 0) throw 0.1;
		else {
			stack_size--;
		}
	}

private:

	T data[MAX_LEN];

	int stack_size;

};