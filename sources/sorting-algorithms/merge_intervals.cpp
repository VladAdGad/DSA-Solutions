#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
	std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) {
		return i1[0] < i2[0];
	});

	for (int i = 0; i < intervals.size() - 1; ++i) {
		if (intervals[i][1] >= intervals[i + 1][0]) {
			if (intervals[i][1] < intervals[i + 1][1]) {
				intervals[i] = std::vector{intervals[i][0], intervals[i + 1][1]};
			} else {
				intervals[i] = std::vector{intervals[i][0], intervals[i][1]};
			}
			intervals.erase(intervals.begin() + i + 1);
			--i;
		}
	}

	return intervals;
}
