#include "singly_list_node.cpp"

auto detectCycle(SinglyListNode* head) -> SinglyListNode* {
	SinglyListNode *walker = head, *runner = head;

	while (runner != nullptr && runner->next != nullptr) {
		runner = runner->next->next;
		walker = walker->next;

		if (runner == walker) {
			SinglyListNode* seeker = head;

			while (seeker != walker) {
				walker = walker->next;
				seeker = seeker->next;
			}

			return walker;
		}
	}

	return nullptr;
}
