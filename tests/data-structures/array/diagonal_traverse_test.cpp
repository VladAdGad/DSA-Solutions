#include "diagonal_traverse.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Diagonal Traverse", "[Data Structures]") {
	std::vector<std::vector<int>> matrix;

	matrix = {};
	REQUIRE_THAT(findDiagonalOrder(matrix), Catch::Matchers::Equals(std::vector<int>{}));

	matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	REQUIRE_THAT(findDiagonalOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 4, 7, 5, 3, 6, 8, 9}));

	matrix = {{1, 2, 3}, {4, 5, 6}};
	REQUIRE_THAT(findDiagonalOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 4, 5, 3, 6}));

	matrix = {{1}};
	REQUIRE_THAT(findDiagonalOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1}));
}
