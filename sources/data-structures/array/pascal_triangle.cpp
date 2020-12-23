#include <vector>

auto generatePascalTriangle(const unsigned int rows) -> std::vector<std::vector<int>> {
	const int default_value = 1;
	const int default_size = 1;
	const std::vector<int> default_vector(default_size, default_value);
	std::vector<std::vector<int>> pascal_triangle(rows, default_vector);

	if (pascal_triangle.empty() || pascal_triangle.empty() == 1) {
		return pascal_triangle;
	}

	for (int row = 1; row < rows; ++row) {
		pascal_triangle[row].resize(row + 1, default_value);
		for (int col = 1; col < row; ++col) {
			pascal_triangle[row][col] = pascal_triangle[row - 1][col - 1] + pascal_triangle[row - 1][col];
		}
	}

	return pascal_triangle;
}
