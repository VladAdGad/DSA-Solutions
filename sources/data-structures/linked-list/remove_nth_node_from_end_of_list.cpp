#include "singly_list_node.cpp"

#include <memory>

SinglyListNode* removeNthFromEnd1(SinglyListNode* head, int n) {
	SinglyListNode* cur_node = head;
	int size = 0;
	while (cur_node != nullptr) {
		cur_node = cur_node->next;
		++size;
	}

	auto* dummy = new SinglyListNode(-1);
	dummy->next = head;
	cur_node = dummy;
	size -= n;
	while (size-- > 0) {
		cur_node = cur_node->next;
	}

	cur_node->next = cur_node->next->next;
	return dummy->next;
}

SinglyListNode* removeNthFromEnd2(SinglyListNode* head, int n) {
	auto* gap_last_node = head;
	while (n-- > 0) {
		gap_last_node = gap_last_node->next;
	}

	auto* dummy = new SinglyListNode(-1);
	dummy->next = head;
	auto* gap_first_node = dummy;
	while (gap_last_node != nullptr) {
		gap_first_node = gap_first_node->next;
		gap_last_node = gap_last_node->next;
	}

	gap_first_node->next = gap_first_node->next->next;
	return dummy->next;
}
