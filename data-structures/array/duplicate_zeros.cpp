#include <catch2/catch.hpp>


std::vector<int> duplicate_zeros(std::vector<int> nums) {
    int zeros = 0, original_size = nums.size();

    for (int num: nums) {
        if (num == 0) {
            ++zeros;
        }
    }

    for (int i = original_size - 1, j = original_size - 1 + zeros; i >= 0; --i, --j) {
        if (nums[i] == 0) {
            if (j < original_size) {
                nums[j] = 0;
            }
            --j;
        }
        if (j < original_size) {
            nums[j] = nums[i];
        }
    }

    return nums;
}

TEST_CASE("Duplicate Zeros", "[Data Structures]") {

    std::vector<int> vector{1, 0, 2, 3, 0, 4, 5, 0};
    REQUIRE_THAT(duplicate_zeros(vector), Catch::Matchers::Equals(std::vector<int>{1, 0, 0, 2, 3, 0, 0, 4}));

}
