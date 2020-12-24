#include "singly_linked_list.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Singly Linked List", "[Data Structures]") {
	SECTION("get using empty linked list") {
		auto linked_list = std::make_unique<SinglyLinkedList>();
		REQUIRE(linked_list->get(0) == -1);
	}

	SECTION("get using index which is higher than size of linked list") {
		auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		REQUIRE(linked_list->get(1) == -1);
	}

	SECTION("get") {
		auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(1);
		REQUIRE(linked_list->get(0) == 1);
	}

	SECTION("addAtHead with empty linked list") {
		auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(1);
		REQUIRE(linked_list->get(0) == 1);
		REQUIRE(linked_list->head == linked_list->tail);
	}

	SECTION("addAtHead multiple times") {
		auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		linked_list->addAtHead(1);
		REQUIRE(linked_list->head != linked_list->tail);
		REQUIRE(linked_list->get(0) == 1);
		REQUIRE(linked_list->get(1) == 0);
		REQUIRE(linked_list->head->value == 1);
		REQUIRE(linked_list->tail->value == 0);
	}

	SECTION("addAtTail multiple times") {
		auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtTail(0);
		linked_list->addAtTail(1);
		REQUIRE(linked_list->head != linked_list->tail);
		REQUIRE(linked_list->get(0) == 0);
		REQUIRE(linked_list->get(1) == 1);
		REQUIRE(linked_list->head->value == 0);
		REQUIRE(linked_list->tail->value == 1);
	}

	SECTION("addAtTail with empty linked list") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtTail(0);
		REQUIRE(linked_list->get(0) == 0);
		REQUIRE(linked_list->tail == linked_list->head);
	}

	SECTION("addAtIndex using index which is higher than size of linked list") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		REQUIRE_FALSE(linked_list->addAtIndex(2, 1));
	}

	SECTION("addAtIndex using index as same as size of linked list") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		REQUIRE(linked_list->addAtIndex(1, 1));
		REQUIRE(linked_list->tail->value == 1);
	}

	SECTION("addAtIndex using index zero (first element) with empty linked list") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		REQUIRE(linked_list->addAtIndex(0, 0));
		REQUIRE(linked_list->head == linked_list->tail);
	}

	SECTION("addAtIndex using index zero (first element)") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		REQUIRE(linked_list->addAtIndex(0, 0));
		REQUIRE(linked_list->addAtIndex(0, 1));
		REQUIRE(linked_list->head->value == 1);
		REQUIRE(linked_list->tail->value == 0);
	}

	SECTION("deleteAtIndex using index which is higher than size of linked list") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		REQUIRE_FALSE(linked_list->deleteAtIndex(1));
	}

	SECTION("deleteAtIndex using index which points to the head (zero)") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		REQUIRE(linked_list->deleteAtIndex(0));
		REQUIRE(linked_list->head == nullptr);
	}

	SECTION("deleteAtIndex using index which points to the tail") {
    auto linked_list = std::make_unique<SinglyLinkedList>();
		linked_list->addAtHead(0);
		linked_list->addAtTail(1);
		REQUIRE(linked_list->deleteAtIndex(1));
		REQUIRE(linked_list->tail->value == 0);
	}
}
