#pragma once
#include "Dictionary.h"
#include "KVpair.h"
// Dictionary implemented with a hash table
template <typename Key, typename E>
class hashdict : public Dictionary<Key, E> {
private:
	KVpair<Key, E>* HT;    // The hash table
	int M;                 // Size of HT
	int currcnt;           // the current number of elements in HT
	Key EMPTYKEY;          // User-supplied key value for empty slot

	int p(Key k, int i) const { return i; }  // Probe using linear probing

	int p(Key k, int i) const {
		srand(k);
		return i*rand();
	}
	int h(int x) const { return x % M; }      // Poor hash function
	int h(char* x) const {
		int i, sum;
		for (sum = 0;i = 0;x[i] != '\0'; i++) sum += (int)x[i];
		return sum % M;
	}

	void hashInsert(const Key& k, const E& e) {
		int home;
		Key pos = home = h(k);
		for (int i = 0;EMPTYKEY != (HT[pos]).key();i++) {
			pos = (home + p(k, i)) % M;
			//Assert(k != (HT[pos]).key(), "Duplicates not allowed");
			if (k == (HT[pos]).key()) {
				cout << "Duplicates not allowed" << endl;
				currcnt--;
				return;
			}
		}
		KVpair<Key, E> temp(k, e);
		HT[pos] = temp;
	}

	E hashSearch(const Key& k) const {
		int home;int pos = home = h(k);
		for (int i = 1;(k != (HT[pos]).key()) && (EMPTYKEY != (HT[pos]).key());i++)
			pos = (home + p(k, i)) % M;
		if (k == (HT[pos]).key())
			return (HT[pos]).value();
		else return NULL;
	}

public:
	hashdict(int sz, Key k) {
		M = sz;
		EMPTYKEY = k;
		currcnt = 0;
		HT = new KVpair<Key, E>[sz];
		for (int i = 0;i < M;i++)
			(HT[i]).setKey(EMPTYKEY);    // Initialize HT
	}

	~hashdict() { delete HT; }

	// Find some record with key value "K"
	E find(const Key& k)const {
		return hashSearch(k);
	}

	int size() { return currcnt; }    // Number stored in table

	// Insert element "it" with Key "k" into the dictionary.
	void insert(const Key& k, const E& it) {
		//Assert(currcnt < M, "Hash table is full");
		if (currcnt > M) {
			cout << "Hash table is full" << endl;
			return;
		}
		hashInsert(k, it);
		currcnt++;
	}

	// Reinitialize hashtable
	void clear() {
		delete HT;
		currcnt = 0;
		HT = new KVpair<Key, E>[M];
		for (int i = 0;i < M;i++) {
			(HT[i]).setKey(EMPTYKEY);
		}
	}
};