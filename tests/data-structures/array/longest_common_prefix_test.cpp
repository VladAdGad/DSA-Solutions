#include "longest_common_prefix.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Longest Common Prefix", "[Data Structures]") {
	std::vector<std::string> vector;

	vector = {};
	REQUIRE(longestCommonPrefix(vector) == "");

	vector = {"", ""};
	REQUIRE(longestCommonPrefix(vector) == "");

	vector = {"flower", "flow", "flight"};
	REQUIRE(longestCommonPrefix(vector) == "fl");

	vector = {"dog", "racecar", "car"};
	REQUIRE(longestCommonPrefix(vector) == "");

	vector = {"dog", "doggy", "kukarachi"};
	REQUIRE(longestCommonPrefix(vector) == "");

	vector = {"dog", "dog"};
	REQUIRE(longestCommonPrefix(vector) == "dog");
}
