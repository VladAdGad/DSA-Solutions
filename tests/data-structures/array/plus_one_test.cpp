#include "plus_one.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Plus One", "[Data Structures]") {
	std::vector<int> digits;

	digits = {1, 2, 3};
	REQUIRE_THAT(plusOne(digits), Catch::Matchers::Equals(std::vector<int>{1, 2, 4}));

	digits = {1, 9, 9};
	REQUIRE_THAT(plusOne(digits), Catch::Matchers::Equals(std::vector<int>{2, 0, 0}));

	digits = {1, 0, 9};
	REQUIRE_THAT(plusOne(digits), Catch::Matchers::Equals(std::vector<int>{1, 1, 0}));

	digits = {9};
	REQUIRE_THAT(plusOne(digits), Catch::Matchers::Equals(std::vector<int>{1, 0}));

	digits = {0};
	REQUIRE_THAT(plusOne(digits), Catch::Matchers::Equals(std::vector<int>{1}));

	digits = {5, 2, 2, 6, 5, 7, 1, 9, 0, 3, 8, 6, 8, 6, 5, 2, 1, 8, 7, 9, 8, 3, 8, 4, 7, 2, 5, 8, 9};
	REQUIRE_THAT(plusOne(digits), Catch::Matchers::Equals(std::vector<int>{5, 2, 2, 6, 5, 7, 1, 9, 0, 3, 8, 6, 8, 6, 5,
																																				 2, 1, 8, 7, 9, 8, 3, 8, 4, 7, 2, 5, 9, 0}));
}