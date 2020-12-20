#include <vector>
#include <catch2/catch.hpp>

std::vector<int> sorted_squares(std::vector<int> &nums) {
    std::vector<int> squares(nums.size());
    int l = 0, r = nums.size() - 1, p = nums.size() - 1;

    while (l <= r) {
        squares[p--] = std::pow(nums[(std::abs(nums[l]) > std::abs(nums[r])) ? l++ : r--], 2);
    }

    return squares;
}

TEST_CASE("Squares of a Sorted Array", "[Data Structures]") {
    std::vector<int> vector;

    vector = {-3, -1, 0};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{0, 1, 9}));

    vector = {-3, 0, 2};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{0, 4, 9}));

    vector = {-4, -1, 0, 3, 10};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{0, 1, 9, 16, 100}));

    vector = {-7, -3, 2, 3, 11};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{4, 9, 9, 49, 121}));

    vector = {2, 3, 11};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{4, 9, 121}));

    vector = {-1};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{1}));

    vector = {-2, 0};
    REQUIRE_THAT(sorted_squares(vector), Catch::Matchers::Equals(std::vector<int>{0, 4}));

}