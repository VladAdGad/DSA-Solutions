#include <memory>

class SinglyListNode {
public:
	int value;
	std::shared_ptr<SinglyListNode> next;

	explicit SinglyListNode(int value) {
		this->value = value;
		next = nullptr;
	}
};
