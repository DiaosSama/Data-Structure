#pragma once
#include"BinNode.h"
template <typename Elem>
class BinNodePtr :public BinNode<Elem> {
private:
	Elem it;          // The node's value
	BinNodePtr* lc;   // Pointer to left child
	BinNodePtr* rc;   // Pointer to right child
public:
	BinNodePtr() { lc = rc = NULL; }

	BinNodePtr(Elem e, BinNodePtr* l = NULL, BinNodePtr* r = NULL) {
		it = e;
		lc = l;
		rc = r;
	}

	Elem& val() { return it; }

	void setVal(const Elem& e) { it = e; }

	inline BinNode<Elem>* left() const { return lc; }

	void setLeft(BinNode<Elem>* b) { lc = (BinNodePtr*)b; }

	inline BinNode<Elem>* right() const { return rc; }

	void setRight(BinNode<Elem>* b) { rc = (BinNodePtr*)b; }

	bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};