#include <vector>

auto duplicateZeros(std::vector<int> nums) -> std::vector<int> {
	int zeros = 0, original_size = nums.size();

	for (int num : nums) {
		if (num == 0) {
			++zeros;
		}
	}

	for (int i = original_size - 1, j = original_size - 1 + zeros; i >= 0; --i, --j) {
		if (nums[i] == 0) {
			if (j < original_size) {
				nums[j] = 0;
			}
			--j;
		}
		if (j < original_size) {
			nums[j] = nums[i];
		}
	}

	return nums;
}
