#include "pch.h"
#include "source5.h"
#include "source4.h"

#include <map>
#include <fstream>
#include <iostream>

__declspec(dllexport) void DumpLog(std::map<ImportantFilePaths, const char*> ProjectFilePaths) {
	auto LogFP = ProjectFilePaths.find(ImportantFilePaths::Logging);
	if (LogFP == ProjectFilePaths.end()) {
		throw Exception{};
	}

	std::ifstream fs(LogFP->second);
	std::cout << fs.rdbuf();
}