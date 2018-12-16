#pragma once
template <typename Key, typename E>
class KVpair {
private:
	Key keys;
	E values;
public:
	KVpair(Key data=NULL, E it=NULL) {
		keys = data;
		values = it;
	}

	void setKey(Key data) {
		keys = data;
	}

	Key key() {
		return keys;
	}

	E value() {
		return values;
	}
};