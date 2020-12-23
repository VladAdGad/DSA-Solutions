#include "spiral_matrix.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Spiral Matrix", "[Data Structures]") {
	std::vector<std::vector<int>> matrix;

	matrix = {};
	REQUIRE_THAT(spiralOrder(matrix), Catch::Matchers::Equals(std::vector<int>{}));

	matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	REQUIRE_THAT(spiralOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5}));

	matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	REQUIRE_THAT(spiralOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));
}