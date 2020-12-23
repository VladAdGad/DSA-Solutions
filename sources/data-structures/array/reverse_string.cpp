#include <vector>

void xorSwap(char& n1, char& n2) {
	n1 ^= n2;
	n2 ^= n1;
	n1 ^= n2;
}

auto reverseString(std::vector<char>& s) -> std::vector<char> {
	for (int pointer1 = 0, pointer2 = s.size() - 1; pointer1 < pointer2; ++pointer1, --pointer2) {
		xorSwap(s[pointer1], s[pointer2]);
	}

	return s;
}
