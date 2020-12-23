#include "valid_parentheses.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Valid Parentheses", "[Data Structures]") {
	REQUIRE(isValid("()"));

	REQUIRE(isValid("()[]{}"));

	REQUIRE(isValid("{[]}"));

	REQUIRE_FALSE(isValid("(])"));

	REQUIRE_FALSE(isValid("(]"));

	REQUIRE_FALSE(isValid("([)]"));

	REQUIRE_FALSE(isValid("]"));
}