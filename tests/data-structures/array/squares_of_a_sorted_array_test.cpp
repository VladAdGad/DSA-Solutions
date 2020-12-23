#include "squares_of_a_sorted_array.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Squares of a Sorted Array", "[Data Structures]") {
	std::vector<int> vector;

	vector = {-3, -1, 0};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{0, 1, 9}));

	vector = {-3, 0, 2};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{0, 4, 9}));

	vector = {-4, -1, 0, 3, 10};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{0, 1, 9, 16, 100}));

	vector = {-7, -3, 2, 3, 11};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{4, 9, 9, 49, 121}));

	vector = {2, 3, 11};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{4, 9, 121}));

	vector = {-1};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{1}));

	vector = {-2, 0};
	REQUIRE_THAT(sortedSquares(vector), Catch::Matchers::Equals(std::vector<int>{0, 4}));
}