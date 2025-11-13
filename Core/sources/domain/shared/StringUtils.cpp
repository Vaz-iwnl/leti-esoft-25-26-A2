#include <locale>
#include <algorithm>
#include <cctype>
#include "domain/shared/StringUtils.h"

std::wstring StringUtils::toUpperCase(const std::wstring &value) {
    std::wstring copy = value;
    const std::ctype<wchar_t>& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

    for (wchar_t &c : copy) {
        c = f.toupper(c);
    }
    return copy;
}

std::wstring StringUtils::toLowerCase(const std::wstring &value) {
    std::wstring copy = value;
    const std::ctype<wchar_t>& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

    for (wchar_t &c : copy) {
        c = f.tolower(c);
    }
    return copy;
}

std::wstring StringUtils::leftTrim(const std::wstring &value) {
    std::wstring copy = value;
    copy.erase(copy.begin(), std::find_if(copy.begin(), copy.end(), [](wchar_t ch) {
        return !std::iswspace(ch);
    }));
    return copy;
}

std::wstring StringUtils::rightTrim(const std::wstring &value) {
    std::wstring copy = value;
    copy.erase(std::find_if(copy.rbegin(), copy.rend(), [](wchar_t ch) {
        return !std::iswspace(ch);
    }).base(), copy.end());
    return copy;
}

std::wstring StringUtils::trim(const std::wstring &value) {
    return rightTrim(leftTrim(value));
}

bool StringUtils::ensureNotNullOrEmpty(const std::wstring &value) {
    return ensureNotNullOrEmpty(value, 1);
}

bool StringUtils::ensureNotNullOrEmpty(const std::wstring &value, int minLength) {
    if (minLength < 1) {
        minLength = 1;
    }

    if (!value.empty()){
        return (trim(value).length() >= minLength);
    }
    return false;
}