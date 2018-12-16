#pragma once
#include<cstdlib>
#include<ctime>
#include<stack>

struct range {
	int head, tail, pivot;
};

template <typename Elem>
void qsort(Elem A[], int i, int j) {
	if (j <= i) return;      // List too small

							 //optimizations(b): combine with insert sort
	if (j - i + 1 < 10) {
		insertsort(A, j - i + 1);
	}
	else {
		int pivotindex = findpivot(A, i, j);
		swap(A, pivotindex, j);  // Put pivot at end
								 // k will be first position on right side
		int k = partition<Elem>(A, i, j, A[j]);
		swap(A, k, j);           // Pit pivot in place
		qsort<Elem>(A, i, k - 1);
		qsort<Elem>(A, k + 1, j);
	}
}

//optimizations(c): Eliminate recursion by using a stack and inline function
template <typename Elem>
void qsortop(Elem A[], int i, int j) {
	if (j <= i) return;
	stack<range> temp;
	range a;
	a.head = i;
	a.tail = j;
	do {
		int pivotindex = findpivot(A, a.head, a.tail);
		swap(A, pivotindex, a.tail);
		int k = partition<Elem>(A, a.head, a.tail, A[a.tail]);
		swap(A, k, a.tail);
		a.pivot = k;
		temp.push(a);
		a.tail = k - 1;
	} while (a.head < a.tail);
		while (!temp.empty()) {
			a = temp.top();
			temp.pop();
			a.head = a.pivot + 1;
			if (a.head >= a.tail) continue;
			int pivotindex = findpivot(A, a.head, a.tail);
			swap(A, pivotindex, a.tail);
			int k = partition<Elem>(A, a.head, a.tail, A[a.tail]);
			swap(A, k, a.tail);
			a.pivot = k;
			temp.push(a);
			a.tail = k - 1;
			while (a.head < a.tail) {
				flag = true;
				int pivotindex = findpivot(A, a.head, a.tail);
				swap(A, pivotindex, a.tail);
				int k = partition<Elem>(A, a.head, a.tail, A[a.tail]);
				swap(A, k, a.tail);
				a.pivot = k;
				temp.push(a);
				a.tail = k - 1;
			}
		}
}

template <typename Elem>
int findpivot(Elem A[], int i, int j) {
	// optimizations(a):select more values
	int a, b, c;
	srand(time(0));
	a = rand() % (j - i + 1);
	b = rand() % (j - i + 1);
	c = rand() % (j - i + 1);
	int max = A[i + a], maxnum = a;
	if (A[i + b] > max) {
		max = A[i + b];
		maxnum = b;
	}
	if (A[i + c] > max) {
		max = A[i + c];
		maxnum = c;
	}
	int min = A[i + a], minnum = a;
	if (A[i + b] <= min) {
		min = A[i + b];
		minnum = b;
	}
	if (A[i + c] <= min) {
		min = A[i + c];
		minnum = c;
	}
	return a + b + c - (maxnum + minnum);
}

template <typename Elem>
int partition(Elem A[], int l, int r, Elem& pivot) {
	do {
		while (A[l] < pivot) l++;
		while ((r > l) && A[r] >= pivot) r--;
		swap(A, l, r);     // Swap out-of-place values
	} while (l < r);       // Stop when they cross
	return l;              // Return first pos on right
}

template <typename Elem>
void swap(Elem A[], int i, int j) {
	Elem temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

template <typename Elem>
void insertsort(Elem A[], int n) {
	for (int i = 1; i<n; i++)
		for (int j = i; (j>0) && (A[j]<A[j - 1]); j--)
			swap(A, j, j - 1);
}
