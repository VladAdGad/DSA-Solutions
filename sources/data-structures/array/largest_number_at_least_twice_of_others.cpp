#include <vector>

auto dominantIndex(std::vector<int>& nums) -> int {
	if (nums.size() == 1) {
		return 0;
	}

	int largest = 0;
	int prev_largest = 0;
	if (nums[0] > nums[1]) {
		largest = 0;
		prev_largest = 1;
	} else {
		largest = 1;
		prev_largest = 0;
	}

	for (int i = 2; i < nums.size(); ++i) {
		if (nums[i] > nums[largest]) {
			prev_largest = largest;
			largest = i;
		} else if (nums[i] > nums[prev_largest]) {
			prev_largest = i;
		}
	}

	return nums[largest] >= nums[prev_largest] * 2 ? largest : -1;
}
