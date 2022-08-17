#include "pch.h"

#include <map>
template <typename Key, typename Value>
Value FindOrThrowAmplify2(std::map<Key, Value>& M, const Key& K) {
	auto I = M.find(K);

	if (I == M.end()) {
		throw Exception{};
	}

	return I->second * 2;
}

template int FindOrThrowAmplify2<int, int>(std::map<int, int>&, const int&);
