#include "singly_list_node.cpp"

auto hasCycle(const std::shared_ptr<SinglyListNode>& head) -> bool {
	if (head == nullptr) {
		return false;
	}

	auto slow = head;
	auto fast = head->next;
	while (slow != fast) {
		if (fast == nullptr || fast->next == nullptr) {
			return false;
		}

		slow = slow->next;
		fast = fast->next->next;
	}

	return true;
}
