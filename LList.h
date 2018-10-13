#pragma once
#include"Link.h"
#include"List.h"
template <typename Elem>
class LList :public List<Elem> {
private:
	Link<Elem> *head;
	Link<Elem> *tail;
	Link<Elem> *fence;
	int leftcnt;
	int rightcnt;
public:
	LList() {
		init();
	}

	void init() {
		fence = tail = head = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}

	~LList() { removeall(); }

	void clear() { removeall(); init(); }

	void removeall() {
		while (head != NULL){
			fence = head;
			head = head->next;
			delete fence;
		}
	}

	void setStart() {
		fence = head;
		rightcnt += leftcnt;
		leftcnt = 0;
	}

	void setEnd() {
		fence = tail;
		leftcnt += rightcnt;
		rightcnt = 0;
	}

	bool next() {
		if (fence != tail) {
			fence = fence->next;
			rightcnt--;
			leftcnt++;
			return true;
		}
		else return false;
	}

	bool prev() {
		if (fence != head) {
			Link<Elem> *temp = head;
			while (temp->next != fence)
				temp = temp->next;
			fence = temp;
			leftcnt--;
			rightcnt++;
			return true;
		}
		else return false;
	}

	bool insert(const Elem& item) {
		fence->next = new Link<Elem>(item, fence->next);
		if (tail == fence) tail = fence->next;
		rightcnt++;
		return true;
	}

	bool remove(Elem& item) {
		Link<Elem> *temp = fence->next;
		if (temp != NULL)
		{
			fence->next = temp->next;
			item = temp->element;
			rightcnt--;
			if (temp == tail) tail = fence;
			delete temp;
			return true;
		}
		else return false;
	}

	bool append(const Elem& item) {
		tail->next = new Link<Elem>(item);
		tail = tail->next;
		rightcnt++;
		return true;
	}

	bool getValue(Elem& item) const {
		if (rightLength() == 0) return false;
		item = fence->next->element;
		return true;
	}

	bool setPos(int pos) {
		if (pos > leftcnt + rightcnt || pos < 0) return false;
		fence = head;
		for (int i = 0;i < pos;i++) {
			fence = fence->next;
		}
		rightcnt = rightcnt + leftcnt - pos;
		leftcnt = pos;
		return true;
	}

	int leftLength() const { return leftcnt; }

	int rightLength() const { return rightcnt; }

	void print() const {
		Link<Elem> *temp = head;
		while (temp->next != NULL) {
			cout << temp->next->element << " ";
			temp = temp->next;
		}
	}
};