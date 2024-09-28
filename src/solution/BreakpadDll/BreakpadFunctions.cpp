#include "BreakpadFunctions.h"

#include <iostream>
#include <string>
#include <locale>
#include <cwchar>
#include <codecvt>
#include <stdexcept>

std::wstring utf8ToWString(const std::string& utf8_str) {
    std::wstring wstr;
    std::mbstate_t state = std::mbstate_t();  // Initialize the conversion state

    const char* str = utf8_str.data();
    std::size_t len = utf8_str.size();
    wchar_t wc;
    while (len > 0) {
        std::size_t converted = std::mbrtowc(&wc, str, len, &state);
        if (converted == static_cast<std::size_t>(-1) || converted == static_cast<std::size_t>(-2)) {
            throw std::runtime_error("UTF-8 to wide conversion error");
        }
        wstr += wc;
        str += converted;
        len -= converted;
    }
    return wstr;
}

#if defined _WIN32
#include <Windows.h>

std::wstring utf8ToWStringWin64(const std::string& str) {
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstr(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
	return wstr;
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
		std::wstring ws = utf8ToWString(dumpDirName);
		BreakpadLib::InitializeBreakpad(ws.c_str());
	}

}
