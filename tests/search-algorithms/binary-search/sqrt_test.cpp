#include "sqrt.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Sqrt", "[Search Algorithms]") {
	REQUIRE(sqrt(4) == 2);

	REQUIRE(sqrt(8) == 2);

	REQUIRE(sqrt(16) == 4);

	REQUIRE(sqrt(32) == 5);
}
