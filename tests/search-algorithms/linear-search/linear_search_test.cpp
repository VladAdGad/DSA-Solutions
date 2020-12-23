#include "linear_search.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Linear Search", "[Search Algorithms]") {
	std::vector<int> simple_vector{9, 7, 2, 16, 4};
	REQUIRE(linearSearch(simple_vector, 16) == 4);
}
