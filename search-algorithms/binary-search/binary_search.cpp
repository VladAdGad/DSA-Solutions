#include <catch2/catch.hpp>


int binary_search(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + ((right - left) / 2);
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

TEST_CASE("Binary Search", "[Search Algorithms]") {
    std::vector<int> vector;

    vector = {};
    REQUIRE(binary_search(vector, 10) == -1);

    vector = {10};
    REQUIRE(binary_search(vector, 10) == 0);

    vector = {2, 5};
    REQUIRE(binary_search(vector, 2) == 0);
    REQUIRE(binary_search(vector, 5) == 1);

    vector = {-1, 0, 3, 5, 9, 12};
    REQUIRE(binary_search(vector, 9) == 4);

}
