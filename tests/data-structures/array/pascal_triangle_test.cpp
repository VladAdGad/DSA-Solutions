#include "pascal_triangle.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Pascal Triangle", "[Data Structures]") {
	REQUIRE_THAT(generatePascalTriangle(0), Catch::Matchers::Equals(std::vector<std::vector<int>>{}));
	REQUIRE_THAT(generatePascalTriangle(1), Catch::Matchers::Equals(std::vector<std::vector<int>>{{1}}));
	REQUIRE_THAT(generatePascalTriangle(5), Catch::Matchers::Equals(std::vector<std::vector<int>>{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}));
}
