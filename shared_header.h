#pragma once

struct Exception {};

template <typename Key, typename Value>
Value FindOrThrow(std::map<Key, Value>& M, const Key& K) {
	auto I = M.find(K);

	if (I == M.end()) {
		throw Exception{};
	}

	return I->second;
}

template <typename Key, typename Value>
Value FindOrThrowAmplify2(std::map<Key, Value>& M, const Key& K);

extern template int FindOrThrowAmplify2<int, int>(std::map<int, int>&, const int&);