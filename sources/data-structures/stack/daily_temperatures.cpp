#include <stack>
#include <vector>

auto dailyTemperatures1(std::vector<int>& daily_temperatures) -> std::vector<int> {
	std::vector<int> days_to_wait(daily_temperatures.size(), 0);

	for (int i = 0; i < daily_temperatures.size(); ++i) {
		for (int j = i + 1; j < daily_temperatures.size(); ++j) {
			if (daily_temperatures[i] < daily_temperatures[j]) {
				days_to_wait[i] = j - i;
				break;
			}
		}
	}

	return days_to_wait;
}

auto dailyTemperatures2(std::vector<int>& temperatures) -> std::vector<int> {
	std::vector<int> result(temperatures.size(), 0);
	std::stack<std::pair<int, int>> number_position;  // First is the number while second is the position

	for (int i = temperatures.size() - 1; i >= 0; i--) {
		int curr = temperatures[i];
		while (!number_position.empty() && number_position.top().first <= curr) {
			number_position.pop();
		}

		result[i] = number_position.empty() ? 0 : number_position.top().second - i;

		number_position.push({curr, i});
	}

	return result;
}
