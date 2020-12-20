#include <catch2/catch.hpp>


int find_numbers_with_even_number_of_digits_solution_0(std::vector<int> &nums) {
    int numbers_with_even_number_of_digits = 0;
    std::string str_num;

    for (int num: nums) {
        str_num = std::to_string(num);
        numbers_with_even_number_of_digits += (str_num.length() % 2 == 0) ? 1 : 0;
    }

    return numbers_with_even_number_of_digits;
}

int find_numbers_with_even_number_of_digits_solution_1(std::vector<int> &nums) {
    int numbers_with_even_number_of_digits = 0;

    for (int num : nums) {
        int digit = 0;

        while (num > 0) {
            num /= 10;
            digit++;
        }
        numbers_with_even_number_of_digits += (digit % 2 == 0) ? 1 : 0;
    }

    return numbers_with_even_number_of_digits;
}

TEST_CASE("Find Numbers With Even Number Of Digits", "[Data Structures]") {
    std::vector<int> vector1{555, 901, 482, 1771};
    std::vector<int> vector2{12, 345, 2, 6, 7896};

    REQUIRE(find_numbers_with_even_number_of_digits_solution_0(vector1) == 1);
    REQUIRE(find_numbers_with_even_number_of_digits_solution_0(vector2) == 2);

    REQUIRE(find_numbers_with_even_number_of_digits_solution_1(vector1) == 1);
    REQUIRE(find_numbers_with_even_number_of_digits_solution_1(vector2) == 2);

}


