#include "pch.h"
#include "source3.h"

#include "other_dependencies.h"
#include <vector>
#include <map>

#if 1

namespace {

	struct LocalValue {
		double V;
		friend LocalValue operator*(LocalValue LV, int I) {
			return LocalValue{ LV.V * I };
		}
	};

}

double CustomOperation::Calculate(const std::vector<int>& In, OtherDependencies& Deps) {
	std::map<int, LocalValue> CalcMap;
	
	for (auto I : In) {
		CalcMap[I].V = Deps.ValueAt(I) * 7; //maybe this already uses std::map::find? ...
	}

	Deps.Prep("CustomOp");

	return FindOrThrow(CalcMap, Deps.ImportantSetting()).V;
	//return FindOrThrowAmplify2(CalcMap, Deps.ImportantSetting()).V;
}







#else
namespace {

	struct LocalValue /* : deep inheritance chain, with bases that also require instantiations */ {
		double V;
		//std::vector<std::map<int, double>> Vals; //working variables
		friend LocalValue operator*(LocalValue LV, int I) {
			return LocalValue{ LV.V * I };
		}
	};

}

double CustomOperation::Calculate(const std::vector<int>& In, OtherDependencies& Deps) {
	std::map<int, LocalValue> CalcMap;

	for (auto I : In) {
		CalcMap[I].V = Deps.ValueAt(I) * 7; //maybe this already uses std::map::find? ...
	}

	Deps.Prep("CustomOp");

	return FindOrThrow(CalcMap, Deps.ImportantSetting()).V;
	//return FindOrThrowAmplify2(CalcMap, Deps.ImportantSetting()).V;
}
#endif