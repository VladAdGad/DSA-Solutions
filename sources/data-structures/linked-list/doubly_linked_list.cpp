class DoublyListNode {
public:
	int value;
	DoublyListNode *next, *prev;

	explicit DoublyListNode(int value) {
		this->value = value;
		prev = nullptr;
		next = nullptr;
	}
};

class DoublyLinkedList {
public:
	DoublyListNode* head;
	DoublyListNode* tail;
	int size;

	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	[[nodiscard]] auto get(int index) const -> int {
		if (index >= size) {
			return -1;
		}

		DoublyListNode* current = nullptr;
		if (index < size / 2) {
			current = head;
			for (; index > 0; --index) {
				current = current->next;
			}
		} else {
			current = tail;
			for (index = size - 1 - index; index > 0; --index) {
				current = current->prev;
			}
		}

		return current->value;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the
	 * first node of the linked list. */
	auto addAtHead(int val) -> bool {
		auto* new_head = new DoublyListNode(val);

		if (size == 0) {
			head = new_head;
			tail = new_head;
		} else {
			head->prev = new_head;
			new_head->next = head;
			head = new_head;
		}

		size++;
		return true;
	}

	/** Append a node of value val to the last element of the linked list. */
	auto addAtTail(int val) -> bool {
		auto* new_tail = new DoublyListNode(val);

		if (size == 0) {
			tail = new_tail;
			head = new_tail;
		} else {
			tail->next = new_tail;
			new_tail->prev = tail;
			tail = new_tail;
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

		DoublyListNode* current = nullptr;
		if (index < size / 2) {
			current = head;
			for (; index > 0; --index) {
				current = current->next;
			}
		} else {
			current = tail;
			for (index = size - 1 - index; index > 0; --index) {
				current = current->prev;
			}
		}

		auto* new_node = new DoublyListNode(val);
		new_node->next = current;
		new_node->prev = current->prev;
		current->prev->next = new_node;
		current->prev = new_node;
		size++;
		return true;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	auto deleteAtIndex(int index) -> bool {
		if (size == 0 || index >= size) {
			return false;
		}

		if (index == 0) {
			head->prev = nullptr;
			head = head->next;
			size--;
			return true;
		}

		if (index == size - 1) {
			tail = tail->prev;
			tail->next->prev = nullptr;
			tail->next = nullptr;
			size--;
			return true;
		}

		DoublyListNode* current = nullptr;
		if (index < size / 2) {
			current = head;
			for (; index > 0; --index) {
				current = current->next;
			}
		} else {
			current = tail;
			for (index = size - 1 - index; index > 0; --index) {
				current = current->prev;
			}
		}

		current->prev->next = current->next;
		current->prev->next->prev = current->prev;
		current->next = nullptr;
		current->prev = nullptr;
		size--;
		return true;
	}
};
