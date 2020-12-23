#include <vector>

auto missingNumber0(const std::vector<int>& nums) -> int {
	int actual_sum = 0;
	for (int num : nums) {
		actual_sum += num;  // overflow is possible
	}

	int expected_sum = nums.size() * (nums.size() + 1) / 2;
	return expected_sum - actual_sum;
}

auto missingNumber1(const std::vector<int>& nums) -> int {
	int x1 = 0;  // xor of all given elements
	int x2 = 0;  // xor of all elements

	for (int i = 0; i < nums.size(); i++) {
		x1 ^= nums[i];
		x2 ^= i + 1;
	}

	return x1 ^ x2;
}
