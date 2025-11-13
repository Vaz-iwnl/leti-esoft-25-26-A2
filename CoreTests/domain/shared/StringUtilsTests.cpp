#include "domain/shared/StringUtils.h"
#include "gtest/gtest.h"
#include <string>

// A StringUtilsFixture não é mais necessária, pois todos os métodos são estáticos.
// Mantive a estrutura mínima de um teste Google Test.

TEST(StringUtilsTests, CheckingUpperCase) {
    std::wstring expected = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::wstring original = L"abcdefghijklmnopqrstuvwxyz";
    // Chamada direta para o metodo estático
    std::wstring result = StringUtils::toUpperCase(original);

    EXPECT_EQ(result, expected);
}

TEST(StringUtilsTests, CheckingLowerCase) {
    std::wstring expected = L"abcdefghijklmnopqrstuvwxyz";
    std::wstring original = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Chamada direta para o metodo estático
    std::wstring result = StringUtils::toLowerCase(original);

    EXPECT_EQ(result, expected);
}

TEST(StringUtilsTests, LeftTrim) {
    std::wstring expected = L"name  ";
    std::wstring original1 = L"   name  ";
    std::wstring original2 = L"name  ";
    std::wstring original3 = L" name  ";

    // Chamadas diretas
    std::wstring result = StringUtils::leftTrim(original1);
    EXPECT_EQ(result, expected);
    result = StringUtils::leftTrim(original2);
    EXPECT_EQ(result, expected);
    result = StringUtils::leftTrim(original3);
    EXPECT_EQ(result, expected);
}

TEST(StringUtilsTests, RightTrim) {
    std::wstring expected = L"  name";
    std::wstring original1 = L"  name  ";
    std::wstring original2 = L"  name";
    std::wstring original3 = L"  name ";

    // Chamadas diretas
    std::wstring result = StringUtils::rightTrim(original1);
    EXPECT_EQ(result, expected);
    result = StringUtils::rightTrim(original2);
    EXPECT_EQ(result, expected);
    result = StringUtils::rightTrim(original3);
    EXPECT_EQ(result, expected);
}

TEST(StringUtilsTests, Trim) {
    std::wstring expected = L"name";
    std::wstring original1 = L"  name  ";
    std::wstring original2 = L"  name";
    std::wstring original3 = L"name  ";

    // Chamadas diretas
    std::wstring result = StringUtils::trim(original1);
    EXPECT_EQ(result, expected);
    result = StringUtils::trim(original2);
    EXPECT_EQ(result, expected);
    result = StringUtils::trim(original3);
    EXPECT_EQ(result, expected);
}

TEST(StringUtilsTests, EnsureNotNullOrEmpty) {
    // Chamadas diretas
    EXPECT_FALSE(StringUtils::ensureNotNullOrEmpty(L""));
    EXPECT_FALSE(StringUtils::ensureNotNullOrEmpty(L"   "));
    EXPECT_TRUE(StringUtils::ensureNotNullOrEmpty(L" some value "));
    EXPECT_TRUE(StringUtils::ensureNotNullOrEmpty(L" some value ", 10));
    EXPECT_FALSE(StringUtils::ensureNotNullOrEmpty(L" some value ", 11));
}