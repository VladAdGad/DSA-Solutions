#include <vector>

class CircularQueue {
private:
	std::vector<int> data;
	int head;
	int tail;

public:
	explicit CircularQueue(int size) {
		data = std::vector<int>(size);
		head = -1;
		tail = -1;
	}

	auto enqueue(int value) -> bool {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % data.capacity();
		data[tail] = value;
		return true;
	}

	auto dequeue() -> bool {
		if (isEmpty()) {
			return false;
		}
		if (head == tail) {
			head = -1;
			tail = -1;
			return true;
		}
		head = (head + 1) % data.size();
		return true;
	}

	[[nodiscard]] auto front() const -> int {
		return isEmpty() == false ? data[head] : -1;
	}

	[[nodiscard]] auto rear() const -> int {
		return isEmpty() == false ? data[tail] : -1;
	}

	[[nodiscard]] auto isEmpty() const -> bool {
		return head == -1;
	}

	[[nodiscard]] auto isFull() const -> bool {
		return ((tail + 1) % data.capacity()) == head;
	}
};
