//
// Created by Xiaochen Wang on 2017-10-06.
//

#ifndef W4_KVLIST_H
#define W4_KVLIST_H
#pragma once
#include <iostream>


template<typename K, typename V, int N>
class KVList {
private:
	struct Table{
		K key;
		V value;
	}table[N];

	size_t listSize = 0;
public:


	KVList():listSize(0){}

	size_t size() const {
		return listSize;
	}


	const K& key(int i) const {
		return table[i].key;
	}


	const V& value(int i) const {
		return table[i].value;
	}

	KVList& add(const K& k, const V& v) {
		if (listSize < N) {
			table[listSize].key = k;
			table[listSize].value = v;
			listSize++;
		}
		return *this;
	}


	int find(const K& k) const {
		int ret = 0;
		for (size_t i = 0; i < listSize; i++) {
			if (table[i].key == k) {
				return i;
			}
		}
		return ret;
	}

	KVList& replace(int i, const K& k, const V& v) {
		table[i].key = k;
		table[i].value = v;
		return *this;
	}
};
#endif //W4_KVLIST_H
