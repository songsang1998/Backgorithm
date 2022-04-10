#include<iostream>
using namespace std;



template<class T> class Queue {

public:
	int front;
	int rear;
	int size;

	T* values;

	Queue(int siz) {
		size = siz;
		rear = 0;
		front = 0;
		values = new T[size];

	}

	void push(T value) {
		values[rear] = value;
		rear =(rear+1)%size;
		
	}
	T pop() {
		T r = values[front];
		front = (front + 1)%size;
		return r;
	}

	int length() {
		if (rear >= front) {
			return rear - front;
		}
		else {
			return rear + size - front;
		}
	}
};





int main() {
	int N;
	cin >> N;
	Queue<int> Q(500001);
	for (int i = 1; i <=N; i++) {
		Q.push(i);
		

	}

	while( Q.length() > 1) {
		Q.pop();
		
		if (Q.length() > 1) {
			int r=Q.pop();
			Q.push(r);
		}
	}
	
	cout<< Q.pop();
}