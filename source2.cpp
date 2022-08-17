#include "pch.h"
#include "source2.h"

#include <iostream>
__declspec(dllexport) void GetTwiceValueEntries(std::map<int, int>& M, int K) {

	std::cout << FindOrThrowAmplify2(M, 4);

}