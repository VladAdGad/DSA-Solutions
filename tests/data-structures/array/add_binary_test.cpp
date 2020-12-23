#include "add_binary.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Add Binary", "[Data Structures]") {
	std::string a, b;

	a = "11";
	b = "1";
	REQUIRE(addBinary(a, b) == "100");

	a = "1010";
	b = "1011";
	REQUIRE(addBinary(a, b) == "10101");
}
