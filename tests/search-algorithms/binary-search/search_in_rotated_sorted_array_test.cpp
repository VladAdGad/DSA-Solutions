#include "search_in_rotated_sorted_array.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Search In Rotated Sort Array", "[Search Algorithms]") {
	std::vector<int> vector;

	vector = {0, 1, 2, 4, 5, 6, 7};
	REQUIRE(search(vector, 0) == 0);

	vector = {4, 5, 6, 7, 0, 1, 2};
	REQUIRE(search(vector, 0) == 4);

	vector = {1};
	REQUIRE(search(vector, 1) == 0);

	vector = {3, 1};
	REQUIRE(search(vector, 1) == 1);
}