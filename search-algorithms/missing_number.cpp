#define CATCH_CONFIG_MAIN //TODO remove when Catch2 will be version 3+
#include <catch2/catch.hpp>


int missing_number_0(const std::vector<int>& nums) {
    int actual_sum = 0;
    for (int num : nums) {
        actual_sum += num;//overflow is possible
    }

    int expected_sum = nums.size() * (nums.size() + 1) / 2;
    return expected_sum - actual_sum;
}

int missing_number_1(const std::vector<int>& nums) {
    int x1 = 0; //xor of all given elements
    int x2 = 0; //xor of all elements

    for (int i = 0; i < nums.size(); i++) {
        x1 ^= nums[i];
        x2 ^= i + 1;
    }

    return x1 ^ x2;
}

TEST_CASE("Missing Number", "[Search Algorithms]") {
    std::vector<int> nums;

    nums = {3, 0, 1};
    REQUIRE(missing_number_0(nums) == 2);
    REQUIRE(missing_number_1(nums) == 2);

    nums = {0, 1, 2, 4, 5, 6};
    REQUIRE(missing_number_0(nums) == 3);
    REQUIRE(missing_number_1(nums) == 3);

    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    REQUIRE(missing_number_0(nums) == 8);
    REQUIRE(missing_number_1(nums) == 8);

    nums = {0};
    REQUIRE(missing_number_0(nums) == 1);
    REQUIRE(missing_number_1(nums) == 1);

}
