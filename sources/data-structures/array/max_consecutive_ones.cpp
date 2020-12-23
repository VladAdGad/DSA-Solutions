#include <vector>

auto findMaxConsecutiveOnes(std::vector<int>& nums) -> int {
	int cur_consecutive_of_ones = 0;
	int max_consecutive_of_ones = 0;

	for (int elem : nums) {
		if (elem == 1) {
			cur_consecutive_of_ones++;
		} else {
			if (cur_consecutive_of_ones > max_consecutive_of_ones) {
				max_consecutive_of_ones = cur_consecutive_of_ones;
			}
			cur_consecutive_of_ones = 0;
		}
	}

	if (cur_consecutive_of_ones > max_consecutive_of_ones) {
		max_consecutive_of_ones = cur_consecutive_of_ones;
	}

	return max_consecutive_of_ones;
}
