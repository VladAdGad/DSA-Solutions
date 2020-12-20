#include <catch2/catch.hpp>


int linear_search(std::vector<int>& arr, int target) {

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i + 1;
        }
    }

    return -1;
}

TEST_CASE("Linear Search", "[Search Algorithms]") {

    std::vector<int> simpleVector{9, 7, 2, 16, 4};
    REQUIRE(linear_search(simpleVector, 16) == 4);

}
