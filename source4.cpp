#include "pch.h"
#include "source4.h"

#include <map>

__declspec(dllexport) void MappingOpValidated(std::map<ImportantFilePaths, const char*> ProjectFilePaths) {
	if (ProjectFilePaths.find(ImportantFilePaths::Logging) == ProjectFilePaths.end()) {
		throw Exception{};
	}

	if (ProjectFilePaths.find(ImportantFilePaths::Saving) == ProjectFilePaths.end()) {
		throw Exception{};
	}

	if (ProjectFilePaths.find(ImportantFilePaths::Resources) == ProjectFilePaths.end()) {
		throw Exception{};
	}
}