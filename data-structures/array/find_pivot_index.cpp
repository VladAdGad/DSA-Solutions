#include <catch2/catch.hpp>


int find_pivot_index(std::vector<int>& nums) {
    int sum = 0;
    int leftSum = 0;
    int right_sum;

    for (auto num : nums) {
        sum += num;
    }

    right_sum = sum;
    for (int i = 0; i < nums.size(); ++i) {
        right_sum -= nums[i];
        if(leftSum == right_sum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

TEST_CASE("Find Pivot Index", "[Data Structures]") {

    std::vector<int> nums{1, 7, 3, 6, 5, 6};
    REQUIRE(find_pivot_index(nums) == 3);

}
