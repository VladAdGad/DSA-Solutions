#include "duplicate_zeros.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Duplicate Zeros", "[Data Structures]") {
	std::vector<int> vector{1, 0, 2, 3, 0, 4, 5, 0};
	REQUIRE_THAT(duplicateZeros(vector), Catch::Matchers::Equals(std::vector<int>{1, 0, 0, 2, 3, 0, 0, 4}));
}
