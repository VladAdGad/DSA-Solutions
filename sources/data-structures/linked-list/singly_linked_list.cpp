#include "singly_list_node.cpp"

class SinglyLinkedList {
public:
	std::shared_ptr<SinglyListNode> head;
  std::shared_ptr<SinglyListNode> tail;
	int size;

	SinglyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	[[nodiscard]] auto get(int index) const -> int {
		if (index >= size) {
			return -1;
		}

		int count = 0;
		for (auto cur = head; count != index + 1; cur = cur->next, ++count) {
			if (count == index) {
				return cur->value;
			}
		}

		return -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the
	 * first node of the linked list. */
	auto addAtHead(int val) -> bool {
		auto new_node = std::make_shared<SinglyListNode>(val);

		new_node->next = head;
		head = new_node;

		if (size == 0) {
			tail = head;
		}
		size++;
		return true;
	}

	/** Append a node of value val to the last element of the linked list. */
	auto addAtTail(int val) -> bool {
    auto new_node = std::make_shared<SinglyListNode>(val);

		if (size == 0) {
			tail = new_node;
			head = tail;
		} else {
			tail->next = new_node;
			tail = new_node;
		}

		size++;
		return true;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
	 * the node will be appended to the end of linked list. If index is greater than the length, the node will not be
	 * inserted. */
	auto addAtIndex(int index, int val) -> bool {
		if (index > size) {
			return false;
		}

		if (index == size) {
			return addAtTail(val);
		}

		if (size == 0 || index == 0) {
			return addAtHead(val);
		}

		int count = 0;
		for (auto cur = head; count != index + 1; cur = cur->next, ++count) {
			if (count == index - 1) {
        auto new_node = std::make_shared<SinglyListNode>(val);
				new_node->next = cur->next;
				cur->next = new_node;
				size++;
				return true;
			}
		}

		return false;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	auto deleteAtIndex(int index) -> bool {
		if (index >= size) {
			return false;
		}

		if (index == 0) {
			head = head->next;
			size--;
			return true;
		}

		int count = 0;
		for (auto cur = head; count != index + 1; cur = cur->next, ++count) {
			if (count == index - 1) {
				cur->next = cur->next->next;
				if (index == size - 1) {
					tail = cur;
				}
				size--;
				return true;
			}
		}

		return false;
	}
};
