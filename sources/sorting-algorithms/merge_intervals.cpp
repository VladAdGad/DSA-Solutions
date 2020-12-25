#include <vector>

auto merge(std::vector<std::vector<int>>& intervals) -> std::vector<std::vector<int>> {
	std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) {
		return i1[0] > i2[0];
	});

	for (unsigned int i = intervals.size() - 1; i > 0; --i) {
		if (intervals[i][1] >= intervals[i - 1][0]) {
			if (intervals[i][1] < intervals[i - 1][1]) {
				intervals[i] = {intervals[i][0], intervals[i - 1][1]};
			} else {
				intervals[i] = {intervals[i][0], intervals[i][1]};
			}
			intervals.erase(intervals.begin() + i - 1);
		}
	}

	return intervals;
}
