#pragma once
#include"Queue.h"
#include"Link.h"
template <typename Elem>
class LQueue :public Queue<Elem> {
private:
	Link<Elem>* head;
	Link<Elem>* tail;
	int size;
public:
	LQueue() {
		head = tail = new Link<Elem>;
		size = 0;
	}

	~LQueue(){}

	void clear() {
		Link<Elem>* temp;
		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	bool enqueue(const Elem& item) {
		tail->element = item;
		tail->next = new Link<Elem>;
		tail = tail->next;
		size++;
		return true;
	}

	bool dequeue(Elem& item) {
		if (size == 0) return false;
		item = head->element;
		Link<Elem>* temp = head;
		head = head->next;
		delete temp;
		size--;
		return true;
	}

	bool frontValue(Elem& item) const {
		if (size == 0) return false;
		item = head->element;
		return true;
	}

	int length() const { return size; }
};