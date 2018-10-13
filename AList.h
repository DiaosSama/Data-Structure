#pragma once
#include"List.h"
template <typename Elem>
class AList : public List<Elem> {
private:
	int maxSize;
	int listSize;
	int fence;
	Elem* listArray;
public:
	AList(int size = 100) {
		maxSize = size;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}

    ~AList() {
		delete[]listArray;
	}

	void clear() {
		delete[]listArray;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}

	bool setPos(int pos) {
		if (pos >= 0 && pos <= listSize)
			fence = pos;
		return  (pos >= 0 && pos <= listSize);
	}

	bool insert(const Elem& item) {
		if (listSize < maxSize)
		{
			for (int i = listSize - 1;i >= fence;i--)
			{
				listArray[i + 1] = listArray[i];
			}
			listArray[fence] = item;
			listSize++;
		}
		return (listSize < maxSize);
	}

	bool append(const Elem& item) {
		if (listSize < maxSize)
		{
			listArray[listSize] = item;
			listSize++;
		}
		return (listSize < maxSize);
	}

	bool remove(Elem& item) {
		if (listSize != 0)
		{
			item = listArray[fence];
			for (int i = fence;i < listSize - 1;i++) {
				listArray[i] = listArray[i + 1];
			}
			listSize--;
		}
		return (listSize != 0);
	}

	bool getValue(Elem& item) const {
		if (listSize != 0)
			item = listArray[fence];
		return listSize != 0;
	}

	void setStart() { fence = 0; }

	void setEnd() { fence = listSize; }

	bool prev() {
		if (fence != 0) {
			fence--;
			return true;
		}
		else return false;
	}

	bool next() {
		if (fence < listSize) {
			fence++;
			return true;
		}
		else return false;
	}

	int leftLength() const {
		return fence;
	}

	int rightLength() const {
		return listSize - fence;
	}

	void print() const {
		for (int i = 0;i < listSize;i++)
		{
			cout << listArray[i] << " ";
		}
	}
};