#pragma once
#include"Stack.h"
#include"Link.h"
template <typename Elem>
class LStack :public Stack<Elem> {
private:
	Link<Elem> *top;
	int size;
public:
	LStack() { 
		top = NULL; 
		size = 0;
	}

	~LStack() { clear(); }

	void clear() {
		while (top != NULL) {
			Link<Elem> *temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}

	bool push(const Elem& item) {
		top = new Link<Elem>(item, top);
		size++;
		return true;
	}

	bool pop(Elem& it) {
		if (size == 0) return false;
		it = top->element;
		Link<Elem> *ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return true;
	}

	bool topValue(Elem& it) const {
		if (size == 0) return false;
		it = top->element;
		return true;
	}

	int length() const { return size; }
};