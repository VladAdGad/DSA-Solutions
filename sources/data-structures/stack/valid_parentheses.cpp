#include <map>
#include <stack>
#include <string>

auto isValid(const std::string& s) -> bool {
	std::stack<char> data;
	const std::map<char, char> parentheses = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

	for (const char& elem : s) {
		if (elem == '(' || elem == '[' || elem == '{') {
			data.push(elem);
		} else {
			if (!data.empty()) {
				if (parentheses.find(data.top())->second == elem) {
					data.pop();
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
	}

	return data.empty();
}
