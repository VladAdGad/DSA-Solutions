#include <cmath>
#include <vector>

auto sortedSquares(std::vector<int>& nums) -> std::vector<int> {
	std::vector<int> squares(nums.size());
	int l = 0, r = nums.size() - 1, p = nums.size() - 1;

	while (l <= r) {
		squares[p--] = std::pow(nums[(std::abs(nums[l]) > std::abs(nums[r])) ? l++ : r--], 2);
	}

	return squares;
}
