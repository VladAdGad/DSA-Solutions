#include "doubly_linked_list.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Doubly Linked List", "[Data Structures]") {
	DoublyLinkedList* linked_ist = nullptr;

	SECTION("get using empty linked list") {
		linked_ist = new DoublyLinkedList();
		REQUIRE(linked_ist->size == 0);
		REQUIRE(linked_ist->get(0) == -1);
	}

	SECTION("get using index which is higher than size of linked list") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->get(1) == -1);
	}

	SECTION("get last element") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		REQUIRE(linked_ist->size == 3);
		REQUIRE(linked_ist->get(2) == 0);
	}

	SECTION("get first element") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		REQUIRE(linked_ist->size == 3);
		REQUIRE(linked_ist->get(0) == 2);
	}

	SECTION("get middle element") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		REQUIRE(linked_ist->size == 3);
		REQUIRE(linked_ist->get(1) == 1);
	}

	SECTION("addAtHead with empty linked list") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(7);
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->get(0) == 7);
		REQUIRE(linked_ist->head == linked_ist->tail);
	}

	SECTION("addAtHead multiple times") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		REQUIRE(linked_ist->size == 2);
		REQUIRE(linked_ist->head != linked_ist->tail);
		REQUIRE(linked_ist->get(0) == 1);
		REQUIRE(linked_ist->get(1) == 0);
		REQUIRE(linked_ist->head->value == 1);
		REQUIRE(linked_ist->tail->value == 0);
	}

	SECTION("addAtTail with empty linked list") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtTail(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->get(0) == 0);
		REQUIRE(linked_ist->tail == linked_ist->head);
	}

	SECTION("addAtTail multiple times") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtTail(0);
		linked_ist->addAtTail(1);
		REQUIRE(linked_ist->size == 2);
		REQUIRE(linked_ist->head != linked_ist->tail);
		REQUIRE(linked_ist->get(0) == 0);
		REQUIRE(linked_ist->get(1) == 1);
		REQUIRE(linked_ist->head->value == 0);
		REQUIRE(linked_ist->tail->value == 1);
	}

	SECTION("addAtIndex using index which is higher than size of linked list") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE_FALSE(linked_ist->addAtIndex(2, 1));
		REQUIRE(linked_ist->size == 1);
	}

	SECTION("addAtIndex using index as same as size of linked list") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->addAtIndex(1, 1));
		REQUIRE(linked_ist->size == 2);
		REQUIRE(linked_ist->tail->value == 1);
	}

	SECTION("addAtIndex using index zero (first element) with empty linked list") {
		linked_ist = new DoublyLinkedList();
		REQUIRE(linked_ist->size == 0);
		REQUIRE(linked_ist->addAtIndex(0, 0));
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->head == linked_ist->tail);
	}

	SECTION("addAtIndex using index zero (first element)") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->addAtIndex(0, 1));
		REQUIRE(linked_ist->size == 2);
		REQUIRE(linked_ist->head->value == 1);
		REQUIRE(linked_ist->tail->value == 0);
	}

	SECTION("addAtIndex where index is less as twice then size") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		linked_ist->addAtHead(3);
		linked_ist->addAtHead(4);
		REQUIRE(linked_ist->size == 5);
		REQUIRE(linked_ist->addAtIndex(1, 5));
		REQUIRE(linked_ist->size == 6);
		REQUIRE(linked_ist->get(1) == 5);
	}

	SECTION("addAtIndex where index is more as size divided twice") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		linked_ist->addAtHead(3);
		linked_ist->addAtHead(4);
		REQUIRE(linked_ist->size == 5);
		REQUIRE(linked_ist->addAtIndex(3, 5));
		REQUIRE(linked_ist->size == 6);
		REQUIRE(linked_ist->get(3) == 5);
	}

	SECTION("addAtIndex where index is on the middle") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		linked_ist->addAtHead(3);
		linked_ist->addAtHead(4);
		REQUIRE(linked_ist->size == 5);
		REQUIRE(linked_ist->addAtIndex(2, 5));
		REQUIRE(linked_ist->size == 6);
		REQUIRE(linked_ist->get(2) == 5);
	}

	SECTION("deleteAtIndex when list is empty") {
		linked_ist = new DoublyLinkedList();
		REQUIRE(linked_ist->size == 0);
		REQUIRE_FALSE(linked_ist->deleteAtIndex(7));
		REQUIRE(linked_ist->size == 0);
	}

	SECTION("deleteAtIndex using index which is higher than size of linked list") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE_FALSE(linked_ist->deleteAtIndex(1));
		REQUIRE(linked_ist->size == 1);
	}

	SECTION("deleteAtIndex using index which points to the head (zero)") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->deleteAtIndex(0));
		REQUIRE(linked_ist->size == 0);
		REQUIRE(linked_ist->head == nullptr);
	}

	SECTION("deleteAtIndex using index which points to the tail") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtTail(1);
		REQUIRE(linked_ist->size == 2);
		REQUIRE(linked_ist->deleteAtIndex(1));
		REQUIRE(linked_ist->size == 1);
		REQUIRE(linked_ist->tail->value == 0);
	}

	SECTION("deleteAtIndex where index is less as twice then size") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		linked_ist->addAtHead(3);
		linked_ist->addAtHead(4);
		REQUIRE(linked_ist->size == 5);
		REQUIRE(linked_ist->deleteAtIndex(1));
		REQUIRE(linked_ist->size == 4);
		REQUIRE(linked_ist->get(1) == 2);
	}

	SECTION("deleteAtIndex where index is more as size divided twice") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		linked_ist->addAtHead(3);
		linked_ist->addAtHead(4);
		REQUIRE(linked_ist->size == 5);
		REQUIRE(linked_ist->deleteAtIndex(3));
		REQUIRE(linked_ist->size == 4);
		REQUIRE(linked_ist->get(3) == 0);
	}

	SECTION("deleteAtIndex where index is on the middle") {
		linked_ist = new DoublyLinkedList();
		linked_ist->addAtHead(0);
		linked_ist->addAtHead(1);
		linked_ist->addAtHead(2);
		linked_ist->addAtHead(3);
		linked_ist->addAtHead(4);
		REQUIRE(linked_ist->size == 5);
		REQUIRE(linked_ist->deleteAtIndex(2));
		REQUIRE(linked_ist->size == 4);
		REQUIRE(linked_ist->get(2) == 1);
	}
}
