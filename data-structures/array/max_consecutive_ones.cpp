#include <catch2/catch.hpp>


int find_max_consecutive_ones(std::vector<int>& nums) {
    int cur_consecutive_of_ones = 0;
    int max_consecutive_of_ones = 0;

    for (int elem: nums) {
        if (elem == 1) {
            cur_consecutive_of_ones++;
        } else {
            if (cur_consecutive_of_ones > max_consecutive_of_ones) {
                max_consecutive_of_ones = cur_consecutive_of_ones;
            }
            cur_consecutive_of_ones = 0;
        }
    }

    if (cur_consecutive_of_ones > max_consecutive_of_ones) {
        max_consecutive_of_ones = cur_consecutive_of_ones;
    }

    return max_consecutive_of_ones;
}

TEST_CASE("Find Max Consecutive Ones", "[Data Structures]"){
    std::vector<int> vector;

    vector = {1};
    REQUIRE(find_max_consecutive_ones(vector) == 1);

    vector = {1, 1, 0, 1, 1, 1};
    REQUIRE(find_max_consecutive_ones(vector) == 3);

}