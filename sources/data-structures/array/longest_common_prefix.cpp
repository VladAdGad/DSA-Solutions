#include <string>
#include <vector>

auto longestCommonPrefix(std::vector<std::string>& strs) -> std::string {
	std::string longest_common_prefix = "";

	if (strs.empty()) {
		return "";
	}

	int smallest_word_size = strs[0].size();
	for (auto& str : strs) {
		if (smallest_word_size > str.size()) {
			smallest_word_size = str.size();
		}
	}

	int current_word = 0;
	int current_pos = 0;
	for (int i = 0; i < strs.size() * smallest_word_size; ++i) {
		if (current_word == 0) {
			longest_common_prefix += strs[current_word][current_pos];
		}
		if (longest_common_prefix[current_pos] != strs[current_word][current_pos]) {
			longest_common_prefix.pop_back();
			return longest_common_prefix;
		}
		if (current_word == strs.size() - 1) {
			current_word = 0;
			++current_pos;
		} else {
			++current_word;
		}
	}

	return longest_common_prefix;
}
