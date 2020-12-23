#include <string>

auto strStr(std::string haystack, std::string needle) -> int {
	if (needle.empty()) {
		return 0;
	}

	int cur_pos = 0;
	while ((int)(haystack.size() - cur_pos + 1) >= (int)needle.size()) {
      for (int i = cur_pos, j = 0; haystack[i] == needle[j]; ++i, ++j) {
        if (j == (int)needle.size() - 1) {
          return cur_pos;
        }
      }
		++cur_pos;
	}

	return -1;
}
