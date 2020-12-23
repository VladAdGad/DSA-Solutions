#include "reverse_string.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Reverse String", "[Data Structures]") {
	std::vector<char> vector;

	vector = {};
	REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{}));

	vector = {'h'};
	REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{'h'}));

	vector = {'h', 'e', 'l', 'l', 'o'};
	REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{'o', 'l', 'l', 'e', 'h'}));

	vector = {'H', 'a', 'n', 'n', 'a', 'h'};
	REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}));
}