#include <vector>

class MinStack {
private:
	std::vector<int> values;
	std::vector<int> min_values;

public:
	MinStack() = default;

	void push(int value) {
		if (values.empty()) {
			min_values.push_back(value);
		} else {
			min_values.push_back(std::min(min_values.back(), value));
		}
		values.push_back(value);
	}

	void pop() {
		values.pop_back();
		min_values.pop_back();
	}

	auto top() -> int {
		return values.back();
	}

	auto getMin() -> int {
		return min_values.back();
	}
};
