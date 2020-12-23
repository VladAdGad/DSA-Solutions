#include "find_pivot_index.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Find Pivot Index", "[Data Structures]") {
	std::vector<int> nums{1, 7, 3, 6, 5, 6};
	REQUIRE(findPivotIndex(nums) == 3);
}