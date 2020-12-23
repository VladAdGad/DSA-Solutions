#include <vector>

auto findIndexOfRotation(std::vector<int>& nums) -> int {
	int left = 0;
	int right = nums.size() - 1;

	if (nums[left] < nums[right]) {
		return 0;
	}

	while (left <= right) {
		int mid = left + ((right - left) / 2);
		if (nums[mid] > nums[mid + 1]) {
			return mid + 1;
		}
		if (nums[mid] < nums[0]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return 0;
}

auto binarySearch(std::vector<int>& nums, int left, int right, int target) -> int {
	int mid = 0;

	while (left <= right) {
		mid = left + ((right - left) / 2);
		if (target == nums[mid]) {
			return mid;
		} else if (target > nums[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

auto search(std::vector<int>& nums, int target) -> int {
	if (nums.empty()) {
		return -1;
	}

	if (nums.size() == 1) {
		return nums[0] == target ? 0 : -1;
	}

	int index_of_rotation = findIndexOfRotation(nums);

	if (index_of_rotation == 0) {
		return binarySearch(nums, 0, nums.size() - 1, target);
	} else {
		if (target >= nums[0]) {
			return binarySearch(nums, 0, index_of_rotation - 1, target);
		} else {
			return binarySearch(nums, index_of_rotation, nums.size() - 1, target);
		}
	}
}
