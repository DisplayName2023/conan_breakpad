#include "BreakpadFunctions.h"

#include <string>
#include <locale>
#include <codecvt>

#if defined _WIN32
#include <Windows.h>

std::wstring stringToWstring(const std::string& str) {
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstr(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
	return wstr;
}

#else
std::wstring stringToWstring(const std::string& str) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(str);
}
#endif

namespace BreakpadLib
{
	void InitializeBreakpad(const wchar_t* dumpDirName);
}


extern "C"
{

	void initBreakpad(const char* dumpDirName)
	{
		std::wstring ws = stringToWstring(dumpDirName);
		BreakpadLib::InitializeBreakpad(ws.c_str());
	}

}
