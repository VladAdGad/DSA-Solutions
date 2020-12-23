#include "daily_temperatures.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Daily Temperatures", "[Data Structures]") {
	std::vector<int> daily_temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	REQUIRE_THAT(dailyTemperatures1(daily_temperatures), Catch::Matchers::Equals(std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
	REQUIRE_THAT(dailyTemperatures2(daily_temperatures), Catch::Matchers::Equals(std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}