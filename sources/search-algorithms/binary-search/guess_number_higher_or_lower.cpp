class Guess {
public:
	int pick;

	auto guess(int n) -> int {
		if (n == pick) {
			return 0;
		} else if (n < pick) {
			return -1;
		} else {
			return 1;
		}
	}
};

auto guessNumber(int n) -> int {
	int left = 0;
	int right = n;
	int mid = 0;
	int res = 0;

	while (left <= right) {
		mid = left + ((right - left) / 2);
		//        res = guess(mid);

		if (res == 0) {
			return mid;
		} else if (res == -1) {
			right = mid + res;
		} else {
			left = mid + res;
		}
	}
	return -1;
}
