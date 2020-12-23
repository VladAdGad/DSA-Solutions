#include <vector>

enum MatrixDirection { Right, Down, Left, Up };

auto spiralOrder(std::vector<std::vector<int>>& matrix) -> std::vector<int> {
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
	MatrixDirection matrix_direction = Right;
	while (spiral_order.size() != expected_number_of_elements) {
		switch (matrix_direction) {
			case Right:
				while (j < right_border) {
					spiral_order.push_back(matrix[i][j++]);
				}
				++top_border;
				++i;
				--j;
				matrix_direction = Down;
				break;
			case Down:
				while (i < bottom_border) {
					spiral_order.push_back(matrix[i++][j]);
				}
				--right_border;
				--j;
				--i;
				matrix_direction = Left;
				break;
			case Left:
				while (j >= left_border) {
					spiral_order.push_back(matrix[i][j--]);
				}
				--bottom_border;
				--i;
				++j;
				matrix_direction = Up;
				break;
			case Up:
				while (i >= top_border) {
					spiral_order.push_back(matrix[i--][j]);
				}
				++left_border;
				++j;
				++i;
				matrix_direction = Right;
				break;
		}
	}

	return spiral_order;
}
