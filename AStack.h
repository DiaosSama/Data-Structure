#pragma once
#include"Stack.h"
template <typename Elem>
class AStack :public Stack<Elem> {
private:
	int size;
	int top;
	Elem *listArray;
public:
	AStack(int sz = 100) {
		size = sz;
		top = 0;
		listArray = new Elem[sz];
	}

	~AStack() { delete[]listArray; }

	void clear() { top = 0; }

	bool push(const Elem& item) {
		if (top == size) return false;
		else { 
			listArray[top++] = item;
		    return true;
		}
	}

	bool pop(Elem& it) {
		if (top == 0) return false;
		else {
			it = listArray[--top];
			return true;
		}
	}

	bool topValue(Elem& it) const {
		if (top == 0) return false;
		else {
			it = listArray[top - 1];
			return true;
		}
	}

	int length() const { return top; }
};