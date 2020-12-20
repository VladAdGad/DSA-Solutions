#include <catch2/catch.hpp>


std::vector<int> find_diagonal_order(std::vector<std::vector<int>> &matrix) {
    std::vector<int> diagonal_traverse;

    if (matrix.empty()) {
        return diagonal_traverse;
    }

    const unsigned int rows = matrix.size();
    const unsigned int columns = matrix[0].size();
    const unsigned int expected_number_of_elements = rows * columns;
    int i = 0;
    int j = 0;
    while (diagonal_traverse.size() != expected_number_of_elements) {
        while (i != -1 && j != columns) {//up
            diagonal_traverse.push_back(matrix[i--][j++]);
        }
        if (j == columns) {
            ++i;
            --j;
            ++i;
        }
        if (i == -1) {
            ++i;
        }

        while (j != -1 && i != rows) {//down
            diagonal_traverse.push_back(matrix[i++][j--]);
        }
        if (i == rows) {
            --i;
            ++j;
            ++j;
        }
        if (j == -1) {
            ++j;
        }

    }

    return diagonal_traverse;
}

TEST_CASE("Diagonal Traverse", "[Data Structures]") {
    std::vector<std::vector<int>> matrix;

    matrix = {};
    REQUIRE_THAT(find_diagonal_order(matrix), Catch::Matchers::Equals(std::vector<int>{}));

    matrix = {{1, 2, 3},
              {4, 5, 6},
              {7, 8, 9}};
    REQUIRE_THAT(find_diagonal_order(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 4, 7, 5, 3, 6, 8, 9}));

    matrix = {{1, 2, 3},
              {4, 5, 6}};
    REQUIRE_THAT(find_diagonal_order(matrix), Catch::Matchers::Equals(std::vector<int>{1, 2, 4, 5, 3, 6}));

    matrix = {{1}};
    REQUIRE_THAT(find_diagonal_order(matrix), Catch::Matchers::Equals(std::vector<int>{1}));

}
