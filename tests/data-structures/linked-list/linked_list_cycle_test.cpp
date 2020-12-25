#include "linked_list_cycle.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Linked List Cycle", "[Data Structures]") {
	SECTION("linked list cycle") {
		auto list_node_0 = std::make_shared<SinglyListNode>(0);
		auto list_node_1 = std::make_shared<SinglyListNode>(1);

		list_node_0->next = list_node_1;
		list_node_1->next = list_node_0;
		REQUIRE(hasCycle(list_node_0));
	}

	SECTION("linked list non-cycle") {
		auto list_node_0 = std::make_shared<SinglyListNode>(1);
		auto list_node_1 = std::make_shared<SinglyListNode>(2);

		list_node_0->next = list_node_1;
		REQUIRE_FALSE(hasCycle(list_node_0));
	}

	SECTION("pass nullptr") {
		REQUIRE_FALSE(hasCycle(nullptr));
	}
}
