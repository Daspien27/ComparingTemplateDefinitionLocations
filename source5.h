#pragma once

enum class ImportantFilePaths : int;

__declspec(dllexport) void DumpLog(std::map<ImportantFilePaths, const char*> ProjectFilePaths);