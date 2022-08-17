// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"


namespace std {
	template <class _Ty = void> struct less;
	template <class _Ty> class allocator;
	template <class _Ty1, class _Ty2> struct pair;

	template <class _Kty, class _Ty, class _Pr = less<_Kty>, class _Alloc = allocator<pair<const _Kty, _Ty>>> class map;
	template <class _Ty, class _Alloc = allocator<_Ty>> class vector;
}


#include "shared_header.h"

#endif //PCH_H
