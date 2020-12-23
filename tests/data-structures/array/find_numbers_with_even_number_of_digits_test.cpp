#include "find_numbers_with_even_number_of_digits.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Find Numbers With Even Number Of Digits", "[Data Structures]") {
	std::vector<int> vector1{555, 901, 482, 1771};
	std::vector<int> vector2{12, 345, 2, 6, 7896};

	REQUIRE(findNumbersWithEvenNumberOfDigits0(vector1) == 1);
	REQUIRE(findNumbersWithEvenNumberOfDigits0(vector2) == 2);

	REQUIRE(findNumbersWithEvenNumberOfDigits1(vector1) == 1);
	REQUIRE(findNumbersWithEvenNumberOfDigits1(vector2) == 2);
}