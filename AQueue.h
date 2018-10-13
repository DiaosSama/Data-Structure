#pragma once
#include"Queue.h"
template <typename Elem>
class AQueue :public Queue<Elem> {
private:
	int size;
	int front;
	int rear;
	Elem *listArray;
public:
	AQueue(int sz = 100) {
		size = sz;
		rear = 0;
		front = 1;
		listArray = new Elem[sz];
	}

	void clear() { front = (rear + 1) % size; }

	bool enqueue(const Elem& item) {
		if ((rear + 2) % size == front) return false;
		listArray[(++rear)%size] = item;
		return true;
	}

	bool dequeue(Elem& item) {
		if ((rear + 1) % size == front) return false;
		item = listArray[front];
		front = (front + 1) % size;
		return true;
	}

	bool frontValue(Elem& item) const {
		if ((rear + 1) % size == front) return false;
		item = listArray[front];
		return true;
	}

	int length() const { return ((rear + size) - front + 1) % size; }
};