#include "missing_number.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Missing Number", "[Search Algorithms]") {
	std::vector<int> nums;

	nums = {3, 0, 1};
	REQUIRE(missingNumber0(nums) == 2);
	REQUIRE(missingNumber1(nums) == 2);

	nums = {0, 1, 2, 4, 5, 6};
	REQUIRE(missingNumber0(nums) == 3);
	REQUIRE(missingNumber1(nums) == 3);

	nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
	REQUIRE(missingNumber0(nums) == 8);
	REQUIRE(missingNumber1(nums) == 8);

	nums = {0};
	REQUIRE(missingNumber0(nums) == 1);
	REQUIRE(missingNumber1(nums) == 1);
}
