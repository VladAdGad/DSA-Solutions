#include "singly_list_node.cpp"

auto hasCycle(SinglyListNode* head) -> bool {
	if (head == nullptr) {
		return false;
	}

	SinglyListNode* slow = head;
	SinglyListNode* fast = head->next;
	while (slow != fast) {
		if (fast == nullptr || fast->next == nullptr) {
			return false;
		}

		slow = slow->next;
		fast = fast->next->next;
	}

	return true;
}
