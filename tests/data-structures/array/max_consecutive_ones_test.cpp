#include "max_consecutive_ones.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Find Max Consecutive Ones", "[Data Structures]") {
	std::vector<int> vector;

	vector = {1};
	REQUIRE(findMaxConsecutiveOnes(vector) == 1);

	vector = {1, 1, 0, 1, 1, 1};
	REQUIRE(findMaxConsecutiveOnes(vector) == 3);
}