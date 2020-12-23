#include <vector>

auto findPivotIndex(std::vector<int>& nums) -> int {
	int sum = 0;
	int left_sum = 0;
	int right_sum = 0;

	for (auto num : nums) {
		sum += num;
	}

	right_sum = sum;
	for (int i = 0; i < nums.size(); ++i) {
		right_sum -= nums[i];
		if (left_sum == right_sum) {
			return i;
		}
		left_sum += nums[i];
	}

	return -1;
}
