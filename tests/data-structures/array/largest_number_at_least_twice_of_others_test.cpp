#include "largest_number_at_least_twice_of_others.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Largest Number At Least Twice Of Others", "[Data Structures]") {
	std::vector<int> vector;

	vector = {3, 6, 1, 0};
	REQUIRE(dominantIndex(vector) == 1);

	vector = {1, 2, 3, 4};
	REQUIRE(dominantIndex(vector) == -1);

	vector = {1};
	REQUIRE(dominantIndex(vector) == 0);

	vector = {1, 0};
	REQUIRE(dominantIndex(vector) == 0);

	vector = {0, 0, 3, 2};
	REQUIRE(dominantIndex(vector) == -1);

	vector = {0, 3, 1, 2};
	REQUIRE(dominantIndex(vector) == -1);
}