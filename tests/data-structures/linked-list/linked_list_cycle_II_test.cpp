#include "linked_list_cycle_II.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Linked List Cycle II", "[Data Structures]") {
	SECTION("linked list cycle") {
		auto* list_node_0 = new SinglyListNode(3);
		auto* list_node_1 = new SinglyListNode(2);
		auto* list_node_2 = new SinglyListNode(0);
		auto* list_node_3 = new SinglyListNode(-4);

		list_node_0->next = list_node_1;
		list_node_1->next = list_node_2;
		list_node_2->next = list_node_3;
		list_node_3->next = list_node_1;
		REQUIRE(detectCycle(list_node_0) == list_node_1);
	}

	SECTION("linked list non-cycle") {
		auto* list_node_0 = new SinglyListNode(1);
		auto* list_node_1 = new SinglyListNode(2);

		list_node_0->next = list_node_1;
		REQUIRE(detectCycle(list_node_0) == nullptr);
	}

	SECTION("linked list non-cycle with one element") {
		auto* list_node_0 = new SinglyListNode(1);

		REQUIRE(detectCycle(list_node_0) == nullptr);
	}

	SECTION("pass nullptr") {
		REQUIRE(detectCycle(nullptr) == nullptr);
	}
}