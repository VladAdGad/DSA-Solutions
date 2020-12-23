#include <vector>

auto plusOne(std::vector<int>& digits) -> std::vector<int> {
	int pivot = digits.size() - 1;

	while (pivot != -1 && digits[pivot] == 9) {
		digits[pivot--] = 0;
	}

	if (pivot == -1) {
		digits[0] += 1;
		digits.push_back(0);
	} else {
		digits[pivot] += 1;
	}

	return digits;
}
