#include <catch2/catch.hpp>

enum matrix_direction {
    right, down, left, up
};

auto spiralOrder(std::vector<std::vector<int>> &matrix) -> std::vector<int> {
    std::vector<int> spiral_order;

    if (matrix.empty()) {
        return spiral_order;
    }

    int top_border = 0;
    int bottom_border = matrix.size();
    int left_border = 0;
    int right_border = matrix[0].size();
    const unsigned int expected_number_of_elements = bottom_border * right_border;

    int i = 0;
    int j = 0;
    matrix_direction matrixDirection = right;
    while (spiral_order.size() != expected_number_of_elements) {
        switch (matrixDirection) {
            case right:
                while (j < right_border) {
                    spiral_order.push_back(matrix[i][j++]);
                }
                ++top_border;
                ++i;
                --j;
                matrixDirection = down;
                break;
            case down:
                while (i < bottom_border) {
                    spiral_order.push_back(matrix[i++][j]);
                }
                --right_border;
                --j;
                --i;
                matrixDirection = left;
                break;
            case left:
                while (j >= left_border) {
                    spiral_order.push_back(matrix[i][j--]);
                }
                --bottom_border;
                --i;
                ++j;
                matrixDirection = up;
                break;
            case up:
                while (i >= top_border) {
                    spiral_order.push_back(matrix[i--][j]);
                }
                ++left_border;
                ++j;
                ++i;
                matrixDirection = right;
                break;
        }
    }

    return spiral_order;
}

TEST_CASE("Spiral Matrix" "[Data Structures]") {
    std::vector<std::vector<int>> matrix;

    matrix = {};
    REQUIRE_THAT(spiralOrder(matrix), Catch::Matchers::Equals(std::vector<int>{}));

    matrix = {{1, 2, 3},
              {4, 5, 6},
              {7, 8, 9}};
    REQUIRE_THAT(spiralOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5}));

    matrix = {{1, 2,  3,  4},
              {5, 6,  7,  8},
              {9, 10, 11, 12}};
    REQUIRE_THAT(spiralOrder(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));

}