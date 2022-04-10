#include <iostream>
using namespace std;

template<class T> class Queue {
public:
	int front;
	int rear;
	int size;

	T* values;

	Queue(int siz)
	{
		size = siz;
		values = new T[size];
		front = 0;
		rear = 0;

	}

	~Queue()
	{
		delete[] values;
	}

	void push(T value) {
		if (!isFull()) {
			values[rear] = value;
			rear = (rear + 1) % size;
		}

	}

	void pop() {
		if (!empty()) {
			front = (front + 1) % size;
		}

	}

	bool empty() {
		if (front == rear) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if ((rear + 1) % size == front) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {

	int T;
	int N;

	cin >> T;

	int x;
	for (int i = 0; i < T; i++) {
		cin >> N;
		Queue<int> q(N);
		cin >> x;
		for (int i = 0; i < N; i++) {
			int v;
			cin >> v;
			q.push(v);
		}
	}

}
