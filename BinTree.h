#pragma once
#include"BinNode.h"
template <typename Elem> 
class BinTree {
public:
	virtual BinNode<Elem>* getRoot() = 0;
	virtual void preorder(BinNode<Elem>* subroot) = 0;
	virtual void inorder(BinNode<Elem>* subroot) = 0;
	virtual void postorder(BinNode<Elem>* subroot) = 0;
};