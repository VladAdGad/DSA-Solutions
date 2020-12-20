#include <catch2/catch.hpp>

int sqrt(int x) {
    int left = 2;
    int right = x / 2;
    int mid = 0;
    int approx = 0;

    if (x < 2){
        return x;
    }

    while (left <= right){
        mid = left + ((right - left) / 2);
        approx = mid * mid;

        if (approx < x){
            left = mid + 1;
        } else if (approx > x){
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return right;
}

TEST_CASE("Sqrt", "[Search Algorithms]") {

    REQUIRE(sqrt(4) == 2);

    REQUIRE(sqrt(8) == 2);

    REQUIRE(sqrt(16) == 4);

    REQUIRE(sqrt(32) == 5);

}
