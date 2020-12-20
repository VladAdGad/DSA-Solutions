#include <catch2/catch.hpp>


int dominant_index(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return 0;
    }

    int largest;
    int prev_largest;
    if (nums[0] > nums[1]) {
        largest = 0;
        prev_largest = 1;
    } else {
        largest = 1;
        prev_largest = 0;
    }

    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] > nums[largest]) {
            prev_largest = largest;
            largest = i;
        } else if (nums[i] > nums[prev_largest]) {
            prev_largest = i;
        }
    }

    return nums[largest] >= nums[prev_largest] * 2 ? largest : -1;
}

TEST_CASE("Largest Number At Least Twice Of Others", "[Data Structures]") {
    std::vector<int> vector;

    vector = {3, 6, 1, 0};
    REQUIRE(dominant_index(vector) == 1);

    vector = {1, 2, 3, 4};
    REQUIRE(dominant_index(vector) == -1);

    vector = {1};
    REQUIRE(dominant_index(vector) == 0);

    vector = {1, 0};
    REQUIRE(dominant_index(vector) == 0);

    vector = {0, 0, 3, 2};
    REQUIRE(dominant_index(vector) == -1);

    vector = {0, 3, 1, 2};
    REQUIRE(dominant_index(vector) == -1);

}
