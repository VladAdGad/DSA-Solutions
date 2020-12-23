#include "binary_search.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Binary Search", "[Search Algorithms]") {
	std::vector<int> vector;

	vector = {};
	REQUIRE(binarySearch(vector, 10) == -1);

	vector = {10};
	REQUIRE(binarySearch(vector, 10) == 0);

	vector = {2, 5};
	REQUIRE(binarySearch(vector, 2) == 0);
	REQUIRE(binarySearch(vector, 5) == 1);

	vector = {-1, 0, 3, 5, 9, 12};
	REQUIRE(binarySearch(vector, 9) == 4);
}
