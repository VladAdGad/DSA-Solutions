#include <vector>

auto linearSearch(std::vector<int>& arr, int target) -> int {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == target) {
			return i + 1;
		}
	}

	return -1;
}
