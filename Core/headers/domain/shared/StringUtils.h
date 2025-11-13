#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <locale>

class StringUtils {
public:
    static std::wstring toUpperCase(const std::wstring &value);
    static std::wstring toLowerCase(const std::wstring &value);
    static std::wstring leftTrim(const std::wstring &value);
    static std::wstring rightTrim(const std::wstring &value);
    static std::wstring trim(const std::wstring &value);
    static bool ensureNotNullOrEmpty(const std::wstring &value);
    static bool ensureNotNullOrEmpty(const std::wstring &value, int minLength);
};

#endif //STRINGUTILS_H