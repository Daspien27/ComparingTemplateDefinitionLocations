#pragma once

enum class ImportantFilePaths : int {
	Logging,
	Saving,
	Resources,
};

__declspec(dllexport) void MappingOpValidated(std::map<ImportantFilePaths, const char*> ProjectFilePaths);