#pragma once
#include<iostream>
#include"LQueue.h"
#include"AStack.h"
#include"BinNodePtr.h"
#include"BinNode.h"
#include"BinTree.h"

template <typename Elem>
class LBinTree :public BinTree<Elem> {
private:
	BinNodePtr<Elem>* root;
public:
	LBinTree() { root = new BinNodePtr<Elem>(); }

	LBinTree(BinNodePtr<Elem>* subroot) { root = subroot; }

	LBinTree(BinNode<Elem>* subroot) { root = subroot; }

	BinNode<Elem>* getRoot() { return root; }
	
	void preorder(BinNode<Elem>* subroot) {
		if (subroot == NULL) return;
		visit(subroot);
		preorder(subroot->left());
		preorder(subroot->right());
	}

	void inorder(BinNode<Elem>* subroot) {
		if (subroot == NULL) return;
		inorder(subroot->left());
		visit(subroot);
		inorder(subroot->right());
	}

	void postorder(BinNode<Elem>* subroot) {
		if (subroot == NULL) return;
		postorder(subroot->left());
		postorder(subroot->right());
		visit(subroot);
	}

	//5.7：按等级输出每一级的数据
	void leveltraversal() {
		LQueue<BinNode<Elem>*> queue;
		BinNode<Elem>* temp = root;
		queue.enqueue(temp);
		while (queue.dequeue(temp)) {
			visit(temp);
			if (temp->left()) {
				//visit(temp->left());
				queue.enqueue(temp->left());
			}
			if (temp->right()) {
				//visit(temp->right());
				queue.enqueue(temp->right());
			}
		}
	}

	//5.8：递归求得树的高度
	void heighthelp(BinNode<Elem>* subroot, int& Max = 0, int now = 0) {
		if (subroot == NULL) return;
		now++;
		if (Max < now) Max = now;
		heighthelp(subroot->left(), Max, now);
		heighthelp(subroot->right(), Max, now);
	}

	int height() {
		int Max = 0;
		heighthelp(root, Max);
		return Max;
	}

	//5.9：递归求叶结点个数
	void countleafhelp(BinNode<Elem>* subroot, int& num = 0) {
		if (subroot->isLeaf()) {
			num++;
			return;
		}
		countleafhelp(subroot->left(), num);
		countleafhelp(subroot->right(), num);
	}

	int countleaf() {
		int num = 0;
		countleafhelp(root, num);
		return num;
	}

	void visit(BinNode<Elem>* subroot) {
		cout << subroot->val() << " ";
	}
};