#include "singly_list_node.cpp"

auto detectCycle(const std::shared_ptr<SinglyListNode>& head) -> std::shared_ptr<SinglyListNode> {
	auto walker = head;
	auto runner = head;

	while (runner != nullptr && runner->next != nullptr) {
		runner = runner->next->next;
		walker = walker->next;

		if (runner == walker) {
			auto seeker = head;

			while (seeker != walker) {
				walker = walker->next;
				seeker = seeker->next;
			}

			return walker;
		}
	}

	return nullptr;
}
