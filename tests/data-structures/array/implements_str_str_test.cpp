#include "implements_str_str.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Implement Str Str", "[Data Structures]") {
	REQUIRE(strStr("", "") == 0);
	REQUIRE(strStr("a", "") == 0);
	REQUIRE(strStr("", "a") == -1);
	REQUIRE(strStr("hello", "ll") == 2);
	REQUIRE(strStr("hello", "hello") == 0);
	REQUIRE(strStr("aaaaa", "bba") == -1);
	REQUIRE(strStr("abc", "c") == 2);
	REQUIRE(strStr("mississippi", "issip") == 4);
}
