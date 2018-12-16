#pragma once
#include"List.h"
#include"LList.h"

// Array-based implement
template <typename Elem>
void mergesort(Elem A[], Elem temp[], int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return;

	mergesort<Elem>(A, temp, left, mid);
	mergesort<Elem>(A, temp, mid + 1, right);

	for (int i = left; i <= right; i++) temp[i] = A[i];
	int i1 = left;
	int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1) A[curr] = temp[i2++]; // Left exhausted
		else if (i2 > right) A[curr] = temp[i1++] // Right exhausted
		else if (temp[i1] < temp[i2]) A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}

// Link list-based implement
template <typename Elem>
LList<Elem>* mergesort(LList<Elem> *inlist) {
	if (inlist->leftLength() + inlist->rightLength() <= 1) return inlist;
	int mid = (inlist->leftLength() + inlist->rightLength()) / 2;
	LList<Elem> *l1 = new LList<Elem>;
	LList<Elem> *l2 = new LList<Elem>;
	inlist->setStart();
	for (int fence = 0; fence < mid; fence++) {
		Elem item;
		inlist->getValue(item);
		l1->append(item);
		inlist->next();
	}
	for (int fence = mid; fence < inlist->leftLength() + inlist->rightLength(); fence++) {
		Elem item;
		inlist->getValue(item);
		l2->append(item);
		inlist->next();
	}
	return merge(mergesort(l1), mergesort(l2));
}

template <typename Elem>
LList<Elem>* merge(LList<Elem> *l1, LList<Elem> *l2) {
	LList<Elem> *temp = new LList<Elem>;
	Elem value1, value2;
	while (l1->getValue(value1) || l2->getValue(value2)) {
		if (!l1->getValue(value1)) {
			l2->getValue(value2);
			temp->append(value2);
			l2->next();
		}
		else if (!l2->getValue(value2)) {
			l1->getValue(value1);
			temp->append(value1);
			l1->next();
		}
		else if (value1 < value2) {
			temp->append(value1);
			l1->next();
		}
		else {
			temp->append(value2);
			l2->next();
		}
	}
	return temp;
}