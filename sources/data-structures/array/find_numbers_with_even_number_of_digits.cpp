#include <string>
#include <vector>

auto findNumbersWithEvenNumberOfDigits0(std::vector<int>& nums) -> int {
	int numbers_with_even_number_of_digits = 0;
	std::string str_num;

	for (int num : nums) {
		str_num = std::to_string(num);
		numbers_with_even_number_of_digits += (str_num.length() % 2 == 0) ? 1 : 0;
	}

	return numbers_with_even_number_of_digits;
}

auto findNumbersWithEvenNumberOfDigits1(std::vector<int>& nums) -> int {
	int numbers_with_even_number_of_digits = 0;

	for (int num : nums) {
		int digit = 0;

		while (num > 0) {
			num /= 10;
			digit++;
		}
		numbers_with_even_number_of_digits += (digit % 2 == 0) ? 1 : 0;
	}

	return numbers_with_even_number_of_digits;
}
