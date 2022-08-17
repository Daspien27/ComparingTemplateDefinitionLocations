#include "pch.h"
#include "source1.h"

#include <map>
#include <iostream>

__declspec(dllexport) void LogMapEntries(std::map<int, int>& M) {
	auto V1 = FindOrThrow(M, 1);
	std::cout << "Value " << V1;

	auto V2 = FindOrThrow(M, 2);
	std::cout << "Value " << V2;

	auto V3 = FindOrThrow(M, 3);
	std::cout << "Value " << V3;
}