#include "singly_list_node.cpp"

auto removeNthFromEnd1(const std::shared_ptr<SinglyListNode>& head, int n) -> std::shared_ptr<SinglyListNode> {
	auto cur_node = head;
	int size = 0;
	while (cur_node != nullptr) {
		cur_node = cur_node->next;
		++size;
	}

	auto dummy = std::make_shared<SinglyListNode>(SinglyListNode(-1));
	dummy->next = head;
	cur_node = dummy;
	size -= n;
	while (size-- > 0) {
		cur_node = cur_node->next;
	}

	cur_node->next = cur_node->next->next;
	return dummy->next;
}

auto removeNthFromEnd2(const std::shared_ptr<SinglyListNode>& head, int n) -> std::shared_ptr<SinglyListNode> {
	auto gap_last_node = head;
	while (n-- > 0) {
		gap_last_node = gap_last_node->next;
	}

	auto dummy = std::make_shared<SinglyListNode>(-1);
	dummy->next = head;
	auto gap_first_node = dummy;
	while (gap_last_node != nullptr) {
		gap_first_node = gap_first_node->next;
		gap_last_node = gap_last_node->next;
	}

	gap_first_node->next = gap_first_node->next->next;
	return dummy->next;
}
