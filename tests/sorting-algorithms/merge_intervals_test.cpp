#include "merge_intervals.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Merge Intervals", "[Sorting Algorithms]") {
	std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	REQUIRE_THAT(merge(intervals), Catch::Matchers::Equals(std::vector<std::vector<int>>{{1, 6}, {8, 10}, {15, 18}}));

	std::vector<std::vector<int>> intervals1 = {{1, 4}, {0, 2}, {3, 5}};
	REQUIRE_THAT(merge(intervals1), Catch::Matchers::Equals(std::vector<std::vector<int>>{{0, 5}}));
}
